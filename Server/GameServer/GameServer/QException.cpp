#include "stdafx.h"
#include "QException.h"
//We wont need this.
/*
QException::QException()
{

}*/
//The exception function!
void QException::Exception(string msg,QException::MSGTYPE msgType)
{
	string printMsg = "";
	switch (msgType)
	{
		case QException::QCRITICAL:
			printMsg = "Critical Error: " + msg + "\n";
			break;
		case QException::QERROR:
			printMsg = "Error: " + msg + "\n";
			break;
		case QException::QDEBUG:
			printMsg = "Debug: " + msg + "\n";
			break;
		case QException::QWARNING:
			printMsg = "Warning: " + msg + "\n";
			break;
		default:
			Exception("Exception type not found!", MSGTYPE::QCRITICAL);
			break;
	}

#ifdef __QEXCEPTION_CONSOLE
	switch (msgType)
	{
		case QException::QCRITICAL:
			throw printf_s(printMsg.c_str());
			break;
		case QException::QERROR:
			throw printf_s(printMsg.c_str());
			break;
		default:
			printf_s(printMsg.c_str());
			break;
	}
#endif
#ifdef __QEXCEPTION_FILE

	time_t rawTime = time(NULL);//... time?
	struct tm * currentTime = localtime(&rawTime);//Get current time
	char fileName[64];//Buffer
	strftime(fileName, 25, "Log_%d-%m-%Y.txt", currentTime);//File name

	FILE* file = fopen(fileName, "a");//Open file (Append) If not excist create file!
	//currentTime
	char timeText[128];//Buffer
	strftime(timeText, 25, "%H:%M:%S", currentTime);//Get current time in text

	fprintf_s(file, "%s  %s \n", timeText, printMsg.c_str());//Write to file
	fclose(file);//Close file.
#endif
#ifdef __QEXCEPTION_NETWORK

#endif
#ifdef __QEXCEPTION_DEBUG

#endif
#ifdef __QEXCEPTION_MSGBOX
	//MessageBoxExA(NULL, msg, "test", MB_OK, 0);
	//MessageBox(NULL, printMsg,L"DING!")
	//MessageBox()
#endif
}
