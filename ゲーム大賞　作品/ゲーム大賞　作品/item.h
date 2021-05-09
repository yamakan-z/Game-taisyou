#pragma once

#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjitem :public CObj
{
public:
	CObjitem(float x, float y);
	~CObjitem() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	int m_hp;
	int hirumatest;
};