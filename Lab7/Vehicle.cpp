/*
 * Vehicle.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: sze
 */
#include <iostream>
#include "Vehicle.h"
using namespace std;


Vehicle::~Vehicle()
{
	cout<<" Calling Vehicle's destructor on the following vehicle:"<<endl;
	print();
}

Vehicle::Vehicle(int nc, Color color, int mileage):Engine(nc),color(color),mileage(mileage) // Constructor
{

}

Color Vehicle::getColor() const
{

	return color;
}

int Vehicle::getMileage() const
{
	return mileage;
}

int Vehicle::getEngine() const
{
	return getNumCylinder();
}

void Vehicle::start()
{
	cout<<"Vehicle with "<< getEngine() << "-cylinder engine started." << endl;
}

void Vehicle::brake(int distance)
{
	cout<<"Vehicle with "<< getEngine() << "-cylinder engine started." << endl;
	mileage += distance;
	cout<<"Driving distance: "<<distance<<endl;
}


void Vehicle::print() const
{
	string CC[6] = {"Black", "White", "Sliver", "Grey", "Red", "Blue"};
	cout<<"Engine: "<<getEngine()<<"    Color: "<<CC[getColor()]
	<<"   Current Mileage: "<<getMileage()<<endl;
}



