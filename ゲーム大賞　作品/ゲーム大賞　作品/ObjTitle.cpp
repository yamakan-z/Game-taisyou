//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include "GameL/UserData.h"
#include "GameL\Audio.h"
#include <thread>
#include <chrono>


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
			//�J�n���r�d
			Audio::Start(1);
			std::this_thread::sleep_for(std::chrono::seconds(2)); //�J�n��������2�b�~�߂�(�J�nSE��炷���߁j
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
		if (((UserData*)Save::GetData())->key_flagT == true)
		{
			//�J�n���r�d
			Audio::Start(1);
			std::this_thread::sleep_for(std::chrono::seconds(2)); //�J�n��������2�b�~�߂�(�J�nSE��炷���߁j
			Scene::SetScene(new CSceneMainT());
			((UserData*)Save::GetData())->key_flagT = false;
		}
	}
	else
	{
		((UserData*)Save::GetData())->key_flagT = true;
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