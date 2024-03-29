/************************************************************************************************************************

Name: Kyle Mason                                Z#:23501948
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 2/7/2019                     Due Time: 11:59PM
Assignment 4: all_area_semi.cpp

Description:
This Program computes and outputs the area of an arbitrary
triangle using, the three sides requested from the user. 
*************************************************************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

//include function prototypes
void Compute(float, float, float, float & semiParimeter, float & triangleArea);
bool validityCheck(float, float, float);


//Semiparimeter and Area Calculation Function
void Compute(float sideA, float sideB, float sideC, float & semiParimeter, float & triangleArea)
{
	semiParimeter = (sideA + sideB + sideC) / 2;
	triangleArea = sqrt(semiParimeter*(semiParimeter - sideA)*(semiParimeter - sideB)*(semiParimeter - sideC));

	return;
}

//Side Validity Function
bool validityCheck(float sideA, float sideB, float sideC)
{
	
	if ((sideA + sideB) <= sideC) { return false; }
	if ((sideA + sideC) <= sideB) { return false; }
	if ((sideC + sideB) <= sideA) { return false; }

	return true;
}

//Main Function
int main()
{
	//declare variables a, b, c,area, and semiperimeter
	float sideA = 0.0, sideB = 0.0, sideC = 0.0, triangleArea = 0.0, semiParimeter = 0.0;
	//declare variable for while loop
	char userContinue = 'n';
	//begin while loop
	do {

		//Request User Input
		cout << "Please enter the length of side A: ";
		cin >> sideA;
		cout << "Please enter the length of side B: ";
		cin >> sideB;
		cout << "Please enter the length of side C: ";
		cin >> sideC;


		//ValidityCheck
		if (!validityCheck(sideA, sideB, sideC))
		{
			cout << "\nError! The lengths of your triangle are not valid. Would you like to continue calculating the semiparimeter and area? (Enter 'y' to continue):" << endl;
			cin >> userContinue;

			if(userContinue != 'y' && userContinue != 'Y')
			{ 
				return 0;
			}
		}

		//call Computer
		Compute(sideA, sideB, sideC, semiParimeter, triangleArea);


		//Print Results
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << "\nSemiperimeter: " << semiParimeter << endl;
		cout << "Area: " << triangleArea << endl;
		cout << "\nWould you like to make another Calculation? (Enter 'y' to do another): ";
		cin >> userContinue;

	} while (userContinue == 'y' || userContinue == 'Y');
	//end while loop
	
	return 0;
}
