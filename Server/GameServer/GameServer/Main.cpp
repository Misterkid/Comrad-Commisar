#include "stdafx.h"
#include "Main.h"
using namespace std;
/*
Unlike c# CPP does not allow string to be in a switch.
https://stackoverflow.com/questions/650162/why-switch-statement-cannot-be-applied-on-strings
The solutions would only make the code longer..
*/
int _tmain(int argc, _TCHAR* argv[])
{
	printf_s("Welcome Comrad! Type in 'help' for the command list \n");
	GameServer * gameServer = NULL;
	string command = "";
	while (true)
	{
		std::cin >> command;
		if (command == "exit")
		{
			return 0;
		}
		else if (command == "test")
		{
			printf_s("Hello World\n");
		}
		else if (command == "start")
		{
			if (gameServer == NULL)
				gameServer = new GameServer(10);
			//GameServer* gameServer = new GameServer(10);
			printf_s("Starting Server...\n");
		}
		else if (command == "shutdown")
		{
			gameServer = NULL;
		}
	}
	return 0;
}
