#include "stdafx.h"
#include "GameServer.h"

GameServer::GameServer(int _maxConnections)
{
	maxConnections = _maxConnections;
	printf_s("Server started max connections: %d", maxConnections);
	StartServer("127.0.0.1", 60);
}

//Destructor
GameServer::~GameServer()
{

}
bool GameServer::StartServer(String^ ip, int port)
{
	try
	{
		Socket^ socket = nullptr;
		IPHostEntry^ hostEntry = nullptr;
		IPAddress^ ipAddr = nullptr;
		IPEndPoint^ endPoint = nullptr;
		return true;
	}
	catch (...)//(Exception^ ex)
	{
		QException::Exception("Unable to start server!", QException::QCRITICAL);
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