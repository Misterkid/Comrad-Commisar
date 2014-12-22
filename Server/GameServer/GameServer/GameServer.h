#pragma once
#include "Client.h"
//#include <windows.networking.sockets.h>
#include <string>
#include "QException.h"
//#include <vector>
#include <list>
//#include <Windows.h>
#using <System.dll>
using namespace System;
using namespace System::Net;
//using namespace System::Collections::Generic;
using namespace System::Net::Sockets;
//Gameserver class
class GameServer
{
	//https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
	public:
		static GameServer& getInstance()
		{
			static GameServer instance;
			return instance;
		}
		//GameServer(int);//Constructor
		//~GameServer();//Destructor.
		bool StartServer(int);//Start the server. Return false if failed.

		Client GetClientBySocket(Socket^);

		void AddClient(Client);
		void RemoveClient(Client);
		//List<Client> clients;
	private:
		GameServer(); //Constructor
		static void BeginAcceptCallback(IAsyncResult^);
		//vector<Client> clients;
		//vector<Client> clients;
		list<Client> clients;
		int maxConnections;//ammount of clients that can connect
		int connections;//Ammount of clients that are connected
		bool AliveCheck();
		void SpawnNPCS();
		GameServer(GameServer const&);
		void operator = (GameServer const&);
};