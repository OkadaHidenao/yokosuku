#pragma once

#include"DirectInput.h"
#include"Sprite.h"
#include"Texture.h"

class Player
{
private:
	//�v���C���[�̍��W
	int playerX;
	int playerY;

	//�v���C���[�̃X�s�[�h
	float playerSpeed;
	//�W�����v�̃p���[
	float jumpPower;

	//�W�����v���Ă��邩�ǂ����̃t���O
	bool jumpFlag;

	//�W�����v�ɕK�v�ȕϐ�
	int y_prev, y_temp;

	//�{�^������p�C���X�^���X
	DirectInput*pDi = DirectInput::GetInstansce();

	//�v���C���[�̃X�v���C�g�ƃe�N�X�`��
	Sprite playerSprite;
	Texture playerTexture;

public:
	Player();
	~Player();
	void Init();
	void Draw(int scrX, int scrY);
	void Control();
	int PlayerX() { return playerX; }
	int PlayerY() { return playerY; }

};