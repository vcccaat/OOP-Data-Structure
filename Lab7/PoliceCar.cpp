/*
 * PoliceCar.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: sze
 */
#include <iostream>
#include "PoliceCar.h"
using namespace std;

PoliceCar::PoliceCar(int nc, Color c, int m, bool action):Car(nc,c,m),inAction(action)
{ }

PoliceCar::~PoliceCar()
{
	cout<<"Calling PoliceCar's destructor on the following police car:"<<endl;
	print();
}

bool PoliceCar::getInAction() const
{
	return inAction;
}

void PoliceCar::setInAction(bool action)
{
	inAction = action;
}

///Print the information of the PoliceCar. Please refer to the sample I/O.
void PoliceCar::print() const
{
	string CC[6] = {"Black", "White", "Sliver", "Grey", "Red", "Blue"};
	cout<<"Information of the police car: "<<endl;
	cout<<"Engine: "<<getEngine()<<"    Color: "<<CC[getColor()]
	<<"   Current Mileage: "<<getMileage()<<endl;
	cout << "PoliceCar's state: ";
	if(getInAction())
		cout << "in action" << endl;
	else
		cout << "not in action" << endl;
}



