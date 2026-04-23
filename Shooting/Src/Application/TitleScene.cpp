#include "TitleScene.h"
#include"SceneManeger.h"
#include"SelectScene.h"

void C_TitleScene::Init()
{
	
}


void C_TitleScene::UpDate()
{

	if (GetAsyncKeyState('Q') & 0x8000)
	{
		SCENEMANAGER.ChangeState(new C_SelectScene());
		SCENEMANAGER.Init();
		return;
	}
}

void C_TitleScene::Draw()
{

	SHADER.m_spriteShader.DrawString(0, 0, "Hello World", Math::Vector4(1, 1, 0, 1));

}


void C_TitleScene::Release()
{

}
