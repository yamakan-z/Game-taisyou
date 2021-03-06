//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock2.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjBlock2::Init()
{
	m_scroll = 0.0f;

	m_px = GetScroll();//位置
	m_py = GetScroll();

	p = 0;
	q = 0;

	//ブロック情報
	//使用ブロック番号　1〜17、80〜81、90〜91、97〜99　
	//01番　ブロック
	//02番　ゴール
	//-----------はしご関係のブロック------------ 
	//03番　はしごアイテム
	//06番  はしご判定ブロック 
	//07番　はしご上ったあとの足場
	//08番　はしご（表示） 
	//80番　上移動制御ブロック
	//97番　はしご設置の空間 

	//-----------板関係のブロック---------------- 
	//04番　板アイテム
	//12番　板　
	//13番　板判定ブロック
	//99番　板設置の穴

	//-----------障害物関係のブロック--------------- 
	//05番　つるはしアイテム
	//10番　障害物
	//11番  障害物判定ブロック
	//98番　障害物破壊後の空間

	//-----------劣化アイテム用-------------
	//14番　はしご判定ブロック（劣化アイテム用）
	//15番　劣化はしご（表示） 
	//16番　板(劣化アイテム用）
	//17番　板判定ブロック(劣化アイテム用）
	//18番　障害物判定ブロック（劣化つるはし用）  　 
	//81番　上移動制御ブロック（劣化アイテム用） 
	//--------------------------------------- 

	//90番　ゴール（旗）
	//91番　ゴール（ポール）
	//19番  はしご看板
	//20番  つるはし看板
	//21番  鉄板看板
	//22番  劣化はしご看板
	//23番  劣化つるはし看板
	//24番  劣化鉄板看板
	//25番  看板棒
	//26番  矢印看板




	//マップ情報
	int block_data[10][100] =
	{
		{01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01},
		{01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,01,07,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01},
		{01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,10,00,00,00,00,01,00,00,00,00,00,00,10,00,00,00,00,00,00,00,00,00,00,00,00,00,10,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,97,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01},
		{01,00,00,00,00,00,00,00,00,00,26,00,00,20,00,10,00,00,00,00,01,00,00,00,00,20,00,10,00,00,00,00,00,00,00,00,00,00,00,20,00,10,00,00,00,00,21,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,19,97,00,00,26,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01},
		{01,00,00,00,00,00,00,00,03,00,25,00,03,25,00,10,00,00,00,00,01,00,00,00,03,25,00,10,00,00,00,00,00,00,00,01,00,00,00,25,00,10,00,00,00,00,25,00,04,00,00,00,00,00,00,00,05,00,00,00,00,00,00,00,00,00,00,00,25,97,03,00,25,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01},
		{01,00,00,00,07,07,07,07,01,01,01,01,01,01,11,01,11,01,01,01,01,00,07,07,01,01,11,01,11,00,00,00,00,00,00,01,07,07,01,01,11,01,11,01,07,01,01,01,01,13,99,99,99,13,01,01,01,00,00,00,00,00,00,00,00,00,07,07,01,06,01,01,01,01,00,00,20,00,10,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01},
		{01,00,00,00,00,97,00,00,00,00,10,00,00,00,00,00,00,00,00,00,00,00,97,00,00,00,00,00,00,00,00,00,00,00,00,00,00,97,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,00,00,00,00,00,00,00,00,00,00,97,00,00,00,00,00,01,00,05,25,00,10,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01},
		{01,00,00,00,19,97,00,00,20,00,10,00,00,00,21,00,00,00,00,00,00,19,97,00,00,00,00,00,00,21,00,00,00,00,00,00,19,97,00,20,00,10,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,00,00,20,00,10,00,00,00,00,19,97,00,00,00,00,00,01,01,01,01,11,01,11,01,01,01,00,24,00,00,00,00,00,00,00,00,20,00,10,00,00,00,01},
		{01,00,00,00,25,97,04,00,25,00,10,00,00,05,25,00,00,00,00,00,03,25,97,00,00,00,00,00,04,25,00,00,00,00,00,00,25,97,05,25,00,10,00,00,00,00,00,00,00,00,00,00,00,00,00,05,01,00,00,25,00,10,00,03,00,00,25,97,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,00,25,00,00,00,00,00,00,03,00,25,00,10,00,00,91,01},
		{01,01,01,01,01,06,01,01,01,11,01,11,01,01,01,13,99,99,99,13,01,01,06,00,00,00,01,01,01,01,13,99,99,99,13,01,01,06,01,01,11,01,11,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,11,01,11,01,01,01,01,06,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,17,99,99,17,01,01,01,01,01,11,01,11,01,02,01},
		//   0  .  .  .  .  5  .  .  .  .  10 .  .  .  .  15 .  .  .  .  20 .  

	};
	//マップデータをコピー
	memcpy(m_map, block_data, sizeof(int) * (10 * 100));


	//アイテム生成
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{

			if (m_map[i][j] == 3)
			{
				//はしごアイテム作成
				CLadderItem* objli = new CLadderItem();
				objli->posset(j * 64, i * 64);

				Objs::InsertObj(objli, OBJ_LADDER_ITEM, 10);
			}

			if (m_map[i][j] == 4)
			{
				//boardオブジェクト作成
				CBoardItem* objbi = new CBoardItem();
				objbi->posset(j * 64, i * 64);

				Objs::InsertObj(objbi, OBJ_BOARD_ITEM, 10);
			}

			if (m_map[i][j] == 5)
			{
				//つるはし作成
				CObjPick* objp = new CObjPick();
				objp->posset(j * 64, i * 64);

				Objs::InsertObj(objp, OBJ_PICK, 10);
			}
		}
	}


}

