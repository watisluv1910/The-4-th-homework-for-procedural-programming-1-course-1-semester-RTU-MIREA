#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h> // printf
#include <fstream> // for working with file
#include <stdlib.h> // for rand, srand
#include <time.h> // for time
#include "Header.h" // for running f4_1 or f4_2
#include <iomanip> // for setw
#include <vector> // for vector

using namespace std;

double inicializeNotNegativeDouble() { // function that check type error
	double temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var) || temp_var < 0)
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		// operator >> will no longer fetch data from the stream
		// as it is in the wrong format
	}
	return temp_var;
}

double inicializeDouble() { // function that check type error
	double temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var))
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		// operator >> will no longer fetch data from the stream
		// as it is in the wrong format
	}
	return temp_var;
}

int inicializeNotNegativeInteger() { // function that check type error
	int temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var) || temp_var < 0)
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		// operator >> will no longer fetch data from the stream 
		// as it is in the wrong format
	}
	return temp_var;
}

int inicializeInteger() { // function that check type error
	int temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var))
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		// operator >> will no longer fetch data from the stream as 
		// it is in the wrong format
	}
	return temp_var;
}

void f1File() {
	ofstream fout; // output file stream (writing)
	string path = "text_file_f1.txt"; // path to the file
	fout.open(path); 
	if (!fout.is_open()) // chacking for the successful
	{
		cout << "File opening error." << endl;
	}
	else
	{	
		srand(time(0)); // randomizing depends on time
		float variable;
		for (size_t i = 0; i < 10; i++)
		{
			variable = (rand() % 100 - 50) / 10.0f; // gets random float var
			fout << variable << endl;
		}
	}
	fout.close(); // closing file 
	ifstream fin; // input file stream (reading)
	fin.open(path);
	if (!fin.is_open()) // chacking for the successful
	{
		cout << "File opening error." << endl;
	}
	else
	{
		float sum = 0;
		cout << "Numbers written in the file: " << endl;
		while (!fin.eof()) // true while not end of file
		{	
			float var;
			fin >> var; // reading numbers
			cout << var << endl;
			sum += var;
		}
		cout << "Sum of numbers written in the file is: " << sum << ".\n";
	}
	fin.close(); // closing file
}

int defineSign(int a) { // for f2
	if (a > 0)
	{
		return 1; // according to the task
	}
	else if (a == 0)
	{
		return 0; // according to the task
	}
	else
	{
		return -1; // according to the task
	}
}

void f2NumberSign() {
	cout << "Enter the number, which sign is needed to be defined:\n";
	int x = inicializeInteger();
	cout << "The sign of entered number is euqal to  "
		 << defineSign(x) << " according to the task.\n";
}

double computeSquareRectangle(double a, double b) { // for f3
	return a * b; // the formula of rectangle's square
}

double computeSquareTriangle(double h, double x) { // for f3
	return h * x / 2; // the formula of triangle's square
}

double computeSquareCircle(double r) { // for f3
	return M_PI * pow(r, 2); // the formula of circle's square
}

void f3GeometricFigures() {
	cout << "Enter:\n1, if you need to compute S of rectangle.\n"
		"2, if you need to compute S of triangle.\n"
		"3, if you need to compute S of circle.\n"
		"Entered value:\n";
	int chose = inicializeNotNegativeInteger(); // choosing figure
	if (chose == 1)
	{
		cout << "Enter the values of the sides of the rectangle:\n";
		double a = inicializeNotNegativeDouble();
		double b = inicializeNotNegativeDouble();
		cout << "S of rectangle = " << computeSquareRectangle(a, b) << ".\n";
	}
	else if (chose == 2)
	{
		cout << "Enter the values of base length and height drawn to it:\n";
		double h = inicializeNotNegativeDouble();
		double x = inicializeNotNegativeDouble();
		cout << "S of triangle = " << computeSquareTriangle(h, x) << ".\n";
	}
	else if (chose == 3)
	{
		cout << "Enter the value of circle radius:\n";
		double r = inicializeNotNegativeDouble();
		cout << "S of circle = " << computeSquareCircle(r) << ".\n";
	}
	else
	{
		cout << "Number of figures can't be more than 3.\nTry again.\n";
	}
}

