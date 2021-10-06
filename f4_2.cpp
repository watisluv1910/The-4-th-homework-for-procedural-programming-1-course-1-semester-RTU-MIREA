//realisation 2:
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;
bool a = true;
int num;
string text = "'Былая слава' - 1912 г.'";

void f4_2() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (a == true) {
		cout << "Печать 'Былой славы'. Для отрисовки нажмите любую клавишу, для выхода - ESC." << endl;
		num = _getch();
		if (num == 27)
		{
			exit(0);
		}
		else {
			system("cls");
			cout << endl;
			for (int z = 0; z < text.length(); z++)
			{
				Sleep(100);
				cout << text[z];
			}
			cout << endl << endl;
			for (int j = 0; j < 8; j++)
			{
				Sleep(100);
				cout << "-" << " ";
			}
			for (int j = 0; j < 15; j++)
			{
				Sleep(100);
				cout << (char)127;
			}
			cout << endl;
			for (int i = 1; i <= 48; i++)
			{
				Sleep(100);
				cout << "*" << " ";
				if (i % 8 == 0) {
					if (i == 16 || i == 32 || i == 48) {
						for (int j = 0; j < 15; j++) {
							Sleep(100);
							cout << (char)127;
						}
					}
					cout << endl;
				}
			}
			for (int q = 0; q < 3; q++) {
				Sleep(100);
				cout << endl;
				for (int j = 0; j <= 30; j++)
				{
					Sleep(100);
					cout << (char)127;
				}
				cout << endl;
			}
		}
		cout << endl << endl << endl;
		cout << "Для повторного запуска программы нажми любую клавишу, для выхода - ESC:";
		num = _getch();
		if (num == 27)
		{
			exit(0);
		}
		else
		{
			system("cls");
			continue;
		}
	}
}