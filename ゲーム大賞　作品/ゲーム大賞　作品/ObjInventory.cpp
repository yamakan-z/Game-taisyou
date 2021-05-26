//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjInventory.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"
#include "GameL/DrawFont.h"

//使用するネームスペース
using namespace GameL;


////コンストラクタ
//CObjInventory::CObjInventory()
//{
//	
//}

// イニシャライズ
void CObjInventory::Init()
{
	float m_scroll;//左右スクロール用

	m_px = 500.0f;//位置
	m_py = -50.0f;

	flame = 0;//フレーム計算
	s_time = 0;
	m_time = 0;

	((UserData*)Save::GetData())->save_s_time = 0;//セーブ用m_time初期化
	((UserData*)Save::GetData())->save_m_time = 0;//セーブ用s_time初期化

}


//アクション
void CObjInventory::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//タイマー
	if (hero->GetBT() != 2)
	{
		flame++;
		//flameが60回回ると1秒カウント
		if (flame == 60)
		{
			flame = 0;
			s_time++;
			//s_time++の時点でセーブ用s_timeもインクリメント
			((UserData*)Save::GetData())->save_s_time++;
		}
		//s_timeが60で1分です
		if (s_time == 60)
		{
			s_time = 0;
			m_time++;
			//m_time++の時点でセーブ用m_timeもインクリメント
			((UserData*)Save::GetData())->save_m_time++;
			((UserData*)Save::GetData())->save_s_time = 0;
		}
	}

}

