#include "stdafx.h"
#include "PacketTypes.h"


PacketTypes::PacketTypes()
{

	packetList[Types::Test] = "Test";
	packetList[Types::Ping] = "Ping";
	packetList[Types::Login] = "Login";
	packetList[Types::Load] = "Load";
	packetList[Types::Close] = "Close";

	//packetList = { "Test", "Ping", "Login", "Load", "Close" };
	//packetList[Types::CmdMax]{"Test", "Ping", "Login", "Load", "Close" };
	//packetList[Types::CmdMax] { "Test", "Ping", "Login", "Load", "Close" };
}
string PacketTypes::MakePacket(Types type, string data)
{
	string packet;
	//packet.append(header);
	//packet.append(spliter);

	packet = header + spliter +  packetList[type]  + spliter + data;
	return packet;
}
string* PacketTypes::DestructPacket(string data)
{
	string splited[3];
	string newData = data;
	int pos = 0;
	string token;
	int i = 0;
	while ((pos = newData.find(spliter)) != string::npos)
	{
		token = newData.substr(0, pos);
		//Do stuff
		splited[i] = token;
		newData.erase(0, pos + 1);
		//printf_s("%s \n", token.c_str());
		//printf("%d \n", i);
		i++;
	}

	/*
	std::string s = "scott>=tiger>=mushroom";
	std::string delimiter = ">=";

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		std::cout << token << std::endl;
		s.erase(0, pos + delimiter.length());
	}
	*/
	return splited;
}