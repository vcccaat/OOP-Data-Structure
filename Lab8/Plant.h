
#ifndef PLANT_H_
#define PLANT_H_

#include "Organism.h"

class Plant: public Organism {
public:
	Plant(double v);
	virtual ~Plant();
	virtual void calculatePrice() = 0;
};


#endif /* PLANT_H_ */
