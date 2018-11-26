#include <Windows.h>
#include <WinUser.h>

#include "glut.h"

using namespace player;

void Map1();
void keyListener(int key, int x, int y);
void changeSize(int w, int h);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH) / 2 - WINWIDTH / 2, glutGet(GLUT_SCREEN_HEIGHT) / 2 - WINHEIGHT / 2); // 실행되는 시작 위치
	glutInitWindowSize(WINWIDTH, WINHEIGHT);     // 생성되는 윈도우 크기
	glutCreateWindow("Test Game"); // 설정한 이름으로 윈도우를 생성함
	glutDisplayFunc(Map1);
	glutReshapeFunc(changeSize); // 창의 크기가 변해도 비율은 변하지 않게 해준다.

	glutSpecialFunc(keyListener); // 키보드 특수키 입력 처리

	glEnable(GL_DEPTH_TEST); // 깊이 검사가 가능하도록 설정한다.
	glutMainLoop();

	return 0;
}

void Map1()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 버퍼 지우기
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(-1.5, 1.5, 1.5, -1.5);

	glClear(GL_DEPTH_BUFFER_BIT); // 깊이 버퍼 지우기
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(playerX1, playerY1, playerX2, playerY2);

	glFlush();
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