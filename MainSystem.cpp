#include <Windows.h>
#include <WinUser.h>

#include "glut.h"

#define FPS 30
#define gravity 3   // �߷�
#define jumpspeed 7 // �����ϴ� ���� �ӷ�
#define gameover 0

using namespace player;

int initial_time = time(NULL);
int final_time;
int frame_count = 0;
int Top_angle;
int Down_angle;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH) / 2 - WINWIDTH / 2, glutGet(GLUT_SCREEN_HEIGHT) / 2 - WINHEIGHT / 2); // ����Ǵ� ���� ��ġ
	glutInitWindowSize(WINWIDTH, WINHEIGHT);     // �����Ǵ� ������ ũ��
	glutCreateWindow("Test Game"); // ������ �̸����� �����츦 ������

	glutDisplayFunc(display);
	glutReshapeFunc(changeSize);
	glutTimerFunc((1000 / FPS), idle, 0);

	glutSpecialFunc(keyListener); // Ű���� Ư��Ű �Է� ó��
	glutMainLoop();
	return 0;
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

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ���� �����
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(-1.5, 1.5, 1.5, -1.5);

	glClear(GL_DEPTH_BUFFER_BIT); // ���� ���� �����
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(playerX1, playerY1, playerX2, playerY2);

	glutSwapBuffers();

	frame_count++;
	final_time = time(NULL);
	if (final_time - initial_time > 0)
	{
		cout << "FPS : " << frame_count / (final_time - initial_time) << endl;
		frame_count = 0;
		initial_time = final_time;
	}

	glFlush(); // �׿��ִ� ��� ����
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

void idle(int) // ���߹��ۿ� �� �Լ�
{
	glutPostRedisplay();
	glutTimerFunc((1000 / FPS), idle, 0);
	if (playerY2 < Down_angle)
	{
		Top_angle -= 0.05;
		Down_angle -= 0.05;
		glTranslatef(0.0, -0.05, 0.0);
	}
	if (playerY1 > Top_angle)
	{
		Top_angle += 0.05;
		Down_angle += 0.05;
		glTranslatef(0.0, 0.05, 0.0);

	}
	playerY1 -= 0.05;
	playerY2 -= 0.05;
}