#pragma once
#include"TitleScene.h"
#include"SelectScene.h"
class C_SceneManager
{
public:

	static C_SceneManager& GetInstance()	//参照返し　アドレスではなく参照を返す
	{
		static C_SceneManager instance;	//static→クラス外でインスタンスなしでも呼べる
		//static　がつくことで静的変数になるローカル変数でも値を保持したままずっと残る
		return instance;
	}

	void ChangeState(C_State* newState)
	{
		delete currentState;	//currentStateのメモリをきれいにしてから代入（しないとメモリリーク）
		currentState = newState;
	}

	void UpDate()
	{
		currentState->UpDate();
	}

	void Draw()
	{
		currentState->Draw();
	}

	void Init()
	{
		currentState->Init();
	}

	void Release()
	{
		currentState->Release();
	}

private:

	C_SceneManager() {}	//シングルトン　コンストラクタがprivate

	C_State* currentState = nullptr;

};

#define SCENEMANAGER C_SceneManager::GetInstance()