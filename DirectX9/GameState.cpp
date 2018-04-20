#include"GameState.h"

GameState::GameState()
{
	//�R���X�g���N�^
}
GameState::~GameState()
{
	//�f�X�g���N�^
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
}
void GameState::GameMain()
{
	//���C��
}
void GameState::GameClear()
{
	//�Q�[���N���A
}
void GameState::GameOver()
{
	//�Q�[���I�[�o�[
}