#pragma once

#include<fstream>
#include<string>

class Map
{
private:
	//�}�b�v�̕��ƍ���
	int mapHeight;
	int mapWidth;

	//�}�b�v���i�[����z��
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