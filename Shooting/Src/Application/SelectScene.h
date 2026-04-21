#pragma once
#include"State.h"


class C_SelectScene :public C_State
{
private:

	KdTexture mapTex;

public:
	C_SelectScene() {}
	~C_SelectScene() {}

	void UpDate()override;
	void Draw()override;
	void Init()override;
	void Release()override;
};