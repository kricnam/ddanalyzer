/*
 * VTDRUniqCode.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#include "VTDRUniqCode.h"

VTDRUniqCode::VTDRUniqCode()
{
	// TODO Auto-generated constructor stub

}

VTDRUniqCode::~VTDRUniqCode()
{
	// TODO Auto-generated destructor stub
}

int VTDRUniqCode::Read(const char* buf)
{
	UniqCode* ptrCode = (UniqCode*) buf;
	assign(strManufacture, ptrCode->Manufacture);
	assign(strAuthType, ptrCode->AuthrizedType);
	nYear = (int) BCD2INT((const char*) &(ptrCode->bcdYear),
			sizeof(ptrCode->bcdYear)) + 2000;
	nMonth = (int) BCD2INT((const char*) &(ptrCode->bcdMonth),
			sizeof(ptrCode->bcdMonth));
	nDay = (int) BCD2INT((const char*) &(ptrCode->bcdDay),
			sizeof(ptrCode->bcdDay));
	nSerialNumber = (ptrCode->SerialNumber);
	return sizeof(*ptrCode);
}

string& VTDRUniqCode::Write(string& buf)
{
	UniqCode code =
	{ 0 };

	set(code.AuthrizedType,strAuthType);
	set(code.Manufacture,strManufacture);
	code.bcdYear = INT2BCDchar(nYear-2000);
	code.bcdMonth  = INT2BCDchar(nMonth);
	code.bcdDay = INT2BCDchar(nDay);
	code.SerialNumber = nSerialNumber;

	buf.append((const char*)&code,sizeof(code));
	return buf;
}
