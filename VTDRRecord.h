/*
 * VTDRRecord.h
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#ifndef VTDRRECORD_H_
#define VTDRRECORD_H_
#include <string>
using namespace std;
class VTDRRecord
{
public:
	VTDRRecord();
	virtual ~VTDRRecord();
	static string BCD2ASCII(string& strBCD);

};

#endif /* VTDRRECORD_H_ */
