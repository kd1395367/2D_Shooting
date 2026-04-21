#include "Stage_1Scene.h"

void C_Stage_1Scene::UpDate()
{
	mybullet.UpDate();
}

void C_Stage_1Scene::Draw()
{
	mybullet.Draw();
}

void C_Stage_1Scene::Init()
{
	mybullet.Init();
}

void C_Stage_1Scene::Release()
{
	mybullet.Release();
}
