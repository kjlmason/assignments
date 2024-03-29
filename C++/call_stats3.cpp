/************************************************************************************************************************

Name:  Kyle Mason                               Z#:23501948
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 2/14/2019                     Due Time: 11:59PM
Total Points: 100
Assignment 5: call_stats3.cpp

Description: Reads, Processes, and Outputs customer call data to a file.

*************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;


class call_record
{
public:
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};


//Function Prototypes

void Input(ifstream &, call_record &);
void Output(ofstream &, const call_record &);
void Process(call_record &);


///*************************************************************************************
//Name:  Input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:  
// Example:Get input (values of cell_number, relays, and call_length) from the user and store in call record.
//*************************************************************************************

void Input(ifstream & in, call_record & customer_record)
{

	in >> customer_record.cell_number;
	in >> customer_record.relays;
	in >> customer_record.call_length;

}

///*************************************************************************************
//Name:  Output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************


void Output(ofstream & outData, const call_record & customer_record)
{

	//Output Data in Format
	outData << left << setw(5) << customer_record.cell_number << "  ";
	outData << left << setw(5) << customer_record.relays << "   ";
	outData << left << setw(5) << customer_record.call_length << "   ";
	outData.setf(ios::showpoint);
	outData.precision(2);
	outData.setf(ios::fixed);
	outData << left << setw(5) << customer_record.net_cost << "   ";
	outData << left << setw(5) << customer_record.tax_rate << "   ";
	outData << left << setw(5) << customer_record.call_tax << "   ";
	outData << left << setw(5) << customer_record.total_cost << endl;

	

}

///*************************************************************************************
//Name:  Process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************
void Process(call_record & customer_record)
{
	//Calculate net Cost
	customer_record.net_cost = (customer_record.relays / 50.0 * 0.40 * customer_record.call_length);

	//Calculate the Tax Rate from Relays
	if (customer_record.relays >= 0 && customer_record.relays <= 5)
	{
		customer_record.tax_rate = 0.01;
	}
	if (customer_record.relays >= 6 && customer_record.relays <= 11)
	{
		customer_record.tax_rate = 0.03;
	}
	if (customer_record.relays >= 12 && customer_record.relays <= 20)
	{
		customer_record.tax_rate = 0.05;
	}
	if (customer_record.relays >= 21 && customer_record.relays <= 50)
	{
		customer_record.tax_rate = 0.08;
	}
	if (customer_record.relays > 50)
	{
		customer_record.tax_rate = 0.12;
	}

	//Calculate Call Tax
	customer_record.call_tax = customer_record.net_cost * customer_record.tax_rate;

	//Calculate Total Cost
	customer_record.total_cost = customer_record.net_cost + customer_record.call_tax;
}


//Main Function
int main()
{

	call_record customer_record;

	ifstream in;    //declaring an input file stream
	in.open("call_data.txt");
	ofstream outData;    //declared output stream
	outData.open("weekly_call_info.txt");  //open file for printing

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{
			Input(in, customer_record);
			Process(customer_record);
			Output(outData, customer_record);
		}
		outData.close(); //close output stream
	}

	in.close();

	return 0;
}


