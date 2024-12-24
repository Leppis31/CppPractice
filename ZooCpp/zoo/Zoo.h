#pragma once
#include <map>
#include "Animal.h"
#include <vector>
#include <list>
class Zoo
{
private:
	map<string, Animal*> animals;
	vector<pair<string, string>> animalList;
public:
	Animal* add(Animal* a);
	Animal* remove(string name);
	void print();
	void printSortedByName();
	static bool compare(Animal* a, Animal* b);
	void printSortedByAge();
	~Zoo();
};

