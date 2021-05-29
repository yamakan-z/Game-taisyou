#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVX() { return m_vx; }
	float GetVY() { return m_vy; }

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	int GetBT() { return m_block_type; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
	void SetBT(int t) { m_block_type = t; }

private:
	float m_px;//位置
	float m_py;
	float m_vx;//移動ベクトル
	float m_vy;
	float m_posture;//姿勢


	int   m_ani_time;//アニメーション動作間隔
	int   m_ani_frame;//描画フレーム

	float m_ani_max_time;//アニメーション最大動作

	bool operation_keyflag;//操作方法表示用のキーフラグ

	bool retry_keyflag;//リトライ用のキーフラグ


	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//踏んでいるブロックの種類を確認
	int m_block_type;

	//アイテムを一つだけ変換させるフラグ
	bool conversionL;//はしご用
	bool conversionB;//板用
	bool conversionP;//つるはし用

	//キーを長押ししたときに処理を通さない
	bool key_flagB;//板設置のキーフラグ
	bool key_flagP;//障害物破壊のキーフラグ
	bool key_flagL;//はしご設置のキーフラグ
	//劣化アイテム用
	bool key_flagBB;//劣化板設置のキーフラグ
	bool key_flagBP;//障害物破壊のキーフラグ（劣化つるはし）
	bool key_flagBL;//劣化はしご設置のキーフラグ


};