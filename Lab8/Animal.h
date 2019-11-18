#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>
#include "Organism.h"

using namespace std;

class Animal: public Organism {
public:
	Animal(double v, string n);
	virtual ~Animal();
	virtual void calculatePrice() = 0;
	string getName();

private:
	string name;
};

#endif /* ANIMAL_H_ */
