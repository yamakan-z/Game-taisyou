#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVX() { return m_vx; }
	float GetVY() { return m_vy; }

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	int GetBT() { return m_block_type; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
	void SetBT(int t) { m_block_type = t; }

private:
	float m_px;//�ʒu
	float m_py;
	float m_vx;//�ړ��x�N�g��
	float m_vy;
	float m_posture;//�p��


	int   m_ani_time;//�A�j���[�V��������Ԋu
	int   m_ani_frame;//�`��t���[��

	float m_ani_max_time;//�A�j���[�V�����ő哮��

	bool operation_keyflag;//������@�\���p�̃L�[�t���O

	bool retry_keyflag;//���g���C�p�̃L�[�t���O


	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//����ł���u���b�N�̎�ނ��m�F
	int m_block_type;

	//�A�C�e����������ϊ�������t���O
	bool conversionL;//�͂����p
	bool conversionB;//�p
	bool conversionP;//��͂��p

	//�L�[�𒷉��������Ƃ��ɏ�����ʂ��Ȃ�
	bool key_flagB;//�ݒu�̃L�[�t���O
	bool key_flagP;//��Q���j��̃L�[�t���O
	bool key_flagL;//�͂����ݒu�̃L�[�t���O
	//�򉻃A�C�e���p
	bool key_flagBB;//�򉻔ݒu�̃L�[�t���O
	bool key_flagBP;//��Q���j��̃L�[�t���O�i�򉻂�͂��j
	bool key_flagBL;//�򉻂͂����ݒu�̃L�[�t���O


};