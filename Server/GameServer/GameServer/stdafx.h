// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
//Defines
//QEXCEPTION how do we log in this build?
#define __QEXCEPTION_CONSOLE
#define __QEXCEPTION_FILE
//#define __QEXCEPTION_NETWORK
//#define __QEXCEPTION_DEBUG
//#define __QEXCEPTION_MSGBOX
#define _CRT_SECURE_NO_WARNINGS//Screw localtime_s
#include "targetver.h"
#include "GameServer.h"
#using <System.dll>
using namespace System;
#include <stdio.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here
