#include "Shark.h"
#include <iostream>
Shark::Shark(string name, Date birth, double weight, string species)
{
	setName(name);
	setBirth(birth);
	setWeight(weight);
	setSpecies(species);
}

void Shark::move()
{
	std::cout << "hai hai sanoi hai" << std::endl;
}

void Shark::utter()
{
	std::cout << "hai hai inahti hai" << std::endl;
}
