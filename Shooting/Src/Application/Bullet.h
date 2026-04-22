#pragma once

struct C_pos
{
	Math::Vector2 m_pos;
	Math::Vector2 m_scale;
	Math::Vector2 m_move;

	Math::Matrix m_scaleMat;
	Math::Matrix m_transMat;
	Math::Matrix m_Mat;

};

class C_Bullet
{
private:

	static const int Width = 640;
	static const int High = 360;

	static const int bulletNum=50;
	struct C_pos mybullet[bulletNum];

	KdTexture myBulletTex;

	bool startBulletFlg[bulletNum];	//íeÇî≠éÀÇ∑ÇÈÇ©ä«óù
	bool chargeBulletFlg[bulletNum];

	float shotTime;
	int bu;

public:

	void Init();
	void UpDate();
	void Alive();
	void Draw();
	void Release();

};