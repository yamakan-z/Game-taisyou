//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"ObjStageClear.h"
#include "GameL/UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjStageClear::Init()
{
	m_key_flag = false;//�L�[�t���O


	//�X�e�[�W�u���b�N�ύX
	//�X�e�[�W�P���X�e�[�W2
	if (((UserData*)Save::GetData())->stage1 == true)
	{
		((UserData*)Save::GetData())->stage1 = false;
		((UserData*)Save::GetData())->stage2 = true;
	}
	//�X�e�[�W2���X�e�[�W3
	else if (((UserData*)Save::GetData())->stage2 == true)
	{
		((UserData*)Save::GetData())->stage2 = false;
		((UserData*)Save::GetData())->stage3 = true;
	}





	//�t���O��j��
	//�A�C�e���֌W�t���O�j��
	((UserData*)Save::GetData())->item = 0;
	((UserData*)Save::GetData())->ladder_item = 0;
	((UserData*)Save::GetData())->pick_item = 0;
	((UserData*)Save::GetData())->board_item = 0;

	//�ϊ��σA�C�e��
	((UserData*)Save::GetData())->converted_item = 0;//�ϊ��ς݃A�C�e���̑���
	((UserData*)Save::GetData())->converted_board = 0;//�ϊ��ςݔA�C�e��
	((UserData*)Save::GetData())->converted_ladder = 0;//�ϊ��ς݂͂����A�C�e��
	((UserData*)Save::GetData())->converted_pick = 0;//�ϊ��ς݂�͂��A�C�e��

	//�򉻃A�C�e��
	((UserData*)Save::GetData())->bad_board = 0;//�򉻔A�C�e��
	((UserData*)Save::GetData())->bad_ladder = 0;//�򉻂͂����A�C�e��
	((UserData*)Save::GetData())->bad_pick = 0;//�򉻂�͂��A�C�e��


	//�M�~�b�N�֌W�t���O�j��
	//�֌W�̃t���O�j��
	((UserData*)Save::GetData())->ins_flag = false;
	//��Q���֌W�̃t���O�j��
	((UserData*)Save::GetData())->break_flag = false;
	//�͂����֌W�̃t���O�j��
	((UserData*)Save::GetData())->ins_ladder = false;
	((UserData*)Save::GetData())->ladder = false;


	//�򉻃M�~�b�N�֌W�̃t���O�j��
	//�͂����֌W�̃t���O�j��
	((UserData*)Save::GetData())->ins_bad_ladder = false;
	((UserData*)Save::GetData())->bad_ladder_put = false;
	//�֌W�̃t���O�j��
	((UserData*)Save::GetData())->ins_bad_flag = false;
	//��Q���֌W�̃t���O�j��
	((UserData*)Save::GetData())->break_bad_flag = false;

	//�X�e�[�W�N���ASE
	((UserData*)Save::GetData())->clear = false;

	//�X�e�[�W���ɂ���ĕϊ��\�񐔕ύX
	if (((UserData*)Save::GetData())->stage1 == true)
	{
		//�ϊ��񐔂������l�ɖ߂�
		((UserData*)Save::GetData())->conversion_num = 5;
	}
	//�X�e�[�W���ɂ���ĕϊ��\�񐔕ύX
	if (((UserData*)Save::GetData())->stage2 == true)
	{
		//�ϊ��񐔂������l�ɖ߂�
		((UserData*)Save::GetData())->conversion_num = 7;
	}


}
//�A�N�V����
void CObjStageClear::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[��Title�Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			if (((UserData*)Save::GetData())->stage2 == true)
			{
				Scene::SetScene(new CSceneMain2());
			}

			if (((UserData*)Save::GetData())->stage3 == true)
			{
				Scene::SetScene(new CSceneMain3());
			}
			
		}
	}
	else
	{
		m_key_flag = true;
	}
}
//�h���[
void CObjStageClear::Draw()
{
	float c[4] = { 1.0f,0.85f,0.0f,01.0f };
	wchar_t str[256];

	Font::StrDraw(L"�X�e�[�W�N���A", 200, 30, 64, c);

	//�^�C��a�\��

	if (((UserData*)Save::GetData())->save_s_time <= 9)
	{
		swprintf_s
		(
			str,
			L"�N���A�^�C���@%d:0%d",
			((UserData*)Save::GetData())->save_m_time,
			((UserData*)Save::GetData())->save_s_time
		);
	}
	else
	{
		swprintf_s
		(
			str,
			L"�N���A�^�C���@%d:%d",
			((UserData*)Save::GetData())->save_m_time,
			((UserData*)Save::GetData())->save_s_time
		);
	}
	Font::StrDraw(str, 120, 100, 64, c);
}