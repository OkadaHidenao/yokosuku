#pragma once

#include<fstream>
#include<string>
#include<tchar.h>

#include"Sprite.h"
#include"Texture.h"

#define PIXEL 32
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 480

class Map
{
private:
	//マップの幅と高さ
	int mapHeight;
	int mapWidth;

	//マップを格納する配列
	int *mapBlock;

	//マップチップのスプライトとテクスチャ
	Sprite sprite;
	Texture texture;

public:
	Map();
	~Map();
	int GetMapHeight() { return mapHeight; }
	int GetMapWidth() { return mapWidth; }
	int GetMapBlock(int x, int y) { return mapBlock[x + y*mapWidth]; }
	void SetMapArray(int Height, int Width, std::ifstream& data, int *array);

	void Init();
	void Draw();
};