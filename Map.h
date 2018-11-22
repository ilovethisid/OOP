#pragma once

#include <ctime>
#include <stdlib.h>

#define MAPWIDTH 15
#define MAPHEIGHT 13

// ��
class Map
{
	struct waterBalloonType
	{
		int player; // ������ ��ǳ������ (1 : player1, 2 : player2)
		int wtrBln; // ��ǳ�� ���� (0 : ��ǳ�� ����, 1 : ��ǳ�� ����)
	};
	struct elements
	{
		int character;                         // ĳ���� (0 : player ���� X, 1 : player1 , 2 : player2)
		struct waterBalloonType waterBalloon;
		int feature;                          // �������� (0 : �ƹ��͵� ���� ��, 1 : ���� �� �ִ� ��, 2 : ���� �� ���� ��)
		int popRange;                         // ��ǳ�� ���� ���� (0 : ��ǳ���� ������ ���� X, 1 : ��ǳ���� ������ ���� O)
		int item;                             // ������ (1 : ��ǳ��(��ǳ�� ���� +1 ����), 2 : ����(��ǳ���� ���ٱ� ���� +1 ����), 3 : �ѷ�������Ʈ(ĳ������ �̵��ӵ� ����), 4 : �ٴ�(��ǳ���� ������ �� ����ϸ� Ż��))
	};
	struct elements gameMap[MAPHEIGHT][MAPWIDTH];
public:
	void initMap()
	{
		for (int i = 0; i < MAPHEIGHT; i++)
		{
			for (int j = 0; j < MAPWIDTH; j++)
			{
				gameMap[i][j].character = 0;
				gameMap[i][j].waterBalloon.player = 0;
				gameMap[i][j].waterBalloon.wtrBln = 0;
				gameMap[i][j].popRange = 0;
			}
		}
	}
	int getCharacter(int x, int y)
	{
		return gameMap[x][y].character;
	}
	int getWhoseWaterBalloon(int x, int y)
	{
		return gameMap[x][y].waterBalloon.player;
	}
	int getWaterBalloon(int x, int y)
	{
		return gameMap[x][y].waterBalloon.wtrBln;
	}
	int getFeature(int x, int y)
	{
		return gameMap[x][y].feature;
	}
	int getPopRange(int x, int y)
	{
		return gameMap[x][y].popRange;
	}
	int getItem(int x, int y)
	{
		return gameMap[x][y].item;
	}
	void setCharacter1(int x, int y)
	{
		gameMap[x][y].character = 1;
	}
	void setCharacter2(int x, int y)
	{
		gameMap[x][y].character = 2;
	}
	void setPlayer1WaterBalloon(int x, int y) // ��ǳ���� ���� ������ player1 �Է�
	{
		gameMap[x][y].waterBalloon.player = 1;
	}
	void setPlayer2WaterBalloon(int x, int y) // ��ǳ���� ���� ������ player2 �Է�
	{
		gameMap[x][y].waterBalloon.player = 2;
	}
	void setWaterBalloon(int x, int y)
	{
		gameMap[x][y].waterBalloon.wtrBln = 1;
	}
	void setFeature0(int x, int y)
	{
		gameMap[x][y].feature = 0;
	}
	void setFeature1(int x, int y)
	{
		gameMap[x][y].feature = 1;
	}
	void setFeature2(int x, int y)
	{
		gameMap[x][y].feature = 2;
	}
	void setPopRange(int x, int y)
	{
		gameMap[x][y].popRange = 1;
	}
	void resetPopRange(int x, int y)
	{
		gameMap[x][y].popRange = 0;
	}
	void setItem(int x, int y)
	{
		srand((unsigned int)time(NULL));
		gameMap[x][y].item = rand() % 4 + 1;
	}
};

class Map1 : public Map
{
public:
	void map1Setting();
};