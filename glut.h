#pragma once
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <GL/glut.h>
#include <cstdlib>
#include <time.h>
#include <iostream>

#define WALKSPD 0.05
#define WINWIDTH 800
#define WINHEIGHT 600

using namespace std;

namespace player
{
	// (X1,Y1) = player1ÀÇ ¿ÞÂÊ À§ ÁÂÇ¥, (X2,Y2) = player1ÀÇ ¿À¸¥ÂÊ ¾Æ·¡ ÁÂÇ¥
	float playerX1 = -0.1;
	float playerY1 = 0.1;
	float playerX2 = 0.1;
	float playerY2 = -0.1;
}

void keyListener(int key, int x, int y);
void changeSize(int w, int h);
void idle(int);
void display();
