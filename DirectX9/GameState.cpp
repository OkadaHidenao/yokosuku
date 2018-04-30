#include"GameState.h"

GameState::GameState()
{
	//�R���X�g���N�^

	pMap = new Map;
	pPlayer = new Player;
}

GameState::~GameState()
{
	//�f�X�g���N�^

	delete pMap;
	delete pPlayer;
}

void GameState::Init()
{
	//���C�����[�v�O�ɌĂ�

	//�X�v���C�g,�e�N�X�`���̐ݒ�
	messageSprite.SetAlpha(1);
	messageSprite.SetAngle(0);
	messageSprite.SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	messageSprite.SetPos(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

	titleTexture.Load(_T("Graph/title.png"));
	titleTexture.SetDivide(1, 1);
	titleTexture.SetNum(0, 0);

	clearTexture.Load(_T("Graph/clear.png"));
	clearTexture.SetDivide(1, 1);
	clearTexture.SetNum(0, 0);

	overTexture.Load(_T("Graph/over.png"));
	overTexture.SetDivide(1, 1);
	overTexture.SetNum(0, 0);

	//�v���C���[�n
	playerSprite.SetAlpha(1);
	playerSprite.SetAngle(0);
	playerSprite.SetSize(20, 50);

	playerTexture.Load(_T("Graph/player.png"));
	playerTexture.SetDivide(1, 1);
	playerTexture.SetNum(0, 0);

	//�}�b�v�`�b�v�̕`��ݒ�
	sprite.SetAlpha(1);
	sprite.SetAngle(0);
	sprite.SetSize(PIXEL, PIXEL);

	texture.Load(_T("Graph/tex.png"));
	texture.SetDivide(4, 1);

	pMap->Init();
}
void GameState::Update()
{
	//���ۂ̓���
	switch (gameSeq)
	{
	case GAME_TITLE:
		GameTitle();
		break;

	case GAME_MAIN:
		GameMain();
		break;

	case GAME_CLEAR:
		GameClear();
		break;

	case GAME_OVER:
		GameOver();
		break;

	default:
		break;
	}
}
void GameState::GameTitle()
{
	//�^�C�g��
	messageSprite.Draw(titleTexture);
	if (pDi->KeyJustPressed(DIK_RETURN))
	{
		gameSeq = GAME_MAIN;
	}
}
void GameState::GameMain()
{
	//���C��
	Draw();
}
void GameState::GameClear()
{
	//�Q�[���N���A
}
void GameState::GameOver()
{
	//�Q�[���I�[�o�[
}

void GameState::Draw()
{
	for (int y = 0; y < pMap->GetMapHeight(); y++)
	{
		for (int x = 0; x < pMap->GetMapWidth(); x++)
		{
			//�}�b�v�̕`��
			//�`��̋N�_�����S�Ȃ̂�PIXEL/2���v���X����
			sprite.SetPos((float)(PIXEL*x + PIXEL / 2), (float)(PIXEL*y + PIXEL / 2));

			//�u���b�N�̕`��
			switch (pMap->GetMapBlock(x, y))
			{
			case 1://��
				texture.SetNum(0, 0);
				sprite.Draw(texture);
				break;

			case 2:
				playerSprite.SetPos((float)(PIXEL*x + PIXEL / 2 + pPlayer->PlayerX()), (float)(PIXEL*y + PIXEL / 2));
				playerSprite.Draw(playerTexture);
				break;

			case 3:
				break;

			default:
				break;
			}
		}
	}

	pPlayer->Control();
}