#include "USBDataFilev2012.h"
#include <stdio.h>
#include <string>
#include "TraceLog.h"
using namespace std;
int main(int argc,const char** argv)
{
	SETTRACELEVEL(0);
	USBDataFilev2012 file;
	string fn,fn2 ;
	fn = argv[1];
	string::size_type pos=fn.rfind("/");
	if (pos != string::npos)
	{
		fn2 = fn.substr(pos+1);
	}
	printf("Datafile %s\n",fn.c_str());
	printf("parse file name %s %s\n",fn2.c_str(),file.ParseFileName(fn2)?"OK":"Fail");
	printf("read file %s %s\n",fn.c_str(),file.ReadFromFile(fn.c_str())?"OK":"Fail");
}
