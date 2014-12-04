#include "stdafx.h"
#include "Client.h"


/*
void Client::BeginRecieveCallBack(IAsyncResult^ ar)
{
	try
	{
		Socket^ clientSocket = dynamic_cast<Socket^>(ar->AsyncState);
		clientSocket->EndReceive(ar);
		array<Byte>^ recBuffer = gcnew array<Byte>(1024);
		//printf_s("?");
		
		int recCount = clientSocket->Receive(recBuffer);
		
		if (recCount <= recBuffer->Length)
		{
			Array::Resize(recBuffer, recCount);
		}
		String^ test = System::Text::Encoding::ASCII->GetString(recBuffer);
		array<Byte>^ buffer = gcnew array<Byte>(1024);
		printf_s("%s \n",test);
		if (test == "test")
		{
			clientSocket->Send(System::Text::Encoding::ASCII->GetBytes("Hello World"));
			printf_s("Repsonding \n");
		}
		if (test == "close")
		{
			clientSocket->Send(System::Text::Encoding::ASCII->GetBytes("Bye"));
			//Close(clientSocket);
			clientSocket->Close();
			printf_s("Removing Client \n");
			return;
		}
		clientSocket->BeginReceive(buffer, 0, 0, SocketFlags::None, gcnew AsyncCallback(Client::BeginRecieveCallBack), clientSocket);
	}
	catch (...)
	{
		QException::Exception("Failed to receive", QException::QWARNING);
	}
}
*/

void Client::Close()
{
//	GameServer::getInstance().RemoveClient(*this);
	socket->Close();
}

Client::Client(Socket^ clientSocket)
{
	try
	{
		array<Byte>^ buffer  = gcnew array<Byte>(1024);
		//clientSocket->BeginReceive(buffer, 0, buffer->Length, SocketFlags::None, gcnew AsyncCallback(BeginRecieveCallBack), clientSocket);
		//socket = *clientSocket;
		socket = clientSocket;
		clientSocket->BeginReceive(buffer, 0, buffer->Length, SocketFlags::None, gcnew AsyncCallback(ClientReceiver::BeginRecieveCallBack),clientSocket);
	}
	catch (...)
	{
		QException::Exception("Failed to begin receive", QException::QWARNING);
		//printf_s("FAIL \n");
	}
}


Client::~Client()
{
	
}
