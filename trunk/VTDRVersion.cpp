/*
 * VTDRVersion.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#include "VTDRVersion.h"

VTDRVersion::VTDRVersion() :
		year(2012), modify(0)
{
	// TODO Auto-generated constructor stub

}

VTDRVersion::~VTDRVersion()
{
	// TODO Auto-generated destructor stub
}

int VTDRVersion::Read(const char* buf)
{
	if (buf)
	{
		VERSION* ptr = (VERSION*) buf;
		year = 2000 + ((ptr->cYear & 0x0F0) >> 4) * 10 + (ptr->cYear) & 0x0F;
		modify = ptr->cModi;
		return sizeof(VERSION);
	}
	return 0;
}

string& VTDRVersion::Write(string& buf)
{
	VERSION version;
	version.cYear = ((((year - 2000) % 100) / 10) << 4) | (year % 10);
	version.cModi = (char) modify;
	buf.append((const char*) &version, sizeof(version));
	return buf;
}
