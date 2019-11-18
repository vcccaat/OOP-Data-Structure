#ifndef ROSE_H_
#define ROSE_H_

#include "Plant.h"

class Rose: public Plant{
public:
	Rose(int c_id);
	virtual void calculatePrice();

private:
	int color_id;
	
};


#endif /* ROSE_H_ */
