#include "Dog.h"

#include <iostream>

using namespace std;

Dog::Dog(int s_id, string n): Animal(0, n)
{
	if(s_id >= 0 && s_id < 3)
		species = s_id;
	else{
		cout<<"Error exists in the index of species!!!"<<endl;
	}
}

void Dog::calculatePrice(){
	cout<<"Dog::calculatePrice() is called! "<<endl;

	double prices[3] = {150.0, 300.0, 450.0};

	int species_idx = species;
	double price_tmp = prices[species_idx];

	setPrice(price_tmp);
}




