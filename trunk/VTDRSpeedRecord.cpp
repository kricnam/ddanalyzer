/*
 * VTDRSpeedRecord.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#include "VTDRSpeedRecord.h"

VTDRSpeedRecord::VTDRSpeedRecord() :
		tStart(0)
{
	Speed[60]=
	{	0xFF};
	State[60]=
	{	0};
	cDataCode = VTDRRecord::SpeedRecord;
}

VTDRSpeedRecord::~VTDRSpeedRecord()
{

}

int VTDRSpeedRecord::Read(const char* buf)
{
	SpeedRecord* ptrRec = (SpeedRecord*) buf;
	tStart = ToSystime(ptrRec->startTime);
	for (int i = 0; i < 60; i++)
	{
		Speed[i] = ptrRec->record[i].speed;
		State[i] = ptrRec->record[i].state;
	}
	return sizeof(*ptrRec);
}

string& VTDRSpeedRecord::Write(string& buf)
{
	SpeedRecord rec =
	{ 0 };
	ToBCDTime(tStart, rec.startTime);
	for (int i = 0; i < 60; i++)
	{
		rec.record[i].speed = Speed[i];
		rec.record[i].state = State[i];
	}
	buf.append((const char*) &rec, sizeof(rec));
	return buf;
}
