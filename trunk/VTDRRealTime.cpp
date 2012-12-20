/*
 * VTDRRealTime.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#include "VTDRRealTime.h"

VTDRRealTime::VTDRRealTime() :
		tTime(0),cDataCode(RealTime)
{

}

VTDRRealTime::~VTDRRealTime()
{
}

int VTDRRealTime::Read(const char* buf)
{
	VTDRTime* ptrTime = (VTDRTime*) buf;
	tTime = ToSystime(*ptrTime);
	return sizeof(*ptrTime);
}

string& VTDRRealTime::Write(string& buf)
{
	VTDRTime vTime =
	{ 0 };
	ToBCDTime(tTime,vTime);
	buf.append((const char*)&vTime,sizeof(vTime));
	return buf;
}