//ドロー
void CObjInventory::Draw()
{

	//フラグ確認用
	wchar_t str[256];

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 1.0f,0.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//主人公情報を持ってくる
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	if (((UserData*)Save::GetData())->stage1 == true)
	{
		//ブロック情報を持ってくる
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		swprintf_s(str, L"X=%.0f,Y=%.0f", (hero->GetX() - block->GetScroll()) / 64, hero->GetY() / 64);
		Font::StrDraw(str, 10, 120, 20, c);
	}


	if (((UserData*)Save::GetData())->ins_place == true)
	{
		swprintf_s(str, L"ins_place");
		Font::StrDraw(str, 10, 490, 20, d);
	}
	if (((UserData*)Save::GetData())->ins_flag == true)
	{
		swprintf_s(str, L"ins_flag");
		Font::StrDraw(str, 10, 520, 20, d);
	}

	if (((UserData*)Save::GetData())->ladder_flag == true)
	{
		swprintf_s(str, L"ladder_flag");
		Font::StrDraw(str, 10, 540, 20, d);
	}

	if (((UserData*)Save::GetData())->up_flag == true)
	{
		swprintf_s(str, L"up_flag");
		Font::StrDraw(str, 10, 560, 20, d);
	}

	swprintf_s(str, L"タイム　%02d:%02d", m_time, s_time);
	Font::StrDraw(str, 10, 200, 20, c);


	//操作説明アイコン表示

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 128.0f;


	//表示位置の設定
	dst.m_top = 100.0;
	dst.m_left = 550.0;
	dst.m_right = dst.m_right = dst.m_left + 220.0;
	dst.m_bottom = dst.m_top + 100.0;

	//描画
	Draw::Draw(46, &src, &dst, c, 0.0f);



	//--------インベントリ--------------
	
	//つるはし
	
	//変換アイテムを所持しているときインベントリのカラーを変化
	if ((((UserData*)Save::GetData())->converted_pick >= 1))
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;

		//表示位置の設定
		dst.m_top = 10.0;
		dst.m_left = 480.0;
		dst.m_right = dst.m_right = dst.m_left + 90.0;
		dst.m_bottom = dst.m_top + 80.0;

		//描画
		Draw::Draw(40, &src, &dst, c, 0.0f);
	}
	else
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;

		//表示位置の設定
		dst.m_top = 10.0;
		dst.m_left = 480.0;
		dst.m_right = dst.m_right = dst.m_left + 90.0;
		dst.m_bottom = dst.m_top + 80.0;

		//描画
		Draw::Draw(37, &src, &dst, c, 0.0f);
	}

	//はしご
	
	//変換アイテムを所持しているときインベントリのカラーを変化
	if ((((UserData*)Save::GetData())->converted_ladder >= 1))
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;

		//表示位置の設定
		dst.m_top = 10.0;
		dst.m_left = 580.0;
		dst.m_right = dst.m_right = dst.m_left + 90.0;
		dst.m_bottom = dst.m_top + 80.0;

		//描画
		Draw::Draw(38, &src, &dst, c, 0.0f);
	}
	else
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;

		//表示位置の設定
		dst.m_top = 10.0;
		dst.m_left = 580.0;
		dst.m_right = dst.m_right = dst.m_left + 90.0;
		dst.m_bottom = dst.m_top + 80.0;

		//描画
		Draw::Draw(35, &src, &dst, c, 0.0f);
	}
	
	//板

	//変換アイテムを所持しているときインベントリのカラーを変化
	if ((((UserData*)Save::GetData())->converted_board >= 1))
	{
	   
	   //切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;

		//表示位置の設定
		dst.m_top = 10.0;
		dst.m_left = 680.0;
		dst.m_right = dst.m_right = dst.m_left + 90.0;
		dst.m_bottom = dst.m_top + 80.0;

		//描画
		Draw::Draw(39, &src, &dst, c, 0.0f);
	}
	else
	{
	    //板
	    //切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;

		//表示位置の設定
		dst.m_top = 10.0;
		dst.m_left = 680.0;
		dst.m_right = dst.m_right = dst.m_left + 90.0;
		dst.m_bottom = dst.m_top + 80.0;

		//描画
		Draw::Draw(36, &src, &dst, c, 0.0f);
	}


	//-------インベントリ(劣化)---------

	//つるはし
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//表示位置の設定
	dst.m_top = 10.0;
	dst.m_left = 140.0;
	dst.m_right = dst.m_right = dst.m_left + 90.0;
	dst.m_bottom = dst.m_top + 80.0;

	//描画
	Draw::Draw(34, &src, &dst, c, 0.0f);


	//はしご
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//表示位置の設定
	dst.m_top = 10.0;
	dst.m_left = 240.0;
	dst.m_right = dst.m_right = dst.m_left + 90.0;
	dst.m_bottom = dst.m_top + 80.0;

	//描画
	Draw::Draw(32, &src, &dst, c, 0.0f);

	//板
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//表示位置の設定
	dst.m_top = 10.0;
	dst.m_left = 340.0;
	dst.m_right = dst.m_right = dst.m_left + 90.0;
	dst.m_bottom = dst.m_top + 80.0;

	//描画
	Draw::Draw(33, &src, &dst, c, 0.0f);



	//--------------------------------

	//空白欄(緑)
	
		if (((UserData*)Save::GetData())->conversion_num ==9 || ((UserData*)Save::GetData())->conversion_num==8 || ((UserData*)Save::GetData())->conversion_num==7 || ((UserData*)Save::GetData())->conversion_num == 6 || ((UserData*)Save::GetData())->conversion_num == 5)
		{
			//切り取り位置の設定
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;


			//表示位置の設定
			dst.m_top = 10.0;
			dst.m_left = 40.0;
			dst.m_right = dst.m_right = dst.m_left + 80.0;
			dst.m_bottom = dst.m_top + 80.0;

			//描画
			Draw::Draw(20, &src, &dst, c, 0.0f);
		}


		//空白欄(黄)

		if (((UserData*)Save::GetData())->conversion_num == 4 || ((UserData*)Save::GetData())->conversion_num == 3 || ((UserData*)Save::GetData())->conversion_num == 2 || ((UserData*)Save::GetData())->conversion_num == 1)
		{
			//切り取り位置の設定
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;


			//表示位置の設定
			dst.m_top = 10.0;
			dst.m_left = 40.0;
			dst.m_right = dst.m_right = dst.m_left + 80.0;
			dst.m_bottom = dst.m_top + 80.0;

			//描画
			Draw::Draw(21, &src, &dst, c, 0.0f);
		}


		//空白欄(赤)

		if (((UserData*)Save::GetData())->conversion_num == 0)
		{
			//切り取り位置の設定
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;


			//表示位置の設定
			dst.m_top = 10.0;
			dst.m_left = 40.0;
			dst.m_right = dst.m_right = dst.m_left +80.0;
			dst.m_bottom = dst.m_top + 80.0;

			//描画
			Draw::Draw(22, &src, &dst, c, 0.0f);
		}

	
	////アイテム数////

	//はしご//

	if (((UserData*)Save::GetData())->ladder_item + ((UserData*)Save::GetData())->converted_ladder == 0)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 595.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item + ((UserData*)Save::GetData())->converted_ladder == 1)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 595.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item + ((UserData*)Save::GetData())->converted_ladder == 2)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 595.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item + ((UserData*)Save::GetData())->converted_ladder == 3)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 595.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item + ((UserData*)Save::GetData())->converted_ladder == 4)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 595.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item + ((UserData*)Save::GetData())->converted_ladder == 5)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 595.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}

	//つるはし//

	if (((UserData*)Save::GetData())->pick_item+ ((UserData*)Save::GetData())->converted_pick == 0)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 495.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item + ((UserData*)Save::GetData())->converted_pick == 1)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 495.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item + ((UserData*)Save::GetData())->converted_pick == 2)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 495.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item + ((UserData*)Save::GetData())->converted_pick == 3)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 495.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item + ((UserData*)Save::GetData())->converted_pick == 4)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 495.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item + ((UserData*)Save::GetData())->converted_pick == 5)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 495.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}

	//板//

	if (((UserData*)Save::GetData())->board_item + ((UserData*)Save::GetData())->converted_board == 0)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 695.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item + ((UserData*)Save::GetData())->converted_board == 1)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 695.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item + ((UserData*)Save::GetData())->converted_board == 2)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 695.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item + ((UserData*)Save::GetData())->converted_board == 3)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 695.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item + ((UserData*)Save::GetData())->converted_board == 4)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 695.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item + ((UserData*)Save::GetData())->converted_board == 5)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 695.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}



	//----------------アイテム数(劣化)-------------------------------

	//はしご(劣化)

	if (((UserData*)Save::GetData())->bad_ladder == 0)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 255.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->bad_ladder == 1)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 255.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->bad_ladder == 2)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 255.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->bad_ladder == 3)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 255.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->bad_ladder == 4)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 255.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->bad_ladder == 5)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 255.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}

	//つるはし(劣化)

