//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"


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
	Draw::LoadImageW(L"仮主人公.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"ブロック.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"背景.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"Ladder.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"板アイテム.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"はしごアイテム.png", 5, TEX_SIZE_512);
	
	//


	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//ladderオブジェクト作成
	CObjLadder* objl = new CObjLadder();
	Objs::InsertObj(objl, OBJ_LADDER, 10);

	//boardオブジェクト作成
	CObjBoard* objbo = new CObjBoard();
	Objs::InsertObj(objbo, OBJ_BOARD, 10);

	//rockオブジェクト作成
	CObjRock* objr = new CObjRock();
	Objs::InsertObj(objr, OBJ_BOARD, 10);

	//rockオブジェクト作成
	CLadderItem* objli = new CLadderItem();
	Objs::InsertObj(objli, OBJ_LADDER_ITEM, 10);

	//plateオブジェクト作成
	CBoardItem* objbi = new CBoardItem();
	Objs::InsertObj(objbi, OBJ_BOARD_ITEM, 10);

}

//実行中メソッド
void CSceneMain::Scene()
{

}
