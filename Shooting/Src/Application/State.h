#pragma once
class C_State
{
public:

	C_State() {}
	~C_State() {}

	virtual void UpDate() = 0;	//ƒˆ‰¼‘zŠÖ”
	virtual void Draw() = 0;	//ƒˆ‰¼‘zŠÖ”
	virtual void Init() = 0;
	virtual void Release() = 0;

};