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
	static unsigned int BCD2INT(const char* bcd, int size);
	static char INT2BCDchar(int n);
	template <class V> void assign(string t,V v) { t.assign((const char*)v,sizeof(v));};
	template <class V> void set(V v,string t) { memcpy(v,t.data(),min(t.size(),sizeof(v)));};
};

#endif /* VTDRRECORD_H_ */
