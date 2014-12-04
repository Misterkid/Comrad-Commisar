#include "stdafx.h"
#include "GameServer.h"

GameServer::GameServer()
{
	//maxConnections = _maxConnections;
	//clients = new vector<Client>();
	//printf_s("Server started max connections: %d \n", maxConnections);
	//StartServer(1337);
	//clients = gcnew list<Client>();
	maxConnections = 10;
	clients = *new list<Client>;
}
//Destructor
/*
GameServer::~GameServer()
{

}*/
void GameServer::BeginAcceptCallback(IAsyncResult^ ar)
{
	try
	{
		Socket^ sSocket = dynamic_cast<Socket^>(ar->AsyncState);
		Socket^ clientSocket = sSocket->EndAccept(ar);
		//BeginAcceptCallback
		
		sSocket->BeginAccept(gcnew AsyncCallback(GameServer::getInstance().BeginAcceptCallback), sSocket);
		printf_s("IP: %d \n", clientSocket->RemoteEndPoint);
		Client* client = new Client(clientSocket);
		GameServer::getInstance().AddClient(*client);
	}
	catch (Exception^ ex)
	{
		//printf_s(ex.Message);
		QException::Exception("Error accepting connection", QException::QWARNING);
	}
}
bool GameServer::StartServer(int port)
{
	printf_s("Server started max connections: %d \n", maxConnections);
	try
	{
		Socket^ sSocket = nullptr;
		sSocket = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
		IPHostEntry^ ipHostInfo = Dns::GetHostEntry(Dns::GetHostName());
		sSocket->Bind(gcnew IPEndPoint((__int64)0, port));
		/*Hey !*/sSocket->Listen(0);//!
		sSocket->BeginAccept(gcnew AsyncCallback(this->BeginAcceptCallback), sSocket);
		return true;
	}
	catch (Exception^ ex)
	{
		QException::Exception("Cannot bind!", QException::QWARNING);
		return false;
	}
}

bool GameServer::AliveCheck()
{
	return false;
}
void GameServer::SpawnNPCS()
{

}
/*
Client GameServer::GetClientBySocket(Socket^ socket)
{

	for each (Client client in clients)
	{
		if (socket->Handle == client.socket->Handle )
		{
			return client;
		}
	}

}*/
void GameServer::AddClient(Client client)
{
	clients.push_back(client);
}
void GameServer::RemoveClient(Client client)
{
	//clients.remove(client);
}