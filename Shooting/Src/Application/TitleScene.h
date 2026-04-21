#pragma once
#include"State.h"

class C_TitleScene :public C_State
{
private:

	KdTexture mapTex;

public:
	C_TitleScene() {}
	~C_TitleScene() {}

	void UpDate()override;
	void Draw()override;
	void Init()override;
	void Release()override;
};