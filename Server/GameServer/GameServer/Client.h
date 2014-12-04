#pragma once
#include "PackageHandler.h"
#include <string>
#include "QException.h"
#include "ClientReceiver.h"
//#include "GameServer.h"
//#include "GameServer.h"
//TEst
#include <vcclr.h>

#using <System.dll>
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace std;

class Client
{
	public:
		Client(Socket^ socket);
		~Client();
		int id;
		string *name;
		void Connect();
		void Send(String^);
		void Close();
		gcroot<Socket^> socket;
	private:
		//Socket^ socket;
		PackageHandler packageHandler;
		static void BeginRecieveCallBack(IAsyncResult^);
};

