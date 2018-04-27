#pragma once

#include"Texture.h"
#include"Sprite.h"

class Player
{
private:
	//プレイヤーの座標
	int playerX;
	int playerY;

	//プレイヤーのスピード
	float playerSpeed;

	Sprite playerSprite;
	Texture playerTexture;

public:
	Player();
	~Player();

};