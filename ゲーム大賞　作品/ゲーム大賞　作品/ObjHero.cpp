//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"ObjHero.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

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

	 m_ani_frame = 1;//�Î~�t���[���������ɂ���
	 m_ani_time = 0;

	 //block�Ƃ̏Փˏ�Ԋm�F
	 m_hit_up = false;
	 m_hit_down = false;
	 m_hit_left = false;
	 m_hit_right = false;
	 float m_ani_max_time = 4;//�A�j���[�V�����Ԋu��

	 //����ł���u���b�N�̎�ނ��m�F
	 m_block_type = 0;

	 //�����蔻��pHitBox���쐬
	 Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);

	 //�A�C�e����������ϊ�������t���O
	 conversionL = true;
	 conversionB = true;
	 conversionP = true;

}



//�A�N�V����
void CObjHero::Action()
{
	//�����ɂ��Q�[���I�[�o�[
	if (m_py > 1000.0f)
	{
		/*((UserData*)Save::GetData())->ladder_item = 0;
		((UserData*)Save::GetData())->item = 0;
		((UserData*)Save::GetData())->pick_item = 0;
		((UserData*)Save::GetData())->board_item = 0;*/
		//��O�ɏo���烊�X�^�[�g
		Scene::SetScene(new CSceneGameOver());
	}

	//�L�[�̓��͕���
	if (Input::GetVKey(VK_RIGHT) == true&& ((UserData*)Save::GetData())->move_flag == true)
	{
		//��l���̈ړ�����炷
		Audio::Start(3);

		m_vx = +5.0f;
		m_posture = 1.0f;
		m_ani_time += 1;                 //�um_ani_time += 1;�v�`��؂�ւ��@
	}

	else if (Input::GetVKey(VK_LEFT) == true&& ((UserData*)Save::GetData())->move_flag == true)
	{
		m_vx = -3.0f;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;//�L�[���͂��Ȃ��ꍇ�Î~�t���[���ɂ���
		m_ani_time = 0;
	}


	//�ݒu(�͂����j
	if (Input::GetVKey('A') == true && ((UserData*)Save::GetData())->ladder_flag == true)
	{
		((UserData*)Save::GetData())->ins_ladder = true;//�͂����ݒu�̃t���O

		//�ݒu��A�͂����A�C�e�����A�C�e������-1
		if (((UserData*)Save::GetData())->ins_ladder_done == true)
		{
			((UserData*)Save::GetData())->item -= 1;
			((UserData*)Save::GetData())->ladder_item -= 1;
			((UserData*)Save::GetData())->ins_ladder_done = false;
		}
	}
	else
	{
		((UserData*)Save::GetData())->ins_ladder = false;
	}


	//�͂����������Ԃ��Ə�ֈړ�
	if (((UserData*)Save::GetData())->up_flag == true&&Input::GetVKey(VK_UP) == true)
	{
		/*if (m_hit_down==true)
		{*/
			//��ړ����͍��E�ړ����󂯕t���Ȃ�
			((UserData*)Save::GetData())->move_flag = false;
			m_vy = -15.0f;
		/*}*/
		
	}
	
	//�ݒu(�j
	if (Input::GetVKey('X') == true&& ((UserData*)Save::GetData())->ins_place==true)
	{
		

		((UserData*)Save::GetData())->ins_flag = true;


		//�ݒu��A�A�C�e�����A�C�e������-1
	    if (((UserData*)Save::GetData())->ins_done == true)
	    {
			//�A�C�e���̐ݒu����炷
			Audio::Start(1);

		   ((UserData*)Save::GetData())->item -= 1;
		   ((UserData*)Save::GetData())->board_item -= 1;
		   ((UserData*)Save::GetData())->ins_done = false;
	    }

	}
	else
	{
		((UserData*)Save::GetData())->ins_flag = false;
	}
	
	//�ݒu(�͂����j
	if (Input::GetVKey('A') == true&&((UserData*)Save::GetData())->ladder_flag==true)
	{
		((UserData*)Save::GetData())->ins_ladder = true;//�͂����ݒu�̃t���O

		//�ݒu��A�͂����A�C�e�����A�C�e������-1
	    if (((UserData*)Save::GetData())->ins_ladder_done == true)
	     {
			//�A�C�e���̐ݒu����炷
			Audio::Start(1);

		     ((UserData*)Save::GetData())->item -= 1;
		     ((UserData*)Save::GetData())->ladder_item -= 1;
		     ((UserData*)Save::GetData())->ins_ladder_done = false;
	     }
	}

	//��Q���j��
	if (Input::GetVKey('W') == true&& ((UserData*)Save::GetData())->break_point==true)
	{

		((UserData*)Save::GetData())->break_flag = true;

		//�ݒu��A�͂����A�C�e�����A�C�e������-1
       if (((UserData*)Save::GetData())->break_done == true)
	      {
		   //�u���b�N�j�󉹂�炷
		   Audio::Start(2);

		     ((UserData*)Save::GetData())->item -= 1;
		     ((UserData*)Save::GetData())->pick_item -= 1;
		     ((UserData*)Save::GetData())->break_done = false;
	      }
	}
	else
	{
		((UserData*)Save::GetData())->break_flag = false;
	}



	//�A�C�e���̕ϊ�
	//���݂̕ϊ��@��͂������͂�������͂�...
	if (((UserData*)Save::GetData())->item > 0&& ((UserData*)Save::GetData())->conversion_num > 0)
	{
		//�ϊ��@��͂�����
		if (Input::GetVKey('1') == true && ((UserData*)Save::GetData())->pick_item > 0&& conversionB == true)
		{
			((UserData*)Save::GetData())->pick_item -= 1;
			((UserData*)Save::GetData())->board_item += 1;
			((UserData*)Save::GetData())->conversion_num -= 1;
			conversionB = false;
		}
		else if(Input::GetVKey('1')==false&& conversionB == false)
		{
			conversionB = true;
		}

		//�ϊ��@���͂���
		if (Input::GetVKey('2') == true && ((UserData*)Save::GetData())->board_item > 0 && conversionL == true)
		{
			((UserData*)Save::GetData())->board_item -= 1;
			((UserData*)Save::GetData())->ladder_item += 1;
			((UserData*)Save::GetData())->conversion_num -= 1;
			conversionL = false;
		}
		else if (Input::GetVKey('2') == false && conversionL == false)
		{
			conversionL = true;
		}

		//�ϊ��@�͂�������͂�
		if (Input::GetVKey('3') == true && ((UserData*)Save::GetData())->ladder_item > 0 && conversionP == true)
		{
			((UserData*)Save::GetData())->ladder_item -= 1;
			((UserData*)Save::GetData())->pick_item += 1;
			((UserData*)Save::GetData())->conversion_num -= 1;
			conversionP = false;
		}
		else if (Input::GetVKey('3') == false && conversionP == false)
		{
			conversionP = true;
		}


	}

	//���C
	m_vx += -(m_vx * 0.098);

	//���R�����^��
	m_vy += 9.8 / (16.0f);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//HitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);

}

//�h���[
void CObjHero::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	int AniData[4]
	{
		1,2,3,0,//�`�揇��
	};

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f+AniData[m_ani_frame] * 64;
	src.m_right =64.0f+AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py;
	dst.m_left   =( 64.0f*m_posture)+m_px;
	dst.m_right  = (64-64.0f*m_posture)+m_px;
	dst.m_bottom = 64.0f+m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}