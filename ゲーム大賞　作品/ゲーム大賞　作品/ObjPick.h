#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjPick :public CObj
{
public:
	CObjPick() {};
	~CObjPick() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void posset(float x, float y) {
		m_px = x;//マップ情報を受け取る
		m_py = y;
	}

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

private:
	int m_mapP[10][100];//マップ情報（仮）

	float m_scroll;//左右スクロール用

	float m_px;//位置
	float m_py;
};