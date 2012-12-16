/*
 * VTDRPositionRecord.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */
#include <arpa/inet.h>
#include "VTDRPositionRecord.h"

VTDRPositionRecord::VTDRPositionRecord() :
		tStart(0)
{
	// TODO Auto-generated constructor stub

}

VTDRPositionRecord::~VTDRPositionRecord()
{
	// TODO Auto-generated destructor stub
}

int VTDRPositionRecord::Read(const char* buf)
{
	PositionRecord* ptrRec = (PositionRecord*) buf;
	tStart = ToSystime(ptrRec->vStart);
	for (int i = 0; i < 60; i++)
	{
		Longititude[i] = ntohl(ptrRec->record[i].pos.longititude) / 10000;
		Latitude[i] = ntohl(ptrRec->record[i].pos.latitude) / 10000;
		Altitude[i] = ntohs(ptrRec->record[i].pos.altitude);
		Speed[i] = ptrRec->record[i].speed;
	}
	return sizeof(*ptrRec);
}

string& VTDRPositionRecord::Write(string& buf)
{
	PositionRecord rec =
	{ 0xFF };

	ToBCDTime(tStart,rec.vStart);
	for (int i = 0; i < 60; i++)
	{
		rec.record[i].pos.longititude = htonl((int)(Longititude[i] * 10000));
		rec.record[i].pos.latitude = htonl((int)(Latitude[i]*10000));
		rec.record[i].pos.altitude = htonl(Altitude[i]);
		rec.record[i].speed = (unsigned char)(Speed[i] & 0x0FF);
	}
	buf.append((const char*)&rec,sizeof(rec));
	return buf;
}
