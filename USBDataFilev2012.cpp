/*
 * USBDataFilev2012.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#include "USBDataFilev2012.h"
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
map<int, string> USBDataFilev2012::DataBlockName;

USBDataFilev2012::USBDataFilev2012() :
		tRecordTime(0), nDataBlockNumber(0)
{
	strPlateCode = "未知车牌";
	initMap();
	PushData(new VTDRVersion());
}

USBDataFilev2012::~USBDataFilev2012()
{
	if (!Datas.empty())
	{
		map<int, DataSet>::iterator it;
		for (it = Datas.begin(); it != Datas.end(); it++)
		{
			DataSet::iterator dit;
			for (dit = it->second.begin(); dit != it->second.end(); dit++)
			{
				delete (*dit);
			}
			it->second.clear();
		}
	}
}

void USBDataFilev2012::PushData(VTDRRecord* ptrRecord)
{
	VTDRRecord::DataCode code = (VTDRRecord::DataCode) ptrRecord->GetDataCode();
	if (Datas.count(code))
	{
		if (code < VTDRRecord::SpeedRecord)
		{
			delete Datas[code].front();
			Datas[code].clear();
			Datas[code].push_back(ptrRecord);
		}
		else
			Datas[ptrRecord->GetDataCode()].push_back(ptrRecord);
	}
	else
	{
		nDataBlockNumber++;
		DataSet records;
		records.push_back(ptrRecord);
		Datas[ptrRecord->GetDataCode()] = records;
	}
}

void USBDataFilev2012::WriteToFile(const char* szFolder)
{
	string buf;
	unsigned short blocks = htons(nDataBlockNumber);
	buf.append((const char*) &blocks, sizeof(blocks));
	map<int, DataSet>::iterator it;
	for (it = Datas.begin(); it != Datas.end(); it++)
	{
		if (it->second.empty())
			continue;
		DataSet::iterator data_set;
		USBDataBlock block =
		{ 0 };
		block.cDataCode = it->second.front()->GetDataCode();
		it->second.front()->set(block.cDataName, DataBlockName[block.cDataCode],
				sizeof(block.cDataName));
		string strBlock;
		for (data_set = it->second.begin(); data_set != it->second.end();
				data_set++)
		{
			(*data_set)->Write(strBlock);
		}
		block.nDataLength = htonl(strBlock.size());
		buf.append((const char*) &block, sizeof(block));
		buf.append(strBlock);
	}

	generateFileName();
	FILE* fp = fopen(strFileName.c_str(), "wb");
	if (fp)
	{
		int n = fwrite((void*) buf.data(), 1, buf.size(), fp);
		fclose(fp);
	}
}

void USBDataFilev2012::generateFileName()
{
	struct tm tmTime;
	tRecordTime = (tRecordTime)?tRecordTime:time(NULL);
	localtime_r(&tRecordTime, &tmTime);
	char buf[64] =
	{ 0 };
	sprintf(buf, "D%02u%02u%02u_%02u%02u_%s.VDR", tmTime.tm_year + 1900 - 2000,
			tmTime.tm_mon + 1, tmTime.tm_mday, tmTime.tm_hour, tmTime.tm_min,
			strPlateCode.c_str());
	strFileName = buf;
}

void USBDataFilev2012::initMap()
{
	if (DataBlockName.empty())
	{
		DataBlockName[0] = "执行标准版本年号";
		DataBlockName[1] = "当前驾驶人信息";
		DataBlockName[2] = "实时时间";
		DataBlockName[3] = "累计行驶里程";
		DataBlockName[4] = "脉冲系数";
		DataBlockName[5] = "车辆信息";
		DataBlockName[6] = "状态信号配置信息";
		DataBlockName[7] = "记录仪唯一性编号";
		DataBlockName[8] = "行驶速度记录";
		DataBlockName[9] = "位置信息记录";
		DataBlockName[0x10] = "事故疑点记录";
		DataBlockName[0x11] = "超时驾驶记录";
		DataBlockName[0x12] = "驾驶人身份记录";
		DataBlockName[0x13] = "外部供电记录";
		DataBlockName[0x14] = "参数修改记录";
		DataBlockName[0x15] = "速度状态日志";
	}
}

bool USBDataFilev2012::ParseFileName(string& strFileName)
{
}

bool USBDataFilev2012::CheckSumOk(void)
{
}

