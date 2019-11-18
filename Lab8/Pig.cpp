#include "Pig.h"
#include <iostream>

using namespace std;

Pig::Pig(double w, double unit_p, string n):Animal(0, n),weight(w), unit_price(unit_p){

}

void Pig::calculatePrice(){
	cout<<"Pig::calculatePrice() is called! "<<endl;

	double price_tmp = weight * unit_price;
	setPrice(price_tmp);
}



