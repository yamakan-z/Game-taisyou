//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)



//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjGameOver.h"
#include "GameL/UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	m_key_flag = false;//�L�[�t���O

	//�t���O��j��
	//�A�C�e���֌W�t���O�j��
	((UserData*)Save::GetData())->item = 0;
	((UserData*)Save::GetData())->ladder_item = 0;
	((UserData*)Save::GetData())->pick_item = 0;
	((UserData*)Save::GetData())->board_item = 0;

	//�ϊ��σA�C�e��
	((UserData*)Save::GetData())->converted_board = 0;//�ϊ��ςݔA�C�e��
	((UserData*)Save::GetData())->converted_ladder = 0;//�ϊ��ς݂͂����A�C�e��
	((UserData*)Save::GetData())->converted_pick = 0;//�ϊ��ς݂�͂��A�C�e��

	//�򉻃A�C�e��
	((UserData*)Save::GetData())->bad_board = 0;//�򉻔A�C�e��
	((UserData*)Save::GetData())->bad_ladder = 0;//�򉻂͂����A�C�e��
	((UserData*)Save::GetData())->bad_pick = 0;//�򉻂�͂��A�C�e��

	//�M�~�b�N�֌W�t���O�j��
	((UserData*)Save::GetData())->ins_flag = false;
	((UserData*)Save::GetData())->break_flag = false;
	((UserData*)Save::GetData())->ins_ladder = false;
	((UserData*)Save::GetData())->ladder = false;

	
	//�ϊ��񐔂������l�ɖ߂�
	((UserData*)Save::GetData())->conversion_num = 5;
}
//�A�N�V����
void CObjGameOver::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[��Title�Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}
	else
	{
		m_key_flag = true;
	}
}
//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"NEXT_CHALLENGE:ENTER_KEY", 225, 340, 32, c);

}