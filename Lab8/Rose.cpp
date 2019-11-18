#include "Rose.h"
#include <iostream>
using namespace std;

Rose::Rose(int c_id):Plant(0),color_id(c_id){
	if(c_id >= 0 && c_id < 4)
		color_id = c_id;
	else{
		cout<<"Error exists in the index of species!!!"<<endl;
	}
}

void Rose::calculatePrice(){
	cout<<"Rose::calculatePrice() is called! " <<endl;
    double prices[4] = {100.0, 200.0, 300.0, 400.0}; 
	double price_tmp = prices[color_id];
	setPrice(price_tmp);
}


