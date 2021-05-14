//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\Audio.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//�Q�[�����C�����������\�b�h
void CSceneTitle::InitScene()
{
	//�o�͂���镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"�^�C�g��");

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"GameTitle(��).wav", SOUND_TYPE::BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0));

	//���y�X�^�[�g
	Audio::Start(0);

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjTitle* obj = new CObjTitle();//�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_TITLE, 10);//��l���I�u�W�F�N�g�o�^

	//�摜�ǂݍ���
	Draw::LoadImageW(L"�^�C�g��.png", 1, TEX_SIZE_1024);

	//�I�u�W�F�N�g�쐬
	CObjTitleBackground* back = new CObjTitleBackground();
	Objs::InsertObj(back, OBJ_TITLE_BACKGROUND, 1);
	
	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"GameTitle(��).wav", SOUND_TYPE::BACK_MUSIC);

	v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(0.1 - v);

	//���y�X�^�[�g
	Audio::Start(0);
	
}

//�Q�[�����C�����s�����\�b�h
void CSceneTitle::Scene()
{

}