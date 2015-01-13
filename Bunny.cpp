#include "Bunny.h"
#include <string>
#include <iostream>
#include <random>

using namespace std;

static int nAllBunnies{};		// Sum of all alive bunnies
static int nCrazyBunnies{};		// Sum of all crazy bunnies
static int nFemaleBunnies{};	// Sum of all fertile female bunnies
static int nMaleBunnies{};		// Sum of all fertile male bunnies
static int nInfantBunnies{};	// Sum of all unfertile bunnies
static Bunny* listStart{};		// Start of the bunnylist

// Functions for bunny creation
// Function to determine sex
char randSex(void);
// Funtion to determine age of starting bunnies
int randAge(void);
// Function to determine colour
string randColour(void);
// Function to determine name
string randName(char);
// Funktion to determine crazyness
int randCrazyness(void);
// Add a Node to Bunny
void addNode(Bunny*);

Bunny::Bunny()
{

}

void Bunny::createBunnies(int max, char start)
{
	int n{};

	for (n = 0; n < max; n++)
	{
		Bunny* add = new Bunny();
		add->sex = randSex();
		add->colour = randColour();
		if (start == 'y')
		{
			add->age = randAge();
		}
		else if (start == 'n')
		{
			add->age = 0;
		}
		add->name = randName(add->sex); 	// Name depending on sex
		add->crazy = randCrazyness();
		addNode(add);
	}



}

int Bunny::countBunnies()
{
	// How many Bunnies?
	Bunny* nPtr = listStart;
	int count{};
	int mCount{};
	int fCount{};
	int cCount{};
	int iCount{};
	while (nPtr != 0)
	{
		count++;
		if ((nPtr->sex == 'm') && (nPtr->age > 1) && (nPtr->crazy != 1))
			mCount++;
		if ((nPtr->sex == 'f') && (nPtr->age > 1) && (nPtr->crazy != 1))
			fCount++;
		if (nPtr->crazy == 1)
			cCount++;
		if (nPtr->age < 2)
			iCount++;
		nPtr = nPtr->next;
	}
	nAllBunnies = count;
	nMaleBunnies = mCount;
	nFemaleBunnies = fCount;
	nCrazyBunnies = cCount;
	nInfantBunnies = iCount;

	// Return fertile female Bunnies
	if (fCount > 0 && mCount > 0)
		return fCount;
	else
		return 0;
}

void Bunny::listBunnies()
{

}

void Bunny::ageBunnies()
{

}

void Bunny::makeBunniesCrazy()
{

}

Bunny::~Bunny()
{
}



// Function to determine sex
char randSex()
{
	random_device generator;
	uniform_int_distribution<int> distribution(1, 2);
	int diceRoll = distribution(generator);

	if (diceRoll == 1)
		return 'm';
	else
		return 'f';
}

// Funtion to determine age of starting bunnies
int randAge()
{
	random_device generator;
	uniform_int_distribution<int> distribution(1, 10);
	int diceRoll = distribution(generator);

	return diceRoll;
}

// Function to determine colour
string randColour()
{
	string colours[] = { "white", "brown", "red", "black", "yellow", "spotted" };

	random_device generator;
	uniform_int_distribution<int> distribution(0, 5);
	int diceRoll = distribution(generator);

	return colours[diceRoll];
}

// Function to determine name
string randName(char sex)
{
	string bunnyFemNames[24] = { "Daisy", "Bella", "Lily", "Lola", "Lucy", "Molly", "Bailey", "Bunbun", "Fluffy", "Honey", "Willow", "Ginger", "Chloe", "Luna", "Snowball", "Cocoa", "Holly", "Cookie", "Ruby", "Pumpkin", "Sophie", "Lilly", "Alice", "Lulu" };
	string bunnyMaleNames[24] = { "Thumper", "Oreo", "Charlie", "Oliver", "Jack", "Clover", "Smokey", "Gizmo", "Binky", "George", "Max", "Nibbles", "Harvey", "Buster", "Peter", "Jasper", "Buddy", "Lucky", "Shadow", "Flopsy", "Pepper", "Hazel", "Midnight", "Peanut" };
	random_device generator;
	uniform_int_distribution<int> distribution(0, 23);
	int diceRoll = distribution(generator);

	if (sex == 'f')
	{
		return bunnyFemNames[diceRoll];
	}
	else if (sex == 'm')
	{
		return bunnyMaleNames[diceRoll];
	}
}

// Funktion to determine crazyness
int randCrazyness()
{
	random_device generator;
	uniform_int_distribution<int> distribution(1, 100);
	int diceRoll = distribution(generator);

	if (diceRoll <= 2)
		return 1;
	else
		return 0;
}

// Add a Node to Bunny
void addNode(Bunny* add)
{
	if (listStart == 0)
	{
		listStart = add;
		add->next = 0;
	}
	else
	{
		Bunny* nPtr = listStart;
		while (nPtr->next != 0)
		{
			nPtr = nPtr->next;
		}
		nPtr->next = add;
		add->next = 0;
	}
	//cout << add->name << "\n" << add->sex << "\n" << add->colour << "\n" << add->age << "\n" << add->crazy << "\n" << endl;

}