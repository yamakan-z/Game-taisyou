#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�͂���
class CObjLadder :public CObj
{
public:
	CObjLadder() {};
	~CObjLadder() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

private:
	int m_mapL[10][100];//�}�b�v���͂����p�i���j

	float m_scroll;//���E�X�N���[���p

};