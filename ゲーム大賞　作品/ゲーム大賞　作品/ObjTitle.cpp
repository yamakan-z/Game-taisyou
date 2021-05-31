//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include "GameL/UserData.h"
#include "GameL\Audio.h"
#include <thread>
#include <chrono>


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;

	((UserData*)Save::GetData())->stage2 = false;
	((UserData*)Save::GetData())->stage3 = false;
	((UserData*)Save::GetData())->stageT = false;
}


//アクション
void CObjTitle::Action()
{
	//エンターキーを押してシーン：ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			//開始時ＳＥ
			Audio::Start(1);
			std::this_thread::sleep_for(std::chrono::seconds(2)); //開始時処理を2秒止める(開始SEを鳴らすため）
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	//スペースキーを押してシーン：チュートリアルステージに移行する
	if (Input::GetVKey(VK_SPACE) == true)
	{
		if (((UserData*)Save::GetData())->key_flagT == true)
		{
			//開始時ＳＥ
			Audio::Start(1);
			std::this_thread::sleep_for(std::chrono::seconds(2)); //開始時処理を2秒止める(開始SEを鳴らすため）
			Scene::SetScene(new CSceneMainT());
			((UserData*)Save::GetData())->key_flagT = false;
		}
	}
	else
	{
		((UserData*)Save::GetData())->key_flagT = true;
	}

}
//ドロー
void CObjTitle::Draw()
{
	//float c[4] = { 1.0f,-1.0f,-1.0f,1.0f };
	////float r[4] = { -1.0f,1.0f,-1.0f,4.0f };
	//Font::StrDraw(L"考え中", 325, 220, 56, c);
	//
	//Font::StrDraw(L"GameStart:EnterKey",220, 400, 44, c);
}