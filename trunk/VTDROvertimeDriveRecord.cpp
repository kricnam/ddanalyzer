/*
 * VTDROvertimeDriveRecord.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#include "VTDROvertimeDriveRecord.h"

VTDROvertimeDriveRecord::VTDROvertimeDriveRecord() :
		tStartTime(0), tEndTime(0), startLongititude(0.0), startLatitude(0.0), startAltitude(
				0), endLogititude(0.0), endLatitude(0.0), endAltitude(0)
{

}

VTDROvertimeDriveRecord::~VTDROvertimeDriveRecord()
{

}

int VTDROvertimeDriveRecord::Read(const char* buf)
{
	OvertimeDriveRecord* ptrRec = (OvertimeDriveRecord*) buf;
	ASSIGN(strLicese, ptrRec->DriverLicense);
	tStartTime = ToSystime(ptrRec->startTime);
	tEndTime = ToSystime(ptrRec->endTime);
	startLongititude = ntohl(ptrRec->startPos.longititude) / 10000.0f;
	startLatitude = ntohl(ptrRec->startPos.latitude) / 10000.0f;
	startAltitude = ntohs(ptrRec->startPos.altitude);
	endLogititude = ntohl(ptrRec->endPos.longititude) / 10000.0f;
	endLatitude = ntohl(ptrRec->endPos.latitude) / 10000.0f;
	endAltitude = ntohs(ptrRec->endPos.altitude);

	return sizeof(*ptrRec);
}

string& VTDROvertimeDriveRecord::Write(string& buf)
{
	OvertimeDriveRecord rec =
	{ 0 };
	SET(rec.DriverLicense, strLicese);
	ToBCDTime(tStartTime, rec.startTime);
	ToBCDTime(tEndTime, rec.endTime);
	rec.startPos.longititude = htonl(MinuteToTenThound(startLongititude));
	rec.startPos.latitude = htonl(MinuteToTenThound(startLatitude));
	rec.startPos.altitude = htons(startAltitude);
	rec.endPos.longititude = htonl(MinuteToTenThound(endLogititude));
	rec.endPos.latitude = htonl(MinuteToTenThound(endLatitude));
	rec.endPos.altitude = htons(endAltitude);

	buf.append((const char*)&rec,sizeof(rec));
	return buf;
}
