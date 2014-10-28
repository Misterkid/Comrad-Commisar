#pragma once
#include <time.h>
#include <iostream>
#include <string>
using namespace std;
//#include <windows.h>
class QException
{
	public:
		//QException();
		static enum MSGTYPE
		{
			QCRITICAL,
			QERROR,
			QDEBUG,
			QWARNING
		};
		static void Exception(string, MSGTYPE);

};

