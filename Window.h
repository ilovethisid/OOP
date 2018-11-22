#pragma once

#define WINWIDTH 100
#define WINHEIGHT 30

class Window
{
public:
	Window();
	Window(const char* wintitle);

	void gotoxy(int x, int y); // window상의 특정 위치(x, y)로 커서를 이동시키는 함수
	void hideCursor();
};

