#pragma once

#include"DirectInput.h"

class Player
{
private:
	//プレイヤーの座標
	int playerX;
	int playerY;

	//プレイヤーのスピード
	float playerSpeed;

	//ジャンプしているかどうかのフラグ
	bool jumpFlag;

	//ボタン操作用インスタンス
	DirectInput*pDi = DirectInput::GetInstansce();

public:
	Player();
	~Player();
	void Control();
	int PlayerX() { return playerX; }
	int PlayerY() { return playerY; }

};