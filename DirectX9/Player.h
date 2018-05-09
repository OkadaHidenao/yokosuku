#pragma once

#include"DirectInput.h"
#include"Sprite.h"
#include"Texture.h"

class Player
{
private:
	//プレイヤーの座標
	int playerX;
	int playerY;

	//プレイヤーのスピード
	float playerSpeed;
	//ジャンプのパワー
	float jumpPower;

	//ジャンプしているかどうかのフラグ
	bool jumpFlag;

	//ジャンプに必要な変数
	int y_prev, y_temp;

	//ボタン操作用インスタンス
	DirectInput*pDi = DirectInput::GetInstansce();

	//プレイヤーのスプライトとテクスチャ
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