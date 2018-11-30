#pragma once
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <GL/glut.h>
#include <Windows.h>
#include <WinUser.h>
#include "Map.h"
//#include "Game.h"

#define WALKSPD 0.5
#define gravity 0.0002   // �߷�
#define friction 0.0002  // ������
#define WINWIDTH 800
#define WINHEIGHT 600
#define FPS 80
#define gameover 0
#define anglemovespeed 0.03 // ȭ�� ������ �ӵ�
#define jumpmovespeed 0.03  // ���� ������ �ӵ�
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
	// (X1,Y1) = player1�� ���� �� ��ǥ, (X2,Y2) = player1�� ������ �Ʒ� ��ǥ
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
	static void mouseClick(int button, int motion, int x, int y); // ���콺 Ŭ�� ����
	static void mousePassiveMotion(int x, int y);                 // ���콺 Ŭ�� �ȵ��� �� ���콺 ��ġ
	static void mouseActiveMotion(int x, int y);                  // ���콺 Ŭ���ϸ鼭 �����̴� ���콺 ��ġ
	static void keyListener(int key, int x, int y);
	static void changeSize(int w, int h);
	static void idle(int);
	static void display();
	static void mapsetting(Map);
	void startFramework(int argc, char** argv);
};