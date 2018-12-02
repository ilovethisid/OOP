#include "glut.h"

using namespace angle;
using namespace player;
using namespace mouse;
using namespace speed;

int main(int argc, char** argv)
{
	glut GLUT;
	GLUT.startFramework(argc, argv);
	return 0;
}

void glut::startFramework(int argc, char** argv)
{
	Map Map;
	mapsetting(Map);

	// Init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH) / 2 - WINWIDTH / 2, glutGet(GLUT_SCREEN_HEIGHT) / 2 - WINHEIGHT / 2); // ����Ǵ� ���� ��ġ
	glutInitWindowSize(WINWIDTH, WINHEIGHT);     // �����Ǵ� ������ ũ��
	glutCreateWindow("Test Game"); // ������ �̸����� �����츦 ������

	glutDisplayFunc(display);
	glutReshapeFunc(changeSize);
	glutTimerFunc((1000 / FPS), idle, 0);

	glutSpecialFunc(keyListener); // Ű���� Ư��Ű �Է� ó��
	glutMouseFunc(mouseClick);
	glutMainLoop();
}

void glut::changeSize(int w, int h)
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

void glut::display()
{
	// ��� �׸���
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ���� �����
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(-1, 1.4, 1, -0.6);

	// �� �׸���
	for (int i = 0; i < MapLength; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (MAP[i][j] == 1)
			{
				glColor3f(0.0f, 0.0f, 1.0f);
				glRectf(LUcornerX + 0.2*(float)j, LUcornerY - 0.2*(float)i, RDcornerX + 0.2*(float)j, RDcornerY - 0.2*(float)i);
			}
		}
	}

	glClear(GL_DEPTH_BUFFER_BIT); // ���� ���� �����
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(objectLeftUpX, objectLeftUpY, objectRightDownX, objectRightDownY);

	glutSwapBuffers();

	glFlush(); // �׿��ִ� ��� ����
}

void glut::idle(int) // ���߹��ۿ� �� �Լ�
{
	if (V_jump != 0.0) // ���� ����� �� (���� �ӵ��� 0�� ��)
	{
		characterLocationY += V_jump;
		V_jump -= gravity;
	}

	if (V_horizon > 0.0)
	{
		characterLocationX += V_horizon;
		//V_horizon -= friction;
	}
	else if (V_horizon < 0.0)
	{
		characterLocationX += V_horizon;
		//V_horizon += friction;
	}

	if (characterLocationY < Down_angle)
	{
		Top_angle -= anglemovespeed;
		Down_angle -= anglemovespeed;
		glTranslatef(0.0, anglemovespeed, 0.0);
	}
	else if (characterLocationY > Top_angle)
	{
		Top_angle += anglemovespeed;
		Down_angle += anglemovespeed;
		glTranslatef(0.0, (-1 * anglemovespeed), 0.0);

	}
	else
	{
		// ȭ�� ����
	}
	glutPostRedisplay();
	glutTimerFunc((1000 / FPS), idle, 0);
}

void glut::mapsetting(Map Map)
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

void glut::keyListener(int key, int x, int y)
{
	//Ű���� ���⿡ ���� ��ġ�̵�
	if (GetKeyState(VK_LEFT) < 0)
	{
		characterLocationX -= WALKSPD;
	}
	else if (GetKeyState(VK_RIGHT) < 0)
	{
		characterLocationX += WALKSPD;
	}

	if (GetKeyState(VK_UP) < 0)
	{
		characterLocationY += WALKSPD;
	}
	else if (GetKeyState(VK_DOWN) < 0)
	{
		characterLocationY -= WALKSPD;
	}

	glutPostRedisplay();
}

void glut::mouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseX1 = x;
		mouseY1 = y;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		mouseX2 = x;
		mouseY2 = y;
		V_horizon += (mouseX1 - mouseX2)*(0.0001);
		V_jump += (mouseY1 - mouseY2)*(-0.0001);
	}
	glutPostRedisplay();
}