//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"ObjPick.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

// イニシャライズ
void CObjPick::Init()
{
	float m_scroll;//左右スクロール用

	//m_px = 200.0f;//位置
	//m_py = 520.0f;

	//m_px = 350.0f;//位置
	//m_py = 520.0f;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ITEM, OBJ_PICK, 1);

}

//アクション
void CObjPick::Action()
{

	//HitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);

	if (((UserData*)Save::GetData())->pick_item < 0)//はしごアイテムが0を下回る時、0にする
	{
		((UserData*)Save::GetData())->pick_item = 0;
	}


	//ステージ毎に持ってくるブロック情報を変える
	//ステージ1
	if (((UserData*)Save::GetData())->stage1 == true)
	{
		//ブロック情報を持ってくる
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		hit->SetPos(m_px + block->GetScroll(), m_py);
	}
	//ステージ2
	else if (((UserData*)Save::GetData())->stage2 == true)
	{
		//ブロック情報を持ってくる
		CObjBlock2* block2 = (CObjBlock2*)Objs::GetObj(OBJ_BLOCK2);

		hit->SetPos(m_px + block2->GetScroll(), m_py);
	}
	//ステージ3
	else if (((UserData*)Save::GetData())->stage3 == true)
	{
		//ブロック情報を持ってくる
		CObjBlock3* block3 = (CObjBlock3*)Objs::GetObj(OBJ_BLOCK3);


		hit->SetPos(m_px + block3->GetScroll(), m_py);
	}
	//チュートリアルステージ
	else if (((UserData*)Save::GetData())->stageT == true)
	{
		//ブロック情報を持ってくる
		CObjBlockT* blockT = (CObjBlockT*)Objs::GetObj(OBJ_BLOCKT);


		hit->SetPos(m_px + blockT->GetScroll(), m_py);
	}

	

	//主人公オブジェクトと接触したらつるはしを削除
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//つるはしが所有するHitBoxを削除する

		//アイテム取得
		//Audio::Start(4);

		((UserData*)Save::GetData())->item += 1;
		((UserData*)Save::GetData())->pick_item += 1;
		
	}

}

//ドロー
void CObjPick::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//ステージ毎の描画
	//ステージ1
	if (((UserData*)Save::GetData())->stage1 == true)
	{
		//ブロック情報を持ってくる
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = m_py;
		dst.m_left = m_px + block->GetScroll();
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(7, &src, &dst, c, 0.0f);
	}
	//ステージ2
	else if (((UserData*)Save::GetData())->stage2 == true)
	{
		//ブロック情報を持ってくる
		CObjBlock2* block2 = (CObjBlock2*)Objs::GetObj(OBJ_BLOCK2);

		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = m_py;
		dst.m_left = m_px + block2->GetScroll();
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		
		Draw::Draw(7, &src, &dst, c, 0.0f);
	}
	//ステージ3
	else if (((UserData*)Save::GetData())->stage3 == true)
	{
		//ブロック情報を持ってくる
		CObjBlock3* block3 = (CObjBlock3*)Objs::GetObj(OBJ_BLOCK3);

		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = m_py;
		dst.m_left = m_px + block3->GetScroll();
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(7, &src, &dst, c, 0.0f);
	}
	//チュートリアルステージ
	else if (((UserData*)Save::GetData())->stageT == true)
	{
		//ブロック情報を持ってくる
		CObjBlockT* blockT = (CObjBlockT*)Objs::GetObj(OBJ_BLOCKT);

		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = m_py;
		dst.m_left = m_px + blockT->GetScroll();
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(7, &src, &dst, c, 0.0f);
	}
	
}