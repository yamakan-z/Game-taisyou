//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"

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

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"GameClear(仮).wav", BACK_MUSIC);

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1.0 - v);

	//音楽スタート
	Audio::Start(0);

	//ゲームクリアオブジェクト作成
	CObjGameClear* obj = new CObjGameClear();
	Objs::InsertObj(obj, OBJ_GAME_CLEAR, 10);
}

//実行中メソッド
void CSceneGameClear::Scene()
{

}
