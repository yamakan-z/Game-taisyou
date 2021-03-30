#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：つるはし＆背景
class CObjTuruhasi :public CObj
{
public:
	CObjTuruhasi() {};
	~CObjTuruhasi() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	int m_map[10][100];//マップ情報（仮）
};