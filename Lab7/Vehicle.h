/*
 * Vehicle.h
 *
 *  Created on: Nov 7, 2019
 *      Author: sze
 */
#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "Engine.h"

class Vehicle: private Engine{
public:
	Vehicle(int nc, Color color, int mileage);
	~Vehicle();

	Color getColor() const;
	int getMileage() const;
	int getEngine() const;
	void brake(int distance);
	void print() const;
	void start();
	void changeMile(int distance){
		mileage+=distance;
	}

private:
	Color color;	// Color of the car
	int mileage;	// Total mileage
};

#endif
