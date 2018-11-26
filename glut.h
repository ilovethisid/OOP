#pragma once
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <gl/glut.h>
#include <cstdlib>
#include <ctime>

#define WALKSPD 0.05
#define WINWIDTH 800
#define WINHEIGHT 600

namespace player
{
	// (X1,Y1) = player1의 왼쪽 위 좌표, (X2,Y2) = player1의 오른쪽 아래 좌표
	float playerX1 = -0.1;
	float playerY1 = 0.1;
	float playerX2 = 0.1;
	float playerY2 = -0.1;
}