//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include "GameL/UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_key_flag = false;

	((UserData*)Save::GetData())->stage2 = false;
	((UserData*)Save::GetData())->stage3 = false;
	((UserData*)Save::GetData())->stageT = false;
}


//�A�N�V����
void CObjTitle::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	//�X�y�[�X�L�[�������ăV�[���F�`���[�g���A���X�e�[�W�Ɉڍs����
	if (Input::GetVKey(VK_SPACE) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMainT());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

}
//�h���[
void CObjTitle::Draw()
{
	//float c[4] = { 1.0f,-1.0f,-1.0f,1.0f };
	////float r[4] = { -1.0f,1.0f,-1.0f,4.0f };
	//Font::StrDraw(L"�l����", 325, 220, 56, c);
	//
	//Font::StrDraw(L"GameStart:EnterKey",220, 400, 44, c);
}