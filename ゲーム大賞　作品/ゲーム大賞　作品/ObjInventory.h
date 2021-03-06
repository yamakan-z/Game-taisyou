#pragma once

//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjInventory :public CObj
{
public:
	CObjInventory() {};
	~CObjInventory() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

private:
	int m_mapR[10][100];//マップ情報（板）

	float m_scroll;//左右スクロール用

	float m_px;//位置
	float m_py;

	int flame;//フレーム計算用
	int s_time;
	int m_time;

	bool T_flag;//チュートリアル表示フラグ（一枚目）
	bool T_flag2;//チュートリアル（二枚目）
	bool T_flag3;//チュートリアル（三枚目）
	bool T_flag4;//チュートリアル（四枚目）
	
};