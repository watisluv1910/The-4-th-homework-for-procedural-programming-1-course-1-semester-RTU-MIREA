//realisation 1:
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

int f4_1() {
	cout << 45325;
	POINT op;
	HWND hWnd = GetConsoleWindow(); //Получаем дескриптор окна консоли
	HDC hDC = GetDC(hWnd); //Получаем контекст устройства по полученному дескриптору
	SelectObject(hDC, GetStockObject(WHITE_PEN)); //Выбираем перо WHITE_PEN в контекст

	MoveToEx(hDC, 50, 50, &op); //Ставим текущую точку в координаты 50,50
	LineTo(hDC, 100, 200); //Рисуем линию из текущей точки в точку 100, 200

	ReleaseDC(hWnd, hDC); //"Освобождаем" контекст
	cin.get();
	return 0;
}