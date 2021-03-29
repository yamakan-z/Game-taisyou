//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjHero.h"
#include "GameL/UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	 m_px=100.0f;//�ʒu
	 m_py=510.0f;
	 m_vx=0.0f;//�ړ��x�N�g��
	 m_vy=0.0f;
	 m_posture = 1.0f;//�E����0.0f������1.0f

	 //block�Ƃ̏Փˏ�Ԋm�F
	 m_hit_up = false;
	 m_hit_down = false;
	 m_hit_left = false;
	 m_hit_right = false;

	 //����ł���u���b�N�̎�ނ��m�F
	 m_block_type = 0;

}

//�A�N�V����
void CObjHero::Action()
{
	//�����ɂ��Q�[���I�[�o�[
	if (m_py > 1000.0f)
	{
		//��O�ɏo���烊�X�^�[�g
		Scene::SetScene(new CSceneGameOver());
	}

	//�L�[�̓��͕���
	if (Input::GetVKey(VK_RIGHT) == true&& ((UserData*)Save::GetData())->move_flag == true)
	{
		m_vx = +5.0f;
		m_posture = 1.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true&& ((UserData*)Save::GetData())->move_flag == true)
	{
		m_vx = -5.0f;
		m_posture = 0.0f;
	}

	//�͂����������Ԃ��Ə�ֈړ�
	if (((UserData*)Save::GetData())->up_flag == true&&Input::GetVKey(VK_UP) == true)
	{
		if (m_hit_down==true)
		{
			//��ړ����͍��E�ړ����󂯕t���Ȃ�
			((UserData*)Save::GetData())->move_flag = false;
			m_vy = -15.0f;
		}
		
	}
	
	//�ݒu(�j
	if (Input::GetVKey('X') == true&& ((UserData*)Save::GetData())->ins_place==true)
	{
		((UserData*)Save::GetData())->ins_flag = true;
	}
	
	//�ݒu(�͂����j
	if (Input::GetVKey('A') == true&&((UserData*)Save::GetData())->ladder_flag==true)
	{
		((UserData*)Save::GetData())->ins_ladder = true;
	}

	//��Q���j��
	if (Input::GetVKey('W') == true&& ((UserData*)Save::GetData())->break_point==true)
	{
		((UserData*)Save::GetData())->break_flag = true;
	}

	//���C
	m_vx += -(m_vx * 0.098);

	//���R�����^��
	m_vy += 9.8 / (16.0f);

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