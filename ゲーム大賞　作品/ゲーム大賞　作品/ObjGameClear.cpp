//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjGameClear.h"
#include "GameL/UserData.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameClear::Init()
{
	m_key_flag = false;//キーフラグ
	//フラグを破棄
	((UserData*)Save::GetData())->ladder_item = 0;
	((UserData*)Save::GetData())->item = 0;
	((UserData*)Save::GetData())->pick_item = 0;
	((UserData*)Save::GetData())->ins_flag = false;
	((UserData*)Save::GetData())->break_flag = false;

	//インベントリ関係のフラグ破棄
	((UserData*)Save::GetData())->I_board1 = false;
	((UserData*)Save::GetData())->I_board2 = false;

	((UserData*)Save::GetData())->I_ladder1 = false;
	((UserData*)Save::GetData())->I_ladder2 = false;

	((UserData*)Save::GetData())->I_pick1 = false;
	((UserData*)Save::GetData())->I_pick2 = false;
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