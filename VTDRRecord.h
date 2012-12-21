/*
 * VTDRRecord.h
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#ifndef VTDRRECORD_H_
#define VTDRRECORD_H_
#include <string>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <arpa/inet.h>
using namespace std;

#define SET(x,y) set(x,y,sizeof(x))
#define ASSIGN(x,y) assign(x,y,sizeof(y))



class VTDRRecord
{
public:
	enum DataCode
	{
		Version = 0,
		CurrentDriver,
		RealTime,
		OderMeter,
		PulseModulu,
		VehicleInfo,
		StateConfig,
		UniqCode,
		SpeedRecord,
		PositionRecord,
		AccidentSuspectPoint = 0x10,
		OverTimeDriving,
		DriverInfo,
		OutPowered,
		ParameterModify,
		SpeedStateLog
	};

	VTDRRecord();
	virtual ~VTDRRecord();
	unsigned char GetDataCode()
	{
		return (unsigned char)cDataCode;
	}
	;

	typedef struct _VTDRTime
	{
		unsigned char bcdYear;
		unsigned char bcdMonth;
		unsigned char bcdDay;
		unsigned char bcdHour;
		unsigned char bcdMinute;
		unsigned char bcdSecond;
	}__attribute__ ((packed)) VTDRTime;

	virtual int Read(const char* buf)=0;
	virtual string& Write(string& buf)=0;
	static string BCD2ASCII(string& strBCD);
	static unsigned int BCD2INT(const char* bcd, int size);
	static unsigned int BCD2INT(unsigned char bcd);
	static char INT2BCDchar(int n);
	static time_t ToSystime(VTDRTime& t);
	static VTDRTime& ToBCDTime(time_t t, VTDRTime& tm);
	static float TenThoundthMinuteToMinute(int n)
	{
		return n / 10000.0;
	}
	;
	static int MinuteToTenThound(float n)
	{
		return (int) (n * 10000);
	}
	;
	template<class V> void assign(string& t, V v, int n)
	{
		t.assign((const char*) v, n);
	}
	;
	template<class V> void set(V v, string& t, int n)
	{
		memcpy(v, t.data(), min((int) t.size(), n));
	}
	;
protected:

	typedef struct _Position
	{
		int longititude;
		int latitude;
		short altitude;
	}__attribute__ ((packed)) Position;



	void readPosition(Position& pos, float& Long, float& Lat, int& Alt)
	{
		Long = ntohl(pos.longititude) / 10000.0;
		Lat = ntohl(pos.latitude) / 10000.0;
		Alt = ntohs(pos.altitude);
	}
	;
	void writePosition(Position& pos, float Long, float Lat, int Alt)
	{
		pos.longititude = htonl((int) (Long * 10000.0));
		pos.latitude = htonl((int) (Lat * 10000.0));
		pos.altitude = htons(Alt);
	}
	;
	DataCode cDataCode;
};

#endif /* VTDRRECORD_H_ */
