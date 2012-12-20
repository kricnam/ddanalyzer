/*
 * VTDRVehicleInfo.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#include "VTDRVehicleInfo.h"

VTDRVehicleInfo::VTDRVehicleInfo()
{
	// TODO Auto-generated constructor stub

}

VTDRVehicleInfo::~VTDRVehicleInfo():
		cDataCode(VehicleInfo)
{
}

int VTDRVehicleInfo::Read(const char* buf)
{
	VehicleInfo* ptrInfo = (VehicleInfo*) buf;
	;
	strTypeCode.assign((const char*) ptrInfo->TypeCode,
			sizeof(ptrInfo->TypeCode));
	strPlateNumber.assign((const char*) ptrInfo->PlateNumber,
			sizeof(ptrInfo->PlateNumber));
	strPlateClass.assign((const char*) ptrInfo->PlateClass,
			sizeof(ptrInfo->PlateClass));
	return sizeof(*ptrInfo);
}

string& VTDRVehicleInfo::Write(string& buf)
{
	VehicleInfo info;
	memset(&info, 0, sizeof(info));
	memcpy(info.TypeCode, strTypeCode.data(),
			min(sizeof(info.TypeCode), strTypeCode.size()));
	memcpy(info.PlateNumber, strPlateNumber.data(),
			min(sizeof(info.PlateNumber), strPlateNumber.size()));
	memcpy(info.PlateClass, strPlateClass.data(),
			min(sizeof(info.PlateClass), strPlateClass.size()));
	buf.append((const char *) &info, sizeof(info));
	return buf;
}
