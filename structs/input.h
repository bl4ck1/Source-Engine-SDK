class CInput
{
public:
	void *GetUserCmd(int sqnum)
	{
		typedef void*(__thiscall* Fn)(void*, int);
		return ((Fn)VMT.GetFunction(this, 8))(this, sqnum);
	}
};