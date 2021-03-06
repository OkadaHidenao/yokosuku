#include"Map.h"

//コンストラクタ
Map::Map()
{
	mapWidth = 0;
	mapHeight = 0;
}

//デストラクタ
Map::~Map()
{
	//開放処理
	if (mapBlock != nullptr)
	{
		delete[] mapBlock;
		mapBlock = nullptr;
	}
}

void Map::Initialize()
{
	//マップの設定
	std::ifstream mapText;
	std::string textName("Graph/map.txt");

	mapText.open(textName);
	mapText >> mapHeight;
	mapText >> mapWidth;
	mapBlock = new int[mapHeight*mapWidth];
	SetMapArray(mapHeight, mapWidth, mapText, mapBlock);
	mapText.close();

	//マップチップの描画設定
	sprite.SetAlpha(1);
	sprite.SetAngle(0);
	sprite.SetSize(PIXEL, PIXEL);

	texture.Load(_T("Graph/tex.png"));
	texture.SetDivide(4, 1);
}

void Map::SetMapArray(int Height, int Width, std::ifstream& data, int *array)
{
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			//最初に0で初期化
			array[i*Width + j] = 0;
		}
	}
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			//初期化したところにmapTextのデータを入れる
			data >> array[i*Width + j];
		}
	}
}

void Map::Draw()
{
	for (int y = 0; y < GetMapHeight(); y++)
	{
		for (int x = 0; x < GetMapWidth(); x++)
		{
			//マップの描画
			//描画の起点が中心なのでPIXEL/2をプラスする
			sprite.SetPos((float)(PIXEL*x + PIXEL / 2), (float)(PIXEL*y + PIXEL / 2));

			//ブロックの描画
			switch (GetMapBlock(x, y))
			{
			case 1://壁
				texture.SetNum(0, 0);
				sprite.Draw(texture);
				break;

			case 2:
				break;

			case 3:
				break;

			default:
				break;
			}
		}
	}
}

void Map::Hit(Player* player)
{
	int playerNowX = player->PlayerX() / PIXEL;
	int playerNowY = player->PlayerY() / PIXEL;
	for (int x = 0; x < GetMapHeight(); x++)
	{
		for (int y = 0; y < GetMapWidth(); y++)
		{
			mapBlock[x + y*mapHeight];
			if (mapBlock[playerNowX + playerNowY*mapWidth] == 1)
			{

			}
		}
	}
}