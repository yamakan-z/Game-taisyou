//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	 m_px=0.0f;//�ʒu
	 m_py=0.0f;
	 m_vx=0.0f;//�ړ��x�N�g��
	 m_vy=0.0f;
	 m_posture = 1.0f;//�E����0.0f������1.0f
}

//�A�N�V����
void CObjHero::Action()
{
	//�ړ��x�N�g���̔j��
	m_vx=0.0f;
	m_vy=0.0f;

	//�L�[�̓��͕���
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx = +1.0f;
		m_posture = 1.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx = -1.0f;
		m_posture = 0.0f;
	}

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

}

//�h���[
void CObjHero::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 656.0f;
	src.m_bottom = 800.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+m_py;
	dst.m_left =( 64.0f*m_posture)+m_px;
	dst.m_right = (64.0-64.0f*m_posture)+m_px;
	dst.m_bottom = 64.0f+m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}