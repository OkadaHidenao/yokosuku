#pragma once

#include"Map.h"
#include"Player.h"

#include"Direct3D.h"

enum Sequence
{
	GAME_TITLE,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER
};

class GameState
{
private:
	Sequence gameSeq;

	//タイトル,クリア,オーバー画面のスプライトとテクスチャ
	//スプライトは位置が同じなので使いまわすよ
	Sprite messageSprite;
	Texture titleTexture;
	Texture clearTexture;
	Texture overTexture;

	//インスタンス作成群
	//ポインタで呼んで処理を軽くする
	Map *pMap;
	Player *pPlayer;

	//ボタン操作用インスタンス
	DirectInput*pDi = DirectInput::GetInstansce();

	int ScrolX, ScrolY;

public:
	GameState();
	~GameState();

	void Init();
	void Update();
	void GameTitle();
	void GameMain();
	void GameClear();
	void GameOver();
};