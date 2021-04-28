//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjHero.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	 m_px=100.0f;//位置
	 m_py=510.0f;
	 m_vx=0.0f;//移動ベクトル
	 m_vy=0.0f;
	 m_posture = 1.0f;//右向き0.0f左向き1.0f

	 //blockとの衝突状態確認
	 m_hit_up = false;
	 m_hit_down = false;
	 m_hit_left = false;
	 m_hit_right = false;

	 //踏んでいるブロックの種類を確認
	 m_block_type = 0;

	 //当たり判定用HitBoxを作成
	 Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);

	 //アイテムを一つだけ変換させるフラグ
	 conversionL = true;
	 conversionB = true;
	 conversionP = true;

}

//アクション
void CObjHero::Action()
{
	//落下によるゲームオーバー
	if (m_py > 1000.0f)
	{
		/*((UserData*)Save::GetData())->ladder_item = 0;
		((UserData*)Save::GetData())->item = 0;
		((UserData*)Save::GetData())->pick_item = 0;
		((UserData*)Save::GetData())->board_item = 0;*/
		//場外に出たらリスタート
		Scene::SetScene(new CSceneGameOver());
	}

	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true&& ((UserData*)Save::GetData())->move_flag == true)
	{
		m_vx = +3.0f;
		m_posture = 1.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true&& ((UserData*)Save::GetData())->move_flag == true)
	{
		m_vx = -3.0f;
		m_posture = 0.0f;
	}


	//設置(はしご）
	if (Input::GetVKey('A') == true && ((UserData*)Save::GetData())->ladder_flag == true)
	{
		((UserData*)Save::GetData())->ins_ladder = true;//はしご設置のフラグ

		//設置後、はしごアイテム＆アイテム総数-1
		if (((UserData*)Save::GetData())->ins_ladder_done == true)
		{
			((UserData*)Save::GetData())->item -= 1;
			((UserData*)Save::GetData())->ladder_item -= 1;
			((UserData*)Save::GetData())->ins_ladder_done = false;
		}
	}


	//はしごがある状態だと上へ移動
	if (((UserData*)Save::GetData())->up_flag == true&&Input::GetVKey(VK_UP) == true)
	{
		/*if (m_hit_down==true)
		{*/
			//上移動時は左右移動を受け付けない
			((UserData*)Save::GetData())->move_flag = false;
			m_vy = -15.0f;
		/*}*/
		
	}
	
	//設置(板）
	if (Input::GetVKey('X') == true&& ((UserData*)Save::GetData())->ins_place==true)
	{
		((UserData*)Save::GetData())->ins_flag = true;


		//設置後、板アイテム＆アイテム総数-1
	    if (((UserData*)Save::GetData())->ins_done == true)
	    {
		   ((UserData*)Save::GetData())->item -= 1;
		   ((UserData*)Save::GetData())->board_item -= 1;
		   ((UserData*)Save::GetData())->ins_done = false;
	    }

	}
	
	
	//障害物破壊
	if (Input::GetVKey('W') == true&& ((UserData*)Save::GetData())->break_point==true)
	{
		((UserData*)Save::GetData())->break_flag = true;

		//設置後、はしごアイテム＆アイテム総数-1
       if (((UserData*)Save::GetData())->break_done == true)
	      {
		     ((UserData*)Save::GetData())->item -= 1;
		     ((UserData*)Save::GetData())->pick_item -= 1;
		     ((UserData*)Save::GetData())->break_done = false;
	      }
	}
	else
	{
		((UserData*)Save::GetData())->break_flag = false;
	}



	//アイテムの変換
	//現在の変換　つるはし→板→はしご→つるはし...
	if (((UserData*)Save::GetData())->item > 0)
	{
		//変換　つるはし→板
		if (Input::GetVKey('1') == true && ((UserData*)Save::GetData())->pick_item > 0&& conversionB == true)
		{
			((UserData*)Save::GetData())->pick_item -= 1;
			((UserData*)Save::GetData())->board_item += 1;
			conversionB = false;
		}
		else if(Input::GetVKey('1')==false&& conversionB == false)
		{
			conversionB = true;
		}

		//変換　板→はしご
		if (Input::GetVKey('2') == true && ((UserData*)Save::GetData())->board_item > 0 && conversionL == true)
		{
			((UserData*)Save::GetData())->board_item -= 1;
			((UserData*)Save::GetData())->ladder_item += 1;
			conversionL = false;
		}
		else if (Input::GetVKey('2') == false && conversionL == false)
		{
			conversionL = true;
		}

		//変換　はしご→つるはし
		if (Input::GetVKey('3') == true && ((UserData*)Save::GetData())->ladder_item > 0 && conversionP == true)
		{
			((UserData*)Save::GetData())->ladder_item -= 1;
			((UserData*)Save::GetData())->pick_item += 1;
			conversionP = false;
		}
		else if (Input::GetVKey('3') == false && conversionP == false)
		{
			conversionP = true;
		}


	}

	//摩擦
	m_vx += -(m_vx * 0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);

}

//ドロー
void CObjHero::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//表示位置の設定
	dst.m_top = 0.0f+m_py;
	dst.m_left =( 64.0f*m_posture)+m_px;
	dst.m_right = (64.0-64.0f*m_posture)+m_px;
	dst.m_bottom = 64.0f+m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}