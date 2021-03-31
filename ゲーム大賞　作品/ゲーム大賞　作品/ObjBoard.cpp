//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjBoard.h"
#include "GameL/UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBoard::Init()
{
	//m_scroll = 0.0f;

	//���
	int board_data[10][100] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,20,1,1,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_mapB, board_data, sizeof(int) * (10 * 100));
}

//�A�N�V����
void CObjBoard::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();


	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//����X�N���[�����C��
	if (hx < 80)
	{
		hero->SetX(80);//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//�O���X�N���[�����C��
	if (hx > 300)
	{
		hero->SetX(300);//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//��l���̏Փˏ�Ԋm�F�t���O�̏�����
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//����ł���u���b�N�̎�ނ̏�����
	hero->SetBT(0);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{


			if (m_mapB[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float x = j * 64.0f;
				float y = i * 64.0;


				//�̓����蔻��
				if (m_mapB[i][j] == 10 && (hx + (-block->GetScroll()) + 64.0f > x) && (hx + (-block->GetScroll()) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-block->GetScroll())) - x;
					float vy = hy - y;

					//���������߂�
					float len = sqrt(vx * vx + vy * vy);

					//�p�x�����߂�
					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//�p�x�ŏ㉺���E�𔻒�

					if (r > 45 && r < 135)
					{
						//��
						hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
						hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
						hero->SetBT(m_mapB[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
					}


				}


				//�ݒu�u���b�N�i�j�̓����蔻��
				if (m_mapB[i][j] == 20 && (hx + (-block->GetScroll()) + 64.0f > x) && (hx + (-block->GetScroll()) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-block->GetScroll())) - x;
					float vy = hy - y;

					//���������߂�
					float len = sqrt(vx * vx + vy * vy);

					//�p�x�����߂�
					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//�p�x�ŏ㉺���E�𔻒�

					if (r > 45 && r < 135)
					{
						//��
						hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
						hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
						hero->SetBT(m_mapB[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
					}


				}


				//�ݒu�ꏊ�Ƀv���C���[������Ɣ��ݒu�ł���
				if (hero->GetBT() == 20)
				{
					((UserData*)Save::GetData())->ins_place = true;

				}
				else
				{
					((UserData*)Save::GetData())->ins_place = false;
				}

				if (((UserData*)Save::GetData())->ins_flag == true && hero->GetBT() == 20 &&((UserData*)Save::GetData())->board_item > 0)//�ݒu�ꏊ��O�̃u���b�N�ɔ���
				{

					if (m_mapB[i][j] == 1)//8�ԁF�ݒu�p�̌�
					{
						m_mapB[i][j] = 10;//�ݒu

						((UserData*)Save::GetData())->item -= 1;
					}
					else if (((UserData*)Save::GetData())->item <= 0)
					{
						((UserData*)Save::GetData())->board_item -= 1;
					}
				}
			}
		}
	}




}

//�h���[
void CObjBoard::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			//��
			//10�ԑ�@��
			if (m_mapB[i][j] == 10)
			{

				float c2[4] = { 1.0f,0.0f,0.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + block->GetScroll();
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 10.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//����
			//20�ԑ�@�i����j
			if (m_mapB[i][j] == 20)
			{

				float c2[4] = { 0.0f,1.0f,0.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + block->GetScroll();
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}
		}
	}

	
}