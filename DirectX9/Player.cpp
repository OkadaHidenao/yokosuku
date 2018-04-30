#include"Player.h"

Player::Player()
{
	//�R���X�g���N�^
	playerX = 0;
	playerY = 0;
	playerSpeed = 2.0f;
	jumpFlag = false;
}

Player::~Player()
{
	//�f�X�g���N�^
}

void Player::Control()
{
	//����������
	if (pDi->KeyState(DIK_LEFTARROW))
	{
		playerX -= (int)playerSpeed;
	}
	//�E��������
	if (pDi->KeyState(DIK_RIGHTARROW))
	{
		playerX += (int)playerSpeed;
	}
	if (pDi->KeyJustPressed(DIK_SPACE) && (!jumpFlag))
	{
		jumpFlag = true;
	}
}