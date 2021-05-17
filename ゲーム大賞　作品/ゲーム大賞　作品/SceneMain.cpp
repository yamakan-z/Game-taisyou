//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL/UserData.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//初期化メソッド
void CSceneMain::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImageW(L"Hero_ani.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"ブロック.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"背景2.png", 2, TEX_SIZE_1024);
	Draw::LoadImageW(L"Ladder.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"板.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"はしごアイテム.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"インベントリｍ２.png", 6, TEX_SIZE_512);
	Draw::LoadImageW(L"つるはし.png", 7, TEX_SIZE_512);
	Draw::LoadImageW(L"ポール.png", 14, TEX_SIZE_1024);
	Draw::LoadImageW(L"旗.png", 15, TEX_SIZE_1024);
	Draw::LoadImageW(L"空白欄.png", 16, TEX_SIZE_1024);
	Draw::LoadImageW(L"劣化はしご.png", 17, TEX_SIZE_512);
	Draw::LoadImageW(L"障害物.png", 18, TEX_SIZE_512);
	Draw::LoadImageW(L"説明画面（仮）.png", 19, TEX_SIZE_512);
	//アイテム数番号
	Draw::LoadImageW(L"0.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"1.png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"2.png", 10, TEX_SIZE_512);
	Draw::LoadImageW(L"3.png", 11, TEX_SIZE_512);
	Draw::LoadImageW(L"4.png", 12, TEX_SIZE_512);
	Draw::LoadImageW(L"5.png", 13, TEX_SIZE_512);

	Draw::LoadImageW(L"ポール.png", 14, TEX_SIZE_1024);
	Draw::LoadImageW(L"旗.png", 15, TEX_SIZE_1024);
	Draw::LoadImageW(L"空白欄.png", 16, TEX_SIZE_1024);
	Draw::LoadImageW(L"空白欄(緑).png", 17, TEX_SIZE_1024);
	Draw::LoadImageW(L"空白欄(黄).png", 18, TEX_SIZE_1024);
	Draw::LoadImageW(L"空白欄(赤).png", 19, TEX_SIZE_1024);
	Draw::LoadImageW(L"空白欄(赤)バツ印.png", 20, TEX_SIZE_1024);
	Draw::LoadImageW(L"インベントリ(劣化).png", 21, TEX_SIZE_512);

	//音楽読み込み
	Audio::LoadAudio(0, L"GameMain(仮).wav", BACK_MUSIC);

	Audio::LoadAudio(1, L"アイテム設置音.wav", EFFECT);
	Audio::LoadAudio(2, L"ブロックを破壊する音.wav", EFFECT);
	Audio::LoadAudio(3, L"主人公の移動音.wav",EFFECT);
	Audio::LoadAudio(4, L"SEItemGet.wav", EFFECT);

	//ボリュームを1.5増やす
	float v = Audio::VolumeMaster(1.0);

	//ボリュームを1.0に戻す
	v = Audio::VolumeMaster(0.0);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	//Audio::Start(0);

	if (((UserData*)Save::GetData())->item <= 0)//アイテムが0を下回る時、0にする
	{
		((UserData*)Save::GetData())->item = 0;
	}



	////オブジェクト作成////

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//インベントリ作成
	CObjInventory* objin = new CObjInventory();
	Objs::InsertObj(objin, OBJ_INVENTORY, 10);

	//はしごアイテム作成
//	CLadderItem* objli = new CLadderItem();
//	Objs::InsertObj(objli, OBJ_LADDER_ITEM, 10);

	////つるはし作成
	//CObjPick* objp = new CObjPick();
	//Objs::InsertObj(objp, OBJ_PICK, 10);

	////boardアイテムオブジェクト作成
	//CBoardItem* objbi = new CBoardItem();
	//Objs::InsertObj(objbi, OBJ_BOARD_ITEM, 10);

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"GameMain(仮).wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"アイテム設置音.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(3, L"ブロックを破壊する音.wav", SOUND_TYPE::EFFECT);

	//ボリュームを1.0に戻す
    v = Audio::VolumeMaster(0.0);
	v = Audio::VolumeMaster((0.1 - v));

}

//実行中メソッド
void CSceneMain::Scene()
{

}
