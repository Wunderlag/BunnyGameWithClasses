#pragma once
#include <string>
#include <vector>

using namespace std;

class Bunny
{
private:
	char sex;
	string colour;
	int age;
	string name;
	int crazy;
	vector<Bunny*> v;

public:
	class Bunny* next;
	Bunny();	
	
	void createBunnies(int, char);	// first parameter determines how many bunnies will be created, 2nd parameter only on gamestart 'y', else 'n' 
	int countBunnies();				// returns fertile Female bunnies
	void listBunnies();				// Lists all alive Bunnies with attributes
	void ageBunnies();				// Ages all Bunnies 1 year each turn
	void makeBunniesCrazy();		// Each crazy Bunny infects another non-crazy Bunny each year/turn
	
	~Bunny();
};

