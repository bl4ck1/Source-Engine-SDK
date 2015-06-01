# Source-Engine-SDK
Set it up like this

    //TF2 Indexes
    void SetupIndexes()
    {
    	using namespace indexes;
    	//todo: add multigame check
    	//Engine
    	GetScreenSize = 5;
    	GetPlayerInfo = 8;
    	GetLocalPlayer = 12;
    	ClientCmd = 102;
    	SetViewAngles = 20;
    	GetViewAngles = 19;
    	WorldToScreenMatrix = 36;
    
    	//ClientEntList
    	GetClientEntity = 3;
    	GetHighestEntityIndex = 8;
    	GetClientEntityFromHandle = 7;
    
    	//Surface
    	SetDrawColor = 11;
    	DrawFilledRect = 12;
    	DrawOutlinedRect = 14;
    	DrawLine = 15;
    	SCreateFont = 66;
    	SetFontGlyphSet = 67;	
    	DrawSetTextFont = 17;
    	DrawSetTextColor = 19;
    	DrawSetTextPos = 20;
    	DrawPrintText = 22;
    
    	//ModelInfo
    	GetStudioModel = 28;
    }
