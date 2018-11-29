#include <Windows.h>
#include <WinUser.h>

#include "glut.h"

using namespace player;
using namespace angle;

int initial_time = clock();
int final_time;
int frame_count = 0;

int main(int argc, char** argv)
{
	Map Map;
	mapsetting(Map);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH) / 2 - WINWIDTH / 2, glutGet(GLUT_SCREEN_HEIGHT) / 2 - WINHEIGHT / 2); // 실행되는 시작 위치
	glutInitWindowSize(WINWIDTH, WINHEIGHT);     // 생성되는 윈도우 크기
	glutCreateWindow("Test Game"); // 설정한 이름으로 윈도우를 생성함

	glutDisplayFunc(display);
	glutReshapeFunc(changeSize);
	glutTimerFunc((1000 / FPS), idle, 0);

	glutSpecialFunc(keyListener); // 키보드 특수키 입력 처리
	glutMainLoop();
	return 0;
}

void changeSize(int w, int h)
{
	// 창이 아주 작을 때, 0으로 나누는 것을 예방
	if (h == 0)
		h = 1;
	float ratio = 1.0* w / h;

	// 좌표계를 수정하기 전에 초기화
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//뷰포트를 창의 전체 크기로 설정
	glViewport(0, 0, w, h);

	//투시값을 설정
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, -1.0, 0.0f, 1.0f, 0.0f);
}

void display()
{
	
	// 배경 그리기
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 버퍼 지우기
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(-1, 1.4, 1, -0.6);
	
	// 맵 그리기
	for (int i = 0; i < MapLength; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (MAP[i][j] == 1)
			{
				glColor3f(0.0f, 0.0f, 1.0f);
				glRectf(LUcornerX+0.2*(float)j,LUcornerY-0.2*(float)i,RDcornerX+0.2*(float)j,RDcornerY-0.2*(float)i);
			}
		}
	}

	glClear(GL_DEPTH_BUFFER_BIT); // 깊이 버퍼 지우기
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(playerX1, playerY1, playerX2, playerY2);

	glutSwapBuffers();

	frame_count++;
	final_time = clock();

	glFlush(); // 쌓여있는 명령 지움
}

void keyListener(int key, int x, int y)
{
	//키보드 방향에 따른 위치이동
	if (GetKeyState(VK_LEFT) < 0)
	{
		playerX1 -= WALKSPD;
		playerX2 -= WALKSPD;
	}
	else if (GetKeyState(VK_RIGHT) < 0)
	{
		playerX1 += WALKSPD;
		playerX2 += WALKSPD;
	}

	if (GetKeyState(VK_UP) < 0)
	{
		playerY1 += WALKSPD;
		playerY2 += WALKSPD;
	}
	else if (GetKeyState(VK_DOWN) < 0)
	{
		playerY1 -= WALKSPD;
		playerY2 -= WALKSPD;
	}

	glutPostRedisplay();
}

void idle(int) // 이중버퍼에 들어갈 함수
{
	if (playerY2 < Down_angle)
	{
		Top_angle -= anglemovespeed;
		Down_angle -= anglemovespeed;
		glTranslatef(0.0, anglemovespeed, 0.0);
	}
	else if (playerY1 > Top_angle)
	{
		Top_angle += anglemovespeed;
		Down_angle += anglemovespeed;
		glTranslatef(0.0, (-1 * anglemovespeed), 0.0);

	}
	else
	{
		// 화면 고정
	}
	glutPostRedisplay();
	glutTimerFunc((1000 / FPS), idle, 0);
}

void mapsetting(Map Map)
{
	for (int i = 0; i < MapLength; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (Map.getXY(i, j) == 1)
			{
				MAP[i][j] = 1;
			}
			else
			{
				MAP[i][j] = 0;
			}
		}
	}
}