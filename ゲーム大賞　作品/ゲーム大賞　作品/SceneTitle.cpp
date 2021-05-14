//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\Audio.h"


//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include"SceneMain.h"
#include"GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//出力される文字のグラフィックを作成
	Font::SetStrTex(L"タイトル");

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"GameTitle(仮).wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0));

	//音楽スタート
	Audio::Start(0);

	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_TITLE, 10);//主人公オブジェクト登録

	//画像読み込み
	Draw::LoadImageW(L"タイトル.png", 1, TEX_SIZE_1024);

	//オブジェクト作成
	CObjTitleBackground* back = new CObjTitleBackground();
	Objs::InsertObj(back, OBJ_TITLE_BACKGROUND, 1);
	
	//音楽情報の読み込み
	Audio::LoadAudio(0, L"GameTitle(仮).wav", SOUND_TYPE::BACK_MUSIC);

	v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(0.1 - v);

	//音楽スタート
	Audio::Start(0);
	
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}