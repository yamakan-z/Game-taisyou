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
#include"SceneMain.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//���������\�b�h
void CSceneMain::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"Hero_ani.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"�u���b�N.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"�w�i2.png", 2, TEX_SIZE_1024);
	Draw::LoadImageW(L"Ladder.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"��.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"�͂����A�C�e��.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"�C���x���g�����Q.png", 6, TEX_SIZE_512);
	Draw::LoadImageW(L"��͂�.png", 7, TEX_SIZE_512);
	Draw::LoadImageW(L"�|�[��.png", 14, TEX_SIZE_1024);
	Draw::LoadImageW(L"��.png", 15, TEX_SIZE_1024);
	Draw::LoadImageW(L"�󔒗�.png", 16, TEX_SIZE_1024);
	Draw::LoadImageW(L"�򉻂͂���.png", 17, TEX_SIZE_512);
	Draw::LoadImageW(L"��Q��.png", 18, TEX_SIZE_512);
	Draw::LoadImageW(L"������ʁi���j.png", 19, TEX_SIZE_512);
	//�A�C�e�����ԍ�
	Draw::LoadImageW(L"0.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"1.png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"2.png", 10, TEX_SIZE_512);
	Draw::LoadImageW(L"3.png", 11, TEX_SIZE_512);
	Draw::LoadImageW(L"4.png", 12, TEX_SIZE_512);
	Draw::LoadImageW(L"5.png", 13, TEX_SIZE_512);

	Draw::LoadImageW(L"�|�[��.png", 14, TEX_SIZE_1024);
	Draw::LoadImageW(L"��.png", 15, TEX_SIZE_1024);
	Draw::LoadImageW(L"�󔒗�.png", 16, TEX_SIZE_1024);
	Draw::LoadImageW(L"�󔒗�(��).png", 17, TEX_SIZE_1024);
	Draw::LoadImageW(L"�󔒗�(��).png", 18, TEX_SIZE_1024);
	Draw::LoadImageW(L"�󔒗�(��).png", 19, TEX_SIZE_1024);
	Draw::LoadImageW(L"�󔒗�(��)�o�c��.png", 20, TEX_SIZE_1024);
	Draw::LoadImageW(L"�C���x���g��(��).png", 21, TEX_SIZE_512);

	//���y�ǂݍ���
	Audio::LoadAudio(0, L"GameMain(��).wav", BACK_MUSIC);

	Audio::LoadAudio(1, L"�A�C�e���ݒu��.wav", EFFECT);
	Audio::LoadAudio(2, L"�u���b�N��j�󂷂鉹.wav", EFFECT);
	Audio::LoadAudio(3, L"��l���̈ړ���.wav",EFFECT);
	Audio::LoadAudio(4, L"SEItemGet.wav", EFFECT);

	//�{�����[����1.5���₷
	float v = Audio::VolumeMaster(1.0);

	//�{�����[����1.0�ɖ߂�
	v = Audio::VolumeMaster(0.0);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	//Audio::Start(0);

	if (((UserData*)Save::GetData())->item <= 0)//�A�C�e����0������鎞�A0�ɂ���
	{
		((UserData*)Save::GetData())->item = 0;
	}



	////�I�u�W�F�N�g�쐬////

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//�C���x���g���쐬
	CObjInventory* objin = new CObjInventory();
	Objs::InsertObj(objin, OBJ_INVENTORY, 10);

	//�͂����A�C�e���쐬
//	CLadderItem* objli = new CLadderItem();
//	Objs::InsertObj(objli, OBJ_LADDER_ITEM, 10);

	////��͂��쐬
	//CObjPick* objp = new CObjPick();
	//Objs::InsertObj(objp, OBJ_PICK, 10);

	////board�A�C�e���I�u�W�F�N�g�쐬
	//CBoardItem* objbi = new CBoardItem();
	//Objs::InsertObj(objbi, OBJ_BOARD_ITEM, 10);

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"GameMain(��).wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"�A�C�e���ݒu��.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(3, L"�u���b�N��j�󂷂鉹.wav", SOUND_TYPE::EFFECT);

	//�{�����[����1.0�ɖ߂�
    v = Audio::VolumeMaster(0.0);
	v = Audio::VolumeMaster((0.1 - v));

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}
