#pragma once
#include"State.h"
#include"Bullet.h"

class C_Stage_1Scene :public C_State
{
private:

	KdTexture mapTex;
	C_Bullet mybullet;

public:
	C_Stage_1Scene() {}
	~C_Stage_1Scene() {}

	void UpDate()override;
	void Draw()override;
	void Init()override;
	void Release()override;
};