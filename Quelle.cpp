
#include <iostream>
#include <string>
#include <random>
#include "Bunny.h"

using namespace std;

int main()
{
	// creating first bunnies
	Bunny::createBunnies(5, 'y'); // first parameter determines how many bunnies will be created, 2nd parameter only on gamestart 'y', else 'n'

	// bunny breeding
	int gameOver{ 1 };
	while (gameOver >= 1)
	{
		Bunny::ageBunnies();
		Bunny::createBunnies(Bunny::countBunnies(), 'n');
		Bunny::listBunnies();
		cout << "\nBirths: " << Bunny::countBunnies() << endl;
		Bunny::makeBunniesCrazy();

		system("PAUSE");


	}






	// Test output
	//listOutput();

	// cout << "\nErgebnis:\n" << bunnyCounting() << endl;

	system("PAUSE");

	return 0;
}
