#pragma once
#include <string>
using namespace std;
#include "Date.h"
#include <iomanip>
class Animal
{
private:
	string name;
	Date birth;
	int weight;
public:
	Animal(string name = "AnAnimal", Date birth = Date(), double weight = 100);
	string getName() { return name; }
	void setName(string name) { this->name = name; }
	Date getBirth() { return birth; }
	void setBirth(Date birth) { this->birth = birth; }
	int getWeight() { return weight; }
	void setWeight(int weight) { this->weight = weight; }
	virtual string toString() { return "Name: " + name +" Birth: " + birth.toString() + " weight: " + to_string(weight); }
	virtual void move() = 0;	// "=0" --> pure virtual --> no definition --> the class Animal is abstract
	virtual void utter() = 0;
	virtual ~Animal();
};

