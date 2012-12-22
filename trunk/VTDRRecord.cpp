/*
 * VTDRRecord.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#include "VTDRRecord.h"

VTDRRecord::VTDRRecord():cDataCode(Version)
{

}

VTDRRecord::~VTDRRecord()
{
	// TODO Auto-generated destructor stub
}

string VTDRRecord::BCD2ASCII(string& strBCD)
{
	string str;
	for (int i = 0; i < strBCD.size(); i++)
	{
		str += ((strBCD[i] & 0xF0) >> 4) + 0x30;
		str += ((strBCD[i] & 0x0F)) + 0x30;
	}
	return str;
}

unsigned int VTDRRecord::BCD2INT(const char* bcd, int size)
{
	unsigned int v = 0;
	for (int i = 0; i < size; i++)
	{
		char c = bcd[i];
		v = v * 100;
		v += (c >> 4) & 0x0F * 10 + (c & 0x0f);
	}
	return v;
}

unsigned int VTDRRecord::BCD2INT(unsigned char c)
{
	unsigned int v = 0;
	v += (c >> 4) & 0x0F * 10 + (c & 0x0f);
	return v;
}

char VTDRRecord::INT2BCDchar(int n)
{
	return ((((n % 100) / 10) & 0x0F) << 4) + (n % 100) % 10;
}

time_t VTDRRecord::ToSystime(VTDRTime& t)
{
	struct tm tmVal =
	{ 0 };
	tmVal.tm_year = BCD2INT(t.bcdYear) + 2000 - 1900;
	tmVal.tm_mon = BCD2INT(t.bcdMonth) - 1;
	tmVal.tm_mday = BCD2INT(t.bcdDay);
	tmVal.tm_hour = BCD2INT(t.bcdHour);
	tmVal.tm_min = BCD2INT(t.bcdMinute);
	tmVal.tm_sec = BCD2INT(t.bcdSecond);
	return mktime(&tmVal);
}

VTDRTime& VTDRRecord::ToBCDTime(time_t t, VTDRTime& tmBCD)
{
	struct tm tmVal;
	localtime_r(&t,&tmVal);
	tmBCD.bcdYear = INT2BCDchar(tmVal.tm_year + 1900 - 2000);
	tmBCD.bcdMonth = INT2BCDchar(tmVal.tm_mon + 1);
	tmBCD.bcdDay = INT2BCDchar(tmVal.tm_mday);
	tmBCD.bcdHour = INT2BCDchar(tmVal.tm_hour);
	tmBCD.bcdMinute = INT2BCDchar(tmVal.tm_min);
	tmBCD.bcdSecond = INT2BCDchar(tmVal.tm_sec);

	return tmBCD;
}
