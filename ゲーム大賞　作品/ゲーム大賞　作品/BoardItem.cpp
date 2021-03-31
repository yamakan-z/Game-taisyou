//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"BoardItem.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

// �C�j�V�����C�Y
void CBoardItem::Init()
{
	float m_scroll;//���E�X�N���[���p

	m_px = 800.0f;//�ʒu
	m_py = 520.0f;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ITEM, OBJ_BOARD_ITEM, 1);
}


//�A�N�V����
void CBoardItem::Action()
{

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);

	//��l���I�u�W�F�N�g�ƐڐG������100�~���폜
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);		//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);	//100�~�����L����HitBox���폜����

		((UserData*)Save::GetData())->item += 1;
		((UserData*)Save::GetData())->ladder_item += 1;
	}
}

//�h���[
void CBoardItem::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

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
	Draw::Draw(4, &src, &dst, c, 0.0f);
}