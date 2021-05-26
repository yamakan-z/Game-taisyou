//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjInventory.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"
#include "GameL/DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


////�R���X�g���N�^
//CObjInventory::CObjInventory()
//{
//	
//}

// �C�j�V�����C�Y
void CObjInventory::Init()
{
	float m_scroll;//���E�X�N���[���p

	m_px = 500.0f;//�ʒu
	m_py = -50.0f;

	flame = 0;//�t���[���v�Z
	s_time = 0;
	m_time = 0;

	((UserData*)Save::GetData())->save_s_time = 0;//�Z�[�u�pm_time������
	((UserData*)Save::GetData())->save_m_time = 0;//�Z�[�u�ps_time������

}


//�A�N�V����
void CObjInventory::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//�^�C�}�[
	if (hero->GetBT() != 2)
	{
		flame++;
		//flame��60�����1�b�J�E���g
		if (flame == 60)
		{
			flame = 0;
			s_time++;
			//s_time++�̎��_�ŃZ�[�u�ps_time���C���N�������g
			((UserData*)Save::GetData())->save_s_time++;
		}
		//s_time��60��1���ł�
		if (s_time == 60)
		{
			s_time = 0;
			m_time++;
			//m_time++�̎��_�ŃZ�[�u�pm_time���C���N�������g
			((UserData*)Save::GetData())->save_m_time++;
			((UserData*)Save::GetData())->save_s_time = 0;
		}
	}

}

