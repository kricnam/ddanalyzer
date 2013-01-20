/*
 * USBDataFilev2012.h
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#ifndef USBDATAFILEV2012_H_
#define USBDATAFILEV2012_H_
#include <string>
#include <list>
#include <map>
#include "VTDRRecord.h"
#include "VTDRVersion.h"
#include "VTDRDriverInfo.h"
#include "VTDRRealTime.h"
#include "VTDROderMeter.h"
#include "VTDRPulseModulus.h"
#include "VTDRVehicleInfo.h"
#include "VTDRVehicleConfigure.h"
#include "VTDRUniqCode.h"
#include "VTDRSpeedRecord.h"
#include "VTDRPositionRecord.h"
#include "VTDRDetailRecord.h"
#include "VTDROvertimeDriveRecord.h"
#include "VTDRDriverIDRecord.h"
#include "VTDROutPoweredRecord.h"
#include "VTDRParameterModifyRecord.h"
#include "VTDRSpeedStatusLog.h"
#include <exception>

using namespace std;

class USBDataFileException: public exception
{
public:
	USBDataFileException(const char* szType) throw()
	{
		strType = szType;
	}
	;
	~USBDataFileException() throw()
	{
	}
	;
	string strType;
};

class USBDataFilev2012
{
public:
	USBDataFilev2012();
	virtual ~USBDataFilev2012();

	bool ParseFileName(const char* szFileName);
	VTDRRecord* PushData(VTDRRecord* ptrRecord);
	void WriteToFile(const char* szFolder);
	bool ReadFromFile(const char* szFileName);
	string& GenerateFileName();
	static int utf8togb2312(const char *sourcebuf, size_t sourcelen,
			char *destbuf, size_t destlen);
	static int gb2312toutf8(const char *sourcebuf, size_t sourcelen,
			char *destbuf, size_t destlen);
protected:
	string strPlateCode;
	time_t tRecordTime;
	string strFileName;
	typedef struct _USBDataBlock
	{
		unsigned char cDataCode;
		unsigned char cDataName[18];
		unsigned int nDataLength;
	}__attribute__ ((packed)) USBDataBlock;

	unsigned short nDataBlockNumber;
	typedef list<VTDRRecord*> DataSet;
	map<int, DataSet> Datas;

	static map<int, string> DataBlockName;
	static void initMap();

	static char checkSum(string& str);
	bool parseFile(string& str);
	int readFileHead(string& str);
	int readBlock(string& str, int index);
	VTDRRecord* generateRecord(VTDRRecord::DataCode code);
};

#endif /* USBDATAFILEV2012_H_ */
