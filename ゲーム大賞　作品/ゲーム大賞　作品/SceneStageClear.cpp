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
#include"SceneStageClear.h"
#include"GameHead.h"

//コンストラクタ
CSceneStageClear::CSceneStageClear()
{

}

//デストラクタ
CSceneStageClear::~CSceneStageClear()
{

}

//初期化メソッド
void CSceneStageClear::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"Next Stage:ENTER_KEY");

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"StageClear(仮).wav", SOUND_TYPE::BACK_MUSIC);

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0.0f);
	
	//音楽スタート
	Audio::Start(0);

	//ゲームクリアオブジェクト作成
	CObjStageClear* obj = new CObjStageClear();
	Objs::InsertObj(obj, OBJ_STAGE_CLEAR, 10);

	//画像読み込み
	Draw::LoadImageW(L"ステージクリア.png", 1, TEX_SIZE_1024);

	////オブジェクト作成
	CObjgameClearBackground* back = new CObjgameClearBackground();
	Objs::InsertObj(back, OBJ_GAME_CLEAR_BACKGROUND, 1);


}

//実行中メソッド
void CSceneStageClear::Scene()
{

}
