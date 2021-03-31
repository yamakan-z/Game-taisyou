//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjGameClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameClear::Init()
{
	m_key_flag = false;//キーフラグ
}
//アクション
void CObjGameClear::Action()
{
	//エンターキーを押してシーン：ゲームTitleに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}
	else
	{
		m_key_flag = true;
	}
}
//ドロー
void CObjGameClear::Draw()
{
	float r[4] = { 0.5f,0.0f,0.0f,1.0f };

	Font::StrDraw(L"GAME CLEAR", 350, 250, 32, r);
}