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
#include"SceneMainT.h"
#include"GameHead.h"

//コンストラクタ
CSceneMainT::CSceneMainT()
{
	((UserData*)Save::GetData())->stageT = true;
}

//デストラクタ
CSceneMainT::~CSceneMainT()
{

}

//初期化メソッド
void CSceneMainT::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImageW(L"aniani.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"ブロック.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"背景2.png", 2, TEX_SIZE_1024);
	Draw::LoadImageW(L"Ladder.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"鉄板.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"はしごアイテム.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"インベントリｍ２.png", 6, TEX_SIZE_512);
	Draw::LoadImageW(L"つるはし.png", 7, TEX_SIZE_512);
	Draw::LoadImageW(L"ポール.png", 14, TEX_SIZE_1024);
	Draw::LoadImageW(L"旗.png", 15, TEX_SIZE_1024);
	Draw::LoadImageW(L"空白欄.png", 16, TEX_SIZE_1024);
	Draw::LoadImageW(L"劣化はしご.png", 17, TEX_SIZE_512);
	Draw::LoadImageW(L"障害物.png", 18, TEX_SIZE_512);
	Draw::LoadImageW(L"説明画面（仮）.png", 19, TEX_SIZE_512);
	Draw::LoadImageW(L"空白欄(緑).png", 20, TEX_SIZE_1024);
	Draw::LoadImageW(L"空白欄(黄).png", 21, TEX_SIZE_1024);
	Draw::LoadImageW(L"空白欄(赤).png", 22, TEX_SIZE_1024);
	Draw::LoadImageW(L"空白欄(赤)バツ印.png", 23, TEX_SIZE_1024);
	Draw::LoadImageW(L"インベントリ(劣化).png", 24, TEX_SIZE_512);
	Draw::LoadImageW(L"はしご看板.png", 25, TEX_SIZE_512);
	Draw::LoadImageW(L"つるはし看板.png", 26, TEX_SIZE_512);
	Draw::LoadImageW(L"鉄板看板.png", 27, TEX_SIZE_512);
	Draw::LoadImageW(L"劣化はしご看板.png", 28, TEX_SIZE_512);
	Draw::LoadImageW(L"劣化つるはし看板.png", 29, TEX_SIZE_512);
	Draw::LoadImageW(L"劣化鉄板看板.png", 30, TEX_SIZE_512);
	Draw::LoadImageW(L"看板棒.png", 31, TEX_SIZE_512);
	Draw::LoadImageW(L"劣化はしごインベントリ.png", 32, TEX_SIZE_512);
	Draw::LoadImageW(L"劣化板インベントリ.png", 33, TEX_SIZE_512);
	Draw::LoadImageW(L"劣化つるはしインベントリ.png", 34, TEX_SIZE_512);
	Draw::LoadImageW(L"はしごインベントリ.png", 35, TEX_SIZE_512);
	Draw::LoadImageW(L"板インベントリ.png", 36, TEX_SIZE_512);
	Draw::LoadImageW(L"つるはしインベントリ.png", 37, TEX_SIZE_512);
	Draw::LoadImageW(L"変換はしごインベントリ.png", 38, TEX_SIZE_512);
	Draw::LoadImageW(L"変換板インベントリ.png", 39, TEX_SIZE_512);
	Draw::LoadImageW(L"変換つるはしインベントリ.png", 40, TEX_SIZE_512);
	Draw::LoadImageW(L"ブロック劣化.png", 41, TEX_SIZE_512);
	Draw::LoadImageW(L"操作説明（表示）.png", 46, TEX_SIZE_512);
	Draw::LoadImageW(L"新芽.png", 47, TEX_SIZE_512);
	Draw::LoadImageW(L"土ブロック.png", 48, TEX_SIZE_512);
	Draw::LoadImageW(L"矢印看板.png", 49, TEX_SIZE_512);
	Draw::LoadImageW(L"鉄板アイテム.png", 50, TEX_SIZE_512);
	Draw::LoadImageW(L"劣化鉄板.png", 51, TEX_SIZE_512);

	//アイテム数番号
	Draw::LoadImageW(L"0.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"1.png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"2.png", 10, TEX_SIZE_512);
	Draw::LoadImageW(L"3.png", 11, TEX_SIZE_512);
	Draw::LoadImageW(L"4.png", 12, TEX_SIZE_512);
	Draw::LoadImageW(L"5.png", 13, TEX_SIZE_512);
	Draw::LoadImageW(L"6.png", 42, TEX_SIZE_512);
	Draw::LoadImageW(L"7.png", 43, TEX_SIZE_512);
	Draw::LoadImageW(L"8.png", 44, TEX_SIZE_512);
	Draw::LoadImageW(L"9.png", 45, TEX_SIZE_512);

	//音楽読み込み
	Audio::LoadAudio(0, L"チュートリアルステージ.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"アイテム設置音.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(2, L"ブロックを破壊する音.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(3, L"ブロックを破壊する音.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(4, L"SEItemGet.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(5, L"アイテム変換音.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(6, L"アイテム取得.wav", SOUND_TYPE::EFFECT);

	//ボリュームを1.5増やす
	float v = Audio::VolumeMaster(0.0f);

	//音楽スタート
	Audio::Start(0);

	if (((UserData*)Save::GetData())->item <= 0)//アイテムが0を下回る時、0にする
	{
		((UserData*)Save::GetData())->item = 0;
	}



	////オブジェクト作成////

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlockT* objbT = new CObjBlockT();
	Objs::InsertObj(objbT, OBJ_BLOCKT, 9);

	//インベントリ作成
	CObjInventory* objin = new CObjInventory();
	Objs::InsertObj(objin, OBJ_INVENTORY, 10);

}

//実行中メソッド
void CSceneMainT::Scene()
{

}
