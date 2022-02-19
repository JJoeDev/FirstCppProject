#include <iostream>
using namespace std;

bool isRunning;
int length;

void makePassword()
{
	cout << "PASSWORD =" << endl;

	for (int i = 0; i < length; i++)
		cout << rand();
	cout << endl;
}

void userInput()
{
	int* trueFalse;
	int* internalLength;

	trueFalse = new int;
	internalLength = new int;
	cout << "Please provide a length for the password" << endl;
	cin >> *internalLength;

	if (*internalLength > 101)
	{
		*internalLength = 5;
		cout << "Password was too long. New length" <<endl;
		cout << *internalLength;
		cout << endl;
	}

	cout << "Generat passord with length with choosen length? (1 = yes, 0 = no)" << endl;
	cin >> *trueFalse;

	if (*trueFalse == 1) 
	{
		length = *internalLength;
		delete internalLength;
		delete trueFalse;
		makePassword();
	}
	else
	{
		system("cls");
		delete trueFalse;
		delete internalLength;
		userInput();
	}
}

int main()
{
	isRunning = true;
	userInput();

    return 0;
}