void CObjBlock2::Item_Spawn()
{


}


//アクション
void CObjBlock2::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (((UserData*)Save::GetData())->item <= 0)//アイテムが0を下回る時、0にする
	{
		((UserData*)Save::GetData())->item = 0;
	}

	if (((UserData*)Save::GetData())->ladder_item < 0)//はしごアイテムが0を下回る時、0にする
	{
		((UserData*)Save::GetData())->ladder_item = 0;
	}



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


			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float x = j * 64.0f;
				float y = i * 64.0;

				//-----------当たり判定の設定--------------------

				//主人公とブロックの当たり判定
				if (m_map[i][j] == 1 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

						//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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

					//lenがある一定の長さのより短い場合判定に入る
					if (len < 88.0f)
					{
						//角度で上下左右を判定
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							hero->SetRight(true);//主人公の左の部分が衝突している
							hero->SetX(x + 64.0f + (m_scroll));//ブロックの位置+主人公の幅
							hero->SetVX(-hero->GetVX() * 0.1f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公の下の部分が衝突している
							hero->SetY(y - 64.0f);//ブロックの位置-主人公の幅
							hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);//主人公の右の部分が衝突している
							hero->SetX(x - 64.0f + (m_scroll));//ブロックの位置-主人公の幅
							hero->SetVX(-hero->GetVX() * 0.1f);
						}
						if (r > 225 && r < 315)
						{
							//下
							hero->SetUp(true);//主人公の上の部分が衝突している
							hero->SetY(y + 64);//ブロックの位置+主人公の幅
							if (hero->GetVY() < 0)
							{
								hero->SetVY(0.0f);
							}
						}

					}

				}


				//主人公とブロックの当たり判定(ゴール）
				if (m_map[i][j] == 2 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

						//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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

					//lenがある一定の長さのより短い場合判定に入る
					if (len < 88.0f)
					{
						//角度で上下左右を判定
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							hero->SetRight(true);//主人公の左の部分が衝突している
							hero->SetX(x + 64.0f + (m_scroll));//ブロックの位置+主人公の幅
							hero->SetVX(-hero->GetVX() * 0.1f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公の下の部分が衝突している
							hero->SetY(y - 64.0f);//ブロックの位置-主人公の幅
							hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVY(0.0f);

							if (m_map[i][j] == 90)
							{
								m_map[i][j] = 10;//障害物復活

							}

						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);//主人公の右の部分が衝突している
							hero->SetX(x - 64.0f + (m_scroll));//ブロックの位置-主人公の幅
							hero->SetVX(-hero->GetVX() * 0.1f);
						}
						if (r > 225 && r < 315)
						{
							//下
						}

					}

				}

				//はしごを設置する場所を判定するブロック
				if (m_map[i][j] == 6 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetX(x + 64.0f + (m_scroll));//ブロックの位置+主人公の幅
						hero->SetVX(-hero->GetVX() * 0.1f);//-VX*反発係数
					}
					if (r > 45 && r < 135)
					{
						//上
						hero->SetDown(true);//主人公の下の部分が衝突している
						hero->SetY(y - 64.0f);//ブロックの位置-主人公の幅
						hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
						hero->SetVY(0.0f);
					}
					if (r > 135 && r < 225)
					{
						//左
						hero->SetLeft(true);//主人公の右の部分が衝突している
						hero->SetX(x - 64.0f + (m_scroll));//ブロックの位置-主人公の幅
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


				//はしごを設置する場所を判定するブロック（劣化アイテム用）
				if (m_map[i][j] == 26 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetX(x + 64.0f + (m_scroll));//ブロックの位置+主人公の幅
						hero->SetVX(-hero->GetVX() * 0.1f);//-VX*反発係数
					}
					if (r > 45 && r < 135)
					{
						//上
						hero->SetDown(true);//主人公の下の部分が衝突している
						hero->SetY(y - 64.0f);//ブロックの位置-主人公の幅
						hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
						hero->SetVY(0.0f);
					}
					if (r > 135 && r < 225)
					{
						//左
						hero->SetLeft(true);//主人公の右の部分が衝突している
						hero->SetX(x - 64.0f + (m_scroll));//ブロックの位置-主人公の幅
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
				if (m_map[i][j] == 7 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
						hero->SetVY(0.0f);
						((UserData*)Save::GetData())->move_flag = true;//足場に移動したら、左右移動制限を解除
						//一部のはしごフラグの初期化
						((UserData*)Save::GetData())->ladder = false;
						((UserData*)Save::GetData())->ins_ladder = false;
						((UserData*)Save::GetData())->up_flag = false;
						//一部の劣化はしごフラグの初期化
						((UserData*)Save::GetData())->bad_ladder_put = false;
						((UserData*)Save::GetData())->ins_bad_ladder = false;
						((UserData*)Save::GetData())->low_up_flag = false;
					}


				}


				//障害物
				if (m_map[i][j] == 10 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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

					//lenがある一定の長さのより短い場合判定に入る
					if (len < 88.0f)
					{
						//角度で上下左右を判定
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							hero->SetRight(true);//主人公の左の部分が衝突している
							hero->SetX(x + 64.0f + (m_scroll));//ブロックの位置+主人公の幅
							hero->SetVX(-hero->GetVX() * 0.1f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公の下の部分が衝突している
							hero->SetY(y - 64.0f);//ブロックの位置-主人公の幅
							hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);//主人公の右の部分が衝突している
							hero->SetX(x - 64.0f + (m_scroll));//ブロックの位置-主人公の幅
							hero->SetVX(-hero->GetVX() * 0.1f);
						}
						if (r > 225 && r < 315)
						{
							//下
						}

					}

				}

				//障害物判定ブロック
				if (m_map[i][j] == 11 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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

					//lenがある一定の長さのより短い場合判定に入る
					if (len < 88.0f)
					{
						//角度で上下左右を判定
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							hero->SetRight(true);//主人公の左の部分が衝突している
							hero->SetX(x + 64.0f + (m_scroll));//ブロックの位置+主人公の幅
							hero->SetVX(-hero->GetVX() * 0.1f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公の下の部分が衝突している
							hero->SetY(y - 64.0f);//ブロックの位置-主人公の幅
							hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);//主人公の右の部分が衝突している
							hero->SetX(x - 64.0f + (m_scroll));//ブロックの位置-主人公の幅
							hero->SetVX(-hero->GetVX() * 0.1f);
						}
						if (r > 225 && r < 315)
						{
							//下
						}

					}

				}





				//板の当たり判定
				if (m_map[i][j] == 12 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
						hero->SetVY(0.0f);
					}


				}

				//設置ブロック（板）の当たり判定
				if (m_map[i][j] == 13 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
						hero->SetVY(0.0f);
					}


				}


				//劣化板の当たり判定
				if (m_map[i][j] == 16 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
						hero->SetVY(0.0f);
					}


				}


				//設置ブロック（板）の当たり判定
				if (m_map[i][j] == 17 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
						hero->SetVY(0.0f);
					}


				}

				//障害物判定ブロック
				if (m_map[i][j] == 18 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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

					//lenがある一定の長さのより短い場合判定に入る
					if (len < 88.0f)
					{
						//角度で上下左右を判定
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							hero->SetRight(true);//主人公の左の部分が衝突している
							hero->SetX(x + 64.0f + (m_scroll));//ブロックの位置+主人公の幅
							hero->SetVY(-hero->GetVX() * 0.1f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公の下の部分が衝突している
							hero->SetY(y - 64.0f);//ブロックの位置-主人公の幅
							hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);//主人公の右の部分が衝突している
							hero->SetX(x - 64.0f + (m_scroll));//ブロックの位置-主人公の幅
							hero->SetVX(-hero->GetVX() * 0.1f);
						}
						if (r > 225 && r < 315)
						{
							//下
						}

					}

				}


				//上移動を許可するブロック
				if (m_map[i][j] == 80 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetX(x + 64.0f + (m_scroll));//ブロックの位置+主人公の幅
						hero->SetVY(-hero->GetVX() * 0.1f);//-VX*反発係数
					}
					if (r > 45 && r < 135)
					{
						//上
						hero->SetDown(true);//主人公の下の部分が衝突している
						hero->SetY(y - 64.0f);//ブロックの位置-主人公の幅
						hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
						hero->SetVY(0.0f);
					}
					if (r > 135 && r < 225)
					{
						//左
						hero->SetLeft(true);//主人公の右の部分が衝突している
						hero->SetX(x - 64.0f + (m_scroll));//ブロックの位置-主人公の幅
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

				//上移動を許可するブロック(劣化アイテム用）
				if (m_map[i][j] == 81 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetX(x + 64.0f + (m_scroll));//ブロックの位置+主人公の幅
						hero->SetVY(-hero->GetVX() * 0.1f);//-VX*反発係数
					}
					if (r > 45 && r < 135)
					{
						//上
						hero->SetDown(true);//主人公の下の部分が衝突している
						hero->SetY(y - 64.0f);//ブロックの位置-主人公の幅
						hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
						hero->SetVY(0.0f);
					}
					if (r > 135 && r < 225)
					{
						//左
						hero->SetLeft(true);//主人公の右の部分が衝突している
						hero->SetX(x - 64.0f + (m_scroll));//ブロックの位置-主人公の幅
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

				//-------------------------------------

				//ギミック関係の処理

				//ステージクリア
				if (hero->GetBT() == 2)
				{
					//クリアSEを流す
					((UserData*)Save::GetData())->clear = true;

				}

				//-------------障害物処理----------------------

				//障害物の両隣のブロックにプレイヤーがいると障害物を破壊
				if (hero->GetBT() == 11 && ((UserData*)Save::GetData())->pick_item > 0 || hero->GetBT() == 11 && ((UserData*)Save::GetData())->converted_pick > 0)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->break_point = true;
					}

				}
				else
				{
					((UserData*)Save::GetData())->break_point = false;
				}



				if (((UserData*)Save::GetData())->break_flag == true)//障害物の一つ前のブロック(障害物判定ブロック）に反応
				{

					if (m_map[i][j] == 10)//障害物
					{
						if ((hx + (-m_scroll) + 64.0f + 40 > x) &&
							(hx + (-m_scroll) < x + 64.0f) &&
							(hy + 64.0f > y) &&
							(hy < y + 64.0f))
						{
							for (int f = 0;; f++)
							{
								if (m_map[i - f][j] == 10)
								{
									m_map[i - f][j] = 98;//障害物破壊
								}
								else
								{

									//ブロック破壊音を鳴らす
									Audio::Start(2);

									//アイテム使用時、変換済みアイテムを優先して使用する
									if (((UserData*)Save::GetData())->converted_pick >= 1)
									{
										//ブロック破壊音を鳴らす
										Audio::Start(2);

										((UserData*)Save::GetData())->converted_pick -= 1;
										((UserData*)Save::GetData())->converted_item -= 1;
										((UserData*)Save::GetData())->item -= 1;
									}
									else
									{
										//ブロック破壊音を鳴らす
										Audio::Start(2);

										((UserData*)Save::GetData())->item -= 1;
										((UserData*)Save::GetData())->pick_item -= 1;
									}

									break;
								}
							}

						}

					}

				}

				//-------------------------------------------------------

				//--------------障害物処理(劣化つるはし用）--------------

				//劣化つるはし、通常つるはしまたは、変換済みつるはしで障害物を破壊
				if (hero->GetBT() == 18 && ((UserData*)Save::GetData())->bad_pick > 0 ||
					hero->GetBT() == 18 && ((UserData*)Save::GetData())->pick_item > 0 ||
					hero->GetBT() == 18 && ((UserData*)Save::GetData())->converted_pick > 0)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->break_bad_point = true;
					}

				}
				else
				{
					((UserData*)Save::GetData())->break_bad_point = false;
				}


				if (((UserData*)Save::GetData())->break_bad_flag == true)//障害物の一つ前のブロック(障害物判定ブロック）に反応
				{

					if (m_map[i][j] == 10)//障害物
					{
						if ((hx + (-m_scroll) + 64.0f + 40 > x) &&
							(hx + (-m_scroll) < x + 64.0f) &&
							(hy + 64.0f > y) &&
							(hy < y + 64.0f))
						{
							for (int f = 0;; f++)
							{
								if (m_map[i - f][j] == 10)
								{
									m_map[i - f][j] = 98;//障害物破壊
								}
								else
								{
									//ブロック破壊音を鳴らす
									Audio::Start(2);

									//アイテム使用時、劣化→変換済み→未変換の順で使用が優先される
									if (((UserData*)Save::GetData())->bad_pick >= 1)
									{
										//ブロック破壊音を鳴らす
										Audio::Start(2);

										((UserData*)Save::GetData())->bad_pick -= 1;
										((UserData*)Save::GetData())->item -= 1;
									}
									else if (((UserData*)Save::GetData())->converted_pick >= 1)
									{
										//ブロック破壊音を鳴らす
										Audio::Start(2);

										((UserData*)Save::GetData())->converted_pick -= 1;
										((UserData*)Save::GetData())->converted_item -= 1;
										((UserData*)Save::GetData())->item -= 1;
									}
									else if (((UserData*)Save::GetData())->pick_item >= 1)
									{
										//ブロック破壊音を鳴らす
										Audio::Start(2);

										((UserData*)Save::GetData())->item -= 1;
										((UserData*)Save::GetData())->pick_item -= 1;
									}

									break;
								}
							}

						}

					}

				}

				//-------------------------------------------------------


				//---------------はしご処理-------------------------

				//はしごの設置
				if (((UserData*)Save::GetData())->ins_ladder == true && ((UserData*)Save::GetData())->ladder_item > 0 || ((UserData*)Save::GetData())->ins_ladder == true && ((UserData*)Save::GetData())->converted_ladder > 0)
				{
					if (m_map[i][j] == 97)//はしご設置用の空間
					{

						if ((x / 64) - 1 <= ((hx + (-m_scroll)) / 64) && ((hx + (-m_scroll)) / 64) <= (x / 64) + 1)
						{
							if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0))
							{
								for (int f = 0;; f++) {
									if (m_map[i - f][j] == 97) {
										m_map[i - f][j] = 8;//はしご設置
									}
									else {

										//アイテムの設置音を鳴らす
										Audio::Start(1);

										//アイテム使用時、変換済みアイテムを優先して使用する
										if (((UserData*)Save::GetData())->converted_ladder >= 1)
										{
											((UserData*)Save::GetData())->item -= 1;
											((UserData*)Save::GetData())->converted_item -= 1;
											((UserData*)Save::GetData())->converted_ladder -= 1;
										}
										else
										{
											((UserData*)Save::GetData())->item -= 1;
											((UserData*)Save::GetData())->ladder_item -= 1;
										}


										((UserData*)Save::GetData())->ladder = true;//上移動の許可

										((UserData*)Save::GetData())->ladder_flag = false;//ここではしごの設置場所を判定

										break;
									}
								}


							}

						}
					}

				}

				//はしごを設置する場所を判定するブロック
				if (hero->GetBT() == 6)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
					{
						((UserData*)Save::GetData())->ladder_flag = true;//ここではしごの設置場所を判定

						if (((UserData*)Save::GetData())->ladder == true)
						{
							//上移動を許可するためにブロックを書き換える
							if (m_map[i][j] == 6)
							{
								m_map[i][j] = 80;//上移動可能ブロックに書き換え
							}
						}


					}


				}
				else if (hero->GetBT() != 6)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						//((UserData*)Save::GetData())->up_flag = false;
						//((UserData*)Save::GetData())->ladder_flag = false;
						//((UserData*)Save::GetData())->ins_ladder = false;
					}

				}

				//上移動を許可するブロック
				if (hero->GetBT() == 80)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->up_flag = true;//はしごがある時のみ上移動
						((UserData*)Save::GetData())->ladder_flag = false;
					}
				}
				else
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->up_flag = false;//はしごがある時のみ上移動
					}
				}

				//----------------------------------------------

				//-------------はしご処理（劣化）---------------

				//はしごを設置する場所を判定するブロック
				if (hero->GetBT() == 14)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
					{
						((UserData*)Save::GetData())->bad_ladder_flag = true;//ここで劣化はしごの設置場所を判定

						if (((UserData*)Save::GetData())->bad_ladder_put == true)
						{
							//((UserData*)Save::GetData())->up_flag = true;//はしごがある時のみ上移動

							//上移動を許可するためにブロックを書き換える
							if (m_map[i][j] == 26)
							{
								m_map[i][j] = 81;//上移動可能ブロックに書き換え
							}
						}


					}


				}
				else if (hero->GetBT() != 14)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
					{
						((UserData*)Save::GetData())->low_up_flag = false;
						((UserData*)Save::GetData())->bad_ladder_flag = false;
						//((UserData*)Save::GetData())->ins_ladder = false;
					}

				}

				//はしごの設置
				if (((UserData*)Save::GetData())->ins_bad_ladder == true && ((UserData*)Save::GetData())->bad_ladder > 0)
				{
					if (m_map[i][j] == 97)//はしご設置用の空間
					{

						if ((x / 64) - 1 <= ((hx + (-m_scroll)) / 64) && ((hx + (-m_scroll)) / 64) <= (x / 64) + 1)
						{

							if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
							{
								for (int f = 0;; f++) {
									if (m_map[i - f][j] == 97) {
										m_map[i - f][j] = 15;//はしご設置
									}
									else
									{

										//アイテムの設置音を鳴らす
										Audio::Start(1);

										((UserData*)Save::GetData())->item -= 1;
										((UserData*)Save::GetData())->bad_ladder -= 1;

										
										((UserData*)Save::GetData())->bad_ladder_put = true;//上移動の許可


										((UserData*)Save::GetData())->bad_ladder_flag = false;//ここではしごの設置場所を判定

										break;
									}
								}


							}
						}
					}

				}



				//上移動を許可するブロック
				if (hero->GetBT() == 81)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->low_up_flag = true;//はしごがある時のみ上移動
						((UserData*)Save::GetData())->bad_ladder_put = false;
					}
				}



				//-------------------------------------



				//------------板処理-----------------

				//板設置場所にプレイヤーがいると板が設置できる
				if (hero->GetBT() == 13 && ((UserData*)Save::GetData())->board_item > 0 || hero->GetBT() == 13 && ((UserData*)Save::GetData())->converted_board > 0)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
					{
						((UserData*)Save::GetData())->ins_place = true;
					}

				}
				else if (hero->GetBT() != 13)//i 8  j 18のとき板置きフラグ初期化バグ
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
					{
						((UserData*)Save::GetData())->ins_place = false;
						((UserData*)Save::GetData())->ins_flag = false;
					}
				}


				if (((UserData*)Save::GetData())->ins_flag == true)//設置場所一つ前のブロックに反応
				{
					if (m_map[i][j] == 99)//板設置用の穴
					{

						//if ((x / 64) - 1 <= ((hx + (-m_scroll)) / 64) && ((hx + (-m_scroll)) / 64) <= (x / 64) + 1)
						int blockx = (int)((32 + hx + (-m_scroll)) / 64);//式省略
						int blocky = (int)((32 + hy) / 64);
						if (m_map[blocky + 1][blockx] == 13)
						{


							for (int f = 1;; f++)
							{
								if (m_map[blocky + 1][blockx + f] == 99)
								{
									m_map[blocky + 1][blockx + f] = 12;

								}
								else
								{
									//アイテムの設置音を鳴らす
									Audio::Start(1);

									//アイテム使用時、変換済みアイテムを優先して使用する
									if (((UserData*)Save::GetData())->converted_board >= 1)
									{
										((UserData*)Save::GetData())->item -= 1;
										((UserData*)Save::GetData())->converted_item -= 1;
										((UserData*)Save::GetData())->converted_board -= 1;
									}
									else
									{
										((UserData*)Save::GetData())->item -= 1;
										((UserData*)Save::GetData())->board_item -= 1;
									}
									break;
								}
							}
						}



					}
				}

				//------------------------------------------


				//------------劣化板処理--------------------

					//劣化板設置場所にプレイヤーがいると劣化板が設置できる
				if (hero->GetBT() == 17 && ((UserData*)Save::GetData())->bad_board > 0)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->ins_bad_place = true;
					}

				}
				else if (hero->GetBT() != 17)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->ins_bad_place = false;
						((UserData*)Save::GetData())->ins_bad_flag = false;
					}
				}

				if (((UserData*)Save::GetData())->ins_bad_flag == true)//劣化板設置ブロックにいると反応する
				{
					if (m_map[i][j] == 99)//板設置用の穴
					{
						int blockx = (int)((32 + hx + (-m_scroll)) / 64);
						int blocky = (int)((32 + hy) / 64);

						if (m_map[blocky + 1][blockx] == 17)
						{
							if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
							{
								for (int f = 0;; f++) {
									if (m_map[i][j + f] == 99) {
										m_map[i][j + f] = 16;//板設置
									}
									else
									{
										//アイテムの設置音を鳴らす
										Audio::Start(1);

										((UserData*)Save::GetData())->item -= 1;
										((UserData*)Save::GetData())->bad_board -= 1;

										break;
									}
								}

							}
						}
					}
				}

			}
		}
	}
}