//�h���[
void CObjInventory::Draw()
{

	//�t���O�m�F�p
	wchar_t str[256];

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 1.0f,0.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//��l�����������Ă���
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	if (((UserData*)Save::GetData())->stage1 == true)
	{
		//�u���b�N���������Ă���
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		swprintf_s(str, L"X=%.0f,Y=%.0f", (hero->GetX() - block->GetScroll()) / 64, hero->GetY() / 64);
		Font::StrDraw(str, 10, 120, 20, c);
	}


	if (((UserData*)Save::GetData())->ins_place == true)
	{
		swprintf_s(str, L"ins_place");
		Font::StrDraw(str, 10, 490, 20, d);
	}
	if (((UserData*)Save::GetData())->ins_flag == true)
	{
		swprintf_s(str, L"ins_flag");
		Font::StrDraw(str, 10, 520, 20, d);
	}

	if (((UserData*)Save::GetData())->ladder_flag == true)
	{
		swprintf_s(str, L"ladder_flag");
		Font::StrDraw(str, 10, 540, 20, d);
	}

	if (((UserData*)Save::GetData())->up_flag == true)
	{
		swprintf_s(str, L"up_flag");
		Font::StrDraw(str, 10, 560, 20, d);
	}

	swprintf_s(str, L"�^�C���@%02d:%02d", m_time, s_time);
	Font::StrDraw(str, 10, 200, 20, c);


	//��������A�C�R���\��

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 128.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = 100.0;
	dst.m_left = 550.0;
	dst.m_right = dst.m_right = dst.m_left + 220.0;
	dst.m_bottom = dst.m_top + 100.0;

	//�`��
	Draw::Draw(46, &src, &dst, c, 0.0f);



	//--------�C���x���g��--------------
	
	//��͂�
	
	//�ϊ��A�C�e�����������Ă���Ƃ��C���x���g���̃J���[��ω�
	if ((((UserData*)Save::GetData())->converted_pick >= 1))
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 10.0;
		dst.m_left = 480.0;
		dst.m_right = dst.m_right = dst.m_left + 90.0;
		dst.m_bottom = dst.m_top + 80.0;

		//�`��
		Draw::Draw(40, &src, &dst, c, 0.0f);
	}
	else
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 10.0;
		dst.m_left = 480.0;
		dst.m_right = dst.m_right = dst.m_left + 90.0;
		dst.m_bottom = dst.m_top + 80.0;

		//�`��
		Draw::Draw(37, &src, &dst, c, 0.0f);
	}

	//�͂���
	
	//�ϊ��A�C�e�����������Ă���Ƃ��C���x���g���̃J���[��ω�
	if ((((UserData*)Save::GetData())->converted_ladder >= 1))
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 10.0;
		dst.m_left = 580.0;
		dst.m_right = dst.m_right = dst.m_left + 90.0;
		dst.m_bottom = dst.m_top + 80.0;

		//�`��
		Draw::Draw(38, &src, &dst, c, 0.0f);
	}
	else
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 10.0;
		dst.m_left = 580.0;
		dst.m_right = dst.m_right = dst.m_left + 90.0;
		dst.m_bottom = dst.m_top + 80.0;

		//�`��
		Draw::Draw(35, &src, &dst, c, 0.0f);
	}
	
	//��

	//�ϊ��A�C�e�����������Ă���Ƃ��C���x���g���̃J���[��ω�
	if ((((UserData*)Save::GetData())->converted_board >= 1))
	{
	   
	   //�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 10.0;
		dst.m_left = 680.0;
		dst.m_right = dst.m_right = dst.m_left + 90.0;
		dst.m_bottom = dst.m_top + 80.0;

		//�`��
		Draw::Draw(39, &src, &dst, c, 0.0f);
	}
	else
	{
	    //��
	    //�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 10.0;
		dst.m_left = 680.0;
		dst.m_right = dst.m_right = dst.m_left + 90.0;
		dst.m_bottom = dst.m_top + 80.0;

		//�`��
		Draw::Draw(36, &src, &dst, c, 0.0f);
	}


	//-------�C���x���g��(��)---------

	//��͂�
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 10.0;
	dst.m_left = 140.0;
	dst.m_right = dst.m_right = dst.m_left + 90.0;
	dst.m_bottom = dst.m_top + 80.0;

	//�`��
	Draw::Draw(34, &src, &dst, c, 0.0f);


	//�͂���
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 10.0;
	dst.m_left = 240.0;
	dst.m_right = dst.m_right = dst.m_left + 90.0;
	dst.m_bottom = dst.m_top + 80.0;

	//�`��
	Draw::Draw(32, &src, &dst, c, 0.0f);

	//��
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 10.0;
	dst.m_left = 340.0;
	dst.m_right = dst.m_right = dst.m_left + 90.0;
	dst.m_bottom = dst.m_top + 80.0;

	//�`��
	Draw::Draw(33, &src, &dst, c, 0.0f);



	//--------------------------------

	//�󔒗�(��)
	
		if (((UserData*)Save::GetData())->conversion_num ==9 || ((UserData*)Save::GetData())->conversion_num==8 || ((UserData*)Save::GetData())->conversion_num==7 || ((UserData*)Save::GetData())->conversion_num == 6 || ((UserData*)Save::GetData())->conversion_num == 5)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;


			//�\���ʒu�̐ݒ�
			dst.m_top = 10.0;
			dst.m_left = 40.0;
			dst.m_right = dst.m_right = dst.m_left + 80.0;
			dst.m_bottom = dst.m_top + 80.0;

			//�`��
			Draw::Draw(20, &src, &dst, c, 0.0f);
		}


		//�󔒗�(��)

		if (((UserData*)Save::GetData())->conversion_num == 4 || ((UserData*)Save::GetData())->conversion_num == 3 || ((UserData*)Save::GetData())->conversion_num == 2 || ((UserData*)Save::GetData())->conversion_num == 1)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;


			//�\���ʒu�̐ݒ�
			dst.m_top = 10.0;
			dst.m_left = 40.0;
			dst.m_right = dst.m_right = dst.m_left + 80.0;
			dst.m_bottom = dst.m_top + 80.0;

			//�`��
			Draw::Draw(21, &src, &dst, c, 0.0f);
		}


		//�󔒗�(��)

		if (((UserData*)Save::GetData())->conversion_num == 0)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;


			//�\���ʒu�̐ݒ�
			dst.m_top = 10.0;
			dst.m_left = 40.0;
			dst.m_right = dst.m_right = dst.m_left +80.0;
			dst.m_bottom = dst.m_top + 80.0;

			//�`��
			Draw::Draw(22, &src, &dst, c, 0.0f);
		}

	
	////�A�C�e����////

	//�͂���//

	if (((UserData*)Save::GetData())->ladder_item + ((UserData*)Save::GetData())->converted_ladder == 0)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 595.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item + ((UserData*)Save::GetData())->converted_ladder == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 595.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item + ((UserData*)Save::GetData())->converted_ladder == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 595.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item + ((UserData*)Save::GetData())->converted_ladder == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 595.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item + ((UserData*)Save::GetData())->converted_ladder == 4)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 595.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->ladder_item + ((UserData*)Save::GetData())->converted_ladder == 5)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 595.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}

	//��͂�//

	if (((UserData*)Save::GetData())->pick_item+ ((UserData*)Save::GetData())->converted_pick == 0)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 495.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item + ((UserData*)Save::GetData())->converted_pick == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 495.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item + ((UserData*)Save::GetData())->converted_pick == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 495.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item + ((UserData*)Save::GetData())->converted_pick == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 495.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item + ((UserData*)Save::GetData())->converted_pick == 4)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 495.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->pick_item + ((UserData*)Save::GetData())->converted_pick == 5)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 495.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}

	//��//

	if (((UserData*)Save::GetData())->board_item + ((UserData*)Save::GetData())->converted_board == 0)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 695.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item + ((UserData*)Save::GetData())->converted_board == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 695.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item + ((UserData*)Save::GetData())->converted_board == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 695.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item + ((UserData*)Save::GetData())->converted_board == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 695.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item + ((UserData*)Save::GetData())->converted_board == 4)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 695.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->board_item + ((UserData*)Save::GetData())->converted_board == 5)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 695.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}



	//----------------�A�C�e����(��)-------------------------------

	//�͂���(��)

	if (((UserData*)Save::GetData())->bad_ladder == 0)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 255.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->bad_ladder == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 255.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->bad_ladder == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 255.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->bad_ladder == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 255.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->bad_ladder == 4)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 255.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->bad_ladder == 5)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 255.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}

	//��͂�(��)

