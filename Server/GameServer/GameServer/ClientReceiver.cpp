#include "stdafx.h"
#include "ClientReceiver.h"


ClientReceiver::ClientReceiver()
{

}
void ClientReceiver::BeginRecieveCallBack(IAsyncResult ^ar)
{
	try
	{
		Socket^ clientSocket = dynamic_cast<Socket^>(ar->AsyncState);
		clientSocket->EndReceive(ar);
		array<Byte>^ recBuffer = gcnew array<Byte>(1024);

		int recCount = clientSocket->Receive(recBuffer);

		if (recCount <= recBuffer->Length)
		{
			Array::Resize(recBuffer, recCount);
		}
		String^ test = System::Text::Encoding::ASCII->GetString(recBuffer);
		array<Byte>^ buffer = gcnew array<Byte>(1024);
		printf_s("%s \n", test);
		if (test == "test")
		{
			clientSocket->Send(System::Text::Encoding::ASCII->GetBytes("Hello World"));
			printf_s("Repsonding \n");
		}
		else if (test == "close")
		{
			clientSocket->Send(System::Text::Encoding::ASCII->GetBytes("Bye"));
			clientSocket->Close();
			return;
		}
		else
		{
			//clientSocket->Close();
		}
		clientSocket->BeginReceive(buffer, 0, 0, SocketFlags::None, gcnew AsyncCallback(ClientReceiver::BeginRecieveCallBack), clientSocket);
	}
	catch (...)
	{
		QException::Exception("Failed to receive", QException::QWARNING);
	}

}
