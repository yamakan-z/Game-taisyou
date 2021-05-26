//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"LadderItem.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

// �C�j�V�����C�Y
void CLadderItem::Init()
{
	float m_scroll;//���E�X�N���[���p

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ITEM, OBJ_LADDER_ITEM, 1);

}


//�A�N�V����
void CLadderItem::Action()
{

	//HitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);

	if (((UserData*)Save::GetData())->stage1 == true)
	{
		//�u���b�N���������Ă���
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		hit->SetPos(m_px + block->GetScroll(), m_py);
	}
	else if (((UserData*)Save::GetData())->stage2 == true)
	{
		//�u���b�N���������Ă���
		CObjBlock2* block2 = (CObjBlock2*)Objs::GetObj(OBJ_BLOCK2);

		hit->SetPos(m_px + block2->GetScroll(), m_py);
	}
	//�X�e�[�W3
	else if (((UserData*)Save::GetData())->stage3 == true)
	{
		//�u���b�N���������Ă���
		CObjBlock3* block3 = (CObjBlock3*)Objs::GetObj(OBJ_BLOCK3);


		hit->SetPos(m_px + block3->GetScroll(), m_py);
	}
	//�`���[�g���A���X�e�[�W
	else if (((UserData*)Save::GetData())->stageT == true)
	{
		//�u���b�N���������Ă���
		CObjBlockT* blockT = (CObjBlockT*)Objs::GetObj(OBJ_BLOCKT);


		hit->SetPos(m_px + blockT->GetScroll(), m_py);
	}

	//��l���I�u�W�F�N�g�ƐڐG������͂������폜
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{

		this->SetStatus(false);		//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);	//100�~�����L����HitBox���폜����
	
		//�A�C�e���擾
		Audio::Start(6);

		((UserData*)Save::GetData())->item += 1;
		((UserData*)Save::GetData())->ladder_item += 1;

	}

	
}

//�h���[
void CLadderItem::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�X�e�[�W���Ɏ����Ă���u���b�N����ς���
	//�X�e�[�W1
	if (((UserData*)Save::GetData())->stage1 == true)
	{
		//�u���b�N���������Ă���
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = m_py;
		dst.m_left = m_px + block->GetScroll();
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	//�X�e�[�W2
	if (((UserData*)Save::GetData())->stage2 == true)
	{
		//�u���b�N���������Ă���
		CObjBlock2* block2 = (CObjBlock2*)Objs::GetObj(OBJ_BLOCK2);

		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = m_py;
		dst.m_left = m_px + block2->GetScroll();
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	//�X�e�[�W3
	else if (((UserData*)Save::GetData())->stage3 == true)
	{
		//�u���b�N���������Ă���
		CObjBlock3* block3 = (CObjBlock3*)Objs::GetObj(OBJ_BLOCK3);

		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = m_py;
		dst.m_left = m_px + block3->GetScroll();
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	//�`���[�g���A���X�e�[�W
	else if (((UserData*)Save::GetData())->stageT == true)
	{
		//�u���b�N���������Ă���
		CObjBlockT* blockT = (CObjBlockT*)Objs::GetObj(OBJ_BLOCKT);

		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 184.0f;
		src.m_bottom = 184.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = m_py;
		dst.m_left = m_px + blockT->GetScroll();
		dst.m_right = dst.m_left + 64.0;
		dst.m_bottom = dst.m_top + 64.0;

		//�`��
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
}

	