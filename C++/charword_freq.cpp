/************************************************************************************************************************

Name:  Kyle Mason             Z#: 23501948
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 3/14/2019                     Due Time: 11:59PM
Total Points: 10
Assignment 7: charword_freq.cpp

Description:
 1. Read the contents of a data file (mytext.dat);
 2. Process the frequency of characters (a-z) that appear in the data file
 3. Print the frequency of characters in the file to the screen;
 4. Be able to use an ifstream object;

*************************************************************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


//Function Prototypes
string ReadFile();
void CountWords();
void OutputCount();
int CountLetters(char letter);




//1. Read the contents of a data file(mytext.dat);
string ReadFile() 
{
	string fileString, stringWord;

	ifstream inFile;
	inFile.open("mytext.dat");

	if (inFile.fail()) 
	{
		cout << "File failed to open." << endl;
		exit(0);
	}

	while (!inFile.eof())
	{
		while (getline(inFile, stringWord))
		{
			fileString = fileString + " " + stringWord;
		}

		cout << "Block of text in the data file: " << endl;
		cout << fileString << "\n" << endl;
	}

	inFile.close();
	return fileString;
}


//2. Process the frequency of characters(a - z) that appear in the data file
void CountWords()
{
	int wordCount = 0;
	string stringWord;

	ifstream inFile;
	inFile.open("mytext.dat");

	if (inFile.fail()) 
	{
		cout << "File failed to open." << endl;
		exit(0);
	}

	while (inFile >> stringWord)
	{
		wordCount++;
	}

	cout << wordCount << " words" << endl;
	inFile.close();
	return;
}


//3. Print the frequency of characters in the file to the screen;
void OutputCount()
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		if (CountLetters(letter) > 0)
		{
			cout << left << setw(2) << CountLetters(letter) << " " << letter << endl;
		}
	}

	return;
}


int CountLetters(char letter)
{

	char letterCheck;
	int letterCount = 0;

	ifstream inFile;
	inFile.open("mytext.dat");
	inFile.get(letterCheck);

	if (inFile.fail())
	{
		cout << "File failed to open." << endl;
		exit(0);
	}

	while (!inFile.eof())
	{
		if (tolower(letterCheck) == letter)
		{
			letterCount++;
		}
		inFile.get(letterCheck);
	}

	inFile.close();
	return letterCount;
}



//Main Funciton
int main() 
{

	ReadFile();
	CountWords();
	OutputCount();

	return 0;
}