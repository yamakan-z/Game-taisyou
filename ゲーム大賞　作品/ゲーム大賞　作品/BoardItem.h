#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CBoardItem :public CObj
{
public:
	CBoardItem() {};
	~CBoardItem() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	void posset(float x, float y) {
		m_px = x;//�}�b�v�����󂯎��
		m_py = y;
	}

private:
	int m_mapR[10][100];//�}�b�v���i�j

	float m_scroll;//���E�X�N���[���p

	float m_px;//�ʒu
	float m_py;

};