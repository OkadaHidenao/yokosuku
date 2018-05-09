#pragma once

#include"Map.h"
#include"Player.h"

#include"Direct3D.h"

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

	//�C���X�^���X�쐬�Q
	//�|�C���^�ŌĂ�ŏ������y������
	Map *pMap;
	Player *pPlayer;

	//�{�^������p�C���X�^���X
	DirectInput*pDi = DirectInput::GetInstansce();

	int ScrolX, ScrolY;

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