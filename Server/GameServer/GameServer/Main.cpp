#include "stdafx.h"
#include "Main.h"
using namespace std;
/*
Unlike c# CPP does not allow string to be in a switch.
https://stackoverflow.com/questions/650162/why-switch-statement-cannot-be-applied-on-strings
The solutions would only make the code longer..
*/
void PrintTitle()
{
	printf_s("   #####                                     \n");
	printf_s("  #     #  ####  #    # #####    ##   #####  \n");
	printf_s("  #       #    # ##  ## #    #  #  #  #    # \n");
	printf_s("  #       #    # # ## # #    # #    # #    # \n");
	printf_s("  #       #    # #    # #####  ###### #    # \n");
	printf_s("  #     # #    # #    # #   #  #    # #    # \n");
	printf_s("   #####   ####  #    # #    # #    # #####  \n");
	printf_s("\n");
	printf_s("   ####   ####  #    # #    # #  ####   ####    ##   #####  \n");
	printf_s("  #    # #    # ##  ## ##  ## # #      #       #  #  #    # \n");
	printf_s("  #      #    # # ## # # ## # #  ####   ####  #    # #    # \n");
	printf_s("  #      #    # #    # #    # #      #      # ###### #####  \n");
	printf_s("  #    # #    # #    # #    # # #    # #    # #    # #   #  \n");
	printf_s("   ####   ####  #    # #    # #  ####   ####  #    # #    # \n");
	printf_s("*************************************************************\n");
}
enum commands
{
	CmdExit,
	CmdStart,
	CmdTest,
	CmdShutdown,
	CmdHelp,
	CmdMax,//Always last !
	CmdError
};

//Fill this in exactly like the enum commands.
string commandList[commands::CmdMax] = { "exit", "start", "test", "shutdown", "help" };

commands GotHit(string command)
{
	for (int i = 0; i < /*sizeof(commandList)*/commands::CmdMax; i++)
	{
		if (command == commandList[i])
			return static_cast<commands>(i);
	}
	return commands::CmdError;//Here?
}
int _tmain(int argc, _TCHAR* argv[])
{
	Console::Title = "Comrad Commissar Server";
	printf_s("Welcome Comrad! Type in 'help' for the command list \n");
	PrintTitle();

	GameServer * gameServer = NULL;
	string command = "";
	while (true)
	{
		std::cin >> command;

		switch (GotHit(command))
		{
			case commands::CmdExit:
				return 0;
				break;
			case commands::CmdShutdown:
				//gameServer = NULL;
				break;
			case commands::CmdStart:
				if (gameServer == NULL)
					GameServer::getInstance().StartServer(1337);
					//gameServer = new GameServer(10);
				printf_s("Starting Server...\n");
				break;
			case commands::CmdTest:
				printf_s("It works\n");
				//string packetTest = PacketTypes::getInstance().DestructPacket("Hello`test`")[1].c_str();
				//printf_s("%s", packetTest.c_str());
				break;
			case commands::CmdHelp:
				printf_s("*************************************************************\n");
				printf_s("To do a explaining every command here.\n");
				printf_s("'start' to start the server.\n");
				printf_s("'exit' to close the server.\n");
				printf_s("*************************************************************\n");
				break;
			case commands::CmdError:
				QException::Exception("Command {" + command + "} not found!", QException::MSGTYPE::QWARNING);
				break;
			default:
				QException::Exception("Command {" + command + "} not found? Wait how did you get here", QException::MSGTYPE::QWARNING);
				break;
		}
	}
	return 0;
}