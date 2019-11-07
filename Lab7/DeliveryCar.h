/*
 * DeliveryCar.h
 *
 *  Created on: Nov 7, 2019
 *      Author: sze
 */

#ifndef DELIVERYCAR_H_
#define DELIVERYCAR_H_

#include "Vehicle.h"

class DeliveryCar : protected Vehicle //
{
	int chargePerMile; //delivery charge per mile
public:
	DeliveryCar(int nc, Color color, int mileage,int change);
	void setChargePerMile(int m);
	int getCharge(); // used to access and mutate the data member chargePerMile.
	void print() ;
	~DeliveryCar();
	void start();
	void brake(int distance);
};



#endif /* DELIVERYCAR_H_ */
