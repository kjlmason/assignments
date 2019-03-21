//5-08for.cpp					-Written by Kyle Mason
/* This program averages test scores, and uses a do-while loop
that allows the code to repeat as many times as the user wishes. */
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int userScore[99], totalScore = 0, scoreNum;
	double scoreAverage;
	char doAgain;

	cout << "Hello User!" << endl;

	do
	{
		// Get test scores
		cout << "\nEnter a set of test scores (as intergers) and I will average them." << endl;
		cout << "Enter a negative number to stop adding scores: ";

		totalScore = 0;

		for (scoreNum = 0; scoreNum < 999; scoreNum++)
		{
			cin >> userScore[scoreNum];
			if (userScore[scoreNum] < 0)
				break;
			totalScore += userScore[scoreNum];

		}

		cout << scoreNum << " test scores have been entered.\n" << endl;
		// Calculate and display the average
		scoreAverage = totalScore / scoreNum;
		cout << "The average is " << scoreAverage << "\n\n";

		// Does the user want to average another set?
		cout << "Do you want to average another set? (Y/N) ";
		cin >> doAgain;


	} while (doAgain == 'Y' || doAgain == 'y');

	cout << "Goodbye!\n" << endl;
	return 0;
}
