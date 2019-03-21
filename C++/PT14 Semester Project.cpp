//Semester Project.cpp          Written by Kyle Mason
//Calculates the monthly payments for a mortgage over a set time.

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

double roundOff(double userValue);


int main()
{
	//Data
	const int MONTH = 9999, DATA = 4;
	double userData[MONTH][DATA]; //Holds money values for each month
	int userYears = 0, userMonths = 0, currentMonth = 0, currentData = 0; //User Info
	double  userPrinciple, interestRate, payPerMonth = 1, prinBalance,  //Money Info
			dollarInterest, dollarToPrin = 0, monthlyRate, lastValue;
	string userName;
	char runAgain;

	cout << "Hello User, what is your name?:";
	getline(cin, userName);
	cout << "\nHello " << userName << "!" << endl;
	cout << "This program will help you calculate a mortgage and find" << endl;
	cout << "the minumum amount of money needed monthly to pay it off." << endl;

	//Program Loop
	do {

		//Get Required Info
		cout << "\nPlease enter the principle in dollars and cents format (0.00): $";
		cin >> userPrinciple;

		cout << "Please input the payment time in years as an integer: ";
		cin >> userYears;

		cout << "Please enter interest rate as a percentage: ";
		cin >> interestRate;

		//Convert info
		interestRate = interestRate / 100; //Percentage to Decimal Value
		userMonths = userYears * 12;  //Years into Months
		monthlyRate = interestRate / 12; //Yearly interest rate into Monthly interest Rate

		//Save Initial Info (Data)
		double firstUserPrinciple = userPrinciple;

		do {
			//Reset Data
			userPrinciple = firstUserPrinciple;
			prinBalance = 0;
			dollarInterest = 0;
			dollarToPrin = 0;

			//Calculation Loop
			for (currentMonth = 0; currentMonth < userMonths; currentMonth++)
			{
				userData[currentMonth][0] = userPrinciple; // [][0] = Principle

				dollarInterest = userPrinciple * monthlyRate; //calculate interest
				userData[currentMonth][1] = dollarInterest; //[][1] = Interest

				dollarToPrin = payPerMonth - dollarInterest; // calculate $ to Prin
				dollarToPrin = roundOff(dollarToPrin); //round to cents
				userData[currentMonth][2] = dollarToPrin; // [][2] = $ to Prin

				prinBalance = userPrinciple - dollarToPrin; // calculate Prin Balance
				prinBalance = roundOff(prinBalance);	//round to cents
				userData[currentMonth][3] = prinBalance; //[][3] = Prin Balance

				userPrinciple = prinBalance; //New Principle for next month
			}

			if (prinBalance > 0)
				payPerMonth += 0.01;		//Check last prinBalance, if not negative increase PPM

		} while (prinBalance > 0);  //Check last prinBalance, if not negative run again

		//Get last payment
		lastValue = payPerMonth + prinBalance;
		lastValue = roundOff(lastValue);


		/*********************************PRINT TABLE***********************************/

		//TableData
		cout << "\n**********************************************************************" << endl;
		cout << "Principle = $" << userData[0][0] << "    ";
		cout << "Rate = " << (interestRate * 100) << "%         ";
		cout << "Monthly Interest Rate = " << monthlyRate << endl;
		cout << "Pay/Mo. = $" << setprecision(2) << fixed << payPerMonth << "       ";
		cout << "Years = " << userYears << "            ";
		cout << "Total Months = " << userMonths << "      " << endl;

		//Table
		cout << "\nMonth    Principle    Interest    $ to Prin   Prin Balance\n";
		for (currentMonth = 0; currentMonth < userMonths; currentMonth++)
		{
			if (currentMonth < 3 || currentMonth > (userMonths - 4))
			{
				cout << setw(3) << (currentMonth + 1) << "    ";
				for (currentData = 0; currentData < DATA; currentData++)
				{
					if (userData[currentMonth][currentData] > 0)
						cout << "$" << setprecision(2) << fixed << setw(10) << userData[currentMonth][currentData] << "  ";
					else // on a negative number
						cout << "($" << setprecision(2) << fixed << setw(10) << fabs(userData[currentMonth][currentData]) << ")  ";
				}
				cout << "\n";
			}
			else if (currentMonth == (userMonths / 2))
				cout << "---------------------------------------------------------" << endl;
		}

		cout << "The last monthly payment is $" << setprecision(2) << fixed << lastValue << "\n" << endl;
		cout << "**********************************************************************\n" << endl;

		/**********************************************************************************/

		//Ask to run the program again
		cout << "Would you like to run this program again, " << userName << "? (Y/N):";
		cin >> runAgain;

	} while (runAgain == 'Y' || runAgain == 'y');

	cout << "Goodbye " << userName << "!" << endl;
	return 0;
}



//Function - Round to two decimal points
double roundOff(double userValue)
{
	userValue = floor(userValue * 100 + 0.5) / 100;
	return userValue;
}