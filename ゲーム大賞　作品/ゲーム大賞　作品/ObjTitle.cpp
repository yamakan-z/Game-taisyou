//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include "GameL/UserData.h"

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
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMainT());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
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