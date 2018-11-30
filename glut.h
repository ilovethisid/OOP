#pragma once
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <GL/glut.h>
#include <Windows.h>
#include <WinUser.h>
#include "Map.h"
//#include "Game.h"

#define WALKSPD 0.5
#define gravity 0.0002   // 중력
#define friction 0.0002  // 마찰력
#define WINWIDTH 800
#define WINHEIGHT 600
#define FPS 80
#define gameover 0
#define anglemovespeed 0.03 // 화면 움직임 속도
#define jumpmovespeed 0.03  // 점프 움직임 속도
#define LUcornerX -1
#define LUcornerY 1.4
#define RDcornerX -0.8
#define RDcornerY 1.2

using namespace std;

namespace angle
{
	float Top_angle = 0;
	float Down_angle = -1;
}

namespace player
{
	// (X1,Y1) = player1의 왼쪽 위 좌표, (X2,Y2) = player1의 오른쪽 아래 좌표
	float playerX1 = -0.1;
	float playerY1 = 0.1;
	float playerX2 = 0.1;
	float playerY2 = -0.1;
}

namespace mouse
{
	int mouseX1;
	int mouseY1;
	int mouseX2;
	int mouseY2;
}

namespace speed
{
	float V_jump = 0.0;
	float V_horizon = 0.0;
}

int MAP[10][10];

class glut
{
public:
	static void mouseClick(int button, int motion, int x, int y); // 마우스 클릭 여부
	static void mousePassiveMotion(int x, int y);                 // 마우스 클릭 안됐을 때 마우스 위치
	static void mouseActiveMotion(int x, int y);                  // 마우스 클릭하면서 움직이는 마우스 위치
	static void keyListener(int key, int x, int y);
	static void changeSize(int w, int h);
	static void idle(int);
	static void display();
	static void mapsetting(Map);
	void startFramework(int argc, char** argv);
};