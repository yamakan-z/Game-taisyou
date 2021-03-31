//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjLadder.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjLadder::Init()
{
	m_scroll = 0.0f;

	//はしご情報
	int ladder_data[10][100] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,30,30,30,30,30,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,20,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	//マップデータをコピー
	memcpy(m_mapL, ladder_data, sizeof(int) * (10 * 100));

	
}

//アクション
void CObjLadder::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (((UserData*)Save::GetData())->ladder_item < 0)//はしごアイテムが0を下回る時、0にする
	{
		((UserData*)Save::GetData())->ladder_item = 0;
	}

	if (((UserData*)Save::GetData())->item < 0)//アイテムが0を下回る時、0にする
	{
		((UserData*)Save::GetData())->item = 0;
	}



	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//後方スクロールライン
	if (hx < 80)
	{
		hero->SetX(80);//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();//主人公が本来動くべき分の値をm_scrollに加える
	}

	//前方スクロールライン
	if (hx > 300)
	{
		hero->SetX(300);//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();//主人公が本来動くべき分の値をm_scrollに加える
	}

	//主人公の衝突状態確認フラグの初期化
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//踏んでいるブロックの種類の初期化
	hero->SetBT(0);


	

	//m_mapの全要素にアクセス
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{


			if (m_mapL[i][j] > 0)
			{
				//要素番号を座標に変更
				float x = j * 64.0f;
				float y = i * 64.0;

				//主人公とブロックの当たり判定(はしご）
				if (m_mapL[i][j] == 20 && (hx + (-block->GetScroll()) + 64.0f > x) && (hx + (-block->GetScroll()) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-block->GetScroll())) - x;
					float vy = hy - y;

					//長さを求める
					float len = sqrt(vx * vx + vy * vy);

					//角度を求める
					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//角度で上下左右を判定
					if ((r < 45 && r>0) || r > 315)
					{
						//右
						hero->SetRight(true);//主人公の左の部分が衝突している
						hero->SetX(x + 64.0f + (block->GetScroll()));//ブロックの位置+主人公の幅
						hero->SetVY(-hero->GetVX() * 0.1f);//-VX*反発係数
					}
					if (r > 45 && r < 135)
					{
						//上
						hero->SetDown(true);//主人公の下の部分が衝突している
						hero->SetY(y - 64.0f);//ブロックの位置-主人公の幅
						hero->SetBT(m_mapL[i][j]);//ブロックの要素(type)を主人公に渡す
						hero->SetVY(0.0f);
					}
					if (r > 135 && r < 225)
					{
						//左
						hero->SetLeft(true);//主人公の右の部分が衝突している
						hero->SetX(x - 64.0f + (block->GetScroll()));//ブロックの位置-主人公の幅
						hero->SetVX(-hero->GetVX() * 0.1f);
					}
					if (r > 225 && r < 315)
					{
						//下
						hero->SetUp(true);//主人公の上の部分が衝突している
						hero->SetY(y + 64.0f);//ブロックの位置+主人公の幅
						if (hero->GetVY() < 0)
						{
							hero->SetVY(0.0f);
						}
					}

				}

				//主人公とブロックの当たり判定(はしご）
				if (m_mapL[i][j] == 21 && (hx + (-block->GetScroll()) + 64.0f > x) && (hx + (-block->GetScroll()) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-block->GetScroll())) - x;
					float vy = hy - y;

					//長さを求める
					float len = sqrt(vx * vx + vy * vy);

					//角度を求める
					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//角度で上下左右を判定
					if ((r < 45 && r>0) || r > 315)
					{
						//右
						hero->SetRight(true);//主人公の左の部分が衝突している
						hero->SetX(x + 64.0f + (block->GetScroll()));//ブロックの位置+主人公の幅
						hero->SetVY(-hero->GetVX() * 0.1f);//-VX*反発係数
					}
					if (r > 45 && r < 135)
					{
						//上
						hero->SetDown(true);//主人公の下の部分が衝突している
						hero->SetY(y - 64.0f);//ブロックの位置-主人公の幅
						hero->SetBT(m_mapL[i][j]);//ブロックの要素(type)を主人公に渡す
						hero->SetVY(0.0f);
					}
					if (r > 135 && r < 225)
					{
						//左
						hero->SetLeft(true);//主人公の右の部分が衝突している
						hero->SetX(x - 64.0f + (block->GetScroll()));//ブロックの位置-主人公の幅
						hero->SetVX(-hero->GetVX() * 0.1f);
					}
					if (r > 225 && r < 315)
					{
						//下
						hero->SetUp(true);//主人公の上の部分が衝突している
						hero->SetY(y + 64.0f);//ブロックの位置+主人公の幅
						if (hero->GetVY() < 0)
						{
							hero->SetVY(0.0f);
						}
					}

				}

				//主人公と足場（上）の当たり判定
				if (m_mapL[i][j] == 30 && (hx + (-block->GetScroll()) + 64.0f > x) && (hx + (-block->GetScroll()) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-block->GetScroll())) - x;
					float vy = hy - y;

					//長さを求める
					float len = sqrt(vx * vx + vy * vy);

					//角度を求める
					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//角度で上下左右を判定

					if (r > 45 && r < 135)
					{
						//上
						hero->SetDown(true);//主人公の下の部分が衝突している
						hero->SetY(y - 64.0f);//ブロックの位置-主人公の幅
						hero->SetBT(m_mapL[i][j]);//ブロックの要素(type)を主人公に渡す
						hero->SetVY(0.0f);
						((UserData*)Save::GetData())->move_flag = true;//足場に移動したら、左右移動制限を解除
						((UserData*)Save::GetData())->ladder = false;
						((UserData*)Save::GetData())->ins_ladder = false;
					}


				}

				//はしごがあると上へ行く
				if (hero->GetBT() == 20)
				{
					((UserData*)Save::GetData())->ladder_flag = true;//ここではしごの設置場所を判定

					if (((UserData*)Save::GetData())->ladder == true)
					{
						((UserData*)Save::GetData())->up_flag = true;//はしごがある時のみ上移動
					}
				
				}
				else if (hero->GetBT() != 20)
				{
					((UserData*)Save::GetData())->up_flag = false;
					((UserData*)Save::GetData())->ladder_flag = false;

				}

				if (((UserData*)Save::GetData())->ins_ladder == true&&((UserData*)Save::GetData())->ladder_item>0)
				{
					if (m_mapL[i][j] == 1)//9番：はしご設置用の空間
					{
						
						m_mapL[i][j] = 10;//はしご設置
						
						((UserData*)Save::GetData())->ladder = true;//上移動の許可
						
						((UserData*)Save::GetData())->item -= 1;

					}
					else if (((UserData*)Save::GetData())->item <= 0)
					{
						((UserData*)Save::GetData())->ladder_item -= 1;
					}
				}
			}
		}
	}
}

//ドロー
void CObjLadder::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//10～19番　はしご
	//20～29番　はしご判定ブロック
	//30～39番　足場ブロック（上）

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			//はしご（描画のみ）
			if (m_mapL[i][j] == 10)
			{
				
				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + block->GetScroll();
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(3, &src, &dst, c, 0.0f);

			
			}

			//はしご用のブロック（ここで上る判定をつける）
			if (m_mapL[i][j] == 20)
			{

				//描画カラー情報
				float c2[4] = { 0.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + block->GetScroll();
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//上の足場ブロック
			if (m_mapL[i][j] == 30)
			{
				//描画カラー情報
				float c2[4] = { 1.0f,0.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + block->GetScroll();
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

		}
	}
}