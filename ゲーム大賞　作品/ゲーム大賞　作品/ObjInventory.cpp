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

// イニシャライズ
void CObjInventory::Init()
{
	float m_scroll;//左右スクロール用

	m_px = 500.0f;//位置
	m_py = -50.0f;
	
	
}


//アクション
void CObjInventory::Action()
{
	if (((UserData*)Save::GetData())->item == 1)
	{
		
	}
}

//ドロー
void CObjInventory::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float i[4] = { 1.0f,0.0f,0.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	//スコアの表示
	wchar_t str[256];
	swprintf_s(str, L"アイテム数:%.0f", ((UserData*)Save::GetData())->item);
	Font::StrDraw(str, 10, 10, 20, i);

	swprintf_s(str, L"はしごアイテム数:%.0f", ((UserData*)Save::GetData())->ladder_item);
	Font::StrDraw(str, 10, 30, 20, c);

	swprintf_s(str, L"板アイテム数:%.0f", ((UserData*)Save::GetData())->board_item);
	Font::StrDraw(str, 10, 50, 20, c);

	swprintf_s(str, L"つるはし:%.0f", ((UserData*)Save::GetData())->pick_item);
	Font::StrDraw(str, 10, 70, 20, c);



	////インベントリ画像////

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 180.0f;
	src.m_bottom = 180.0f;


	//表示位置の設定
	dst.m_top = m_py;
	dst.m_left = m_px;
	dst.m_right = dst.m_left + 300.0;
	dst.m_bottom = dst.m_top + 200.0;

	//描画
	Draw::Draw(6, &src, &dst, c, 0.0f);


	////アイテム数////

	//はしご//

	if (((UserData*)Save::GetData())->ladder_item == 0)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 615.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item == 1)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 615.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item == 2)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 615.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item == 3)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 615.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item == 4)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 615.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item == 5)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 615.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}

	//つるはし//

	if (((UserData*)Save::GetData())->pick_item == 0)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 520.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item == 1)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left =520.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item == 2)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 520.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item == 3)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 520.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item == 4)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 520.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item == 5)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 520.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}

	//板//

	if (((UserData*)Save::GetData())->board_item == 0)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 710.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item == 1)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 710.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item == 2)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 710.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item == 3)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 710.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item == 4)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 710.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item == 5)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 710.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}
}


	////インベントリのアイテムアイコンの表示

	////一つ目
	//if (((UserData*)Save::GetData())->item >= 1)
	//{
//	if (((UserData*)Save::GetData())->I_ladder == true)
//	{
//		//切り取り位置の設定
//		src.m_top = 0.0f;
//		src.m_left = 0.0f;
//		src.m_right = 184.0f;
//		src.m_bottom = 184.0f;
//
//		//表示位置の設定
//		dst.m_top = 50.0f;
//		dst.m_left = 510.0f;
//		dst.m_right = dst.m_left + 64.0;
//		dst.m_bottom = dst.m_top + 64.0;
//
//		//描画
//		Draw::Draw(3, &src, &dst, c, 0.0f);
//	}
//	//}
//
//
//		//		
////		else if (((UserData*)Save::GetData())->I_pick == true)
////		{
//		//切り取り位置の設定
//		src.m_top = 0.0f;
//		src.m_left = 0.0f;
//		src.m_right = 184.0f;
//		src.m_bottom = 184.0f;
//
//		//表示位置の設定
//		dst.m_top = 50.0f;
//		dst.m_left = 510.0f;
//		dst.m_right = dst.m_left + 64.0;
//		dst.m_bottom = dst.m_top + 64.0;
//		//描画
//		Draw::Draw(3 & src, &dst, c, 0.0f);
//
//}


