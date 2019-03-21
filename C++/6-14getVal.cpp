//6-14getVal.cpp			Written by Kyle Mason
//This program uses functions to determine if an integer is even or odd

#include "stdafx.h"
#include <iostream>
using namespace std;

// Function prototype
bool isEven(int);
int getVal(int);

int main()
{
	int valNum = 0;        // the value to be tested

	cout << "Hello User!\n" << endl;
	valNum = getVal(valNum);

	// Indicate whether it is even or odd
	if (isEven(valNum))
		cout << valNum << " is even.\n";
	else
		cout << valNum << " is odd.\n";
	return 0;
}





//Functions
bool isEven(int number)
{
	if (number % 2 == 0)
		return true;   // The number is even if there's no remainder 
	else
		return false;  // Otherwise, the number is odd 
}

int getVal(int valInt)
{
	// Get a number from the user
	do {
		cout << "Enter an integer between -999 and 999, and I will tell you ";
		cout << "if it is even or odd: ";
		cin >> valInt;
		if (valInt > 999 || valInt < -999)
			cout << "This number is out of range.\n" << endl;
	} while (valInt > 999 || valInt < -999);

	return valInt;
}