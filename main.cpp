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

double inizializeDouble() { // function that check type error
	double temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var) || temp_var < 0)
	{
		cout << "Ошибка ввода.\nВведите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

double inicializeDoubleNegative() { // function that check type error
	double temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var))
	{
		cout << "Ошибка ввода.\nВведите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

int inizializeInteger() { // function that check type error
	int temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var) || temp_var < 0)
	{
		cout << "Ошибка ввода.\nВведите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

int inizializeIntegerNegative() { // function that check type error
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

int defineSign(int a) { // for f2
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
	int x = inizializeIntegerNegative();
	cout << "Знак введёного числа соответствует числу " << defineSign(x) << " в предоставленной системе." << endl;
}

double computeSquareRectangle(double a, double b) { // for f3
	return a * b;
}

double computeSquareTriangle(double h, double x) { // for f3
	return h * x / 2;
}

double computeSquareCircle(double r) { // for f3
	return M_PI * pow(r, 2);
}

void f3() {
	cout << "Введите:\n1, если хотите посчитать S прямоугольника.\n2, если хотите посчитать S треугольника.\n3, если хотите посчитать S круга.\nВведённое значение:\n";
	int chose = inizializeInteger(); // choosing figure
	if (chose == 1)
	{
		cout << "Введите значения сторон прямоугольника:\n";
		double a = inizializeDouble();
		double b = inizializeDouble();
		cout << "S прямоугольника = " << computeSquareRectangle(a, b) << "." << endl;
	}
	else if (chose == 2)
	{
		cout << "Введите значения длин основания и проведённой к нему высоты:\n";
		double h = inizializeDouble();
		double x = inizializeDouble();
		cout << "S треугольника = " << computeSquareTriangle(h, x) << "." << endl;
	}
	else if (chose == 3)
	{
		cout << "Введите значение радиуса круга:\n";
		double r = inizializeDouble();
		cout << "S круга = " << computeSquareCircle(r) << "." << endl;
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
	system("\"D:/Microsoft VS source/C++/Home Tasks/1 курс/ДЗ №5 на 6ю неделю/Task 5 (graph)/Debug/Task 5 (graph).exe\"");
}

void f6() {
	
}

void f7() {

}

void f8() {
	float productsArray[3][4] = { {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} };
	float profitsArray[3][2] = { 0 };
	float pricesArray[4][2] = { {1.2, 0.5}, {2.8, 0.4}, {5, 1}, {2, 1.5} };
	cout << endl << "Матрица C = A * B:\n\n";
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 4; j++) {
			// i - index of seller
			// j - index of product
			// 0 - index of price
			// 1 - index of commision
			profitsArray[i][0] += productsArray[i][j] * pricesArray[j][0];
			profitsArray[i][1] += productsArray[i][j] * pricesArray[j][1];
		}
		cout << profitsArray[i][0] << "\t" << profitsArray[i][1] << endl;
	}

	float sumProfit = 0, sumCommision = 0, maxProfitSeller, maxCommissionSeller, minProfitSeller, minCommissionSeller;

	float minProfit = numeric_limits<float>::max(), minCommision = minProfit, maxProfit = numeric_limits<float>::lowest(), maxCommision = maxProfit;

	for (size_t i = 0; i < 3; i++) {

		for (size_t k = 0; k < 2; k++) {

			if (k == 0) {

				if (profitsArray[i][k] > maxProfit) {
					maxProfit = profitsArray[i][k];
					maxProfitSeller = i + 1;
				}
				if (profitsArray[i][k] < minProfit) {
					minProfit = profitsArray[i][k];
					minProfitSeller = i + 1;
				}
				sumProfit += profitsArray[i][k];
			}
			else {
				if (profitsArray[i][k] > maxCommision) {
					maxCommision = profitsArray[i][k];
					maxCommissionSeller = i + 1;
				}
				if (profitsArray[i][k] < minCommision) {
					minCommision = profitsArray[i][k];
					minCommissionSeller = i + 1;
				}
				sumCommision += profitsArray[i][k];
			}
		}
	}
	cout << "\nОтветы на вопросы задачи:\n1)" << maxProfitSeller << "й продавец выручил больше всего денег с продаж, " << minProfitSeller << "й продавец выручил меньше всего денег с продаж.\n";
	cout << "2)" << maxCommissionSeller << "й продавец получил наибольшие коммисионные с продаж, " << minCommissionSeller << "й продавец получил наименьшие коммисионные с продаж.\n";
	cout << "3)Общая сумма денег, вырученных за проданные товары, равна " << sumProfit << ".\n4)Общая сумма коммиссионых, полученных продавцами, равна " << sumCommision << ".\n";
	cout << "5)Общая сумма денег, прошедших через руки продавцов, равна " << sumProfit + sumCommision << ".\n\n";
}

void f9() {
	string number, number_end;
	int ss1, ss2, number_int = 0;
	cout << "Введите число:\n";
	cin >> number;
	cout << "Введите изначальную систему счисления:\n";
	ss1 = inizializeInteger();
	cout << "Введите конечную систему счисления:\n";
	ss2 = inizializeInteger();
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
	counter = inizializeInteger();
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
		counter = inizializeInteger();;
	}
}