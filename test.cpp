#include "USBDataFilev2012.h"
#include <stdio.h>
#include <string>
#include "TraceLog.h"
using namespace std;
int main(int argc,const char** argv)
{
	SETTRACELEVEL(0);
	USBDataFilev2012 file;
	file.WriteToFile("./");
	string& filename = file.GenerateFileName();
	string fn = "./";
	fn += filename;
	printf("read file %s %s\n",fn.c_str(),file.ReadFromFile(fn.c_str())?"OK":"Fail");
}
