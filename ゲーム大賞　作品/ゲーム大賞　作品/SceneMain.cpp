//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL/UserData.h"

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
	Draw::LoadImageW(L"����l��2.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"�u���b�N.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"�w�i2.png", 2, TEX_SIZE_1024);
	Draw::LoadImageW(L"Ladder.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"��.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"�͂����A�C�e��.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"�C���x���g��.png", 6, TEX_SIZE_512);
	Draw::LoadImageW(L"��͂�.png", 7, TEX_SIZE_512);
	

	if (((UserData*)Save::GetData())->item <= 0)//�A�C�e����0������鎞�A0�ɂ���
	{
		((UserData*)Save::GetData())->item = 0;
	}



	

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//ladder�I�u�W�F�N�g�쐬
	CObjLadder* objl = new CObjLadder();
	Objs::InsertObj(objl, OBJ_LADDER, 10);

	//board�I�u�W�F�N�g�쐬
	CObjBoard* objbo = new CObjBoard();
	Objs::InsertObj(objbo, OBJ_BOARD, 10);

	//rock�I�u�W�F�N�g�쐬
	CObjRock* objr = new CObjRock();
	Objs::InsertObj(objr, OBJ_BOARD, 10);

	//�C���x���g���쐬
	CObjInventory* objin = new CObjInventory();
	Objs::InsertObj(objin, OBJ_INVENTORY, 10);

	//�͂����A�C�e���쐬
//	CLadderItem* objli = new CLadderItem();
//	Objs::InsertObj(objli, OBJ_LADDER_ITEM, 10);

	CLadderItem2* objli2 = new CLadderItem2();
	Objs::InsertObj(objli2, OBJ_LADDER_ITEM2, 10);

	////��͂��쐬
	//CObjPick* objp = new CObjPick();
	//Objs::InsertObj(objp, OBJ_PICK, 10);

	////board�A�C�e���I�u�W�F�N�g�쐬
	//CBoardItem* objbi = new CBoardItem();
	//Objs::InsertObj(objbi, OBJ_BOARD_ITEM, 10);

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}
