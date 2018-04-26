#pragma once

#include<fstream>
#include<string>
#include<tchar.h>

#include"Sprite.h"
#include"Texture.h"

#define PIXEL 32
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600

class Map
{
private:
	//�}�b�v�̕��ƍ���
	int mapHeight;
	int mapWidth;

	//�}�b�v���i�[����z��
	int *mapBlock;

	//�}�b�v�`�b�v�̃X�v���C�g�ƃe�N�X�`��
	Sprite sprite;
	Texture texture;

	//�X�N���[���p
	int scrol;

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