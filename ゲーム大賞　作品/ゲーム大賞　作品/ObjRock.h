#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjRock :public CObj
{
public:
	CObjRock() {};
	~CObjRock() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

private:
	int m_mapR[10][100];//マップ情報（板）

	float m_scroll;//左右スクロール用

};
