#pragma once

#define WINWIDTH 100
#define WINHEIGHT 30

class Window
{
public:
	Window();
	Window(const char* wintitle);

	void gotoxy(int x, int y); // window���� Ư�� ��ġ(x, y)�� Ŀ���� �̵���Ű�� �Լ�
	void hideCursor();
};

