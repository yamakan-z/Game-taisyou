//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock3.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjBlock3::Init()
{
	m_scroll = 0.0f;

	m_px = GetScroll();//�ʒu
	m_py = GetScroll();

	p = 0;
	q = 0;

	//�u���b�N���
	//�g�p�u���b�N�ԍ��@1�`17�A80�`81�A90�`91�A97�`99�@
	//01�ԁ@�u���b�N
	//02�ԁ@�S�[��
	//-----------�͂����֌W�̃u���b�N------------ 
	//03�ԁ@�͂����A�C�e��
	//06��  �͂�������u���b�N 
	//07�ԁ@�͂�����������Ƃ̑���
	//08�ԁ@�͂����i�\���j 
	//80�ԁ@��ړ�����u���b�N
	//97�ԁ@�͂����ݒu�̋�� 

	//-----------�֌W�̃u���b�N---------------- 
	//04�ԁ@�A�C�e��
	//12�ԁ@�@
	//13�ԁ@����u���b�N
	//99�ԁ@�ݒu�̌�

	//-----------��Q���֌W�̃u���b�N--------------- 
	//05�ԁ@��͂��A�C�e��
	//10�ԁ@��Q��
	//11��  ��Q������u���b�N
	//98�ԁ@��Q���j���̋��

	//-----------�򉻃A�C�e���p-------------
	//14�ԁ@�͂�������u���b�N�i�򉻃A�C�e���p�j
	//15�ԁ@�򉻂͂����i�\���j 
	//16�ԁ@��(�򉻃A�C�e���p�j
	//17�ԁ@����u���b�N(�򉻃A�C�e���p�j
	//18�ԁ@��Q������u���b�N�i�򉻂�͂��p�j  �@ 
	//81�ԁ@��ړ�����u���b�N�i�򉻃A�C�e���p�j 
	//--------------------------------------- 

	//90�ԁ@�S�[���i���j
	//91�ԁ@�S�[���i�|�[���j
	//19��  �͂����Ŕ�
	//20��  ��͂��Ŕ�
	//21��  �S�Ŕ�
	//22��  �򉻂͂����Ŕ�
	//23��  �򉻂�͂��Ŕ�
	//24��  �򉻓S�Ŕ�
	//25��  �Ŕ_
	//26��  ���Ŕ�




	//�}�b�v���
	int block_data[10][100] =
	{
		{01,00,00,00,00,00,00,00,00,00,00,00,01,00,03,00,05,00,04,00,03,04,00,05,00,01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,04,00,00,00,00,00,00,00,00,00,00,00,00,00,01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01},
		{01,00,00,00,00,00,00,00,00,00,00,00,01,07,07,07,01,01,01,01,01,01,01,01,01,01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,07,07,07,00,00,00,00,00,00,00,00,00,00,00,01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01},
		{01,00,00,00,00,00,00,00,00,00,00,00,00,97,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,10,00,00,00,00,00,00,00,00,00,00,00,10,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,10,00,00,00,00,01,00,97,00,00,00,00,00,00,00,00,00,00,00,00,01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01},
		{01,00,00,00,00,00,00,00,00,00,00,00,19,97,00,00,00,00,00,00,00,00,00,00,00,00,00,10,00,00,10,00,20,00,00,00,00,00,00,00,20,00,10,00,00,00,00,01,00,00,00,00,00,00,00,00,00,00,20,00,10,00,00,00,00,01,00,97,00,00,00,26,00,01,00,00,00,00,00,00,01,00,00,00,00,00,00,00,21,00,00,00,00,00,00,00,00,00,00,01},
		{01,00,00,00,00,00,00,00,00,00,00,03,25,97,00,00,00,00,00,00,00,00,00,00,00,00,00,10,00,00,10,00,25,05,00,00,00,00,00,04,25,00,10,00,00,00,00,01,00,00,00,00,00,00,00,00,05,00,25,00,10,00,00,00,00,01,00,97,00,00,00,25,00,01,00,00,00,00,00,00,01,00,00,00,00,00,00,04,25,00,00,00,00,00,00,00,00,00,00,01},
		{01,00,00,00,00,00,07,07,07,01,01,01,01,06,01,01,01,01,00,00,00,00,00,00,00,00,11,01,11,01,01,11,01,01,07,07,07,01,01,01,01,11,01,11,01,01,01,01,00,00,00,00,00,07,07,07,01,01,01,11,01,11,00,00,00,01,01,06,01,07,07,07,00,01,07,07,07,01,01,01,01,00,00,00,00,07,07,07,01,13,99,99,99,01,00,00,00,00,00,01},
		{01,00,00,00,00,00,97,00,00,00,00,00,00,00,00,00,00,00,01,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,97,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,97,01,00,00,00,00,00,00,00,00,00,00,00,00,00,97,01,00,00,00,97,00,00,00,00,00,00,00,00,00,00,00,97,00,00,00,00,00,00,01,00,00,00,00,00,01},
		{01,26,00,00,00,19,97,00,00,00,00,00,00,00,00,00,00,00,00,01,00,00,00,00,00,21,00,00,00,00,00,00,00,00,00,97,00,00,00,21,00,00,00,00,00,00,00,00,00,00,00,00,00,19,97,01,00,00,00,00,00,00,00,00,00,00,00,00,00,97,01,00,00,00,97,00,00,00,00,00,24,00,00,00,00,19,97,00,21,00,00,00,00,01,00,00,00,00,00,01},
		{01,25,00,00,03,25,97,00,00,00,00,00,00,00,00,00,00,00,00,00,01,00,00,05,00,25,00,00,00,00,00,00,00,03,00,97,00,00,05,25,00,00,00,00,00,00,00,00,00,00,00,04,00,25,97,01,00,00,00,00,00,00,00,00,00,00,03,00,03,97,01,00,00,00,97,00,00,00,00,03,25,00,00,00,00,25,97,04,25,00,00,00,00,01,00,00,00,00,00,01},
		{01,01,01,01,01,01,06,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,13,99,99,99,13,01,01,01,01,06,01,01,01,01,13,99,99,99,13,01,01,01,01,01,01,01,01,01,06,01,01,01,01,01,01,01,01,01,01,01,01,01,01,06,01,01,01,01,14,01,01,01,01,01,01,17,99,99,17,01,06,01,01,13,99,99,99,13,01,01,01,01,02,01},
		//   0  .  .  .  .  5  .  .  .  .  10 .  .  .  .  15 .  .  .  .  20 .  

	};
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, block_data, sizeof(int) * (10 * 100));


	//�A�C�e������
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{

			if (m_map[i][j] == 3)
			{
				//�͂����A�C�e���쐬
				CLadderItem* objli = new CLadderItem();
				objli->posset(j * 64, i * 64);

				Objs::InsertObj(objli, OBJ_LADDER_ITEM, 10);
			}

			if (m_map[i][j] == 4)
			{
				//board�I�u�W�F�N�g�쐬
				CBoardItem* objbi = new CBoardItem();
				objbi->posset(j * 64, i * 64);

				Objs::InsertObj(objbi, OBJ_BOARD_ITEM, 10);
			}

			if (m_map[i][j] == 5)
			{
				//��͂��쐬
				CObjPick* objp = new CObjPick();
				objp->posset(j * 64, i * 64);

				Objs::InsertObj(objp, OBJ_PICK, 10);
			}
		}
	}


}