if (((UserData*)Save::GetData())->bad_pick== 0)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 152.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(8, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_pick == 1)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 152.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(9, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_pick == 2)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 152.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(10, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_pick == 3)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 152.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(11, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_pick == 4)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 152.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(12, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_pick == 5)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 152.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(13, &src, &dst, c, 0.0f);
}


     //板(劣化)

if (((UserData*)Save::GetData())->bad_board == 0)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 355.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(8, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_board == 1)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 355.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(9, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_board == 2)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 355.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(10, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_board == 3)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 355.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(11, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_board == 4)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 355.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(12, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_board == 5)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 355.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(13, &src, &dst, c, 0.0f);
}
	//残り変換回数
if (((UserData*)Save::GetData())->conversion_num == 9)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 48.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(45, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->conversion_num == 8)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 48.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(44, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->conversion_num == 7)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 48.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(43, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->conversion_num == 6)
{
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//表示位置の設定
	dst.m_top = 17.0f;
	dst.m_left = 48.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//描画
	Draw::Draw(42, &src, &dst, c, 0.0f);
}
	if (((UserData*)Save::GetData())->conversion_num == 5)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 48.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->conversion_num == 4)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 48.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}

	if (((UserData*)Save::GetData())->conversion_num == 3)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 48.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}

	if (((UserData*)Save::GetData())->conversion_num == 2)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 48.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}

	if (((UserData*)Save::GetData())->conversion_num == 1)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 48.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	if (((UserData*)Save::GetData())->conversion_num == 0)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 48.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}


	//空白欄(赤)バツ印

	if (((UserData*)Save::GetData())->conversion_num == 0)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;


		//表示位置の設定
		dst.m_top = 10.0;
		dst.m_left = 40.0;
		dst.m_right = dst.m_right = dst.m_left + 80.0;
		dst.m_bottom = dst.m_top + 80.0;

		//描画
		Draw::Draw(23, &src, &dst, c, 0.0f);
	}

}


	