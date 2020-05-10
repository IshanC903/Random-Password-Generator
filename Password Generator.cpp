//BIT1400
//Assignment 5
//This program generates a random password with the amount of characters and numbers the user asks for.
//Ishan Chaurasia
//101011068
//Mar 24, 2017

#include <iostream>
#include <fstream> //Library to output file
#include <cstdlib> 
#include <ctime>
#include <vector> //Library to use vectors
#include <time.h>> 

using namespace std;

char charGenerator(vector<char>* _char, int *wordCount); //Function declaration to generate random characters.
int numGenerator(vector<int>* _num, int *numCount); //Function declaration to generate random numbers.

void main() {

	int charNum = 0; //Variable to store number of characters for password.
	int *wordCount = &charNum; //Pointer for number of characters variable.
	int numNum = 0; //Variable to store number of numbers for password.
	int *numCount = &numNum; //Pointer for number of numbers variable.
	char passSave; //Character to store users choice to save password.
	char *savePermish = &passSave; //Pointer for user choice to save password.
	ofstream outfile; //File output stream.
	ofstream *drop = &outfile; //Pointer for file output.

	srand(time(NULL)); //To make sure generated numbers are random everything the program is run.

	cout << "How many characters would you like your password to have? ";
	cin >> *wordCount; //Pointer stores users number in charNum variable.
	cout << "How many numbers would you like your password to have? ";
	cin >> *numCount; //Pointer stores users number in numNum variable.

	vector<char> charPass(*wordCount); //Vector defination to store the random generated letters.
	vector<int> intPass(*numCount); //Vector defination to store the random generated numbers.

	charGenerator(&charPass, wordCount); //Function call that will generate random letters.
	numGenerator(&intPass, numCount); //Function call that will generate random numbers.

	cout << endl << "Your password is: ";
	//For loops to output the generated characters for the user.
	for (int i = 0; i < *wordCount; i++)
	{
		cout << charPass[i];
	}
	for (int i = 0; i < *numCount; i++)
	{
		cout << intPass[i];
	}
	cout << endl << endl << "Would you like to save this password to file? (Y/N): ";
	cin >> *savePermish; //Saves users options to save password to file.

	if (*savePermish == 'Y' || *savePermish == 'y') { //If statement to check if user said yes to save password.

		outfile.open("password.txt"); //Opens / creates file.
		//For loops to output the stored values in the vector to a file.
		for (int i = 0; i < *wordCount; i++)
		{
			*drop << charPass[i];
		}
		for (int i = 0; i < *numCount; i++)
		{
			*drop << intPass[i];
		}
		cout << "Password Saved" << endl;
		outfile.close(); //Closes file.

	}

}

char charGenerator(vector<char>* _char, int *wordCount) { //Function that takes in the vector and number of chacters to generate as a parameter and stores them in the vector.

	static const char alphanum[] =
		"abcdefghijklmnopqrstuvwxyz";
	int stringLength = sizeof(alphanum) - 1;

	for (int i = 0; i < *wordCount; i++) {
		_char->at(i) = alphanum[rand() % stringLength];
	}

	return 0;
}

int numGenerator(vector<int>* _num, int *numCount) { //Function that takes in the vector and number of numbers to generate as a parameter and stores them in the vector.

	for (int i = 0; i < *numCount; i++) {
		_num->at(i) = (rand() % 9);
	}

	return 0;

}