void CObjBlock3::Item_Spawn()
{


}


//�A�N�V����
void CObjBlock3::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (((UserData*)Save::GetData())->item <= 0)//�A�C�e����0������鎞�A0�ɂ���
	{
		((UserData*)Save::GetData())->item = 0;
	}

	if (((UserData*)Save::GetData())->ladder_item < 0)//�͂����A�C�e����0������鎞�A0�ɂ���
	{
		((UserData*)Save::GetData())->ladder_item = 0;
	}



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


			if (m_map[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float x = j * 64.0f;
				float y = i * 64.0;

				//-----------�����蔻��̐ݒ�--------------------

				//��l���ƃu���b�N�̓����蔻��
				if (m_map[i][j] == 1 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

						//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							hero->SetRight(true);//��l���̍��̕������Փ˂��Ă���
							hero->SetX(x + 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
							hero->SetVX(-hero->GetVX() * 0.1f);//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
							hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
							hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
							hero->SetX(x - 64.0f + (m_scroll));//�u���b�N�̈ʒu-��l���̕�
							hero->SetVX(-hero->GetVX() * 0.1f);
						}
						if (r > 225 && r < 315)
						{
							//��
							hero->SetUp(true);//��l���̏�̕������Փ˂��Ă���
							hero->SetY(y + 64);//�u���b�N�̈ʒu+��l���̕�
							if (hero->GetVY() < 0)
							{
								hero->SetVY(0.0f);
							}
						}

					}

				}


				//��l���ƃu���b�N�̓����蔻��(�S�[���j
				if (m_map[i][j] == 2 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

						//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							hero->SetRight(true);//��l���̍��̕������Փ˂��Ă���
							hero->SetX(x + 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
							hero->SetVX(-hero->GetVX() * 0.1f);//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
							hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
							hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVY(0.0f);

							if (m_map[i][j] == 90)
							{
								m_map[i][j] = 10;//��Q������

							}


							//�u���b�N�ɐG�ꂽ��V�[���ړ�
							Scene::SetScene(new CSceneGameClear());
						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
							hero->SetX(x - 64.0f + (m_scroll));//�u���b�N�̈ʒu-��l���̕�
							hero->SetVX(-hero->GetVX() * 0.1f);
						}
						if (r > 225 && r < 315)
						{
							//��
						}

					}

				}

				//�͂�����ݒu����ꏊ�𔻒肷��u���b�N
				if (m_map[i][j] == 6 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetX(x + 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
						hero->SetVX(-hero->GetVX() * 0.1f);//-VX*�����W��
					}
					if (r > 45 && r < 135)
					{
						//��
						hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
						hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
						hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
					}
					if (r > 135 && r < 225)
					{
						//��
						hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
						hero->SetX(x - 64.0f + (m_scroll));//�u���b�N�̈ʒu-��l���̕�
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


				//�͂�����ݒu����ꏊ�𔻒肷��u���b�N�i�򉻃A�C�e���p�j
				if (m_map[i][j] == 14 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetX(x + 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
						hero->SetVX(-hero->GetVX() * 0.1f);//-VX*�����W��
					}
					if (r > 45 && r < 135)
					{
						//��
						hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
						hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
						hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
					}
					if (r > 135 && r < 225)
					{
						//��
						hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
						hero->SetX(x - 64.0f + (m_scroll));//�u���b�N�̈ʒu-��l���̕�
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
				if (m_map[i][j] == 7 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
						((UserData*)Save::GetData())->move_flag = true;//����Ɉړ�������A���E�ړ�����������
						//�ꕔ�̂͂����t���O�̏�����
						((UserData*)Save::GetData())->ladder = false;
						((UserData*)Save::GetData())->ins_ladder = false;
						((UserData*)Save::GetData())->up_flag = false;
						//�ꕔ�̗򉻂͂����t���O�̏�����
						((UserData*)Save::GetData())->bad_ladder_put = false;
						((UserData*)Save::GetData())->ins_bad_ladder = false;
						((UserData*)Save::GetData())->low_up_flag = false;
					}


				}


				//��Q��
				if (m_map[i][j] == 10 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							hero->SetRight(true);//��l���̍��̕������Փ˂��Ă���
							hero->SetX(x + 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
							hero->SetVX(-hero->GetVX() * 0.1f);//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
							hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
							hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
							hero->SetX(x - 64.0f + (m_scroll));//�u���b�N�̈ʒu-��l���̕�
							hero->SetVX(-hero->GetVX() * 0.1f);
						}
						if (r > 225 && r < 315)
						{
							//��
						}

					}

				}

				//��Q������u���b�N
				if (m_map[i][j] == 11 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							hero->SetRight(true);//��l���̍��̕������Փ˂��Ă���
							hero->SetX(x + 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
							hero->SetVX(-hero->GetVX() * 0.1f);//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
							hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
							hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
							hero->SetX(x - 64.0f + (m_scroll));//�u���b�N�̈ʒu-��l���̕�
							hero->SetVX(-hero->GetVX() * 0.1f);
						}
						if (r > 225 && r < 315)
						{
							//��
						}

					}

				}





				//�̓����蔻��
				if (m_map[i][j] == 12 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
					}


				}

				//�ݒu�u���b�N�i�j�̓����蔻��
				if (m_map[i][j] == 13 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
					}


				}


				//�򉻔̓����蔻��
				if (m_map[i][j] == 16 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
					}


				}


				//�ݒu�u���b�N�i�j�̓����蔻��
				if (m_map[i][j] == 17 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
					}


				}

				//��Q������u���b�N
				if (m_map[i][j] == 18 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							hero->SetRight(true);//��l���̍��̕������Փ˂��Ă���
							hero->SetX(x + 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
							hero->SetVY(-hero->GetVX() * 0.1f);//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
							hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
							hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
							hero->SetX(x - 64.0f + (m_scroll));//�u���b�N�̈ʒu-��l���̕�
							hero->SetVX(-hero->GetVX() * 0.1f);
						}
						if (r > 225 && r < 315)
						{
							//��
						}

					}

				}


				//��ړ���������u���b�N
				if (m_map[i][j] == 80 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetX(x + 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
						hero->SetVY(-hero->GetVX() * 0.1f);//-VX*�����W��
					}
					if (r > 45 && r < 135)
					{
						//��
						hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
						hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
						hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
					}
					if (r > 135 && r < 225)
					{
						//��
						hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
						hero->SetX(x - 64.0f + (m_scroll));//�u���b�N�̈ʒu-��l���̕�
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

				//��ړ���������u���b�N(�򉻃A�C�e���p�j
				if (m_map[i][j] == 81 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
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
						hero->SetX(x + 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
						hero->SetVY(-hero->GetVX() * 0.1f);//-VX*�����W��
					}
					if (r > 45 && r < 135)
					{
						//��
						hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
						hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
						hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
						hero->SetVY(0.0f);
					}
					if (r > 135 && r < 225)
					{
						//��
						hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
						hero->SetX(x - 64.0f + (m_scroll));//�u���b�N�̈ʒu-��l���̕�
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

				//-------------------------------------

				//�M�~�b�N�֌W�̏���

				//-------------��Q������----------------------

				//��Q���̗��ׂ̃u���b�N�Ƀv���C���[������Ə�Q����j��
				if (hero->GetBT() == 11 && ((UserData*)Save::GetData())->pick_item > 0 || hero->GetBT() == 11 && ((UserData*)Save::GetData())->converted_pick > 0)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->break_point = true;
					}

				}
				else
				{
					((UserData*)Save::GetData())->break_point = false;
				}



				if (((UserData*)Save::GetData())->break_flag == true)//��Q���̈�O�̃u���b�N(��Q������u���b�N�j�ɔ���
				{

					if (m_map[i][j] == 10)//��Q��
					{
						if ((hx + (-m_scroll) + 64.0f + 40 > x) &&
							(hx + (-m_scroll) < x + 64.0f) &&
							(hy + 64.0f > y) &&
							(hy < y + 64.0f))
						{
							for (int f = 0;; f++)
							{
								if (m_map[i - f][j] == 10)
								{
									m_map[i - f][j] = 98;//��Q���j��
								}
								else
								{
									((UserData*)Save::GetData())->break_done = true;

									break;
								}
							}

						}

					}

				}

				//-------------------------------------------------------

				//--------------��Q������(�򉻂�͂��p�j--------------

				//�򉻂�͂��A�ʏ��͂��܂��́A�ϊ��ς݂�͂��ŏ�Q����j��
				if (hero->GetBT() == 18 && ((UserData*)Save::GetData())->bad_pick > 0 ||
					hero->GetBT() == 18 && ((UserData*)Save::GetData())->pick_item > 0 ||
					hero->GetBT() == 18 && ((UserData*)Save::GetData())->converted_pick > 0)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->break_bad_point = true;
					}

				}
				else
				{
					((UserData*)Save::GetData())->break_bad_point = false;
				}


				if (((UserData*)Save::GetData())->break_bad_flag == true)//��Q���̈�O�̃u���b�N(��Q������u���b�N�j�ɔ���
				{

					if (m_map[i][j] == 10)//��Q��
					{
						if ((hx + (-m_scroll) + 64.0f + 40 > x) &&
							(hx + (-m_scroll) < x + 64.0f) &&
							(hy + 64.0f > y) &&
							(hy < y + 64.0f))
						{
							for (int f = 0;; f++)
							{
								if (m_map[i - f][j] == 10)
								{
									m_map[i - f][j] = 98;//��Q���j��
								}
								else
								{
									((UserData*)Save::GetData())->break_bad_done = true;

									break;
								}
							}

						}

					}

				}

				//-------------------------------------------------------


				//---------------�͂�������-------------------------

				//�͂����̐ݒu
				if (((UserData*)Save::GetData())->ins_ladder == true && ((UserData*)Save::GetData())->ladder_item > 0 || ((UserData*)Save::GetData())->ins_ladder == true && ((UserData*)Save::GetData())->converted_ladder > 0)
				{
					if (m_map[i][j] == 97)//�͂����ݒu�p�̋��
					{

						if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
						{
							for (int f = 0;; f++) {
								if (m_map[i - f][j] == 97) {
									m_map[i - f][j] = 8;//�͂����ݒu
								}
								else {
									((UserData*)Save::GetData())->ladder = true;//��ړ��̋���

									((UserData*)Save::GetData())->ins_ladder_done = true;//�͂����A�C�e����1������邽��

									((UserData*)Save::GetData())->ladder_flag = false;//�����ł͂����̐ݒu�ꏊ�𔻒�

									break;
								}
							}


						}
					}

				}

				//�͂�����ݒu����ꏊ�𔻒肷��u���b�N
				if (hero->GetBT() == 6)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
					{
						((UserData*)Save::GetData())->ladder_flag = true;//�����ł͂����̐ݒu�ꏊ�𔻒�

						if (((UserData*)Save::GetData())->ladder == true)
						{
							//((UserData*)Save::GetData())->up_flag = true;//�͂��������鎞�̂ݏ�ړ�

							//��ړ��������邽�߂Ƀu���b�N������������
							if (m_map[i][j] == 6)
							{
								m_map[i][j] = 80;//��ړ��\�u���b�N�ɏ�������
							}
						}


					}


				}
				else if (hero->GetBT() != 6)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->up_flag = false;
						((UserData*)Save::GetData())->ladder_flag = false;
						//((UserData*)Save::GetData())->ins_ladder = false;
					}

				}

				//��ړ���������u���b�N
				if (hero->GetBT() == 80)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->up_flag = true;//�͂��������鎞�̂ݏ�ړ�
					}
				}

				//----------------------------------------------

				//-------------�͂��������i�򉻁j---------------

				//�͂�����ݒu����ꏊ�𔻒肷��u���b�N
				if (hero->GetBT() == 14)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
					{
						((UserData*)Save::GetData())->bad_ladder_flag = true;//�����ŗ򉻂͂����̐ݒu�ꏊ�𔻒�

						if (((UserData*)Save::GetData())->bad_ladder_put == true)
						{
							//((UserData*)Save::GetData())->up_flag = true;//�͂��������鎞�̂ݏ�ړ�

							//��ړ��������邽�߂Ƀu���b�N������������
							if (m_map[i][j] == 26)
							{
								m_map[i][j] = 81;//��ړ��\�u���b�N�ɏ�������
							}
						}


					}


				}
				else if (hero->GetBT() != 14)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
					{
						((UserData*)Save::GetData())->low_up_flag = false;
						((UserData*)Save::GetData())->bad_ladder_flag = false;
						//((UserData*)Save::GetData())->ins_ladder = false;
					}

				}

				//�͂����̐ݒu
				if (((UserData*)Save::GetData())->ins_bad_ladder == true && ((UserData*)Save::GetData())->bad_ladder > 0)
				{
					if (m_map[i][j] == 97)//�͂����ݒu�p�̋��
					{

						if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
						{
							for (int f = 0;; f++) {
								if (m_map[i - f][j] == 97) {
									m_map[i - f][j] = 15;//�͂����ݒu
								}
								else {
									((UserData*)Save::GetData())->bad_ladder_put = true;//��ړ��̋���

									((UserData*)Save::GetData())->ins_bad_ladder_done = true;//�͂����A�C�e����1������邽��

									((UserData*)Save::GetData())->bad_ladder_flag = false;//�����ł͂����̐ݒu�ꏊ�𔻒�

									break;
								}
							}


						}
					}

				}



				//��ړ���������u���b�N
				if (hero->GetBT() == 81)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->low_up_flag = true;//�͂��������鎞�̂ݏ�ړ�
						((UserData*)Save::GetData())->bad_ladder_put = false;
					}
				}



				//-------------------------------------



				//------------����-----------------

				//�ݒu�ꏊ�Ƀv���C���[������Ɣ��ݒu�ł���
				if (hero->GetBT() == 13 && ((UserData*)Save::GetData())->board_item > 0 || hero->GetBT() == 13 && ((UserData*)Save::GetData())->converted_board > 0)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
					{
						((UserData*)Save::GetData())->ins_place = true;
						p = i;
						q = j;
					}

				}
				else if (hero->GetBT() != 13)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
					{
						((UserData*)Save::GetData())->ins_place = false;
						((UserData*)Save::GetData())->ins_flag = false;
					}
				}

				if (((UserData*)Save::GetData())->ins_flag == true)//�ݒu�ꏊ��O�̃u���b�N�ɔ���
				{
					if (m_map[i][j] == 99)//�ݒu�p�̌�
					{

						/*if (hx+(-m_scroll)/64 ==x/64)
						{*/
						if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
						{
							for (int f = 0;; f++) {
								if (m_map[i][j + f] == 99) {
									m_map[i][j + f] = 12;//�ݒu
								}
								else
								{
									((UserData*)Save::GetData())->ins_done = true;
									break;
								}
							}

						}
						//}



					}
				}

				//------------------------------------------


				//------------�򉻔���--------------------

				//�򉻔ݒu�ꏊ�Ƀv���C���[������Ɨ򉻔��ݒu�ł���
				if (hero->GetBT() == 17 && ((UserData*)Save::GetData())->bad_board > 0)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->ins_bad_place = true;
					}

				}
				else if (hero->GetBT() != 17)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
					{
						((UserData*)Save::GetData())->ins_bad_place = false;
						((UserData*)Save::GetData())->ins_bad_flag = false;
					}
				}

				if (((UserData*)Save::GetData())->ins_bad_flag == true)//�򉻔ݒu�u���b�N�ɂ���Ɣ�������
				{
					if (m_map[i][j] == 99)//�ݒu�p�̌�
					{
						if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f))
						{
							for (int f = 0;; f++) {
								if (m_map[i][j + f] == 99) {
									m_map[i][j + f] = 16;//�ݒu
								}
								else {
									((UserData*)Save::GetData())->ins_bad_done = true;
									break;
								}
							}

						}
					}
				}

			}
		}
	}
}




