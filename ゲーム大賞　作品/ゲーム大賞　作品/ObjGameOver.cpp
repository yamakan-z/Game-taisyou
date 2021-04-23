//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)



//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjGameOver.h"
#include "GameL/UserData.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	m_key_flag = false;//キーフラグ

	//フラグを破棄
	//アイテム関係フラグ破棄
	((UserData*)Save::GetData())->item = 0;
	((UserData*)Save::GetData())->ladder_item = 0;
	((UserData*)Save::GetData())->pick_item = 0;
	((UserData*)Save::GetData())->board_item = 0;

	//ギミック関係フラグ破棄
	((UserData*)Save::GetData())->ins_flag = false;
	((UserData*)Save::GetData())->break_flag = false;
	((UserData*)Save::GetData())->ins_ladder = false;
	((UserData*)Save::GetData())->ladder = false;

	//インベントリ関係のフラグ破棄
	((UserData*)Save::GetData())->I_board1 = false;
	((UserData*)Save::GetData())->I_board2 = false;

	((UserData*)Save::GetData())->I_ladder1 = false;
	((UserData*)Save::GetData())->I_ladder2 = false;

	((UserData*)Save::GetData())->I_pick1 = false;
	((UserData*)Save::GetData())->I_pick2 = false;
}
//アクション
void CObjGameOver::Action()
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
void CObjGameOver::Draw()
{
	float r[4] = { 0.5f,0.0f,0.0f,1.0f };
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"YOU LOST", 350, 250, 32, r);
	Font::StrDraw(L"GAMEOVER", 350, 290, 32, r);
	Font::StrDraw(L"NEXT_CHALLENGE:ENTER_KEY", 225, 340, 32, c);

}