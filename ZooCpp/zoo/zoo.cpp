// zoo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Zoo.h"
#include "Animal.h"
#include "Tiger.h"
#include "Shark.h"
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    // local object, default constructor
    // when function (or block {}) ends (main() in this case) all LOCAL objects destructor is called
    Zoo zoo;
    //Zoo* pz = new Zoo(); // not necessary, the local Zoo obj is ok
    //delete pz;
    zoo.print();
    printf("Tyhjä lista\n\n");
    // zoo.add(new Animal()); // Animal is abstract
    Animal* pa = new Tiger("Keijo");
    zoo.add(pa);
    pa->move();
    pa->utter();
    Animal* hai = new Shark("Keijo");
    zoo.add(hai);
    hai->move();
    hai->utter();
    zoo.add(new Tiger("Timo", Date(11, 12, 1990), 50, "swedish"));
    zoo.add(new Tiger("Aatu", Date(11, 12, 2000), 700, "swedish"));
    zoo.add(new Tiger("Jorma", Date(11, 12, 1950), 500, "swedish"));
    zoo.add(new Tiger("Kullervo", Date(11, 12, 2008), 200, "german"));
    zoo.add(new Tiger("Johanna", Date(11, 12, 2030), 100, "swedish"));
    zoo.print();
    zoo.printSortedByAge();
    zoo.printSortedByName();
    pa = zoo.remove("Aatu");
    if (pa) {
        cout << "Removed: " + pa->toString() + "\n"; // << endl;
        delete pa;
    }
    zoo.printSortedByName();

    // finally zoo destructor is called automatically since zoo is a local object
}
// deletes if and replaces if name is same
Animal* Zoo::add(Animal* a)
{
    Animal* tmp = remove(a->getName());
    animals[a->getName()] = a;
    return tmp;
}

Animal* Zoo::remove(string name)
{
    Animal* tmp = 0;
    auto it = animals.find(name);
    if (it != animals.end()) {
        tmp = it->second;
        animals.erase(it);
    }
    return tmp;
}

void Zoo::print()
{
    // tulostaa pelkän valuen
    printf("\n---------- print ----------\n");
    list<Animal*> animalList;
    for (auto it = animals.begin(); it != animals.end(); it++)
        animalList.push_back(it->second);
    animalList.sort();
    for (auto& x : animalList) {
        printf("%s\n", x->toString().c_str());
    }
}

void Zoo::printSortedByName()
{
    // tulostaa keyn ja valuen
    printf("\n---------- printSortedByName ----------\n");
    for (auto k : animals) {
        printf("key: %s Value: %s\n", k.first.c_str(), k.second->toString().c_str());
    }
}

bool Zoo::compare(Animal* a, Animal* b) {
    Date birthA = a->getBirth();
    Date birthB = b->getBirth();
    if (birthA.getY() < birthB.getY()) {
        return true;
    }
    else if (birthA.getY() == birthB.getY()) {
        if (birthA.getM() < birthB.getM()) {
            return true;
        }
        else if (birthA.getM() == birthB.getM()) {
            if (birthA.getD() < birthB.getD()) {
                return true;
            }
        }
    }
    return false;
}
// ikä sortttaaja
void Zoo::printSortedByAge()
{
    printf("\n---------- printSortedByAge ----------\n");
    list<Animal*> animalList;
    for (auto it = animals.begin(); it != animals.end(); it++)
        animalList.push_back(it->second);
    animalList.sort(Zoo::compare);
    for (auto& x : animalList) {
        printf("Value: %s\n", x->toString().c_str());
    }
}

Zoo::~Zoo()
{
    for (auto it = animals.begin(); it != animals.end(); ) {
        delete it->second;
        it = animals.erase(it);
    }
}

