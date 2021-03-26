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
	////グラフィック読み込み////

	//主人公
	Draw::LoadImageW(L"Hero_ani.png", 0, TEX_SIZE_512);
	//ブロック
	Draw::LoadImageW(L"ブロック.png", 1, TEX_SIZE_512);
	//背景グラフィック
	Draw::LoadImageW(L"背景.png", 2, TEX_SIZE_512);


	////オブジェクト作成////

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 9);
}

//実行中メソッド
void CSceneMain::Scene()
{

}
