#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// We evenly distribute a random number in our range.
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int checkUserNumber(int userNumber, int number)
{
	if (userNumber == number)
	{
		cout << "Correct! You win!" << endl;
		return 0;
	}
	else if (userNumber > number)
	{
		cout << "Your guess is too high!" << endl;
		return 1;
	}
	else if (userNumber < number)
	{
		cout << "Your guess is too low!" << endl;
		return 2;
	}
}

int main()
{	
	srand(static_cast<unsigned int>(time(0)));
	int randVisualStudio = rand();
	int number = getRandomNumber(1, 100);
	int userNamber;
	cout << "Let's play a game. I'm thinking of a number. You have unlimited tries to guess what it is." << endl;
	while (true)
	{
		cout << "Guess #1: ";		
		cin >> userNamber;
		int result = checkUserNumber(userNamber, number);
		if (result == 0)
		{
			return 0;
		}
	}
}

