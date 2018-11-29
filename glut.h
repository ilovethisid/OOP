#pragma once
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <GL/glut.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Map.h"

#define WALKSPD 0.5
#define WINWIDTH 800
#define WINHEIGHT 600
#define FPS 80
#define gravity 3   // 중력
#define jumpspeed 7 // 점프하는 순간 속력
#define gameover 0
#define anglemovespeed 0.03 // 화면 움직임 속도
#define LUcornerX -1
#define LUcornerY 1.4
#define RDcornerX -0.8
#define RDcornerY 1.2

using namespace std;

namespace player
{
	// (X1,Y1) = player1의 왼쪽 위 좌표, (X2,Y2) = player1의 오른쪽 아래 좌표
	float playerX1 = -0.1;
	float playerY1 = 0.1;
	float playerX2 = 0.1;
	float playerY2 = -0.1;
}
namespace angle
{
	float Top_angle = 1;
	float Down_angle = -1;
}

int MAP[10][10];

void keyListener(int key, int x, int y);
void changeSize(int w, int h);
void idle(int);
void display();
void mapsetting(Map);