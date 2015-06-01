class CInterfaces
{
public:
	CEngine *Engine;
	CClient *Client;
	CInput *Input;
	CClientEntityList *ClientEntList;
	CModelInfo *ModelInfo;
	CPanel* Panel;
	CSurface* Surface;
	CTrace* Trace;
	void GetInterfaces()
	{
		Engine = (CEngine*)GetPointer("engine.dll", "VEngineClient");
		Trace = (CTrace*)GetPointer("engine.dll", "EngineTraceClient");
		Client = (CClient*)GetPointer("client.dll", "VClient");
		ClientEntList = (CClientEntityList*)GetPointer("client.dll", "VClientEntityList");
		ModelInfo = (CModelInfo*)GetPointer("engine.dll","VModelInfoClient");
		if (!ModelInfo)
			::MessageBox(0, "Broke", 0, 0);
		Panel = (CPanel*)GetPointer("vgui2.dll","VGUI_Panel");
		Surface = (CSurface*)GetPointer("vguimatsurface", "VGUI_Surface");
		Input = **(CInput***)((*(DWORD**)Client)[14] + 0x2);
	}

	void* GetPointer(const char* Module, const char* InterfaceName)
	{
		void* Interface = NULL;
		char PossibleInterfaceName[1024];

		CreateInterfaceFn CreateInterface = (CreateInterfaceFn)GetProcAddress(GetModuleHandleA(Module), "CreateInterface");
		for (int i = 1; i < 100; i++)
		{
			sprintf(PossibleInterfaceName, "%s0%i", InterfaceName, i);
			Interface = (void*)CreateInterface(PossibleInterfaceName, NULL);
			if (Interface != NULL)
			{
				std::cout << PossibleInterfaceName << " Found: " << hex << (DWORD)Interface << endl;
				break;
			}
			sprintf(PossibleInterfaceName, "%s00%i", InterfaceName, i);
			Interface = (void*)CreateInterface(PossibleInterfaceName, NULL);
			if (Interface != NULL)
			{
				std::cout << PossibleInterfaceName << " Found: " << hex << (DWORD)Interface << endl;
				break;
			}
		}

		return Interface;
	}
}; CInterfaces Interfaces;