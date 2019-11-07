/*
 * DeliveryCar.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: sze
 */

#include <iostream>
#include "DeliveryCar.h"
using namespace std;

DeliveryCar::DeliveryCar(int nc, Color color, int mileage,int change):
		Vehicle(nc,color,mileage), chargePerMile(change)
{}

DeliveryCar::~DeliveryCar()
{
	cout<<"Calling Vehicle's destructor on the following delivery car: "<<endl;
	print();
}
void DeliveryCar::setChargePerMile(int m)
{
	chargePerMile = m;
}

int DeliveryCar::getCharge()
{
	return chargePerMile;
}

void DeliveryCar::print()
{
	string CC[6] = {"Black", "White", "Sliver", "Grey", "Red", "Blue"};
	cout<<"Information of the delivery car: "<<endl;
	cout<<"Engine: "<<getEngine()<<"    Color: "<<CC[getColor()]
	<<"   Current Mileage: "<<getMileage()<<endl;
	cout << " DeliveryCar's charges per mile: "<<getCharge()<<endl;
	cout <<" DeliveryCar's calculated charges: "<<getCharge()*getMileage()<<endl;
	
}


void DeliveryCar::start(){
	cout << "Vehicle with " << getEngine() << "-cylinder engine started." << endl;
}

void DeliveryCar::brake(int distance){
	cout << "Vehicle with " << getEngine() << "-cylinder engine stopped." << endl;
	cout << "Driving distance: " << distance << endl;
	changeMile(distance);
}