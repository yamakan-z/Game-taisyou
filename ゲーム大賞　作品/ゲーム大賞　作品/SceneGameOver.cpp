//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"

#include"GameL\DrawTexture.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneGameOver.h"
#include"GameHead.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//初期化メソッド
void CSceneGameOver::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"NEXT_CHALLENGE:ENTER_KEY");

	//音楽読み込み
	Audio::LoadAudio(0, L"GameOver(仮).wav", BACK_MUSIC);

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);

	//ゲームオーバーオブジェクト作成
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
	
	//画像読み込み
	Draw::LoadImageW(L"ゲームオーバー3.png", 10, TEX_SIZE_1024);

	//オブジェクト作成
	CObjgameOverBackground* back = new CObjgameOverBackground();
	Objs::InsertObj(back, OBJ_GAME_OVER_BACKGROUND, 10);

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"GameOver(仮).wav", SOUND_TYPE::BACK_MUSIC);

	v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(0.1 - v);

	//音楽スタート
	Audio::Start(0);
}

//実行中メソッド
void CSceneGameOver::Scene()
{

}
