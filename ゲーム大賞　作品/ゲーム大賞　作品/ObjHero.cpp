//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"ObjHero.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"
#include <thread>
#include <chrono>

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

	 m_ani_frame = 1;//静止フレームを初期にする
	 m_ani_time = 0;

	 //blockとの衝突状態確認
	 m_hit_up = false;
	 m_hit_down = false;
	 m_hit_left = false;
	 m_hit_right = false;
	 float m_ani_max_time = 4;//アニメーション間隔幅

	 //踏んでいるブロックの種類を確認
	 m_block_type = 0;

	 //操作方法表示用のキーフラグ
	 operation_keyflag = false;

	 //リトライ用のキーフラグ
	 retry_keyflag = false;

	 //当たり判定用HitBoxを作成
	 Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);

	 //アイテムを一つだけ変換させるフラグ
	 conversionL = true;
	 conversionB = true;
	 conversionP = true;

	 key_flagB = false;//板設置のキーフラグ
	 key_flagP = false;//障害物破壊のキーフラグ
	 key_flagL = false;

	 key_flagBB = false;
	 key_flagBP = false;
	 key_flagBL = false;

	 //フラグの初期化---------------------------------
	  
	//アイテム関係フラグ初期化
	 ((UserData*)Save::GetData())->item = 0;
	 ((UserData*)Save::GetData())->ladder_item = 0;
	 ((UserData*)Save::GetData())->pick_item = 0;
	 ((UserData*)Save::GetData())->board_item = 0;

	 //変換済アイテム
	 ((UserData*)Save::GetData())->converted_item = 0;//変換済みアイテムの総数
	 ((UserData*)Save::GetData())->converted_board = 0;//変換済み板アイテム
	 ((UserData*)Save::GetData())->converted_ladder = 0;//変換済みはしごアイテム
	 ((UserData*)Save::GetData())->converted_pick = 0;//変換済みつるはしアイテム

	 //劣化アイテム
	 ((UserData*)Save::GetData())->bad_board = 0;//劣化板アイテム
	 ((UserData*)Save::GetData())->bad_ladder = 0;//劣化はしごアイテム
	 ((UserData*)Save::GetData())->bad_pick = 0;//劣化つるはしアイテム


	 //ギミック関係フラグ初期化
	 //板関係のフラグ初期化
	 ((UserData*)Save::GetData())->ins_flag = false;
	 //((UserData*)Save::GetData())->ins_place = false;
	 //障害物関係のフラグ初期化
	 ((UserData*)Save::GetData())->break_flag = false;
	 //はしご関係のフラグ初期化
	 ((UserData*)Save::GetData())->ins_ladder = false;
	 ((UserData*)Save::GetData())->ladder = false;
	 ((UserData*)Save::GetData())->up_flag = false;


	 //劣化ギミック関係のフラグ破棄
	 //はしご関係のフラグ初期化
	 ((UserData*)Save::GetData())->ins_bad_ladder = false;
	 ((UserData*)Save::GetData())->bad_ladder_put = false;
	 ((UserData*)Save::GetData())->low_up_flag = false;
	 //板関係のフラグ初期化
	 ((UserData*)Save::GetData())->ins_bad_flag = false;
	 //障害物関係のフラグ初期化
	 ((UserData*)Save::GetData())->break_bad_flag = false;

	 ((UserData*)Save::GetData())->move_flag = true;

	 //ステージ毎によって変換可能回数変更
	 if (((UserData*)Save::GetData())->stage1 == true)
	 {
		 //変換回数を初期値に戻す
		 ((UserData*)Save::GetData())->conversion_num = 5;
	 }
	 //ステージ毎によって変換可能回数変更
	 if (((UserData*)Save::GetData())->stage2 == true)
	 {
		 //変換回数を初期値に戻す
		 ((UserData*)Save::GetData())->conversion_num = 7;
	 }
	 //ステージ毎によって変換可能回数変更
	 if (((UserData*)Save::GetData())->stage3 == true)
	 {
		 //変換回数を初期値に戻す
		 ((UserData*)Save::GetData())->conversion_num = 9;
	 }

	 //------------------------------------------

}



