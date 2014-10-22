#pragma once
#include "PackageHandler.h"
class Client
{
	public:
		Client();
		~Client();
		int id;
		void Connect();
		void Send(String^);
		void Close();
	private:
		PackageHandler packageHandler;


};

