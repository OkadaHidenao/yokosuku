#include"Player.h"
#include"Map.h"

Player::Player()
{
	//�R���X�g���N�^
	playerX = 0;
	playerY = 0;
	playerSpeed = 2.0f;
	jumpPower = 20;
	jumpFlag = false;
	y_prev = 0;
	y_temp = 0;
}

Player::~Player()
{
	//�f�X�g���N�^
}

void Player::Init()
{
	//�v���C���[�n
	playerSprite.SetAlpha(1);
	playerSprite.SetAngle(0);
	playerSprite.SetSize(PIXEL, PIXEL);

	playerTexture.Load(_T("Graph/player.png"));
	playerTexture.SetDivide(1, 1);
	playerTexture.SetNum(0, 0);
}

void Player::Draw(int scrX,int scrY)
{
	playerSprite.SetPos(playerX - scrX, playerY - scrY);
	playerSprite.Draw(playerTexture);

	Control();
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

	//�X�y�[�X��������(�W�����v)
	if (pDi->KeyState(DIK_SPACE) && (!jumpFlag))
	{
		jumpFlag = true;

		y_prev = playerY;
		playerY = playerY - 20;
	}

	//�W�����v����
	if (jumpFlag)
	{
		y_temp = playerY;

		playerY += (playerY - y_prev) + 1;
		y_prev = y_temp;
		if (playerY == 0)
		{
			jumpFlag = false;
		}
	}
}