//アクション
void CObjHero::Action()
{
	//落下によるゲームオーバー
	if (m_py > 1000.0f)
	{
		//落下音
		Audio::Start(7);
		std::this_thread::sleep_for(std::chrono::seconds(2)); //開始時処理を2秒止める(落下SEを鳴らすため）
		//場外に出たらリスタート
		Scene::SetScene(new CSceneGameOver());
	}

	if (((UserData*)Save::GetData())->clear == true&& ((UserData*)Save::GetData())->stage1||
		((UserData*)Save::GetData())->clear == true && ((UserData*)Save::GetData())->stage2)
	{
		//シーンBGMを止める
		Audio::Stop(0);
		//クリアSE
		Audio::Start(8);
		std::this_thread::sleep_for(std::chrono::seconds(3)); //開始時処理を2秒止める(落下SEを鳴らすため）
		//ブロックに触れたらシーン移動
		Scene::SetScene(new CSceneStageClear());
	}
	else if (((UserData*)Save::GetData())->clear == true && ((UserData*)Save::GetData())->stage3)
	{
		//シーンBGMを止める
		Audio::Stop(0);
		//クリアSE
		Audio::Start(8);
		std::this_thread::sleep_for(std::chrono::seconds(3)); //開始時処理を2秒止める(落下SEを鳴らすため）
		//ブロックに触れたらシーン移動
		Scene::SetScene(new CSceneGameClear());
	}

	if (((UserData*)Save::GetData())->converted_board < 0 || ((UserData*)Save::GetData())->board_item < 0)
	{
		((UserData*)Save::GetData())->converted_board = 0;
		((UserData*)Save::GetData())->board_item = 0;
	}


	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true&& ((UserData*)Save::GetData())->move_flag == true)
	{
		m_vx = +5.0f;
		m_posture = 1.0f;
		m_ani_time += 1;                 //「m_ani_time += 1;」描画切り替え　
	}

	else if (Input::GetVKey(VK_LEFT) == true&& ((UserData*)Save::GetData())->move_flag == true)
	{
		m_vx = -5.0f;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;//キー入力がない場合静止フレームにする
		m_ani_time = 0;
	}

	if (m_ani_time > 15)//描画切り替え速度
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 1;
	}


	//設置(はしご）
	if (Input::GetVKey('A') == true && ((UserData*)Save::GetData())->ladder_flag == true)
	{
		if (key_flagL == true)
		{
			((UserData*)Save::GetData())->ins_ladder = true;//はしご設置のフラグ
			key_flagL = false;
		}
		
	}
	else
	{
		key_flagL = true;
		((UserData*)Save::GetData())->ins_ladder = false;
	}


	//設置(劣化はしご）
	if (Input::GetVKey('A') == true && ((UserData*)Save::GetData())->bad_ladder_flag == true)
	{
		if (key_flagBL ==true)
		{
			((UserData*)Save::GetData())->ins_bad_ladder = true;//はしご設置のフラグ
			key_flagBL = false;
		}
	
	}
	else
	{
		key_flagBL = true;
		((UserData*)Save::GetData())->ins_bad_ladder = false;
	}


	//はしごがある状態だと上へ移動
	if (((UserData*)Save::GetData())->up_flag == true&&Input::GetVKey(VK_UP) == true)
	{
			((UserData*)Save::GetData())->move_flag = false;
			m_vy = -20.0f;
	}

	//はしごがある状態だと上へ移動（劣化はしご用）
	if (((UserData*)Save::GetData())->low_up_flag == true && Input::GetVKey(VK_UP) == true)
	{
		//上移動時は左右移動を受け付けない
		((UserData*)Save::GetData())->move_flag = false;
		m_vy = -15.0f;

	}
	
	//板設置
	if (Input::GetVKey('S') == true&& ((UserData*)Save::GetData())->ins_place==true)
	{
		if (key_flagB == true)
		{
			((UserData*)Save::GetData())->ins_flag = true;
			key_flagB = false;

		}

	}
	else
	{
		((UserData*)Save::GetData())->ins_flag = false;
		key_flagB = true;
	}
	

	//劣化板設置
	if (Input::GetVKey('S') == true && ((UserData*)Save::GetData())->ins_bad_place == true)
	{

		if (key_flagBB == true)
		{
			((UserData*)Save::GetData())->ins_bad_flag = true;
			key_flagBB = false;
		}
		


	}
	else
	{
		key_flagBB = true;
		((UserData*)Save::GetData())->ins_bad_flag = false;
	}



	//障害物破壊
	if (Input::GetVKey('D') == true&& ((UserData*)Save::GetData())->break_point==true)
	{
		if (key_flagP== true)
		{
			((UserData*)Save::GetData())->break_flag = true;
			key_flagP = false;
		}
		
	}
	else
	{
		((UserData*)Save::GetData())->break_flag = false;
		key_flagP = true;
	}

	//障害物破壊(劣化つるはし）
	if (Input::GetVKey('D') == true && ((UserData*)Save::GetData())->break_bad_point == true)
	{
		if (key_flagBP == true)
		{
			((UserData*)Save::GetData())->break_bad_flag = true;
			key_flagBP = false;
		}
		

		
	}
	else
	{
		((UserData*)Save::GetData())->break_bad_flag = false;
		key_flagBP = true;
	}

	//説明画面表示
	if (Input::GetVKey('W') == true)
	{
		Audio::Start(9);
		operation_keyflag = true;
		retry_keyflag = true;//説明画面表示時のみリトライ可能
	}
	else if (Input::GetVKey('E') == true&& operation_keyflag == true)
	{
		Audio::Start(10);
		operation_keyflag = false;
		retry_keyflag = false;
	}


	//リトライ
	if (Input::GetVKey(VK_SPACE) == true&& retry_keyflag == true&& ((UserData*)Save::GetData())->stage1)
	{
		Scene::SetScene(new CSceneMain());
	}
	else if (Input::GetVKey(VK_SPACE) == true && retry_keyflag == true && ((UserData*)Save::GetData())->stage2)
	{
		Scene::SetScene(new CSceneMain2());
	}
	else if (Input::GetVKey(VK_SPACE) == true && retry_keyflag == true && ((UserData*)Save::GetData())->stage3)
	{
		Scene::SetScene(new CSceneMain3());
	}

	if (Input::GetVKey(VK_SPACE) == true && retry_keyflag == true && ((UserData*)Save::GetData())->stageT)
	{
		if (((UserData*)Save::GetData())->key_flagT == true)
		{
			Scene::SetScene(new CSceneTitle());
			((UserData*)Save::GetData())->key_flagT = false;
		}
	}
	else
	{
		((UserData*)Save::GetData())->key_flagT = true;
	}


	//アイテムの変換
	//現在の変換　つるはし→板→はしご→つるはし...
	if (((UserData*)Save::GetData())->item > 0 && ((UserData*)Save::GetData())->conversion_num > 0)
	{
		//変換済みアイテム→劣化アイテムの変換
		//変換済みアイテムを優先して変換させる
		if (((UserData*)Save::GetData())->converted_item > 0)
		{
			//変換　変換済みつるはし→劣化板
			if (Input::GetVKey(VK_F1) == true && ((UserData*)Save::GetData())->converted_pick > 0 && conversionB == true)
			{
				Audio::Start(5);

				((UserData*)Save::GetData())->converted_pick -= 1;
				((UserData*)Save::GetData())->bad_board += 1;

				((UserData*)Save::GetData())->converted_item -= 1;

				((UserData*)Save::GetData())->conversion_num -= 1;
				conversionB = false;

			}
			else if (Input::GetVKey(VK_F1) == false && conversionB == false)
			{
				conversionB = true;
			}

			//変換　変換済み板→劣化はしご
			if (Input::GetVKey(VK_F2) == true && ((UserData*)Save::GetData())->converted_board > 0 && conversionL == true)
			{
				Audio::Start(5);

				((UserData*)Save::GetData())->converted_board -= 1;
				((UserData*)Save::GetData())->bad_ladder += 1;

				((UserData*)Save::GetData())->converted_item -= 1;

				((UserData*)Save::GetData())->conversion_num -= 1;
				conversionL = false;

			}
			else if (Input::GetVKey(VK_F2) == false && conversionL == false)
			{
				conversionL = true;
			}

			//変換　変換済みはしご→劣化つるはし
			if (Input::GetVKey(VK_F3) == true && ((UserData*)Save::GetData())->converted_ladder > 0 && conversionP == true)
			{
				Audio::Start(5);

				((UserData*)Save::GetData())->converted_ladder -= 1;
				((UserData*)Save::GetData())->bad_pick += 1;

				((UserData*)Save::GetData())->converted_item -= 1;


				((UserData*)Save::GetData())->conversion_num -= 1;
				conversionP = false;
			}
			else if (Input::GetVKey(VK_F3) == false && conversionP == false)
			{
				conversionP = true;
			}
		}

		//未変換アイテム→変換済みアイテム
		else
		{
			//変換　つるはし→変換済み板
			if (Input::GetVKey(VK_F1) == true && ((UserData*)Save::GetData())->pick_item > 0 && conversionB == true)
			{

				Audio::Start(5);

				((UserData*)Save::GetData())->pick_item -= 1;
				((UserData*)Save::GetData())->converted_board += 1;
				//((UserData*)Save::GetData())->board_item += 1;
				((UserData*)Save::GetData())->converted_item += 1;


				((UserData*)Save::GetData())->conversion_num -= 1;
				conversionB = false;
			}
			else if (Input::GetVKey(VK_F1) == false && conversionB == false)
			{
				conversionB = true;
			}

			//変換　板→変換済みはしご
			if (Input::GetVKey(VK_F2) == true && ((UserData*)Save::GetData())->board_item > 0 && conversionL == true)
			{
				Audio::Start(5);

				((UserData*)Save::GetData())->board_item -= 1;
				//((UserData*)Save::GetData())->ladder_item += 1;
				((UserData*)Save::GetData())->converted_ladder += 1;

				((UserData*)Save::GetData())->converted_item += 1;
				((UserData*)Save::GetData())->conversion_num -= 1;
				conversionL = false;
			}
			else if (Input::GetVKey(VK_F2) == false && conversionL == false)
			{
				conversionL = true;
			}

			//変換　はしご→変換済みつるはし
			if (Input::GetVKey(VK_F3) == true && ((UserData*)Save::GetData())->ladder_item > 0 && conversionP == true)
			{
				Audio::Start(5);

				((UserData*)Save::GetData())->ladder_item -= 1;
				//((UserData*)Save::GetData())->pick_item += 1;
				((UserData*)Save::GetData())->converted_pick += 1;

				((UserData*)Save::GetData())->converted_item += 1;
				((UserData*)Save::GetData())->conversion_num -= 1;
				conversionP = false;
			}
			else if (Input::GetVKey(VK_F3) == false && conversionP == false)
			{
				conversionP = true;
			}
		}

	}

	//摩擦
	m_vx += -(m_vx * 0.198);

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

	int AniData[4]
	{
		2,1,0,3,//描画順序
	};

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f+AniData[m_ani_frame] * 64;
	src.m_right =64.0f+AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top    = 0.0f + m_py;
	dst.m_left   =( 64.0f*m_posture)+m_px;
	dst.m_right  = (64-64.0f*m_posture)+m_px;
	dst.m_bottom = 64.0f+m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);


	//説明画面（仮）
	if (operation_keyflag == true)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;


		//表示位置の設定
		dst.m_top = 100.0;
		dst.m_left = 160.0;
		dst.m_right = dst.m_right = dst.m_left + 500.0;
		dst.m_bottom = dst.m_top + 500.0;

		//描画
		Draw::Draw(19, &src, &dst, c, 0.0f);
	}
		

	
	
}