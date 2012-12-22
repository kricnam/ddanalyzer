/*
 * VTDRVehicleConfigure.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#include "VTDRVehicleConfigure.h"

VTDRVehicleConfigure::VTDRVehicleConfigure()
{
	cDataCode = StateConfig;
}

VTDRVehicleConfigure::~VTDRVehicleConfigure()
{

}

int VTDRVehicleConfigure::Read(const char* buf)
{
	Config* ptrConfig = (Config*) buf;
	for (int i = 0; i < 8; i++)
	{
		strNameOf[i].assign((const char*) ptrConfig->NameOfD[i],
				sizeof(ptrConfig->NameOfD[i]));
	}
	return sizeof(*ptrConfig);
}

string& VTDRVehicleConfigure::Write(string& buf)
{
	Config conf =
	{ 0 };

	for (int i = 0; i < 8; i++)
	{
		memcpy(conf.NameOfD[i], strNameOf[i].data(),
				min(strNameOf[i].size(), sizeof(conf.NameOfD[i])));
	}

	buf.append((const char*) &conf, sizeof(conf));
	return buf;
}
