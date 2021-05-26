//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL/UserData.h"
#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMainT.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneMainT::CSceneMainT()
{
	((UserData*)Save::GetData())->stageT = true;
}

//�f�X�g���N�^
CSceneMainT::~CSceneMainT()
{

}

//���������\�b�h
void CSceneMainT::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"aniani.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"�u���b�N.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"�w�i2.png", 2, TEX_SIZE_1024);
	Draw::LoadImageW(L"Ladder.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"�S��.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"�͂����A�C�e��.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"�C���x���g�����Q.png", 6, TEX_SIZE_512);
	Draw::LoadImageW(L"��͂�.png", 7, TEX_SIZE_512);
	Draw::LoadImageW(L"�|�[��.png", 14, TEX_SIZE_1024);
	Draw::LoadImageW(L"��.png", 15, TEX_SIZE_1024);
	Draw::LoadImageW(L"�󔒗�.png", 16, TEX_SIZE_1024);
	Draw::LoadImageW(L"�򉻂͂���.png", 17, TEX_SIZE_512);
	Draw::LoadImageW(L"��Q��.png", 18, TEX_SIZE_512);
	Draw::LoadImageW(L"������ʁi���j.png", 19, TEX_SIZE_512);
	Draw::LoadImageW(L"�󔒗�(��).png", 20, TEX_SIZE_1024);
	Draw::LoadImageW(L"�󔒗�(��).png", 21, TEX_SIZE_1024);
	Draw::LoadImageW(L"�󔒗�(��).png", 22, TEX_SIZE_1024);
	Draw::LoadImageW(L"�󔒗�(��)�o�c��.png", 23, TEX_SIZE_1024);
	Draw::LoadImageW(L"�C���x���g��(��).png", 24, TEX_SIZE_512);
	Draw::LoadImageW(L"�͂����Ŕ�.png", 25, TEX_SIZE_512);
	Draw::LoadImageW(L"��͂��Ŕ�.png", 26, TEX_SIZE_512);
	Draw::LoadImageW(L"�S�Ŕ�.png", 27, TEX_SIZE_512);
	Draw::LoadImageW(L"�򉻂͂����Ŕ�.png", 28, TEX_SIZE_512);
	Draw::LoadImageW(L"�򉻂�͂��Ŕ�.png", 29, TEX_SIZE_512);
	Draw::LoadImageW(L"�򉻓S�Ŕ�.png", 30, TEX_SIZE_512);
	Draw::LoadImageW(L"�Ŕ_.png", 31, TEX_SIZE_512);
	Draw::LoadImageW(L"�򉻂͂����C���x���g��.png", 32, TEX_SIZE_512);
	Draw::LoadImageW(L"�򉻔C���x���g��.png", 33, TEX_SIZE_512);
	Draw::LoadImageW(L"�򉻂�͂��C���x���g��.png", 34, TEX_SIZE_512);
	Draw::LoadImageW(L"�͂����C���x���g��.png", 35, TEX_SIZE_512);
	Draw::LoadImageW(L"�C���x���g��.png", 36, TEX_SIZE_512);
	Draw::LoadImageW(L"��͂��C���x���g��.png", 37, TEX_SIZE_512);
	Draw::LoadImageW(L"�ϊ��͂����C���x���g��.png", 38, TEX_SIZE_512);
	Draw::LoadImageW(L"�ϊ��C���x���g��.png", 39, TEX_SIZE_512);
	Draw::LoadImageW(L"�ϊ���͂��C���x���g��.png", 40, TEX_SIZE_512);
	Draw::LoadImageW(L"�u���b�N��.png", 41, TEX_SIZE_512);
	Draw::LoadImageW(L"��������i�\���j.png", 46, TEX_SIZE_512);
	Draw::LoadImageW(L"�V��.png", 47, TEX_SIZE_512);
	Draw::LoadImageW(L"�y�u���b�N.png", 48, TEX_SIZE_512);
	Draw::LoadImageW(L"���Ŕ�.png", 49, TEX_SIZE_512);
	Draw::LoadImageW(L"�S�A�C�e��.png", 50, TEX_SIZE_512);
	Draw::LoadImageW(L"�򉻓S��.png", 51, TEX_SIZE_512);

	//�A�C�e�����ԍ�
	Draw::LoadImageW(L"0.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"1.png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"2.png", 10, TEX_SIZE_512);
	Draw::LoadImageW(L"3.png", 11, TEX_SIZE_512);
	Draw::LoadImageW(L"4.png", 12, TEX_SIZE_512);
	Draw::LoadImageW(L"5.png", 13, TEX_SIZE_512);
	Draw::LoadImageW(L"6.png", 42, TEX_SIZE_512);
	Draw::LoadImageW(L"7.png", 43, TEX_SIZE_512);
	Draw::LoadImageW(L"8.png", 44, TEX_SIZE_512);
	Draw::LoadImageW(L"9.png", 45, TEX_SIZE_512);

	//���y�ǂݍ���
	Audio::LoadAudio(0, L"�`���[�g���A���X�e�[�W.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"�A�C�e���ݒu��.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(2, L"�u���b�N��j�󂷂鉹.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(3, L"�u���b�N��j�󂷂鉹.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(4, L"SEItemGet.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(5, L"�A�C�e���ϊ���.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(6, L"�A�C�e���擾.wav", SOUND_TYPE::EFFECT);

	//�{�����[����1.5���₷
	float v = Audio::VolumeMaster(0.0f);

	//���y�X�^�[�g
	Audio::Start(0);

	if (((UserData*)Save::GetData())->item <= 0)//�A�C�e����0������鎞�A0�ɂ���
	{
		((UserData*)Save::GetData())->item = 0;
	}



	////�I�u�W�F�N�g�쐬////

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlockT* objbT = new CObjBlockT();
	Objs::InsertObj(objbT, OBJ_BLOCKT, 9);

	//�C���x���g���쐬
	CObjInventory* objin = new CObjInventory();
	Objs::InsertObj(objin, OBJ_INVENTORY, 10);

}

//���s�����\�b�h
void CSceneMainT::Scene()
{

}
