#include "SelectScene.h"
#include"SceneManeger.h"
#include"Stage_1Scene.h"

void C_SelectScene::Init()
{

}


void C_SelectScene::UpDate()
{

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{



		SCENEMANAGER.ChangeState(new C_Stage_1Scene());
		SCENEMANAGER.Init();
		return;
	}
}

void C_SelectScene::Draw()
{


}


void C_SelectScene::Release()
{

}
