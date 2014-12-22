#pragma once
#using <System.dll>
#include <string>
#include "QException.h"
#include "Client.h"
#include "PacketTypes.h"
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

class ClientReceiver
{
	public:
		ClientReceiver();
		static void BeginRecieveCallBack(IAsyncResult^);
	private:
		//string commandList[packetNames::CmdMax] = { "exit", "start", "test", "shutdown", "help" };
};

