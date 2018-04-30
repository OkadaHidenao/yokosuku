#pragma once

#include<fstream>
#include<string>

class Map
{
private:
	//マップの幅と高さ
	int mapHeight;
	int mapWidth;

	//マップを格納する配列
	int *mapBlock;

public:
	Map();
	~Map();

	int GetMapHeight() { return mapHeight; }
	int GetMapWidth() { return mapWidth; }
	int GetMapBlock(int x, int y) { return mapBlock[x + y*mapWidth]; }
	void SetMapArray(int Height, int Width, std::ifstream& data, int *array);

	void Init();
};