if (((UserData*)Save::GetData())->bad_pick== 0)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 152.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(8, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_pick == 1)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 152.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(9, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_pick == 2)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 152.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(10, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_pick == 3)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 152.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(11, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_pick == 4)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 152.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(12, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_pick == 5)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 152.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(13, &src, &dst, c, 0.0f);
}


     //��(��)

if (((UserData*)Save::GetData())->bad_board == 0)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 355.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(8, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_board == 1)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 355.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(9, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_board == 2)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 355.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(10, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_board == 3)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 355.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(11, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_board == 4)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 355.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(12, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->bad_board == 5)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 355.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(13, &src, &dst, c, 0.0f);
}
	//�c��ϊ���
if (((UserData*)Save::GetData())->conversion_num == 9)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 48.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(45, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->conversion_num == 8)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 48.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(44, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->conversion_num == 7)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 48.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(43, &src, &dst, c, 0.0f);
}
if (((UserData*)Save::GetData())->conversion_num == 6)
{
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 17.0f;
	dst.m_left = 48.0f;
	dst.m_right = dst.m_left + 64.0;
	dst.m_bottom = dst.m_top + 64.0;

	//�`��
	Draw::Draw(42, &src, &dst, c, 0.0f);
}
	if (((UserData*)Save::GetData())->conversion_num == 5)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 48.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(13, &src, &dst, c, 0.0f);
	}
	if (((UserData*)Save::GetData())->conversion_num == 4)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 48.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}

	if (((UserData*)Save::GetData())->conversion_num == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 48.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(11, &src, &dst, c, 0.0f);
	}

	if (((UserData*)Save::GetData())->conversion_num == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 48.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}

	if (((UserData*)Save::GetData())->conversion_num == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 48.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	if (((UserData*)Save::GetData())->conversion_num == 0)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 17.0f;
		dst.m_left = 48.0f;
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}


	//�󔒗�(��)�o�c��

	if (((UserData*)Save::GetData())->conversion_num == 0)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;


		//�\���ʒu�̐ݒ�
		dst.m_top = 10.0;
		dst.m_left = 40.0;
		dst.m_right = dst.m_right = dst.m_left + 80.0;
		dst.m_bottom = dst.m_top + 80.0;

		//�`��
		Draw::Draw(23, &src, &dst, c, 0.0f);
	}

}


	