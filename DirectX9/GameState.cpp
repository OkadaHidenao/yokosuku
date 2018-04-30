#include"GameState.h"

GameState::GameState()
{
	//コンストラクタ

	pMap = new Map;
	pPlayer = new Player;
}

GameState::~GameState()
{
	//デストラクタ

	delete pMap;
	delete pPlayer;
}

void GameState::Init()
{
	//メインループ前に呼ぶ

	//スプライト,テクスチャの設定
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

	//プレイヤー系
	playerSprite.SetAlpha(1);
	playerSprite.SetAngle(0);
	playerSprite.SetSize(20, 50);

	playerTexture.Load(_T("Graph/player.png"));
	playerTexture.SetDivide(1, 1);
	playerTexture.SetNum(0, 0);

	//マップチップの描画設定
	sprite.SetAlpha(1);
	sprite.SetAngle(0);
	sprite.SetSize(PIXEL, PIXEL);

	texture.Load(_T("Graph/tex.png"));
	texture.SetDivide(4, 1);

	pMap->Init();
}
void GameState::Update()
{
	//実際の動き
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
	//タイトル
	messageSprite.Draw(titleTexture);
	if (pDi->KeyJustPressed(DIK_RETURN))
	{
		gameSeq = GAME_MAIN;
	}
}
void GameState::GameMain()
{
	//メイン
	Draw();
}
void GameState::GameClear()
{
	//ゲームクリア
}
void GameState::GameOver()
{
	//ゲームオーバー
}

void GameState::Draw()
{
	for (int y = 0; y < pMap->GetMapHeight(); y++)
	{
		for (int x = 0; x < pMap->GetMapWidth(); x++)
		{
			//マップの描画
			//描画の起点が中心なのでPIXEL/2をプラスする
			sprite.SetPos((float)(PIXEL*x + PIXEL / 2), (float)(PIXEL*y + PIXEL / 2));

			//ブロックの描画
			switch (pMap->GetMapBlock(x, y))
			{
			case 1://壁
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