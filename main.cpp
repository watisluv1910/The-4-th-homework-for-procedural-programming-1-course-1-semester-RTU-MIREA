#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h> // printf
#include <fstream> // for working with file
#include <stdlib.h> // for rand, srand
#include <time.h> // for time
#include "Header.h" // for running f4_1 or f4_2
#include <iomanip> // for f4 setw
#include <vector> // for f9 vector

using namespace std;

double err_check() { // function that check type error
	double temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var) || temp_var < 0)
	{
		cout << "Ошибка ввода.\nВведите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

double err_check_for_negative() { // function that check type error
	double temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var))
	{
		cout << "Ошибка ввода.\nВведите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

int err_check_int() { // function that check type error
	int temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var) || temp_var < 0)
	{
		cout << "Ошибка ввода.\nВведите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

int err_check_int_for_negative() { // function that check type error
	int temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var))
	{
		cout << "Ошибка ввода.\nВведите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

void f1() {
	ofstream fout; // output file stream (writing)
	string path = "text_file_f1.txt"; // path to the file
	fout.open(path); 
	if (!fout.is_open()) // chacking for the successful
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{	
		srand(time(NULL)); // randomizing depends on time
		float variable;
		for (size_t i = 0; i < 10; i++)
		{
			variable = (rand() % 100 - 50) / 10.0;
			fout << variable << endl;
		}
	}
	fout.close(); // closing file 
	ifstream fin; // input file stream (reading)
	fin.open(path);
	if (!fin.is_open()) // chacking for the successful
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{
		float sum = 0;
		cout << "Записанные в файл элементы: " << endl;
		while (!fin.eof()) // true while not end of file
		{	
			float var;
			fin >> var;
			cout << var << endl;
			sum += var;
		}
		cout << "Сумма записанных в файл чисел равна: " << sum << "." << endl;
	}
	fin.close(); // closing file
}

int sign_definition(int a) { // for f2
	if (a > 0)
	{
		return 1;
	}
	else if (a == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void f2() {
	cout << "Введите число, знак которого нужно определить:" << endl;
	int x = err_check_int_for_negative();
	cout << "Знак введёного числа соответствует числу " << sign_definition(x) << " в предоставленной системе." << endl;
}

double S_rectangle(double a, double b) { // for f3
	return a * b;
}

double S_triangle(double h, double x) { // for f3
	return h * x / 2;
}

double S_round(double r) { // for f3
	return M_PI * pow(r, 2);
}

void f3() {
	cout << "Введите:\n1, если хотите посчитать S прямоугольника.\n2, если хотите посчитать S треугольника.\n3, если хотите посчитать S круга.\nВведённое значение:\n";
	int chose = err_check_int(); // choosing figure
	if (chose == 1)
	{
		cout << "Введите значения сторон прямоугольника:\n";
		double a = err_check();
		double b = err_check();
		cout << "S прямоугольника = " << S_rectangle(a, b) << "." << endl;
	}
	else if (chose == 2)
	{
		cout << "Введите значения длин основания и проведённой к нему высоты:\n";
		double h = err_check();
		double x = err_check();
		cout << "S треугольника = " << S_triangle(h, x) << "." << endl;
	}
	else if (chose == 3)
	{
		cout << "Введите значение радиуса круга:\n";
		double r = err_check();
		cout << "S круга = " << S_round(r) << "." << endl;
	}
	else
	{
		cout << "Количество данных фигур не превышает 3.\n";
	}
}

void f4() {
	//realisation 3:
	for (int i = 0; i < 13; ++i)
	{
		if (i < 6) {
			if (0 == i % 2) {
				for (int j = 0; j < 8; ++j)
				{
					cout << "  *";
				}
				cout.width(60);
				cout << setw(60) << setfill('/');
			}
			else {
				cout << " ";
				for (int j = 0; j < 8; ++j)
					cout << "*  ";
			}
			cout << '\n';
		}

	}
	for (int i = 1; i < 8; ++i)
	{
		if (0 == i % 2)
		{
			cout << setw(84) << setfill(' ') << '\n';
		}
		else
		{
			cout << setw(84) << setfill('/') << '\n';
		}
	}
}

void f5() {
	int 
}

void f6() {

}

void f7() {

}

void f8() {

}

void f9() {
	string number, number_end;
	int ss1, ss2, number_int = 0;
	cout << "Введите число:\n";
	cin >> number;
	cout << "Введите изначальную систему счисления:\n";
	ss1 = err_check_int();
	cout << "Введите конечную систему счисления:\n";
	ss2 = err_check_int();
	vector <char> alphabet; // inicialization of not-fixed len vector
	for (size_t i = 65; i < 65 + 26; i++) 
	{
		alphabet.push_back((char)i); // appending letter to the end of vector
	}
	for (int i = number.length()-1; i >= 0; i--) // reversed iteration for transfer to decimal sys
	{
		char rank_s = number[i]; 
		if (find(alphabet.begin(), alphabet.end(), rank_s) != alphabet.end()) // if char is letter 
		{
			number_int += (static_cast<int>(rank_s) - 55) * pow(ss1, (number.length() - 1 - i));
		}
		else // if char is number
		{
			number_int += (static_cast<int>(rank_s) - 48) * pow(ss1, (number.length() - 1 - i));
		}
	}
	while (number_int > 0) // transfer to ss2
	{
		if (number_int % ss2 >= 10) // transfer number to letter
		{
			char rank_ch = (char)((number_int % ss2) + 55);
			number_end = rank_ch + number_end;
		}
		else
		{
			number_end = to_string(number_int % ss2) + number_end;
		}
		number_int /= ss2; // <= rank
	}
	cout << "Итоговый результат: " << number_end << "." << endl;
}

int main() {
	int counter;
	setlocale(LC_ALL, "Russian");
	cout << "Номер задачи не превышает 9.\n" << "Чтобы закончить работу, введите 0.\n";
	cout << "Введите номер задачи: \n";
	counter = err_check_int();
	while (counter > 0)
	{
		switch (counter)
		{
		case 1:
			f1();
			break;
		case 2:
			f2();
			break;
		case 3:
			f3();
			break;
		case 4:
			f4();
			break;
		case 5:
			f5();
			break;
		case 6:
			f6();
			break;
		case 7:
			f7();
			break;
		case 8:
			f8();
			break;
		case 9:
			f9();
			break;
		default:
			cout << "Номер задачи не превышает 9.\n" << "Чтобы закончить работу, введите 0.\n";
			break;
		}
		cout << "Введите номер следующей задачи: \n";
		cin >> counter;
	}
}