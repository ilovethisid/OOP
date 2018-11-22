#pragma once

#include "Window.h"

#define MAPWIDTH 100
#define MAPHEIGHT 30


class Map
{
	class Tile
		// 맵의 한 타일
	{
	protected:
		int x, y; // 타일의 위치
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
		int player; // 물풍선 주인
		int duration; // 물풍선 지속시간
		int poplength; // 터질때 길이

	public:
		WaterBalloon();

		void pop(); // 물풍선이 터지는 함수
	};

	class Character :Tile
	{
	private:
		int player; // 플래이어 1 또는 2

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
		bool rigid; // 단단한 오브젝트인지(통과가 가능하면 0, 아니면 1)

	public:
		Block();
	};

	class Needle :Tile
		// 바늘
	{
	private:
		int tag;

	public:
		Needle();
	};

private:
	Tile tile[MAPHEIGHT][MAPWIDTH]; // 맵상의 타일들
	Window win; // 콘솔창

public:
	Map();
	Map(Window);

	void draw();
};