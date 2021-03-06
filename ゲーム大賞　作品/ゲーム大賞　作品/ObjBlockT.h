#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjBlockT :public CObj
{
public:
	CObjBlockT() {};
	~CObjBlockT() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void Item_Spawn();//マップの情報を参照してアイテム生成場所を決定する


	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

private:
	int m_map[10][100];//マップ情報（仮）

	float m_scroll = 0;//左右スクロール用

	float m_px;//位置
	float m_py;

	int p;
	int q;

	bool T_flag;

};
