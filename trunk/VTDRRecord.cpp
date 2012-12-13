/*
 * VTDRRecord.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#include "VTDRRecord.h"

VTDRRecord::VTDRRecord()
{
	// TODO Auto-generated constructor stub

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

char VTDRRecord::INT2BCDchar(int n)
{
	return ((((n%100)/10) & 0x0F) << 4) + (n%100)%10;
}
