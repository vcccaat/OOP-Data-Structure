/*
 * Car.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: sze
 */
#include <iostream>
#include "Car.h"
using namespace std;

Car::Car(int nc, Color color, int mileage):engine(nc),color(color),mileage(mileage) // Constructor
{ }

Color Car::getColor() const
{
	
	return color;
}

int Car::getMileage() const
{
	return mileage;
}

int Car::getEngine() const
{
	return engine.getNumCylinder();
}

Car::~Car()
{
	cout<<"Calling Car's destructor on the following car:"<<endl;
	print();
	
}

// Start the engine and print the information.
// Please refer to the sample I/O.
void Car::start()
{
	cout<<"Car with ";
	engine.Start();
}

// Stop the engine and update the data member "mileage" by adding the traveled distance to it.
// Print the information.
// Please refer to the sample I/O.
void Car::brake(int distance)
{
	cout<<"Car with ";
	engine.Stop();
	mileage += distance;
	cout<<"Driving distance: "<<distance<<endl;
}

// Print the information of the car. (Please refer to the I/O sample)
void Car::print() const
{
	string CC[6] = {"Black", "White", "Sliver", "Grey", "Red", "Blue"};
	cout<<"Engine: "<<getEngine()<<"    Color: "<<CC[getColor()]
	<<"   Current Mileage: "<<getMileage()<<endl;
}


