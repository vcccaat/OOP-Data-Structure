#ifndef DOG_H_
#define DOG_H_

#include "Animal.h"

class Dog: public Animal{
public:
	Dog(int s_id, string n);
	virtual void calculatePrice();

private:
	int species;
};

#endif /* DOG_H_ */
