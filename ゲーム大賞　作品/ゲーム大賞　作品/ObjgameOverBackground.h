#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjgameOverBackground :public CObj
{
public:
	CObjgameOverBackground() {};
	~CObjgameOverBackground() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
};