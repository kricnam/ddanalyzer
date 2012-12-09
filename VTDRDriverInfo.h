/*
 * VTDRDriverInfo.h
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#ifndef VTDRDRIVERINFO_H_
#define VTDRDRIVERINFO_H_
#include <string>
using namespace std;
class VTDRDriverInfo
{
public:
	VTDRDriverInfo();
	virtual ~VTDRDriverInfo();
	string& LicenceNumber(void);
};

#endif /* VTDRDRIVERINFO_H_ */
