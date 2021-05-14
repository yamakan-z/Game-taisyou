//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"

#include"GameL\DrawTexture.h"
#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneGameOver.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneGameOver::CSceneGameOver()
{

}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//���������\�b�h
void CSceneGameOver::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"NEXT_CHALLENGE:ENTER_KEY");

	//���y�ǂݍ���
	Audio::LoadAudio(0, L"GameOver(��).wav", BACK_MUSIC);

	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(0);

	//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
	
	//�摜�ǂݍ���
	Draw::LoadImageW(L"�Q�[���I�[�o�[3.png", 10, TEX_SIZE_1024);

	//�I�u�W�F�N�g�쐬
	CObjgameOverBackground* back = new CObjgameOverBackground();
	Objs::InsertObj(back, OBJ_GAME_OVER_BACKGROUND, 10);

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"GameOver(��).wav", SOUND_TYPE::BACK_MUSIC);

	v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(0.1 - v);

	//���y�X�^�[�g
	Audio::Start(0);
}

//���s�����\�b�h
void CSceneGameOver::Scene()
{

}
