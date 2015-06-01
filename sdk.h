#include <stdio.h>
#include <vector>
#include <string>
#include <time.h>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <sstream>
#include <iostream>
#include <cstdio>

using namespace std;


#include "definitions.h"
#include "indexes.h"

#include "console.h"

#include "libraries\vmt.h"

#include "structs\angle.h"
#include "structs\vmatrix.h"
#include "structs\baseentity.h"
#include "structs\cliententlist.h"
#include "structs\usercmd.h"
#include "structs\playerinfo.h"
#include "structs\engine.h"
#include "structs\input.h"
#include "structs\panel.h"
#include "structs\surface.h"
#include "structs\client.h"
#include "structs\crc32.h"
#include "structs\quaternion.h"
#include "structs\modelinfo.h"
#include "structs\dt_common2.h"
#include "structs\dt_recv2.h"
#include "structs\trace.h"
#include "structs\checksum_md5.h"

#include "libraries\math.h"


#include "libraries\interfaces.h"

/*
	I like the idea of having the point of entry in the SDK itself, this way if we want to start a new cheat utilizing our SDK, all we have to do is create our
	"StartCheat" function and the SDK will take care of the boring tasks for you.
*/
void StartCheat();
BOOL WINAPI DllMain(HINSTANCE Instance, DWORD Reason, LPVOID Reserved)
{
	if (Reason == DLL_PROCESS_ATTACH)
	{
		Console.Initialize();
		Interfaces.GetInterfaces();
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)StartCheat, NULL, NULL, NULL);
	}
	return true;
}