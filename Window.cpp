#define _CRT_SECURE_NO_WARNINGS

#include "Window.h"

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

Window::Window(const char* wintitle)
{
	char winsetting[256] = { '\0', };

	sprintf(winsetting, "mode con: cols=%d lines=%d|title=%s", WINWIDTH, WINHEIGHT, wintitle);
	system(winsetting);
}

void Window::gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


