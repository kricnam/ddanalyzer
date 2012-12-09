/*
 * USBDataFilev2012.h
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#ifndef USBDATAFILEV2012_H_
#define USBDATAFILEV2012_H_

#include <string>

using namespace std;

namespace DataCenter
{

class USBDataFilev2012
{
public:
	USBDataFilev2012();
	virtual ~USBDataFilev2012();

	bool ParseFileName(string& strFileName);
	bool CheckSumOk(void);
protected:

	typedef struct _USBDataBlock
	{
		unsigned char cDataCode;
		unsigned char cDataName[18];
		unsigned int nDataLength;
	} USBDataBlock;

	unsigned short nDataBlockNumber;

};

} /* namespace DataCenter */
#endif /* USBDATAFILEV2012_H_ */
