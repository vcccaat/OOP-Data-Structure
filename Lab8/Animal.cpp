#include "Animal.h"
#include <iostream>

using namespace std;

Animal::Animal(double v, string n): Organism(v), name(n){

}

Animal::~Animal(){

}

string Animal::getName()
{
	return name;
}
