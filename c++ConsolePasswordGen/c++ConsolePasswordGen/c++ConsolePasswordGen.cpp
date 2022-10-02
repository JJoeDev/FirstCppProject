#include <iostream>
#include <chrono>

// Define clear crossplatform
#ifdef _WIN32
#define clear system("cls");
#elif defined __unix__
#define clear system("clear");
#elif defined __APPLE__
#define clear system("clear");
#endif

int length;

// Time since epoch function
int timeSinceEpochNanosec() {
	using namespace std::chrono;
	return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
}

// Make password function
void makePassword(int length)
{
	std::cout << "PASSWORD =" << std::endl;
	for (int i = 0; i < length; i++)
	{
		srand(timeSinceEpochNanosec()); // Set random seed
		std::cout << (rand() % 9) + 1; // Random number between 0 and 9
	}
	std::cout << std::endl;
}

void userInput()
{
	int trueFalse;

	std::cout << "Please provide a length for the password" << std::endl;
	std::cin >> length;

	std::cout << "Generat passord with length with choosen length? (1 = yes, 0 = no)" << std::endl;
	std::cin >> trueFalse;

	switch (trueFalse) {
	case 1:
		makePassword(length);
		break;
	case 2:
		clear;
		userInput();
		break;
	}
}

int main()
{
	userInput();
	return 0;
}
