//19.5Mortgage.cpp          Written by Kyle Mason
//Calculates the payments for a mortgage over a given period of time

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#define DATA 4
#define MONTHS 9999

double roundOff(double userValue);


int main()
{
	double userData[MONTHS][DATA];
	int userYears = 0, userMonths = 0, currentMonth = 0, currentData = 0;
	double  userPrinciple, interestRate, payPerMonth, prinBalance;
	double dollarInterest, dollarToPrin, monthlyRate, lastValue;
	printf("Please enter the principle in dollars and cents format (0.00): $");
	scanf_s("%lf", &userPrinciple);
	printf("Please input the payment time in years as an integer: ");
	scanf_s("%d", &userYears);
	printf("Please enter interest rate as a percentage: %%");
	scanf_s("%lf", &interestRate);

	interestRate = interestRate / 100;
	userMonths = userYears * 12;
	monthlyRate = interestRate / 12;

	/*debug
	printf("\nTotal payment time is %d months.\n", userMonths);
	printf("Monthly Rate is: %.4lf\n", monthlyRate);
	*/

	//find payPerMonth
	payPerMonth = userPrinciple * (monthlyRate * pow((1 + monthlyRate), userMonths) / (pow(((1 + monthlyRate)), userMonths) - 1));
	payPerMonth = roundOff(payPerMonth);

	//debug
	//printf("Pay per month is: %.2lf\n", payPerMonth);


	//Store Data
	for (currentMonth = 0; currentMonth < userMonths; currentMonth++)
	{
		userData[currentMonth][currentData] = userPrinciple;
		dollarInterest = userPrinciple * monthlyRate;
		dollarInterest = roundOff(dollarInterest);
		userData[currentMonth][currentData + 1] = dollarInterest;
		dollarToPrin = payPerMonth - dollarInterest;
		dollarToPrin = roundOff(dollarToPrin);
		userData[currentMonth][currentData + 2] = dollarToPrin;
		prinBalance = userPrinciple - dollarToPrin;
		prinBalance = roundOff(prinBalance);

		//debug
		//printf("prinbalance is %lf\n", prinBalance);
		userData[currentMonth][currentData + 3] = prinBalance;

		userPrinciple = prinBalance;
	}

	//TableData
	printf("\nPrinciple = $%.2lf    ", userData[0][0]);
	printf("Rate = %%%.2lf         ", interestRate * 100);
	printf("Monthly Interest Rate = %%%.2lf\n", monthlyRate * 100);
	printf("Pay/Mo. = $%.2lf       ", payPerMonth);
	printf("Years = %d            ", userYears);
	printf("Total Months = %d      \n", userMonths);

	//Table
	printf("\nMonth    Principle    Interest    $ to Prin   Prin Balance\n");
	for (currentMonth = 0; currentMonth < userMonths; currentMonth++)
	{
		printf("%3d    ", currentMonth + 1);
		for (currentData = 0; currentData < DATA; currentData++)
		{
			if (userData[currentMonth][currentData] > 0)
				printf("$%10.2lf  ", userData[currentMonth][currentData]);
			else
				printf("($%10.2lf)  ", fabs(userData[currentMonth][currentData]));
		}
		printf("\n");
	}
	lastValue = payPerMonth + prinBalance;
	lastValue = roundOff(lastValue);
	printf("The last monthly payment is $%.2lf\n\n", lastValue);
	return 0;
}

double roundOff(double userValue)
{
	userValue = floor(userValue * 100 + 0.5) / 100;

	return userValue;
}
