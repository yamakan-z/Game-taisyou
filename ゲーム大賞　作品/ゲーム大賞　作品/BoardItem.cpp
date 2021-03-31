//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"BoardItem.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

// イニシャライズ
void CBoardItem::Init()
{
	float m_scroll;//左右スクロール用

	m_px = 800.0f;//位置
	m_py = 520.0f;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ITEM, OBJ_BOARD_ITEM, 1);
}


//アクション
void CBoardItem::Action()
{

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);

	//主人公オブジェクトと接触したら100円を削除
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//100円が所有するHitBoxを削除する

		((UserData*)Save::GetData())->item += 1;
		((UserData*)Save::GetData())->ladder_item += 1;
	}
}

//ドロー
void CBoardItem::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

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
	Draw::Draw(4, &src, &dst, c, 0.0f);
}