#include "stdafx.h"
#include "GameServer.h"



GameServer::GameServer(int _maxConnections)
{
	maxConnections = _maxConnections;
	printf_s("Server started max connections: %d \n", maxConnections);
	StartServer(1337);
}

//Destructor
GameServer::~GameServer()
{

}
void BeginAcceptCallback(IAsyncResult^ ar)
{
	try
	{
		Socket^ sSocket = dynamic_cast<Socket^>(ar->AsyncState);
		printf_s("Socket: %s", sSocket);//Null but why
		Socket^ clientSocket = sSocket->EndAccept(ar);
		sSocket->BeginAccept(gcnew AsyncCallback(BeginAcceptCallback), nullptr);
		printf_s("IP: %s", clientSocket->RemoteEndPoint);
	}
	catch (Exception^ ex)
	{
		//printf_s(ex.Message);
		QException::Exception("Error accepting connection", QException::QWARNING);
	}
}
bool GameServer::StartServer(int port)
{
	try
	{
		Socket^ sSocket = nullptr;
		sSocket = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
		//TcpListener^ listener = nullptr;
		IPHostEntry^ ipHostInfo = Dns::GetHostEntry(Dns::GetHostName());
		//IPAddress^ ipAddress = ipHostInfo->AddressList[0];
		//printf_s("IPAddr: %s \n", ipAddress->ToString());
		sSocket->Bind(gcnew IPEndPoint((__int64)0, port));
		//sSocket->Bind(gcnew IPEndPoint(ipAddress, port);
		//printf_s("IPAddr: %s \n", ipAddress->ToString());
		/*Hey !*/sSocket->Listen(0);//!
		sSocket->BeginAccept(gcnew AsyncCallback(BeginAcceptCallback), nullptr);
		return true;
	}
	catch (Exception^ ex)
	{
		//QException::Exception("Unable to start server!", QException::QCRITICAL);
		//msclr::interop::marshal_as
		//System::Runtime::InteropServices::Marshal::StringToCoTaskMemUni(ex->Message);
		//string message = msclr::interop::marshal_as<string>(ex->Message);
		//msclr::interop::marshal_as< std::string >(xyz);
		//QException::Exception(message, QException::QWARNING);
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