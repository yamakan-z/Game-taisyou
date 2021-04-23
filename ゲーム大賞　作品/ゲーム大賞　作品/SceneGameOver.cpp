//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

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
	Font::SetStrTex(L"YOU LOST");
	Font::SetStrTex(L"GAME　OVER");
	Font::SetStrTex(L"NEXT_CHALLENGE:ENTER_KEY");

	//ゲームオーバーオブジェクト作成
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);


	//音楽情報の読み込み
	Audio::LoadAudio(0, L"GameOver(仮).wav", SOUND_TYPE::BACK_MUSIC);

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);
}

//実行中メソッド
void CSceneGameOver::Scene()
{

}
