//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjGameClear.h"
#include "GameL/UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameClear::Init()
{
	m_key_flag = false;//�L�[�t���O
	//�t���O��j��
	((UserData*)Save::GetData())->ladder_item = 0;
	((UserData*)Save::GetData())->item = 0;
	((UserData*)Save::GetData())->pick_item = 0;
	((UserData*)Save::GetData())->ins_flag = false;
	((UserData*)Save::GetData())->break_flag = false;

	//�C���x���g���֌W�̃t���O�j��
	((UserData*)Save::GetData())->I_board1 = false;
	((UserData*)Save::GetData())->I_board2 = false;

	((UserData*)Save::GetData())->I_ladder1 = false;
	((UserData*)Save::GetData())->I_ladder2 = false;

	((UserData*)Save::GetData())->I_pick1 = false;
	((UserData*)Save::GetData())->I_pick2 = false;
}
//�A�N�V����
void CObjGameClear::Action()
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
void CObjGameClear::Draw()
{
	float r[4] = { 0.5f,0.0f,0.0f,1.0f };

	Font::StrDraw(L"GAME CLEAR", 350, 250, 32, r);
}