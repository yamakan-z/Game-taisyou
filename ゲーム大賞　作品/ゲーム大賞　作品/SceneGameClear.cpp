//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneGameClear.h"
#include"GameHead.h"

//コンストラクタ
CSceneGameClear::CSceneGameClear()
{

}

//デストラクタ
CSceneGameClear::~CSceneGameClear()
{

}

//初期化メソッド
void CSceneGameClear::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"Game Clear");

	//ゲームクリアオブジェクト作成
	CObjGameClear* obj = new CObjGameClear();
	Objs::InsertObj(obj, OBJ_GAME_CLEAR, 10);
}

//実行中メソッド
void CSceneGameClear::Scene()
{

}
