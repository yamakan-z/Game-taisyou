//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	m_key_flag = false;//�L�[�t���O
}
//�A�N�V����
void CObjGameOver::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[��Title�Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		
	}
	else
	{
		m_key_flag = true;
	}
}
//�h���[
void CObjGameOver::Draw()
{
	float r[4] = { 0.5f,0.0f,0.0f,1.0f };
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"YOU LOST", 350, 250, 32, r);
	Font::StrDraw(L"GAMEOVER", 350, 290, 32, r);
	Font::StrDraw(L"NEXT_CHALLENGE:ENTER_KEY", 225, 340, 32, c);

}