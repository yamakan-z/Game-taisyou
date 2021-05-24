#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjTime :public CObj
{
public:
	CObjTime() {};
	~CObjTime() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	
};
