#include"Map.h"

//�R���X�g���N�^
Map::Map()
{
	mapWidth = 0;
	mapHeight = 0;
}

//�f�X�g���N�^
Map::~Map()
{
	//�J������
	if (mapBlock != nullptr)
	{
		delete[] mapBlock;
		mapBlock = nullptr;
	}
}

void Map::Init()
{
	//�}�b�v�̐ݒ�
	std::ifstream mapText;
	std::string textName("Graph/map.txt");

	mapText.open(textName);
	mapText >> mapHeight;
	mapText >> mapWidth;
	mapBlock = new int[mapHeight*mapWidth];
	SetMapArray(mapHeight, mapWidth, mapText, mapBlock);
	mapText.close();
}

void Map::SetMapArray(int Height, int Width, std::ifstream& data, int *array)
{
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			array[i*Width + j] = 0;
		}
	}
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			data >> array[i*Width + j];
		}
	}
}