//�h���[
void CObjBlock3::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	//�`��
	Draw::Draw(2, &src, &dst, c, 0.0f);



	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			//�u���b�N
			if (m_map[i][j] == 1)
			{

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;



				//�`��
				Draw::Draw(1, &src, &dst, c, 0.0f);

			}

			//�S�[���u���b�N
			if (m_map[i][j] == 2)
			{
				//�`��J���[���
				float c[4] = { 1.0f,0.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c, 0.0f);
			}

			//�S�[���|�[��
			if (m_map[i][j] == 91)
			{

				//�`��J���[���
				float c[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 480.0f;
				src.m_bottom = 800.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(14, &src, &dst, c, 0.0f);
			}

			//��(�S�[��)
			if (m_map[i][j] == 90)
			{

				//�`��J���[���
				float c[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 480.0f;
				src.m_bottom = 800.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}

			//��Q��
			if (m_map[i][j] == 10)
			{

				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 314.0f;
				src.m_bottom = 250.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(18, &src, &dst, c2, 0.0f);
			}

			//��Q������u���b�N
			if (m_map[i][j] == 11)
			{

				float c2[4] = { 0.0f,0.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//�͂����p�̃u���b�N�i�����ŏ�锻�������j
			if (m_map[i][j] == 6)
			{

				//�`��J���[���
				float c2[4] = { 0.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//��̑���u���b�N
			if (m_map[i][j] == 7)
			{
				//�`��J���[���
				float c2[4] = { 1.0f,0.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//�͂����i�`��̂݁j
			if (m_map[i][j] == 8)
			{

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(3, &src, &dst, c, 0.0f);


			}

			//�͂����p�̃u���b�N�i�����ŏ�锻�������(�򉻃A�C�e���p)�j
			if (m_map[i][j] == 14)
			{

				//�`��J���[���
				float c2[4] = { 1.0f,0.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//��
			if (m_map[i][j] == 12)
			{

				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 230.0f;
				src.m_bottom = 42.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 10.0;

				//�`��
				Draw::Draw(47, &src, &dst, c2, 0.0f);
			}

			//����u���b�N
			if (m_map[i][j] == 13)
			{

				float c2[4] = { 0.0f,1.0f,0.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}


			//�򉻂͂����i�`��̂݁j
			if (m_map[i][j] == 15)
			{

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);


			}

			//�򉻔�
			if (m_map[i][j] == 16)
			{

				float c2[4] = { 1.0f,0.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 10.0;

				//�`��
				Draw::Draw(47, &src, &dst, c2, 0.0f);
			}

			//�򉻔���u���b�N
			if (m_map[i][j] == 17)
			{

				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(41, &src, &dst, c2, 0.0f);
			}

			//��Q������u���b�N�i�򉻂�͂��p�j
			if (m_map[i][j] == 18)
			{

				float c2[4] = { 0.0f,0.0f,0.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(41, &src, &dst, c2, 0.0f);
			}

			//�͂����p�̃u���b�N�i�����ŏ�锻�������j
			if (m_map[i][j] == 80)
			{

				//�`��J���[���
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//�͂����p�̃u���b�N�i�򉻃A�C�e���p�E�����ŏ�锻�������j
			if (m_map[i][j] == 81)
			{

				//�`��J���[���
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(41, &src, &dst, c2, 0.0f);
			}

			//�͂����Ŕ�
			if (m_map[i][j] == 19)
			{

				//�`��J���[���
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//�`��
				Draw::Draw(25, &src, &dst, c2, 0.0f);
			}

			//��͂��Ŕ�
			if (m_map[i][j] == 20)
			{

				//�`��J���[���
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//�`��
				Draw::Draw(26, &src, &dst, c2, 0.0f);
			}

			//�S�Ŕ�
			if (m_map[i][j] == 21)
			{

				//�`��J���[���
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//�`��
				Draw::Draw(27, &src, &dst, c2, 0.0f);
			}

			//�򉻂͂����Ŕ�
			if (m_map[i][j] == 22)
			{

				//�`��J���[���
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//�`��
				Draw::Draw(28, &src, &dst, c2, 0.0f);
			}

			//�򉻂�͂��Ŕ�
			if (m_map[i][j] == 23)
			{

				//�`��J���[���
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//�`��
				Draw::Draw(29, &src, &dst, c2, 0.0f);
			}

			//�򉻓S�Ŕ�
			if (m_map[i][j] == 24)
			{

				//�`��J���[���
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//�`��
				Draw::Draw(30, &src, &dst, c2, 0.0f);
			}

			//���Ŕ�
			if (m_map[i][j] == 26)
			{

				//�`��J���[���
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 77.0;

				//�`��
				Draw::Draw(46, &src, &dst, c2, 0.0f);
			}

			//�Ŕ_
			if (m_map[i][j] == 25)
			{

				//�`��J���[���
				float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 504.0f;
				src.m_bottom = 504.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(31, &src, &dst, c2, 0.0f);
			}
		}
	}
}
