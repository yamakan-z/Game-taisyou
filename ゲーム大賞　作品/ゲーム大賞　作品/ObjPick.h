#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjPick :public CObj
{
public:
	CObjPick() {};
	~CObjPick() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void posset(float x, float y) {
		m_px = x;//�}�b�v�����󂯎��
		m_py = y;
	}

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

private:
	int m_mapP[10][100];//�}�b�v���i���j

	float m_scroll;//���E�X�N���[���p

	float m_px;//�ʒu
	float m_py;
};