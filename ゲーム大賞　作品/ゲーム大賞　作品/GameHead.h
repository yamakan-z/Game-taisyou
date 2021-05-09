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
	OBJ_GAME_CLEAR,
	OBJ_GAME_OVER,
	OBJ_LADDER,
	OBJ_BOARD,
	OBJ_ROCK,
	OBJ_INVENTORY,
	OBJ_TITLE_BACKGROUND,
	OBJ_GAME_OVER_BACKGROUND,
	OBJ_GAME_CLEAR_BACKGROUND,

	//�͂����A�C�e��
	OBJ_LADDER_ITEM,

	//��͂�
	OBJ_PICK,

	OBJ_BOARD_ITEM,
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

	//��l���֌W�̃t���O
	bool up_flag = false;  //�͂��������鎞�A��ɏオ��t���O
	bool move_flag = true; //��ړ����A���E�ړ��𐧌�����t���O
	float item = 0;  //�A�C�e��������

	//�֌W�t���O
	bool ins_flag = false; //�ݒu�t���O�i�j
	bool ins_place = false;//�ݒu�ꏊ�Ǘ�(�j
	float board_item = 0;//�A�C�e�������t���O
	bool ins_done = false;//�ݒu�I���t���O�i���̂Ƃ���́A���ꂪ�Ȃ��ƈ�̃A�C�e����2�g�p����邽�߁j

	//�͂����֌W�t���O
	bool ins_ladder = false;//�͂����ݒu
	bool ladder_flag = false;//�͂����̐ݒu�ꏊ�𔻒�
	bool ladder = false;//�͂����̗L��
	float ladder_item = 0;//�͂����A�C�e�������t���O
	bool ins_ladder_done = false;//�͂����ݒu�I���t���O�i���̂Ƃ���́A���ꂪ�Ȃ��Ƃ͂������S���\������Ȃ��j

	//��Q���֌W�t���O
	bool break_flag = false;//��Q���j��t���O
	bool break_point = false;//��Q���j�󔻒�
	float pick_item = 0;//��͂�������
	bool break_done = false;//�ݒu�I���t���O�i���̂Ƃ���́A���ꂪ�Ȃ��ƈ�̃A�C�e����2�g�p����邽�߁j

	//�C���x���g���֌W
	bool I_ladder = false;//1�ڂ̎�����A�C�e�����͂����̎��C���x���g���ɕ\��
	bool I_board = false;//1�ڂ̎�����A�C�e�����̎��C���x���g���ɕ\��
	bool I_pick = false;//1�ڂ̎�����A�C�e������͂��̎��C���x���g���ɕ\��

	bool I_ladder1 = false;//2�ڂ̎�����A�C�e�����͂����̎��C���x���g���ɕ\��
	bool I_board1 = false;//2�ڂ̎�����A�C�e�����̎��C���x���g���ɕ\��
	bool I_pick1 = false;//2�ڂ̎�����A�C�e������͂��̎��C���x���g���ɕ\��

	bool I_ladder2 = false;//3�ڂ̎�����A�C�e�����͂����̎��C���x���g���ɕ\��
	bool I_board2 = false;//3�ڂ̎�����A�C�e�����̎��C���x���g���ɕ\��
	bool I_pick2 = false;//3�ڂ̎�����A�C�e������͂��̎��C���x���g���ɕ\��

	//�̂���ϊ���
	int conversion_num = 5;
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
#include"BoardItem.h"
#include"ObjTitleBackground.h"
#include"ObjgameOverBackground.h"
#include"ObjgameClearBackground.h"

#include"ObjInventory.h"
#include"ObjTitle.h"
#include"ObjGameClear.h"
#include"ObjGameOver.h"
//��͂�
#include"ObjPick.h"

//�͂����A�C�e��
#include"LadderItem.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include"SceneMain.h"
#include"SceneTitle.h"
#include"SceneGameOver.h"
#include"SceneGameClear.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------