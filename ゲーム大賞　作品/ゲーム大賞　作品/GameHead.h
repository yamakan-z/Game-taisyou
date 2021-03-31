#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_HERO,
	OBJ_BLOCK,
	OBJ_ITEM,
	OBJ_TURUHASI,
	OBJ_TITLE,
	OBJ_GAME_OVER,
	OBJ_LADDER,
	OBJ_BOARD,
	OBJ_ROCK,
	OBJ_LADDER_ITEM,
	OBJ_INVENTORY,
	OBJ_PICK,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_PICK,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	bool up_flag = false;  //�͂��������鎞�A��ɏオ��t���O
	bool move_flag = true; //��ړ����A���E�ړ��𐧌�����t���O
	bool ins_flag = false; //�ݒu�t���O�i�j
	bool ins_place = false;//�ݒu�ꏊ�Ǘ�(�j
	bool ins_ladder = false;//�͂����ݒu
	bool ladder_flag = false;//�͂����̐ݒu�ꏊ�𔻒�
	bool ladder = false;//�͂����̗L��
	bool break_flag = false;//��Q���j��t���O
	bool break_point = false;//��Q���j�󔻒�
	float item = 0;  //�A�C�e��������
	float ladder_item = 0;//�͂����A�C�e�������t���O
	float pick_item = 0;//��͂�������
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include"ObjHero.h"
#include"ObjBlock.h"
#include"ObjLadder.h"
#include"ObjBoard.h"
#include"ObjRock.h"
#include"LadderItem.h"
#include"ObjInventory.h"
#include"ObjPick.h"

#include"ObjTitle.h"
#include"ObjGameOver.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include"SceneMain.h"
#include"SceneTitle.h"
#include"SceneGameOver.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START  CSceneMain
//-----------------------------------------------