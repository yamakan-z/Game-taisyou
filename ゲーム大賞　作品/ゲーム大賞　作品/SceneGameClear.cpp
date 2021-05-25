//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"

#include"GameL\DrawTexture.h"
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
	Font::SetStrTex(L"Return_to_title:ENTER_KEY");

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

	//画像読み込み
	Draw::LoadImageW(L"ゲームクリア2.png", 1, TEX_SIZE_1024);

	//オブジェクト作成
	CObjgameClearBackground* back = new CObjgameClearBackground();
	Objs::InsertObj(back, OBJ_GAME_CLEAR_BACKGROUND, 1);

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"GameClear(仮).wav", SOUND_TYPE::BACK_MUSIC);

	v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(0.2 - v);

	//音楽スタート
	Audio::Start(0);
}

//実行中メソッド
void CSceneGameClear::Scene()
{

}