//ドロー
void CObjBlock2::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//背景表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);



	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			//ブロック
			if (m_map[i][j] == 1)
			{

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;



				//描画
				Draw::Draw(1, &src, &dst, c, 0.0f);

			}

			//ゴールブロック
			if (m_map[i][j] == 2)
			{
				//描画カラー情報
				float c[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(48, &src, &dst, c, 0.0f);
			}

			//ゴールポール
			if (m_map[i][j] == 91)
			{

				//描画カラー情報
				float c[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(47, &src, &dst, c, 0.0f);
			}

			//旗(ゴール)
			if (m_map[i][j] == 90)
			{

				//描画カラー情報
				float c[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 480.0f;
				src.m_bottom = 800.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}

			//障害物
			if (m_map[i][j] == 10)
			{

				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 512.0f;
				src.m_bottom = 512.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(18, &src, &dst, c2, 0.0f);
			}

			//障害物判定ブロック
			if (m_map[i][j] == 11)
			{

				float c2[4] = { 0.0f,1.0f,0.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;

				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//はしご用のブロック（ここで上る判定をつける）
			if (m_map[i][j] == 6)
			{

				//描画カラー情報
				float c2[4] = { 0.0f,1.0f,0.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//上の足場ブロック
			if (m_map[i][j] == 7)
			{
				//描画カラー情報
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//はしご（描画のみ）
			if (m_map[i][j] == 8)
			{

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;

				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(3, &src, &dst, c, 0.0f);


			}

			//はしご用のブロック（ここで上る判定をつける(劣化アイテム用)）
			if (m_map[i][j] == 14)
			{

				//描画カラー情報
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//板
			if (m_map[i][j] == 12)
			{

				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 230.0f;
				src.m_bottom = 40.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 10.0;

				//描画
				Draw::Draw(4, &src, &dst, c2, 0.0f);
			}

			//板判定ブロック
			if (m_map[i][j] == 13)
			{

				float c2[4] = { 0.0f,1.0f,0.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}


			//劣化はしご（描画のみ）
			if (m_map[i][j] == 15)
			{

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;

				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);


			}

			//劣化板
			if (m_map[i][j] == 16)
			{

				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 230.0f;
				src.m_bottom = 40.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 10.0;

				//描画
				Draw::Draw(51, &src, &dst, c2, 0.0f);
			}

			//劣化板判定ブロック
			if (m_map[i][j] == 17)
			{

				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(41, &src, &dst, c2, 0.0f);
			}

			//障害物判定ブロック（劣化つるはし用）
			if (m_map[i][j] == 18)
			{

				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;

				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//はしご用のブロック（ここで上る判定をつける）
			if (m_map[i][j] == 80)
			{

				//描画カラー情報
				float c2[4] = { 0.0f,1.0f,0.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//はしご用のブロック（劣化アイテム用・ここで上る判定をつける）
			if (m_map[i][j] == 81)
			{

				//描画カラー情報
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(41, &src, &dst, c2, 0.0f);
			}

			//はしご看板
			if (m_map[i][j] == 19)
			{

				//描画カラー情報
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//描画
				Draw::Draw(25, &src, &dst, c2, 0.0f);
			}

			//つるはし看板
			if (m_map[i][j] == 20)
			{

				//描画カラー情報
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//描画
				Draw::Draw(26, &src, &dst, c2, 0.0f);
			}

			//鉄板看板
			if (m_map[i][j] == 21)
			{

				//描画カラー情報
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//描画
				Draw::Draw(27, &src, &dst, c2, 0.0f);
			}

			//劣化はしご看板
			if (m_map[i][j] == 22)
			{

				//描画カラー情報
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//描画
				Draw::Draw(28, &src, &dst, c2, 0.0f);
			}

			//劣化つるはし看板
			if (m_map[i][j] == 23)
			{

				//描画カラー情報
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//描画
				Draw::Draw(29, &src, &dst, c2, 0.0f);
			}

			//劣化鉄板看板
			if (m_map[i][j] == 24)
			{

				//描画カラー情報
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//描画
				Draw::Draw(30, &src, &dst, c2, 0.0f);
			}

			//矢印看板
			if (m_map[i][j] == 26)
			{

				//描画カラー情報
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//描画
				Draw::Draw(49, &src, &dst, c2, 0.0f);
			}

			//看板棒
			if (m_map[i][j] == 25)
			{

				//描画カラー情報
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//描画
				Draw::Draw(31, &src, &dst, c2, 0.0f);
			}
		}
	}
}
