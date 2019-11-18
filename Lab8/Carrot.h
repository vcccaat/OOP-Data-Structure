#ifndef CARROT_H_
#define CARROT_H_

#include "Plant.h"

class Carrot:public Plant{
public:
	Carrot(double w, double unit_p);
	virtual void calculatePrice();

private:
	double weight;
	double unit_price;
};




#endif /* CARROT_H_ */
