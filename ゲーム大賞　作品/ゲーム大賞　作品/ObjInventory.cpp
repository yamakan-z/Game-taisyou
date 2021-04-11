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

// �C�j�V�����C�Y
void CObjInventory::Init()
{
	float m_scroll;//���E�X�N���[���p

	m_px = 500.0f;//�ʒu
	m_py = -50.0f;
	
	
}


//�A�N�V����
void CObjInventory::Action()
{
	if (((UserData*)Save::GetData())->item == 1)
	{
		
	}
}

//�h���[
void CObjInventory::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	//�X�R�A�̕\��
	wchar_t str[256];
	swprintf_s(str, L"�A�C�e����:%f", ((UserData*)Save::GetData())->item);
	Font::StrDraw(str, 10, 10, 20, c);


	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 180.0f;
	src.m_bottom = 180.0f;

	
	//�\���ʒu�̐ݒ�
	dst.m_top = m_py;
	dst.m_left = m_px;
	dst.m_right = dst.m_left + 256.0;
	dst.m_bottom = dst.m_top + 256.0;

	//�`��
	Draw::Draw(6, &src, &dst, c, 0.0f);


	//�C���x���g���̃A�C�e���A�C�R���̕\��

	//���
	if (((UserData*)Save::GetData())->item >= 1)
	{
		if (((UserData*)Save::GetData())->ladder_item > 1)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 184.0f;
			src.m_bottom = 184.0f;

			//�\���ʒu�̐ݒ�
			dst.m_top = 50.0f;
			dst.m_left = 510.0f;
			dst.m_right = dst.m_left + 64.0;
			dst.m_bottom = dst.m_top + 64.0;

			//�`��
			Draw::Draw(5, &src, &dst, c, 0.0f);
		}
		
		else if (((UserData*)Save::GetData())->pick_item >= 1)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 184.0f;
			src.m_bottom = 184.0f;

			//�\���ʒu�̐ݒ�
			dst.m_top = 50.0f;
			dst.m_left = 510.0f;
			dst.m_right = dst.m_left + 64.0;
			dst.m_bottom = dst.m_top + 64.0;

			//�`��
			Draw::Draw(7, &src, &dst, c, 0.0f);
		}

		else if (((UserData*)Save::GetData())->board_item >= 1)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 184.0f;
			src.m_bottom = 184.0f;

			//�\���ʒu�̐ݒ�
			dst.m_top = 50.0f;
			dst.m_left = 510.0f;
			dst.m_right = dst.m_left + 64.0;
			dst.m_bottom = dst.m_top + 64.0;

			//�`��
			Draw::Draw(4, &src, &dst, c, 0.0f);
		}
	}

	
	//���
	if (((UserData*)Save::GetData())->item >= 2 )
	{
		if (((UserData*)Save::GetData())->ladder_item >= 1)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 184.0f;
			src.m_bottom = 184.0f;

			//�\���ʒu�̐ݒ�
			dst.m_top = 50.0f;
			dst.m_left = 590.0f;
			dst.m_right = dst.m_left + 64.0;
			dst.m_bottom = dst.m_top + 64.0;

			//�`��
			Draw::Draw(5, &src, &dst, c, 0.0f);
		}

		else if (((UserData*)Save::GetData())->pick_item >= 1)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 184.0f;
			src.m_bottom = 184.0f;

			//�\���ʒu�̐ݒ�
			dst.m_top = 50.0f;
			dst.m_left = 590.0f;
			dst.m_right = dst.m_left + 64.0;
			dst.m_bottom = dst.m_top + 64.0;

			//�`��
			Draw::Draw(7, &src, &dst, c, 0.0f);
		}

		else if (((UserData*)Save::GetData())->board_item >= 1)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 184.0f;
			src.m_bottom = 184.0f;

			//�\���ʒu�̐ݒ�
			dst.m_top = 50.0f;
			dst.m_left = 590.0f;
			dst.m_right = dst.m_left + 64.0;
			dst.m_bottom = dst.m_top + 64.0;

			//�`��
			Draw::Draw(4, &src, &dst, c, 0.0f);
		}
		
	}


	//�O��
	if (((UserData*)Save::GetData())->item >= 3)
	{
		if (((UserData*)Save::GetData())->ladder_item +1)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 184.0f;
			src.m_bottom = 184.0f;

			//�\���ʒu�̐ݒ�
			dst.m_top = 50.0f;
			dst.m_left = 680.0f;
			dst.m_right = dst.m_left + 64.0;
			dst.m_bottom = dst.m_top + 64.0;

			//�`��
			Draw::Draw(5, &src, &dst, c, 0.0f);
		}

		else if (((UserData*)Save::GetData())->pick_item +1)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 184.0f;
			src.m_bottom = 184.0f;

			//�\���ʒu�̐ݒ�
			dst.m_top = 50.0f;
			dst.m_left = 680.0f;
			dst.m_right = dst.m_left + 64.0;
			dst.m_bottom = dst.m_top + 64.0;

			//�`��
			Draw::Draw(7, &src, &dst, c, 0.0f);
		}

		else if (((UserData*)Save::GetData())->board_item + 1)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 184.0f;
			src.m_bottom = 184.0f;

			//�\���ʒu�̐ݒ�
			dst.m_top = 50.0f;
			dst.m_left = 680.0f;
			dst.m_right = dst.m_left + 64.0;
			dst.m_bottom = dst.m_top + 64.0;

			//�`��
			Draw::Draw(4, &src, &dst, c, 0.0f);
		}
		
	}


}