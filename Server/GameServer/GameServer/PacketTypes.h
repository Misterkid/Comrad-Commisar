#pragma once
//#include <regex>
#include <vector>
class PacketTypes
{
	public:
		PacketTypes();
		static PacketTypes& getInstance()
		{
			static PacketTypes instance;
			return instance;
		}

		enum Types
		{
			Test,
			Ping,
			Login,
			Load,
			Close,
			CmdMax,//Always last !
			CmdError
		};
		//string packetList[Types::CmdMax];
		string header = "€";
		string spliter = "`";
		string packetList[Types::CmdMax];
		string MakePacket(Types type, string data);
		string* DestructPacket(string data);
	private:
		PacketTypes(PacketTypes const&);
		void operator = (PacketTypes const&);

};