void f4PastGlory() {
	//realisation 3:
	for (int i = 0; i < 13; ++i) { // number of lines is 13
		if (i < 6) { // lines with * and /
			if (0 == i % 2) { // if line is even
				for (int j = 0; j < 8; ++j) { // fill by *
					cout << "  *";
				}
				cout.width(60);
				cout << setw(60) << setfill('/'); // fill the rest of line by /
			}
			else { // if line is uneven
				cout << " "; 
				for (int j = 0; j < 8; ++j) { 
					cout << "*  ";
				}
			}
			cout << '\n'; // go to next line
		}

	}
	for (int i = 1; i < 8; ++i) // fill the rest lines (without *)
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

void f5SinusoidGraph() {
	system("\"D:/Microsoft VS source/C++/Home Tasks/1 курс/ДЗ №5 на 6ю неделю/"
		   "Task 5 (graph)/Debug/Task 5 (graph).exe\""); // path to the file
}

bool isCorrect(string romanNumber) { 
	// check for 4 and more identical elements in a row:
	if (romanNumber.length() > 3) { // check for acces to compare 4 elements
		for (size_t i = 0; i != romanNumber.length() - 3; i++) {
			if (romanNumber[i] == romanNumber[i + 1] &&
				romanNumber[i + 1] == romanNumber[i + 2] &&
				romanNumber[i + 2] == romanNumber[i + 3]) { // comparing
				return false;
			}
		}
	}
	char romanNumbers[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	// belonging of the element of the entered number to the roman num alphabet
	for (size_t i = 0; i < romanNumber.length(); i++) {	
		bool isromanNumber = false; 
		for (size_t j = 0; j < 7; j++) {
			if (romanNumber[i] == romanNumbers[j]) {
				isromanNumber = true;
			}
		}
		if (!isromanNumber) {
			return false;
		}
	}
	return true;
}

void f6AutomaticRecognizer() {
	cout << "Enter romanian number:\n";
	string romanNumber;
	cin >> romanNumber;
	if (isCorrect(romanNumber)) { // if number is correct according to rules
		char romanNumbers[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
		// equal to romanian numbers
		int arabicNumbers[7] = { 1, 5, 10, 50, 100, 500, 1000 };
		int arabicNumber = 0; // final decimal arabic number
		// iteration over all elements of the entered roman number:
		for (size_t i = 0; i < romanNumber.length(); i++) {
			// iteration over all roman numbers to compare with certain element:
			for (size_t j = 0; j < 7; j++) {
				if (romanNumber[i] == romanNumbers[j]) { // possibility to
					// compare with next element:
					if (i + 1 < romanNumber.length()) { 
						// iteration over all roman numbers to compare with
						// next element:
						for (size_t k = 0; k < 7; k++) { // i
							if (romanNumber[i + 1] == romanNumbers[k]) {
								if (j < k) {
									// if certain < next
									arabicNumber -= arabicNumbers[j]; 
								}
								else {
									arabicNumber += arabicNumbers[j];
								}
							}
						}
					}
					else { // if elem if the last it can't be below zero
						arabicNumber += arabicNumbers[j];
					}
				}
			}
		}
		cout << "Entered roman number is euqal to "<< arabicNumber
			 << " decimal arabic number.\n"; 
	}
	else { // if number is uncorrect
		cout << "Wrong number entered.\n"
				"Try again and enter the number correctly.\n";
	}
}

void generatePseudoRandomNumber(int path) {
	int nS = 0, m, a, c;
	// options depends on chose:
	if (path == 0) {
		cout << "Enter the value of multiplier m:\n";
		m = inicializeInteger();
		cout << "Enter the value of increment a:\n";
		a = inicializeInteger();
		cout << "Enter the sequence range c:\n";
		c = inicializeInteger();
	}
	else if (path == 1) { // I set
		m = 37;
		cout << "Enter the value of multiplier m: " << m << ".\n";
		a = 3;
		cout << "Enter the value of increment a: " << a << ".\n";
		c = 64;
		cout << "Enter the sequence range c: " << c << ".\n";
	}
	else { // II set
		m = 25173;
		cout << "Enter the value of multiplier m: " << m << ".\n";
		a = 13849;
		cout << "Enter the value of increment a: " << a << ".\n";
		c = 65537;
		cout << "Enter the sequence range c: " << c << ".\n";
	}
	cout << "Enter the number of elements in a sequence maxLen:\n";
	int maxLen = inicializeNotNegativeInteger();
	cout << endl;
	for (int i = 0; i < maxLen; i++) { // generation by iteration
		nS = (m * nS + a) % c;
		cout << "Pseudorandom number is: " << nS << ".\n";
	}
	cout << endl;
}

void f7PseudoRandomNumberGenerator() {
	cout << "Choose:\n1, to continue with entering numbers.\n"
			"2, to continue with prepared sets of numbers.\n";
	int choosePath = inicializeNotNegativeInteger();
	switch (choosePath) {
	case 1 :
		generatePseudoRandomNumber(0);
		break;
	case 2 :
		cout << "Choose:\n1, to continue with I set of numbers.\n"
			    "2, to continue with II set of numbers.\n";
		choosePath = inicializeNotNegativeInteger();
		switch (choosePath) {
		case 1 :
			generatePseudoRandomNumber(1);
			break;
		case 2 :
			generatePseudoRandomNumber(2);
			break;
		}
		break;
	default :
		cout << "Entered number doesn't match the suggested.\nTry again.\n";
		break;
	}
}

void f8MatrixMultiplication() {
	float productsArray[3][4] = { {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} };
	float profitsArray[3][2] = { 0 };
	float pricesArray[4][2] = { {1.2, 0.5}, {2.8, 0.4}, {5.0, 1.0}, {2.0, 1.5} };
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

	float sumProfit = 0.0, sumCommision = 0.0, maxProfitSeller, 
		  maxCommissionSeller, minProfitSeller, minCommissionSeller;

	float minProfit = numeric_limits<float>::max(), minCommision = minProfit, 
		  maxProfit = numeric_limits<float>::lowest(), 
		  maxCommision = maxProfit;

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
	cout << "\nОтветы на вопросы задачи:\n1)" << maxProfitSeller 
		 << "й продавец выручил больше всего денег с продаж, " 
		 << minProfitSeller << "й продавец выручил меньше всего "
			"денег с продаж.\n";
	cout << "2)" << maxCommissionSeller 
		 << "й продавец получил наибольшие коммисионные с продаж, " 
		 << minCommissionSeller << "й продавец получил наименьшие "
			"коммисионные с продаж.\n";
	cout << "3)Общая сумма денег, вырученных за проданные товары, равна " 
		 << sumProfit << ".\n4)Общая сумма коммиссионых, "
			"полученных продавцами, равна " << sumCommision << ".\n";
	cout << "5)Общая сумма денег, прошедших через руки продавцов, равна " 
		 << sumProfit + sumCommision << ".\n\n";
}

void f9NumberSystems() {
	string number, number_end;
	int ss1, ss2, number_int = 0;
	cout << "Enter the number:\n";
	cin >> number;
	cout << "Enter original number system:\n";
	ss1 = inicializeNotNegativeInteger();
	cout << "Enter final number result:\n";
	ss2 = inicializeNotNegativeInteger();
	vector <char> alphabet; // inicialization of not-fixed len vector
	for (size_t i = 65; i < 65 + 26; i++) 
	{
		alphabet.push_back((char)i); // appending letter to the end of vector
	}
	// reversed iteration for transfer to decimal system:
	for (int i = number.length()-1; i >= 0; i--) 
	{
		char rank_s = number[i]; 
		// if char is letter:
		if (find(alphabet.begin(), alphabet.end(), rank_s) != alphabet.end())  
		{
			number_int += (static_cast<int>(rank_s) - 55) * pow(ss1, (number.length() - 1 - i));
		}
		// if char is number:
		else 
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
	cout << "Final result: " << number_end << ".\n";
}

int main() {
	int chooseTask;
	setlocale(LC_ALL, "Russian");
	cout << "Hello!\nTask number can't be more than 9.\n" 
			"Enter 0 to end the programm.\n"
			"Enter the task number: \n";
	chooseTask = inicializeNotNegativeInteger();
	while (chooseTask > 0) {
		switch (chooseTask) {
		case 1 :
			f1File();
			break;
		case 2 :
			f2NumberSign();
			break;
		case 3 :
			f3GeometricFigures();
			break;
		case 4 :
			f4PastGlory();
			break;
		case 5 :
			f5SinusoidGraph();
			break;
		case 6 :
			f6AutomaticRecognizer();
			break;
		case 7 :
			f7PseudoRandomNumberGenerator();
			break;
		case 8 :
			f8MatrixMultiplication();
			break;
		case 9 :
			f9NumberSystems();
			break;
		default :
			cout << "Entered task number is incorrect, try again.\n"
					"Task number can't be more than 9.\n"
					"Enter 0 to end the programm.\n";
			break;
		}
		cout << "Enter the next task number:\n";
		chooseTask = inicializeNotNegativeInteger();;
	}
}