/*
 * VTDRRecord.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: mxx
 */

#include "VTDRRecord.h"

VTDRRecord::VTDRRecord()
{
	// TODO Auto-generated constructor stub

}

VTDRRecord::~VTDRRecord()
{
	// TODO Auto-generated destructor stub
}

string VTDRRecord::BCD2ASCII(string& strBCD)
{
	string str;
	for (int i = 0; i < strBCD.size(); i++)
	{
		str += ((strBCD[i] & 0xF0) >> 4) + 0x30;
		str += ((strBCD[i] & 0x0F)) + 0x30;
	}
	return str;
}


