#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��͂����w�i
class CObjTuruhasi :public CObj
{
public:
	CObjTuruhasi() {};
	~CObjTuruhasi() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	int m_map[10][100];//�}�b�v���i���j
};