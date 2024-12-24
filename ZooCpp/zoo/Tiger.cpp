#include "Tiger.h"
#include <iostream>
Tiger::Tiger(string name, Date birth, double weight, string species)
{
	setName(name);
	setBirth(birth);
	setWeight(weight);
	setSpecies(species);
}
void Tiger::move()
{
	std::cout << "mau mau sanoi tiikeri" << std::endl;
}

void Tiger::utter()
{
	std::cout << "mau mau inaisi tiikeri" << std::endl;
}
