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
using namespace std;

#define SET(x,y) set(x,y,sizeof(x))
#define ASSIGN(x,y) assign(x,y,sizeof(y))

class VTDRRecord
{
public:
	VTDRRecord();
	virtual ~VTDRRecord();
	static string BCD2ASCII(string& strBCD);
	static unsigned int BCD2INT(const char* bcd, int size);
	static char INT2BCDchar(int n);
	template<class V> void assign(string& t, V v, int n)
	{
		t.assign((const char*) v, n);
		printf("%s,%d\n",v,n);
	}
	;
	template<class V> void set(V v, string& t, int n)
	{
		memcpy(v, t.data(), min((int)t.size(),n));
	}
	;
};

#endif /* VTDRRECORD_H_ */
