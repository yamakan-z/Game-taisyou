#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_BLOCK,
	OBJ_ITEM,
	OBJ_TURUHASI,
	OBJ_TITLE,
	OBJ_GAME_CLEAR,
	OBJ_GAME_OVER,
	OBJ_LADDER,
	OBJ_BOARD,
	OBJ_ROCK,
	OBJ_INVENTORY,
	//はしごアイテム
	OBJ_LADDER_ITEM,
	OBJ_LADDER_ITEM2,
	//つるはし
	OBJ_PICK,
	OBJ_BOARD_ITEM,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_PICK,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	bool up_flag = false;  //はしごがある時、上に上がるフラグ
	bool move_flag = true; //上移動時、左右移動を制限するフラグ
	float item = 0;  //アイテム所持数
	//板関係フラグ
	bool ins_flag = false; //設置フラグ（板）
	bool ins_place = false;//設置場所管理(板）
	float board_item = 0;//板アイテム所持フラグ
	bool ins_done = false;//板設置終了フラグ（今のところは、これがないと板が全部表示されない）
	//はしご関係フラグ
	bool ins_ladder = false;//はしご設置
	bool ladder_flag = false;//はしごの設置場所を判定
	bool ladder = false;//はしごの有無
	float ladder_item = 0;//はしごアイテム所持フラグ
	bool ins_ladder_done = false;//はしご設置終了フラグ（今のところは、これがないとはしごが全部表示されない）
	//障害物関係フラグ
	bool break_flag = false;//障害物破壊フラグ
	bool break_point = false;//障害物破壊判定
	float pick_item = 0;//つるはし所持数


};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include"ObjHero.h"
#include"ObjBlock.h"
#include"ObjLadder.h"
#include"ObjBoard.h"
#include"ObjRock.h"
#include"LadderItem.h"
#include"BoardItem.h"


#include"ObjInventory.h"
#include"ObjTitle.h"
#include"ObjGameClear.h"
#include"ObjGameOver.h"
//つるはし
#include"ObjPick.h"

//はしごアイテム
#include"LadderItem.h"
#include"LadderItem2.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include"SceneMain.h"
#include"SceneTitle.h"
#include"SceneGameOver.h"
#include"SceneGameClear.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------