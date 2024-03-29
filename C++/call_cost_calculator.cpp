/***********************************************************

Kyle J. L. Mason
Due Date:  1/17/2019
Course:  C0P3014
Assignment:  Assignment 1
Professor: Dr. Lofton Bullard

Description: Calculates the net cost of a call, the tax, and the total cost of the call.

*************************************************************/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string user_response = "y";

	double net_cost = 0.0, call_tax = 0.0, total_cost = 0.0, tax_rate = 0.0;
	string cell_num = "XXXXXXXXX";
	int relays = 0, call_length = 0;

	while (user_response == "y" || user_response == "Y")
	{

		//Request input for Phone Number, Relays, and Call Length in Minutes
		cout << "Please Enter a Cell Phone Number (XXXXXXXXX): ";
		cin >> cell_num;
		cout << "\nPlease Enter the Number of Relay Stations: ";
		cin >> relays;
		cout << "\nPlease Enter the Length of the Call in Minutes: ";
		cin >> call_length;

		//Calculate the Tax Rate from Relays
		if (relays >= 0 && relays <= 5)
		{
			tax_rate = 0.01;
		}
		if (relays >= 6 && relays <= 11)
		{
			tax_rate = 0.03;
		}
		if (relays >= 12 && relays <= 20)
		{
			tax_rate = 0.05;
		}
		if (relays >= 21 && relays <= 50)
		{
			tax_rate = 0.08;
		}
		if (relays > 50)
		{
			tax_rate = 0.12;
		}

		//Calculate net Cost
		net_cost = (relays / 50.0 * 0.40 * call_length);

		//Calculate Call Tax
		call_tax = net_cost * tax_rate;

		//Calculate Total Cost
		total_cost = net_cost + call_tax;

		//Print Information Screen.
		cout << "======================================" << endl;
		cout << "Cell Phone" << "                 " << cell_num << endl;
		cout << "Number of Relay Stations" << "   " << relays << endl;
		cout << "Minutes Used" << "               " << call_length << endl;
		cout << fixed;
		cout << setprecision(2);
		cout << "Net Cost" << "                   $" << net_cost << endl;
		cout << "Call Tax" << "                   $" << call_tax << endl;
		cout << "Total Cost of Call" << "         $" << total_cost << endl;


		cout << "\nWould you like to do another calculation (Y or N): " << endl;
		cin >> user_response;
	}

	return  0;
}





