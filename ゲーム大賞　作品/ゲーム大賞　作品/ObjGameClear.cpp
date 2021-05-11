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
	//アイテム関係フラグ破棄
	((UserData*)Save::GetData())->item = 0;
	((UserData*)Save::GetData())->ladder_item = 0;
	((UserData*)Save::GetData())->pick_item = 0;
	((UserData*)Save::GetData())->board_item = 0;

	//変換済アイテム
	((UserData*)Save::GetData())->converted_board = 0;//変換済み板アイテム
	((UserData*)Save::GetData())->converted_ladder = 0;//変換済みはしごアイテム
	((UserData*)Save::GetData())->converted_pick = 0;//変換済みつるはしアイテム

	//劣化アイテム
	((UserData*)Save::GetData())->bad_board = 0;//劣化板アイテム
	((UserData*)Save::GetData())->bad_ladder = 0;//劣化はしごアイテム
	((UserData*)Save::GetData())->bad_pick = 0;//劣化つるはしアイテム


	//ギミック関係フラグ破棄
	//板関係のフラグ破棄
	((UserData*)Save::GetData())->ins_flag = false;
	//障害物関係のフラグ破棄
	((UserData*)Save::GetData())->break_flag = false;
	//はしご関係のフラグ破棄
	((UserData*)Save::GetData())->ins_ladder = false;
	((UserData*)Save::GetData())->ladder = false;


	//劣化ギミック関係のフラグ破棄
	//はしご関係のフラグ破棄
	((UserData*)Save::GetData())->ins_bad_ladder = false;
	((UserData*)Save::GetData())->bad_ladder_put = false;


	//変換回数を初期値に戻す
	((UserData*)Save::GetData())->conversion_num = 5;
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
	float c[4] = { 0.0f,0.0f,1.0f,1.0f };

	Font::StrDraw(L"Return_to_title:ENTER_KEY", 225, 340, 32, c);
}