//		}
//
//		else if (((UserData*)Save::GetData())->I_board == true)
//		{
//			//切り取り位置の設定
//			src.m_top = 0.0f;
//			src.m_left = 0.0f;
//			src.m_right = 184.0f;
//			src.m_bottom = 184.0f;
//
//			//表示位置の設定
//			dst.m_top = 50.0f;
//			dst.m_left = 510.0f;
//			dst.m_right = dst.m_left + 64.0;
//			dst.m_bottom = dst.m_top + 64.0;
//
//			//描画
//			Draw::Draw(4, &src, &dst, c, 0.0f);
//		}
//	}
//
//	
//	//二つ目
//	if (((UserData*)Save::GetData())->item >= 2 )
//	{
//		if (((UserData*)Save::GetData())->I_ladder1 == true)
//		{
//			//切り取り位置の設定
//			src.m_top = 0.0f;
//			src.m_left = 0.0f;
//			src.m_right = 184.0f;
//			src.m_bottom = 184.0f;
//
//			//表示位置の設定
//			dst.m_top = 50.0f;
//			dst.m_left = 590.0f;
//			dst.m_right = dst.m_left + 64.0;
//			dst.m_bottom = dst.m_top + 64.0;
//
//			//描画
//			Draw::Draw(5, &src, &dst, c, 0.0f);
//		}
//
//		else if (((UserData*)Save::GetData())->I_pick1 == true)
//		{
//			//切り取り位置の設定
//			src.m_top = 0.0f;
//			src.m_left = 0.0f;
//			src.m_right = 184.0f;
//			src.m_bottom = 184.0f;
//
//			//表示位置の設定
//			dst.m_top = 50.0f;
//			dst.m_left = 590.0f;
//			dst.m_right = dst.m_left + 64.0;
//			dst.m_bottom = dst.m_top + 64.0;
//
//			//描画
//			Draw::Draw(7, &src, &dst, c, 0.0f);
//		}
//
//		else if (((UserData*)Save::GetData())->I_board1 == true)
//		{
//			//切り取り位置の設定
//			src.m_top = 0.0f;
//			src.m_left = 0.0f;
//			src.m_right = 184.0f;
//			src.m_bottom = 184.0f;
//
//			//表示位置の設定
//			dst.m_top = 50.0f;
//			dst.m_left = 590.0f;
//			dst.m_right = dst.m_left + 64.0;
//			dst.m_bottom = dst.m_top + 64.0;
//
//			//描画
//			Draw::Draw(4, &src, &dst, c, 0.0f);
//		}
//		
//	}
//
//
//	//三つ目
//	if (((UserData*)Save::GetData())->item >= 3)
//	{
//		if (((UserData*)Save::GetData())->I_ladder2 == true)
//		{
//			//切り取り位置の設定
//			src.m_top = 0.0f;
//			src.m_left = 0.0f;
//			src.m_right = 184.0f;
//			src.m_bottom = 184.0f;
//
//			//表示位置の設定
//			dst.m_top = 50.0f;
//			dst.m_left = 670.0f;
//			dst.m_right = dst.m_left + 64.0;
//			dst.m_bottom = dst.m_top + 64.0;
//
//			//描画
//			Draw::Draw(5, &src, &dst, c, 0.0f);
//		}
//
//		else if (((UserData*)Save::GetData())->I_pick2 == true)
//		{
//			//切り取り位置の設定
//			src.m_top = 0.0f;
//			src.m_left = 0.0f;
//			src.m_right = 184.0f;
//			src.m_bottom = 184.0f;
//
//			//表示位置の設定
//			dst.m_top = 50.0f;
//			dst.m_left = 670.0f;
//			dst.m_right = dst.m_left + 64.0;
//			dst.m_bottom = dst.m_top + 64.0;
//
//			//描画
//			Draw::Draw(7, &src, &dst, c, 0.0f);
//		}
//
//		else if (((UserData*)Save::GetData())->I_board2 == true)
//		{
//			//切り取り位置の設定
//			src.m_top = 0.0f;
//			src.m_left = 0.0f;
//			src.m_right = 184.0f;
//			src.m_bottom = 184.0f;
//
//			//表示位置の設定
//			dst.m_top = 50.0f;
//			dst.m_left = 670.0f;
//			dst.m_right = dst.m_left + 64.0;
//			dst.m_bottom = dst.m_top + 64.0;
//
//			//描画
//			Draw::Draw(4, &src, &dst, c, 0.0f);
//		}
//		
//	}
//
//