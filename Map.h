#pragma once

#include "Window.h"

#define MAPWIDTH 100
#define MAPHEIGHT 30


class Map
{
	class Tile
		// ���� �� Ÿ��
	{
	protected:
		int x, y; // Ÿ���� ��ġ
		char* type;
		// type: WaterBalloon, Character, Land, Block

	public:
		Tile();
		Tile(int x, int y);
	};



	// types of tiles

	class WaterBalloon :Tile
	{
	private:
		int player; // ��ǳ�� ����
		int duration; // ��ǳ�� ���ӽð�
		int poplength; // ������ ����

	public:
		WaterBalloon();

		void pop(); // ��ǳ���� ������ �Լ�
	};

	class Character :Tile
	{
	private:
		int player; // �÷��̾� 1 �Ǵ� 2

	public:
		Character();
	};

	class Land :Tile
	{
	public:
		Land();
	};

	class Block :Tile
	{
	private:
		bool rigid; // �ܴ��� ������Ʈ����(����� �����ϸ� 0, �ƴϸ� 1)

	public:
		Block();
	};

	class Needle :Tile
		// �ٴ�
	{
	private:
		int tag;

	public:
		Needle();
	};

private:
	Tile tile[MAPHEIGHT][MAPWIDTH]; // �ʻ��� Ÿ�ϵ�
	Window win; // �ܼ�â

public:
	Map();
	Map(Window);

	void draw();
};