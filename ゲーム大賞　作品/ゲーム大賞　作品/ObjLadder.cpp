//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjLadder.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjLadder::Init()
{
	m_scroll = 0.0f;

	//�͂������
	int ladder_data[10][100] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,30,30,30,30,30,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,20,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_mapL, ladder_data, sizeof(int) * (10 * 100));

	
}

//�A�N�V����
void CObjLadder::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (((UserData*)Save::GetData())->ladder_item < 0)//�͂����A�C�e����0������鎞�A0�ɂ���
	{
		((UserData*)Save::GetData())->ladder_item = 0;
	}

	if (((UserData*)Save::GetData())->item < 0)//�A�C�e����0������鎞�A0�ɂ���
	{
		((UserData*)Save::GetData())->item = 0;
	}



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


	

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{


			if (m_mapL[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float x = j * 64.0f;
				float y = i * 64.0;

				//��l���ƃu���b�N�̓����蔻��(�͂����j
				if (m_mapL[i][j] == 20 && (hx + (-block->GetScroll()) + 64.0f > x) && (hx + (-block->GetScroll()) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
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
					if ((r < 45 && r>0) || r > 315)
					{
						//�E
						hero->SetRight(true);//��l���̍��̕������Փ˂��Ă���
						hero->SetX(x + 64.0f + (block->GetScroll()));//�u���b�N�̈ʒu+��l���̕�
						hero->SetVY(-hero->GetVX() * 0.1f);//-VX*�����W��
					}
					if (r > 45 && r < 135)
					{
						//��
						hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
						hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
						hero->SetBT(m_mapL[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
					}
					if (r > 135 && r < 225)
					{
						//��
						hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
						hero->SetX(x - 64.0f + (block->GetScroll()));//�u���b�N�̈ʒu-��l���̕�
						hero->SetVX(-hero->GetVX() * 0.1f);
					}
					if (r > 225 && r < 315)
					{
						//��
						hero->SetUp(true);//��l���̏�̕������Փ˂��Ă���
						hero->SetY(y + 64.0f);//�u���b�N�̈ʒu+��l���̕�
						if (hero->GetVY() < 0)
						{
							hero->SetVY(0.0f);
						}
					}

				}

				//��l���ƃu���b�N�̓����蔻��(�͂����j
				if (m_mapL[i][j] == 21 && (hx + (-block->GetScroll()) + 64.0f > x) && (hx + (-block->GetScroll()) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
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
					if ((r < 45 && r>0) || r > 315)
					{
						//�E
						hero->SetRight(true);//��l���̍��̕������Փ˂��Ă���
						hero->SetX(x + 64.0f + (block->GetScroll()));//�u���b�N�̈ʒu+��l���̕�
						hero->SetVY(-hero->GetVX() * 0.1f);//-VX*�����W��
					}
					if (r > 45 && r < 135)
					{
						//��
						hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
						hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
						hero->SetBT(m_mapL[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
					}
					if (r > 135 && r < 225)
					{
						//��
						hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
						hero->SetX(x - 64.0f + (block->GetScroll()));//�u���b�N�̈ʒu-��l���̕�
						hero->SetVX(-hero->GetVX() * 0.1f);
					}
					if (r > 225 && r < 315)
					{
						//��
						hero->SetUp(true);//��l���̏�̕������Փ˂��Ă���
						hero->SetY(y + 64.0f);//�u���b�N�̈ʒu+��l���̕�
						if (hero->GetVY() < 0)
						{
							hero->SetVY(0.0f);
						}
					}

				}

				//��l���Ƒ���i��j�̓����蔻��
				if (m_mapL[i][j] == 30 && (hx + (-block->GetScroll()) + 64.0f > x) && (hx + (-block->GetScroll()) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
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
						hero->SetBT(m_mapL[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
						((UserData*)Save::GetData())->move_flag = true;//����Ɉړ�������A���E�ړ�����������
						((UserData*)Save::GetData())->ladder = false;
						((UserData*)Save::GetData())->ins_ladder = false;
					}


				}

				//�͂���������Ə�֍s��
				if (hero->GetBT() == 20)
				{
					((UserData*)Save::GetData())->ladder_flag = true;//�����ł͂����̐ݒu�ꏊ�𔻒�

					if (((UserData*)Save::GetData())->ladder == true)
					{
						((UserData*)Save::GetData())->up_flag = true;//�͂��������鎞�̂ݏ�ړ�
					}
				
				}
				else if (hero->GetBT() != 20)
				{
					((UserData*)Save::GetData())->up_flag = false;
					((UserData*)Save::GetData())->ladder_flag = false;

				}

				if (((UserData*)Save::GetData())->ins_ladder == true&&((UserData*)Save::GetData())->ladder_item>0)
				{
					if (m_mapL[i][j] == 1)//9�ԁF�͂����ݒu�p�̋��
					{
						
						m_mapL[i][j] = 10;//�͂����ݒu
						
						((UserData*)Save::GetData())->ladder = true;//��ړ��̋���
						
						((UserData*)Save::GetData())->item -= 1;

					}
					else if (((UserData*)Save::GetData())->item <= 0)
					{
						((UserData*)Save::GetData())->ladder_item -= 1;
					}
				}
			}
		}
	}
}

//�h���[
void CObjLadder::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 184.0f;
	src.m_bottom = 184.0f;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//10�`19�ԁ@�͂���
	//20�`29�ԁ@�͂�������u���b�N
	//30�`39�ԁ@����u���b�N�i��j

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			//�͂����i�`��̂݁j
			if (m_mapL[i][j] == 10)
			{
				
				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + block->GetScroll();
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(3, &src, &dst, c, 0.0f);

			
			}

			//�͂����p�̃u���b�N�i�����ŏ�锻�������j
			if (m_mapL[i][j] == 20)
			{

				//�`��J���[���
				float c2[4] = { 0.0f,1.0f,1.0f,1.0f };

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

			//��̑���u���b�N
			if (m_mapL[i][j] == 30)
			{
				//�`��J���[���
				float c2[4] = { 1.0f,0.0f,1.0f,1.0f };

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