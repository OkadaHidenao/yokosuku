#include"Player.h"

Player::Player()
{
	//コンストラクタ
	playerX = 0;
	playerY = 0;
	playerSpeed = 2.0f;
	jumpFlag = false;
}

Player::~Player()
{
	//デストラクタ
}

void Player::Control()
{
	//左押したら
	if (pDi->KeyState(DIK_LEFTARROW))
	{
		playerX -= (int)playerSpeed;
	}
	//右押したら
	if (pDi->KeyState(DIK_RIGHTARROW))
	{
		playerX += (int)playerSpeed;
	}
	if (pDi->KeyJustPressed(DIK_SPACE) && (!jumpFlag))
	{
		jumpFlag = true;
	}
}