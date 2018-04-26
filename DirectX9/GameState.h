#pragma once
#include"Direct3D.h"
#include"DirectInput.h"
#include"Sprite.h"
#include"Texture.h"

#include"Map.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600

enum Sequence
{
	GAME_TITLE,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER
};

class GameState
{
private:
	Sequence gameSeq;

	//�^�C�g��,�N���A,�I�[�o�[��ʂ̃X�v���C�g�ƃe�N�X�`��
	//�X�v���C�g�͈ʒu�������Ȃ̂Ŏg���܂킷��
	Sprite messageSprite;
	Texture titleTexture;
	Texture clearTexture;
	Texture overTexture;

	//�{�^������p�C���X�^���X
	DirectInput*pDi = DirectInput::GetInstansce();

	Map map;

public:
	GameState();
	~GameState();

	void Init();
	void Update();
	void GameTitle();
	void GameMain();
	void GameClear();
	void GameOver();
};