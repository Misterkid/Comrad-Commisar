#pragma once
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
ref class SocketData
{
	public:
		SocketData();
		Socket^ socket;
};

