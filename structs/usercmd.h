
class CUserCmd
{
public:
	char pad_0x0000[0x4]; //0x0000
	float command_number; //0x0004 
	float tick_count; //0x0008 
	Vector viewangles; //0x000C 
	float forwardmove; //0x0018 
	float sidemove; //0x001C 
	char pad_0x0020[0x4]; //0x0020
	int buttons; //0x0024 
	char pad_0x0028[0xC]; //0x0028
	int randomseed; //0x0034 
	__int16 mousedx; //0x0038 
	__int16 mousedy; //0x003A 
	char pad_0x003C[0x4]; //0x003C

};//Size=0x0040

/*
class CVerifiedUserCmd
{
public:
void* m_cmd; //0x0000
__int32 m_crc; //0x0004

};//Size=0x0008*/
class CVerifiedUserCmd
{
public:
	CUserCmd	m_cmd;
	unsigned long	m_crc;
};
