//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = 0.0f;

	m_px = GetScroll();//�ʒu
    m_py = GetScroll();

	//�}�b�v���
	int block_data[10][100] =
	{
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,40,40,40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,80,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,5,4,80,5,3,3,3,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,30,30,1,1,1,1,70,100,100,70,1,1,20,1,20,1,1,1,1,1,1,1,1,1,2,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, block_data, sizeof(int) * (10 * 100));

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{

			if (m_map[i][j] == 3)
			{
				//�͂����A�C�e���쐬
               CLadderItem* objli = new CLadderItem();
			   objli->posset(j*64,i*64);

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

void CObjBlock::Item_Spawn()
{

	
}


//�A�N�V����
void CObjBlock::Action()
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
	 
	 
	//�u���b�N���
	//1�ԁ@�u���b�N
	//2�Ł@�S�[��
	//10�`19�ԁ@��Q��
	//20�`29�ԁ@��Q������u���b�N
	//30�`39�ԁ@�͂�������u���b�N
	//40�`49�ԁ@�͂�����������Ƃ̑���
	//50�`59�ԁ@�͂����i�\���j
	//60�`69�ԁ@��
	//70�`79�ԁ@����u���b�N 
	//80�`89�ԁ@�͂����ݒu�̋�� 
	//90�`99�ԁ@��Q���j���̒l
	//100�`109�ԁ@�ݒu�̌�


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{


			if (m_map[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float x = j * 64.0f;
				float y = i * 64.0;

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
							hero->SetVY(-hero->GetVX() * 0.1f);//-VX*�����W��
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

				//��Q������u���b�N
				if (m_map[i][j] == 20 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
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


				//��l���ƃu���b�N�̓����蔻��(�͂����j
				if (m_map[i][j] == 30 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
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


				//��l���Ƒ���i��j�̓����蔻��
				if (m_map[i][j] == 40 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
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
						((UserData*)Save::GetData())->ladder = false;
						((UserData*)Save::GetData())->ins_ladder = false;
					}


				}


				//�̓����蔻��
				if (m_map[i][j] == 60 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
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
				if (m_map[i][j] == 70 && (hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
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

				


				//��Q���̗��ׂ̃u���b�N�Ƀv���C���[������Ə�Q����j��
				if (hero->GetBT() == 20 && ((UserData*)Save::GetData())->pick_item > 0)
				{
					((UserData*)Save::GetData())->break_point = true;

				}
				else
				{
					((UserData*)Save::GetData())->break_point = false;
				}

				

				if (((UserData*)Save::GetData())->break_flag == true)//��Q���̈�O�̃u���b�N�ɔ���
				{

					if (m_map[i][j] == 10)
					{
						m_map[i][j] = 90;//��Q���j��

						((UserData*)Save::GetData())->break_done = true;
						
					}
					else if (((UserData*)Save::GetData())->break_done == true)
					{
						((UserData*)Save::GetData())->item -= 1;
						((UserData*)Save::GetData())->pick_item -= 1;
						((UserData*)Save::GetData())->break_done = false;
					}
				}



				//�͂���������Ə�֍s��
				if (hero->GetBT() == 30)
				{
					((UserData*)Save::GetData())->ladder_flag = true;//�����ł͂����̐ݒu�ꏊ�𔻒�

					if (((UserData*)Save::GetData())->ladder == true)
					{
						((UserData*)Save::GetData())->up_flag = true;//�͂��������鎞�̂ݏ�ړ�
					}

				}
				else if (hero->GetBT() != 30)
				{
					((UserData*)Save::GetData())->up_flag = false;
					((UserData*)Save::GetData())->ladder_flag = false;

				}

				//�͂����̐ݒu
				if (((UserData*)Save::GetData())->ins_ladder == true && ((UserData*)Save::GetData())->ladder_item > 0)
				{
					if (m_map[i][j] == 80)//�͂����ݒu�p�̋��
					{

						m_map[i][j] = 50;//�͂����ݒu

						((UserData*)Save::GetData())->ladder = true;//��ړ��̋���

						((UserData*)Save::GetData())->ins_ladder_done = true;

					}
					
		
				}
				else if (((UserData*)Save::GetData())->ins_ladder_done == true)
				{
					((UserData*)Save::GetData())->item -= 1;
					((UserData*)Save::GetData())->ladder_item -= 1;
					((UserData*)Save::GetData())->ins_ladder_done = false;
				}

				//�ݒu�ꏊ�Ƀv���C���[������Ɣ��ݒu�ł���
				if (hero->GetBT() == 70)
				{
					((UserData*)Save::GetData())->ins_place = true;

				}
				else
				{
					((UserData*)Save::GetData())->ins_place = false;
				}

				if (((UserData*)Save::GetData())->ins_flag == true && hero->GetBT() == 70 && ((UserData*)Save::GetData())->board_item > 0)//�ݒu�ꏊ��O�̃u���b�N�ɔ���
				{

					if (m_map[i][j] == 100)//�ݒu�p�̌�
					{
						m_map[i][j] = 60;//�ݒu
						((UserData*)Save::GetData())->ins_done = true;
					}
					else if (((UserData*)Save::GetData())->ins_done == true)
					{
						((UserData*)Save::GetData())->item -= 1;
						((UserData*)Save::GetData())->board_item -= 1;
						((UserData*)Save::GetData())->ins_done = false;
					}
				}



			}
		}
	}
}	




//�h���[
void CObjBlock::Draw()
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
	dst.m_top =0.0f;
	dst.m_left =0.0f;
	dst.m_right =800.0f;
	dst.m_bottom = 600.0f;
	//�`��
	Draw::Draw(2, &src, &dst, c, 0.0f);

	

	for (int i = 0; i < 10; i++)
	{
		for(int j=0;j<100;j++)
		{
			//�u���b�N
			if (m_map[i][j] == 1)
			{

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top =i* 64.0f;
				dst.m_left =j*64.0f+m_scroll;
				dst.m_right =dst.m_left+ 64.0;
				dst.m_bottom =dst.m_top+ 64.0;
				


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
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c, 0.0f);
			}
			


			//��Q��
			if (m_map[i][j] == 10)
			{

				float c2[4] = { 1.0f,1.0f,0.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//��Q������u���b�N
			if (m_map[i][j] == 20)
			{

				float c2[4] = { 0.0f,0.0f,1.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//�͂����p�̃u���b�N�i�����ŏ�锻�������j
			if (m_map[i][j] == 30)
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
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//��̑���u���b�N
			if (m_map[i][j] == 40)
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
				dst.m_left = j * 64.0f + +m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//�͂����i�`��̂݁j
			if (m_map[i][j] == 50)
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

			//��
			//10�ԑ�@��
			if (m_map[i][j] == 60)
			{

				float c2[4] = { 1.0f,0.0f,0.0f,1.0f };

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 184.0f;
				src.m_bottom = 184.0f;


				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 10.0;

				//�`��
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

			//����
			//20�ԑ�@�i����j
			if (m_map[i][j] == 70)
			{

				float c2[4] = { 0.0f,1.0f,0.0f,1.0f };

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
				Draw::Draw(1, &src, &dst, c2, 0.0f);
			}

		}
	}
}
