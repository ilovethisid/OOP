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

	glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH) / 2 - WINWIDTH / 2, glutGet(GLUT_SCREEN_HEIGHT) / 2 - WINHEIGHT / 2); // ����Ǵ� ���� ��ġ
	glutInitWindowSize(WINWIDTH, WINHEIGHT);     // �����Ǵ� ������ ũ��
	glutCreateWindow("Test Game"); // ������ �̸����� �����츦 ������
	glutDisplayFunc(Map1);
	glutReshapeFunc(changeSize); // â�� ũ�Ⱑ ���ص� ������ ������ �ʰ� ���ش�.

	glutSpecialFunc(keyListener); // Ű���� Ư��Ű �Է� ó��

	glEnable(GL_DEPTH_TEST); // ���� �˻簡 �����ϵ��� �����Ѵ�.
	glutMainLoop();

	return 0;
}

void Map1()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ���� �����
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(-1.5, 1.5, 1.5, -1.5);

	glClear(GL_DEPTH_BUFFER_BIT); // ���� ���� �����
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(playerX1, playerY1, playerX2, playerY2);

	glFlush();
}


void changeSize(int w, int h)
{
	// â�� ���� ���� ��, 0���� ������ ���� ����
	if (h == 0)
		h = 1;
	float ratio = 1.0* w / h;

	// ��ǥ�踦 �����ϱ� ���� �ʱ�ȭ
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//����Ʈ�� â�� ��ü ũ��� ����
	glViewport(0, 0, w, h);

	//���ð��� ����
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, -1.0, 0.0f, 1.0f, 0.0f);
}

void keyListener(int key, int x, int y)
{
	//Ű���� ���⿡ ���� ��ġ�̵�
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