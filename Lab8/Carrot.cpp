#include "Carrot.h"
#include <iostream>

using namespace std;

Carrot::Carrot(double w, double unit_p):Plant(0),weight(w), unit_price(unit_p){

}

void Carrot::calculatePrice(){
	cout<<"Carrot::calculatePrice() is called! " <<endl;

	double price_tmp = weight * unit_price;
	setPrice(price_tmp);
}






