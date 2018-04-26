#pragma once
#include"Direct3D.h"
#include"DirectInput.h"
#include"Sprite.h"
#include"Texture.h"

#include"Map.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600

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

	//ボタン操作用インスタンス
	DirectInput*pDi = DirectInput::GetInstansce();

	Map map;

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