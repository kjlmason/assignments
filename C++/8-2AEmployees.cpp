// 8-2AEmployees.cpp			Written by Kyle Mason
// This program stores employee work hours in an int array, and returns
// the total and average number of hours worked to the user.

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void outputOfArray(int arr[], int size);
void totalOfArray(int arr[], int size);
void avgOfArray(int arr[], int size);

int main()
{
	int employeeHours[20], employeeCount;
	char doAgain;
	string userName;

	//Introduction
	cout << "Hello user, my name is Kyle!" << endl;
	cout << "What is your name?: ";
	cin >> userName;
	cout << "Hello, " << userName << "!\n" << endl;
	cout << "This program will give record the number of hours worked for up to 20 employees, ";
	cout << "as well as give you the total hours and average hours worked between them.\n" << endl;

	//Input Hours and Get Data
	do {
		employeeCount = 0;
		cout << userName << ", please input the number of hours worked for up to 20 of your employees. (example: '20')" << endl;
		cout << "Entering '-1' will end the input process.\n" << endl;
		for (int i = 0; i < 20; i++) {
			cout << "Employee #" << i + 1 << ": ";
			cin >> employeeHours[i];
			if (cin.fail() || employeeHours[i] < 0) {
				break;
			}
			employeeCount++;
		}
		cout << endl;

		//Functions
		outputOfArray(employeeHours, employeeCount);
		totalOfArray(employeeHours, employeeCount);
		avgOfArray(employeeHours, employeeCount);

		//Run Again?
		cout << "Would you like to run this program again? (Y/N): ";
		cin >> doAgain;
		cout << endl;
	} while (doAgain == 'y' || doAgain == 'Y');

	cout << "Goodbye, " << userName << "!" << endl;

	return 0;
}

void outputOfArray(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << "Employee #" << i + 1 << ", ";
		cout << "Hours worked: " << arr[i] << endl;
	}
	cout << endl;
}

void totalOfArray(int arr[], int size)
{
	int totalHours = 0;

	for (int i = 0; i < size; i++)
		totalHours += arr[i];

	cout << "Total number of hours worked: " << totalHours << endl;
	cout << endl;
}

void avgOfArray(int arr[], int size)
{
	int totalHours = 0;
	double avgHours;

	for (int i = 0; i < size; i++)
		totalHours += arr[i];

	avgHours = totalHours / size;
	cout << "Average number of hours worked: " << avgHours << endl;
	cout << endl;
}
