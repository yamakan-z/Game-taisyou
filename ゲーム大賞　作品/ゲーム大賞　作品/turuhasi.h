#pragma once

#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjturuhasi :public CObj
{
public:
	CObjturuhasi(float x, float y);
	~CObjturuhasi() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
};