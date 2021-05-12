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
	OBJ_TITLE_BACKGROUND,
	OBJ_GAME_OVER_BACKGROUND,
	OBJ_GAME_CLEAR_BACKGROUND,

	//はしごアイテム
	OBJ_LADDER_ITEM,

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

	//主人公関係のフラグ
	bool up_flag = false;  //はしごがある時、上に上がるフラグ
	bool low_up_flag = false;//はしごがある時、上に上がるフラグ（劣化アイテム用）
	bool move_flag = true; //上移動時、左右移動を制限するフラグ
	

	//板関係フラグ
	bool ins_flag = false; //設置フラグ（板）
	bool ins_place = false;//設置場所管理(板）
	bool ins_done = false;//板設置終了フラグ（今のところは、これがないと一つのアイテムが2つ使用されるため）

	//劣化板関係フラグ
	bool ins_bad_flag = false; //劣化板設置フラグ
	bool ins_bad_place = false;//劣化板設置場所管理
	bool ins_bad_done = false;//劣化板設置終了フラグ（今のところは、これがないと一つのアイテムが2つ使用されるため）

	//はしご関係フラグ
	bool ins_ladder = false;//はしご設置
	bool ladder_flag = false;//はしごの設置場所を判定
	bool ladder = false;//はしごの有無
	bool ins_ladder_done = false;//はしご設置終了フラグ（今のところは、これがないとはしごが全部表示されない）

	//はしご関係フラグ（劣化）
	bool bad_ladder_flag = false;//劣化はしごの設置場所を判定
	bool ins_bad_ladder = false;//劣化はしご設置
	bool bad_ladder_put = false;//劣化はしごの有無
	bool ins_bad_ladder_done = false;//劣化はしご設置終了フラグ（今のところは、これがないとはしごが全部表示されない）

	//障害物関係フラグ
	bool break_flag = false;//障害物破壊フラグ
	bool break_point = false;//障害物破壊判定
	bool break_done = false;//障害物破壊終了フラグ（今のところは、これがないと一つのアイテムが2つ使用されるため）

	//障害物関係フラグ(劣化つるはし用）
	bool break_bad_flag = false;//障害物破壊フラグ(劣化つるはし用）
	bool break_bad_point = false;//障害物破壊判定(劣化つるはし用）
	bool break_bad_done = false;//障害物破壊終了フラグ（今のところは、これがないと一つのアイテムが2つ使用されるため）(劣化つるはし用）

	//アイテム数
	float item = 0;  //アイテム所持数
	float board_item = 0;//板アイテム所持数
	float ladder_item = 0;//はしごアイテム所持数
	float pick_item = 0;//つるはし所持数

	//変換済アイテム
	float converted_item = 0;//変換済みアイテムの総数
	float converted_board = 0;//変換済み板アイテム
	float converted_ladder = 0;//変換済みはしごアイテム
	float converted_pick = 0;//変換済みつるはしアイテム

	//劣化アイテム
	float bad_board = 0;//劣化板アイテム
	float bad_ladder = 0;//劣化はしごアイテム
	float bad_pick = 0;//劣化つるはしアイテム

	//のこり変換回数
	int conversion_num = 5;
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include"ObjHero.h"
#include"ObjBlock.h"
#include"ObjPick.h"
#include"LadderItem.h"
#include"BoardItem.h"
#include"ObjTitleBackground.h"
#include"ObjgameOverBackground.h"
#include"ObjgameClearBackground.h"

#include"ObjInventory.h"
#include"ObjTitle.h"
#include"ObjGameClear.h"
#include"ObjGameOver.h"



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