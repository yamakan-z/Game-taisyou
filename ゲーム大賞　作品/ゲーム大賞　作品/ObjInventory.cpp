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
	float d[4] = { 1.0f,0.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//スコアの表示
	wchar_t str[256];
	swprintf_s(str, L"アイテム数:%.0f", ((UserData*)Save::GetData())->item);
	Font::StrDraw(str, 10, 10, 20, d);

	swprintf_s(str, L"はしごアイテム数:%.0f", ((UserData*)Save::GetData())->ladder_item);
	Font::StrDraw(str, 10, 30, 20, d);

	swprintf_s(str, L"板アイテム数:%.0f", ((UserData*)Save::GetData())->board_item);
	Font::StrDraw(str, 10, 50, 20, d);

	swprintf_s(str, L"つるはし:%.0f", ((UserData*)Save::GetData())->pick_item);
	Font::StrDraw(str, 10, 70, 20, d);

	if (((UserData*)Save::GetData())->break_point == true){
		swprintf_s(str, L"breakpoint");
		Font::StrDraw(str, 10, 230, 20, c);
	}
	swprintf_s(str, L"X=%.0f,Y=%.0f", (hero->GetX()-block->GetScroll())/64,hero->GetY()/64);
	Font::StrDraw(str, 10, 120, 20, c);

	if (((UserData*)Save::GetData())->break_flag == true) {
		swprintf_s(str, L"breakflag");
		Font::StrDraw(str, 10, 250, 20, c);
	}

	swprintf_s(str, L"1キー　変換・つるはし→板");
	Font::StrDraw(str, 10, 170, 20, c);

	swprintf_s(str, L"2キー　変換・板→はしご");
	Font::StrDraw(str, 10, 190, 20, c);

	swprintf_s(str, L"3キー　変換・はしご→つるはし");
	Font::StrDraw(str, 10, 210, 20, c);

	swprintf_s(str, L"残り変換回数:%d", ((UserData*)Save::GetData())->conversion_num);
	Font::StrDraw(str, 10, 90, 20, d);


	//インベントリ
	
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


	//残り変換回数
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;


	//表示位置の設定
	dst.m_top = 10.0;
	dst.m_left =400.0;
	dst.m_right =dst.m_right = dst.m_left + 80.0;
	dst.m_bottom = dst.m_top + 80.0;

	//描画
	Draw::Draw(16, &src, &dst, c, 0.0f);


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


	//残り変換回数
	if (((UserData*)Save::GetData())->conversion_num == 5)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//表示位置の設定
		dst.m_top = 17.0f;
		dst.m_left = 410.0f;
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
		dst.m_left = 410.0f;
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
		dst.m_left = 410.0f;
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
		dst.m_left = 410.0f;
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
		dst.m_left = 410.0f;
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
		dst.m_left = 410.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//描画
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
}


	