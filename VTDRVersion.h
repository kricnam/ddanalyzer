/*
 * VTDRVersion.h
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#ifndef VTDRVERSION_H_
#define VTDRVERSION_H_
#include <string>
using namespace std;
class VTDRVersion
{
public:
	VTDRVersion();
	virtual ~VTDRVersion();
	int Read(const char* buf);
	string& Write(string& buf);
	int year;
	int modify;
protected:
	typedef struct _Version
	{
		unsigned char cYear;
		unsigned char cModi;
	}__attribute__ ((packed)) VERSION;
};

#endif /* VTDRVERSION_H_ */
