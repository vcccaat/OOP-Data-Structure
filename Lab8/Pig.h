
#ifndef PIG_H_
#define PIG_H_

#include "Animal.h"

class Pig: public Animal{
public:
	Pig(double w, double unit_p, string n);
	virtual void calculatePrice();

private:
	double weight;
	double unit_price;
};



#endif /* PIG_H_ */
