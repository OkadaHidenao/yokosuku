#pragma once

#include"Texture.h"
#include"Sprite.h"

class Player
{
private:
	//�v���C���[�̍��W
	int playerX;
	int playerY;

	//�v���C���[�̃X�s�[�h
	float playerSpeed;

	Sprite playerSprite;
	Texture playerTexture;

public:
	Player();
	~Player();

};