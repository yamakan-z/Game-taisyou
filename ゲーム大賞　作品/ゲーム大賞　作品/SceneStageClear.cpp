//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"

#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneStageClear.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneStageClear::CSceneStageClear()
{

}

//�f�X�g���N�^
CSceneStageClear::~CSceneStageClear()
{

}

//���������\�b�h
void CSceneStageClear::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"Next Stage:ENTER_KEY");

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"GameClear(��).wav", BACK_MUSIC);

	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1.0 - v);

	//���y�X�^�[�g
	Audio::Start(0);

	//�Q�[���N���A�I�u�W�F�N�g�쐬
	CObjStageClear* obj = new CObjStageClear();
	Objs::InsertObj(obj, OBJ_STAGE_CLEAR, 10);

	//�摜�ǂݍ���
	Draw::LoadImageW(L"�Q�[���N���A.png", 1, TEX_SIZE_1024);

	////�I�u�W�F�N�g�쐬
	//CObjgameClearBackground* back = new CObjgameClearBackground();
	//Objs::InsertObj(back, OBJ_GAME_CLEAR_BACKGROUND, 1);

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"GameClear(��).wav", SOUND_TYPE::BACK_MUSIC);

	//�{�����[����1.0�ɖ߂�
	v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(0);

}

//���s�����\�b�h
void CSceneStageClear::Scene()
{

}
