#include <iostream>
#define _USE_MATH_DEFINES
#define NOMINMAX
#include <windows.h>
#include <math.h>
#include <string>
#include <stdio.h> // printf
#include <fstream> // for working with file
#include <stdlib.h> // for rand, srand
#include <time.h> // for time
#include <iomanip> // for setw
#include <vector>
#include <sstream>

using namespace std;

//function that check type error or "border crossing"
int initializeInteger(string path, int lowerBound, int upperBound) {
	bool isCorrect = false;
	int temporaryVariable;
	while (!isCorrect) {
		string temporaryVariableString;
		cin >> temporaryVariableString;
		isCorrect = true;
		for (size_t i = 0; i < 128; i++) {
			if ((i < (int)'0' || i >(int)'9') && i != (int)'-') {
				if (temporaryVariableString.find((char)i) != string::npos) {
					isCorrect = false;
				}
			}
		}
		if (isCorrect) {
			temporaryVariable = stoi(temporaryVariableString);
			if (lowerBound != 0 || upperBound != 0) {
				if (temporaryVariable < lowerBound
					|| temporaryVariable > upperBound) {
					cout << "Initialization error.\nEnter correct value:\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					isCorrect = false;
					// operator >> will no longer fetch data from the stream 
					// as it is in the wrong format
				}
			}
			else if (path == "allExceptZero" && temporaryVariable == 0 ||
				path == "negative" && temporaryVariable >= 0 ||
				path == "notpositive" && temporaryVariable > 0 ||
				path == "notnegative" && temporaryVariable < 0 ||
				path == "positive" && temporaryVariable <= 0) {
				cout << "Initialization error.\nEnter correct value:\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				isCorrect = false;
			}
		}
		else {
			cout << "Initialization error.\nEnter correct value:\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return temporaryVariable;
}

// function that check type error or "border crossing"
double initializeDouble(string path, double lowerBound, double upperBound) {
	bool isCorrect = false;
	double temporaryVariable;
	while (!isCorrect) {
		string temporaryVariableString;
		cin >> temporaryVariableString;
		isCorrect = true;
		for (size_t i = 0; i < 128; i++) {
			if ((i < (int)'0' || i >(int)'9') &&
				i != (int)'-' && i != (int)'.') {
				if (temporaryVariableString.find((char)i) != string::npos) {
					isCorrect = false;
				}
			}
		}
		if (isCorrect) {
			// turns a string into a stream:
			istringstream stringStream(temporaryVariableString);
			stringStream >> temporaryVariable; // reads data from the stream
			if (lowerBound != 0.0 || upperBound != 0.0) {
				if (temporaryVariable < lowerBound ||
					temporaryVariable > upperBound) {
					cout << "Initialization error.\nEnter correct value:\n";
					cin.clear();
					// operator >> will no longer fetch data from the stream:
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					isCorrect = false;
				}
			}
			else if (path == "allExceptZero" && temporaryVariable == 0.0 ||
				path == "negative" && temporaryVariable >= 0.0 ||
				path == "notpositive" && temporaryVariable > 0.0 ||
				path == "notnegative" && temporaryVariable < 0.0 ||
				path == "positive" && temporaryVariable <= 0.0) {
				cout << "Initialization error.\nEnter correct value:\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				isCorrect = false;
			}
		}
		else {
			cout << "Initialization error.\nEnter correct value:\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return temporaryVariable;
}

void f1File() {
	ofstream fout; // output file stream (writing)
	string path = "text_file_f1.txt"; // path to the file
	fout.open(path); 
	if (!fout.is_open()) { // checking for the successful opening
		cout << "\nFile opening error.\n";
	}
	else {	
		srand(time(0)); // randomizing depends on time
		float variable;
		for (size_t i = 0; i < 10; i++) {
			variable = (rand() % 100 - 50) / 10.0f; // gets random float var
			fout << variable << endl;
		}
	}
	fout.close(); // closing file 
	ifstream fin; // input file stream (reading)
	fin.open(path);
	if (!fin.is_open()) { // chacking for the successful
		cout << "\nFile opening error.\n";
	}
	else {
		float sum = 0;
		cout << "\nNumbers written in the file:\n";
		while (!fin.eof()) { // true while not end of file
			float variable;
			fin >> variable; // reading numbers
			cout << variable << endl;
			sum += variable;
		}
		cout << "\nSum of numbers written in the file is: " << sum << ".\n";
	}
	fin.close(); // closing file
}

int defineSign(double a) { // for f2
	if (a > 0) {
		return 1; // according to the task
	}
	else if (a == 0.0) {
		return 0;
	}
	else {
		return -1;
	}
}

void f2NumberSign() {
	cout << "\nEnter the number, which sign is needed to be defined:\n";
	double x = initializeDouble("all", 0.0, 0.0);
	cout << "\nThe sign of entered number is equal to "
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
	cout << "\nEnter:\n1, if you need to compute S of rectangle.\n"
		"2, if you need to compute S of triangle.\n"
		"3, if you need to compute S of circle.\n";
	int choise = initializeInteger("all", 1, 3); // choosing figure
	switch (choise) {
	case 1: {
			cout << "\nEnter the values of the sides of the rectangle:\n";
			double a = initializeDouble("positive", 0, 0);
			double b = initializeDouble("positive", 0, 0);
			cout << "\nS of rectangle = " << computeSquareRectangle(a, b) << ".\n";
			break;
	}
	case 2: {
			cout << "\nEnter the values of base length "
				"and height of the triangle:\n";
			double h = initializeDouble("positive", 0, 0);
			double x = initializeDouble("positive", 0, 0);
			cout << "\nS of triangle = " << computeSquareTriangle(h, x) << ".\n";
			break;
	}
	case 3: {
			cout << "\nEnter the value of circle radius:\n";
			double r = initializeDouble("positive", 0, 0);
			cout << "\nS of circle = " << computeSquareCircle(r) << ".\n";
			break;
	}
	}
}

void f4PastGlory() {
	cout << endl;
	for (int i = 0; i < 13; i++) { // number of lines is 13
		if (i < 6) { // lines with * and /
			if (i % 2 == 0) { // if line is even
				for (int j = 0; j < 8; j++) { // fill by *
					cout << "\x1b[34m  *\x1b[0m";
				}
				cout << ' ';
				for (size_t i = 0; i < 60; i++)	{
					cout << "\x1b[31m/\x1b[0m";
				} // fill the rest of line by /
			}
			else { // if line is uneven
				cout << " "; 
				for (int j = 0; j < 8; j++) { 
					cout << "\x1b[34m*  \x1b[0m";
				}
				for (size_t i = 0; i < 60; i++) {
					cout << '/';
				} // fill the rest of line by /
			}
			cout << endl; // go to next line
		}

	}
	for (int i = 1; i < 8; ++i) { // fill the rest lines (without *)
		if (i % 2 == 0) {
			for (size_t i = 0; i < 85; i++) {
				cout << '/';
			}
			cout << endl;
		}
		else {
			for (size_t i = 0; i < 85; i++) {
				cout << "\x1b[31m/\x1b[0m";
			}
			cout << endl;
		}
	}
}

void f5SinusoidGraph() {
	cout << "\nEnter 1, if you want to see window application graph.\n"
		"Enter 2, if you want to see console graph.\n\nEntered value:\n";
	int path = initializeInteger("all", 1, 2);
	switch (path) {
	case 1:
		system("\"D:/Microsoft VS source/C++/Home Tasks/1 курс/"
			"ДЗ №5 на 6ю неделю/Task 5 (graph)/Debug/Task 5 (graph).exe\"");
		break;
	case 2: {
		cout << endl;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int height = 30;
		int length = 180;
		string array[30][180];
		for (int y = 0; y < height; ++y) {
			for (int x = 0; x < length; ++x) {
				int y = (sin(x * 4 * M_PI / length) + 1) / 2 * height;
				if ((y >= 0) && (y < height)) {
					array[y][x] = "0";
				}
			}
		}
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < length; x++) {
				if (array[y][x] == "") {
					if (y == 0 && x == length / 2) {
						cout << "^";
					}
					else if (y == height / 2 - 1 && x == length - 1) {
						cout << ">";
					}
					else if (y == 0 && x == length / 2 + 2) {
						cout << "Y";
					}
					else if (y == height / 2 && x == length - 1) {
						cout << "X";
					}
					else if (y == height / 2 - 1) {
						cout << "-";
					}
					else if (x == length / 2) {
						cout << "|";
					}
					else {
						cout << " ";
					}
				}
				else {
					cout << array[y][x];
				}
			}
			cout << endl;
		}
		break;
	}
	}
}

bool isCorrect(string romanNumber) { 
	char romanNumbers[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	int arabicNumbers[7] = { 1, 5, 10, 50, 100, 500, 1000 };
	// belonging of the element of the entered number to the roman num alphabet
	for (size_t i = 0; i < romanNumber.length(); i++) {	
		bool isRomanNumber = false;
		for (size_t j = 0; j < 7; j++) {
			if (romanNumber[i] == romanNumbers[j]) {
				isRomanNumber = true;
			}
		}
		if (!isRomanNumber) {
			return false;
		}
	}
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
	// check for 2 and more identical numbers less than the next not identical
	if (romanNumber.length() > 2) {
		for (size_t i = romanNumber.length() - 1; i != 1; i--) {
			int indexOfCurrent, indexOfNext;
			for (size_t j = 0; j < 7; j++) {
				if (romanNumber[i] == romanNumbers[j]) {
					indexOfCurrent = j;
				}
				if (romanNumber[i - 1] == romanNumbers[j]) {
					indexOfNext = j;
				}
			}
			if (arabicNumbers[indexOfCurrent] > arabicNumbers[indexOfNext] &&
				romanNumber[i - 1] == romanNumber[i - 2]) { // comparing
				return false;
			}
		}
	}
	return true;
}

void f6AutomaticRecognizer() {
	cout << "\nEnter roman number:\n";
	string romanNumber;
	cin >> romanNumber;
	if (isCorrect(romanNumber)) { // if number is correct according to rules
		char romanNumbers[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
		// equal to romanian numbers
		int arabicNumbers[7] = { 1, 5, 10, 50, 100, 500, 1000 };
		int arabicNumber = 0; // final decimal arabic number
		// iteration over all elements of the entered roman number:
		for (size_t i = 0; i < romanNumber.length(); i++) {
			// iteration over all roman numbers to compare with certain elem:
			for (size_t j = 0; j < 7; j++) {
				if (romanNumber[i] == romanNumbers[j]) { 
					// possibility to compare with next element: 
					if (i + 1 < romanNumber.length()) { 
						// iteration over all roman numbers to compare with
						// the next element:
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
		cout << "\nEntered roman number is euqal to "<< arabicNumber
			 << " decimal arabic number.\n"; 
	}
	else { // if number is uncorrect
		cout << "\nWrong number entered.\n"
				"Try again and enter the number correctly.\n";
	}
}

void generatePseudoRandomNumber(int path) {
	int nS = 0, m, a, c;
	// options depends on chose:
	if (path == 0) {
		cout << "\nEnter the value of multiplier m:\n";
		m = initializeInteger("allExceptZero", 0, 0);
		cout << "Enter the value of increment a:\n";
		a = initializeInteger("all", 0, 0);
		cout << "Enter the value of sequence range c:\n";
		c = initializeInteger("allExceptZero", 0, 0);
	}
	else if (path == 1) { // I set
		m = 37;
		cout << "\nThe value of multiplier m: " << m << ".\n";
		a = 3;
		cout << "The value of increment a: " << a << ".\n";
		c = 64;
		cout << "The value of sequence range c: " << c << ".\n";
	}
	else { // II set
		m = 25173;
		cout << "\nThe value of multiplier m: " << m << ".\n";
		a = 13849;
		cout << "The value of increment a: " << a << ".\n";
		c = 65537;
		cout << "The value of sequence range c: " << c << ".\n";
	}
	cout << "\nEnter the number of elements in a sequence maxLen:\n";
	int maxLen = initializeInteger("positive", 0, 0);
	cout << endl;
	for (int i = 0; i < maxLen; i++) { // generation by iteration
		nS = (m * nS + a) % c;
		cout << "Pseudorandom number is: " << nS << ".\n";
	}
}

void f7PseudoRandomNumberGenerator() {
	cout << "\nEnter:\n1, to continue with entering numbers.\n"
		"2, to continue with prepared sets of numbers.\n";
	int choosePath = initializeInteger("all", 1, 2);
	switch (choosePath) {
	case 1 :
		generatePseudoRandomNumber(0);
		break;
	case 2 :
		cout << "\nEnter:\n1, to continue with I set of numbers.\n"
			"2, to continue with II set of numbers.\n";
		choosePath = initializeInteger("all", 1, 2);
		generatePseudoRandomNumber(choosePath);
		break;
	}
}

void f8MatrixMultiplication() {
	double productsArray[3][4] = { {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} },
		profitsArray[3][2] = { 0 },
		pricesArray[4][2] = { {1.2, 0.5}, {2.8, 0.4}, {5.0, 1.0}, {2.0, 1.5} };
	cout << "\nMatrix C = A * B:\n";
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
	double sumProfit = 0.0, sumCommision = 0.0, maxProfitSeller, 
		  maxCommissionSeller, minProfitSeller, minCommissionSeller;
	double minProfit = numeric_limits<double>::max(), minCommision = minProfit, 
		  maxProfit = numeric_limits<double>::lowest(), 
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
	cout << "\nAnswers to the questions of the task:\n1)" << maxProfitSeller
		 << " seller received the most amount of money from sales, "
		 << minProfitSeller << " seller received the least amount "
		    "of money from sales.\n";
	cout << "2)" << maxCommissionSeller 
		 << " seller received the highest amount of commission from sales, " 
		 << minCommissionSeller << " seller received the least amount "
			"of commission from sales.\n";
	cout << "3)The total amount of money received for sold goods is " 
		 << sumProfit << ".\n4)The total amount of commision "
			"received by sellers is " << sumCommision << ".\n";
	cout << "5)The total amount of money, "
			"passed through the hands of sellers is " 
		 << sumProfit + sumCommision << ".\n";
}

void f9NumberSystems() {
	string number, numberEnd;
	long numberInteger = 0;
	float numberFloat = 0.0f;
	cout << "\nEnter the number (if the number if fractal, use (,)):\n";
	cin >> number;
	int ss1, ss2;
	cout << "\nEnter original number system:\n";
	ss1 = initializeInteger("all", 2, 36);
	cout << "\nEnter final number system:\n";
	ss2 = initializeInteger("all", 2, 36);
	vector <char> alphabet; // initialization of non-fixed len vector
	for (size_t i = 65; i < 65 + 26; i++) {
		alphabet.push_back((char)i); // appending letter to the end
	}
	int pointIndex = number.find(","); // check point place
	//int pointIndexInteger = number.find(",");
	if (pointIndex == string::npos) { // if there is no , in number
		// reversed iteration for transfer to decimal system:
		for (int i = number.length() - 1; i >= 0; i--) {
			char rankCh = number[i];
			// if char is letter:
			if (find(alphabet.begin(), alphabet.end(), rankCh) != alphabet.end()) {
				numberInteger += (static_cast<long>(rankCh) - 55) * 
					pow(ss1, (number.length() - 1 - i));
			}
			// if char is number:
			else {
				numberInteger += (static_cast<long>(rankCh) - 48) * 
					pow(ss1, (number.length() - 1 - i));
			}
		}
		while (numberInteger > 0) { // transfer to ss2
			if (numberInteger % ss2 >= 10) { // transfer number to letter
				char rankCh = (char)((numberInteger % ss2) + 55);
				numberEnd = rankCh + numberEnd;
			}
			else {
				numberEnd = to_string(numberInteger % ss2) + numberEnd;
			}
			numberInteger /= ss2; // <= rank
		}
	}
	else { // if , is in number
		// reversed iteration for transfer to decimal system before point:
		for (int i = pointIndex - 1; i >= 0; i--) {
			char rankCh = number[i];
			// if char is letter:
			if (find(alphabet.begin(), alphabet.end(), rankCh) != alphabet.end()) {
				numberInteger += (static_cast<long>(rankCh) - 55) * 
					pow(ss1, (pointIndex - 1 - i));
			}
			// if char is number:
			else {
				numberInteger += (static_cast<long>(rankCh) - 48) * 
					pow(ss1, (pointIndex - 1 - i));
			}
		}
		// reversed iteration for transfer to decimal system after point:
		for (int i = number.length() - 1; i > pointIndex; i--) {
			char rankCh = number[i];
			// if char is letter:
			if (find(alphabet.begin(), alphabet.end(), rankCh) 
				!= alphabet.end()) {
				numberFloat += (static_cast<long>(rankCh) - 55) *
					pow(ss1, (-1 * (i - pointIndex)));
			}
			// if char is number:
			else {
				numberFloat += (static_cast<long>(rankCh) - 48) *
					pow(ss1, (-1 * (i - pointIndex)));
			}
		}
		// fractional number in decimal system:
		float numberDecimal = numberInteger + numberFloat; 
		while (numberInteger > 0) { // transfer integer part to ss2
			if (numberInteger % ss2 >= 10) { // transfer number to letter
				char rankCh = (char)((numberInteger % ss2) + 55);
				numberEnd = rankCh + numberEnd;
			}
			else {
				numberEnd = to_string(numberInteger % ss2) + numberEnd;
			}
			numberInteger /= ss2; // <= rank
		}
		numberEnd += ","; // adding the point to integer
		string numberFloatString = to_string(numberFloat);
		pointIndex = numberFloatString.find(",");
		float transferAccuracy = 1.0f / 
			pow(ss2, numberFloatString.length() - 1 - pointIndex);
		// transfer fractional part to ss2:
		int counterOfRanks = 0;
		cout << "\nEnter needful number of ranks after (,):\n";
		int maxCountOfRanks = initializeInteger("positive", 0, 0);
		while (stof(numberFloatString.substr(numberFloatString.find(",") + 1, 
			numberFloatString.length() - 1 - numberFloatString.find(","))) > 
			transferAccuracy) {
			numberFloatString = to_string(numberFloat *= ss2);
			// integer part of numberFloat:
			string integerPart = 
				numberFloatString.substr(0, numberFloatString.find(","));
			// transfer number to letter:
			if (stoi(integerPart) % ss2 >= 10) {
				if (counterOfRanks >= maxCountOfRanks) {
					break;
				}
				else {
					char rankCh = (char)(stoi(integerPart) % ss2 + 55);
					numberEnd = numberEnd + rankCh;
					counterOfRanks++;
				}
			}
			else {
				if (counterOfRanks >= maxCountOfRanks) {
					break;
				}
				else {
					numberEnd = numberEnd + to_string(stoi(integerPart) % ss2);
					counterOfRanks++;
				}
			}
		}
	}
	cout << "\nFinal result is: " << numberEnd << ".\n";
}

int main() {
	int chooseTask;
	setlocale(LC_ALL, "Russian");
	cout << "Hello!\nTask number can't be more than 9.\n" 
			"Enter 0 to end the programm.\n"
			"Enter the task number: \n";
	chooseTask = initializeInteger("all", 0, 9);
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
		}
		cout << "\nEnter the next task number:\n";
		chooseTask = initializeInteger("all", 0, 9);
	}
}
