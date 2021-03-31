//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"


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
	Draw::LoadImageW(L"����l��.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"�u���b�N.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"�w�i.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"Ladder.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"�A�C�e��.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"�͂����A�C�e��.png", 5, TEX_SIZE_512);
	
	//


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

	//rock�I�u�W�F�N�g�쐬
	CLadderItem* objli = new CLadderItem();
	Objs::InsertObj(objli, OBJ_LADDER_ITEM, 10);

	//plate�I�u�W�F�N�g�쐬
	CBoardItem* objbi = new CBoardItem();
	Objs::InsertObj(objbi, OBJ_BOARD_ITEM, 10);

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}
