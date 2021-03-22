#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：はしご
class CObjLadder :public CObj
{
public:
	CObjLadder() {};
	~CObjLadder() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

private:
	int m_mapL[10][100];//マップ情報はしご用（仮）

	float m_scroll;//左右スクロール用

};