#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h> // printf
#include <fstream> // for working with file
#include <stdlib.h> // for rand, srand
#include <time.h> // for time

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
		for (size_t i = 0; i < 10; i++)
		{
			fout << rand() % 100 << endl;
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
		int sum = 0;
		cout << "Записанные в файл элементы: " << endl;
		while (!fin.eof()) // true while not end of file
		{	
			int var = 0;
			fin >> var;
			cout << var << endl;
			sum += var;
		}
		cout << "Сумма записанных в файл чисел равна: " << sum << endl;
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

}

void f5() {

}

void f6() {

}

void f7() {

}

void f8() {

}

void f9() {

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