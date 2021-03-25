//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjGameOver.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	 m_key_flag=false;//キーフラグ
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
	float c[4] = { 1.0f,1.0f,1.0f,1.0f};

	Font::StrDraw(L"YOU LOST",0,0,32,c);
	Font::StrDraw(L"GAMEOVER",0,40,32,c);
	Font::StrDraw(L"NEXT_CHALLENGE:ENTER_KEY",0,80,32,c);

}