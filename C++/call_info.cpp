/************************************************************************************************************************

Name: Kyle Mason                                Z#:23501948
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 1/24/2019                     Due Time: 11:59PM
Total Points: 100
Assignment 2: call_info.cpp

Description:
In this assignment  a program a call management system is implemented.  The program used three functions:
input, output, and process.  The function input gets input from the user, the function process performs
the necessary calculations, and the function output prints the results.
*************************************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//Function Prototypes

void Input(string & cell_number, int & relays, int & call_length);
void Output(const string cell_number, const int relays, const int call_length, const double & net_cost, const double & call_tax, const double & total_cost_of_call);
void Process(const int relays, const int call_length, double & net_cost, double & call_tax, double & total_cost_of_call);

///*************************************************************************************
//Name:  Input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:  
// Example:Get input (values of cell_number, relays, and call_length) from the user.
//*************************************************************************************
void Input(string & cell_number, int & relays, int & call_length) // example of all formal parameter using the call by reference mechanism in C++
{
	cout << "Enter your Cell Phone Number: ";
	cin >> cell_number;
	cout << "Enter the number of relay stations: ";
	cin >> relays;
	cout << "Enter the length of the call in minutes: ";
	cin >> call_length;
}

///*************************************************************************************
//Name:  Output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************
void Output(const string cell_number, const int relays, const int call_length, const double & net_cost, const double & call_tax, const double & total_cost_of_call)
{
	cout << "/n======================================" << endl;
	cout << "Cell Phone" << "                 " << cell_number << endl;
	cout << "Number of Relay Stations" << "   " << relays << endl;
	cout << "Minutes Used" << "               " << call_length << endl;

	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	cout << "Net Cost" << "                   $" << net_cost << endl;
	cout << "Call Tax" << "                   $" << call_tax << endl;
	cout << "Total Cost of Call" << "         $" << total_cost_of_call << endl;
}

///*************************************************************************************
//Name:  Process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

//Note: there are 3 input parameter and 3 output parameters
void Process(const int relays, const int call_length, double & net_cost, double & call_tax, double & total_cost_of_call)
{
	double tax_rate = 0.0;
	
	//Calculate net Cost
	net_cost = (relays / 50.0 * 0.40 * call_length);
	
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

	//Calculate Call Tax
	call_tax = net_cost * tax_rate;

	//Calculate Total Cost
	total_cost_of_call = net_cost + call_tax;
}

int main()
{

	string cell_number, user_response = "y";
	int relays;
	int  call_length;
	double net_cost;
	double call_tax;
	double total_cost_of_call;

	//While Loop for multiple calculations
	while (user_response == "y" || user_response == "Y")
	{


	Input(cell_number, relays, call_length);
	Process(relays, call_length, net_cost, call_tax, total_cost_of_call);
	Output(cell_number, relays, call_length, net_cost, call_tax, total_cost_of_call);

	//Request another Calculation
	cout << "\nWould you like to do another calculation for another employee? (Y or N): " << endl;
	cin >> user_response;
	}


	return 0;
}
