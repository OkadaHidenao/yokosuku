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
	//�}�b�v�̐ݒ�============================
	std::ifstream mapText;
	std::string textName("Graph/map.txt");

	mapText.open(textName);
	mapText >> mapHeight;
	mapText >> mapWidth;
	mapBlock = new int[mapHeight*mapWidth];
	SetMapArray(mapHeight, mapWidth, mapText, mapBlock);
	mapText.close();
	//========================================

	//�}�b�v�`�b�v�̕`��ݒ�
	sprite.SetAlpha(1);
	sprite.SetAngle(0);
	sprite.SetSize(PIXEL, PIXEL);

	texture.Load(_T("Graph/tex.png"));
	texture.SetDivide(4, 1);

	//�X�N���[���̐ݒ�
	scrol = 0;
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

void Map::Draw()
{

	scrol++;
	for (int y = 0; y < GetMapHeight(); y++)
	{
		for (int x = 0; x < GetMapWidth(); x++)
		{
			//�}�b�v�̕`��
			sprite.SetPos(PIXEL*x+scrol, PIXEL*y + WINDOW_HEIGHT / 4);

			//�u���b�N�̕`��
			switch (GetMapBlock(x, y))
			{
			case 1:
				texture.SetNum(0, 0);
				sprite.Draw(texture);
				break;

			case 0:
				texture.SetNum(2, 0);
				sprite.Draw(texture);

			default:
				break;
			}
		}
	}
}