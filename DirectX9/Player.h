#pragma once

#include"DirectInput.h"

class Player
{
private:
	//�v���C���[�̍��W
	int playerX;
	int playerY;

	//�v���C���[�̃X�s�[�h
	float playerSpeed;

	//�W�����v���Ă��邩�ǂ����̃t���O
	bool jumpFlag;

	//�{�^������p�C���X�^���X
	DirectInput*pDi = DirectInput::GetInstansce();

public:
	Player();
	~Player();
	void Control();
	int PlayerX() { return playerX; }
	int PlayerY() { return playerY; }

};