//
//  food.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "food.h"

/*-----------------------------
 Constructor

 You may assume fat_gain, protain_gain & price are always non-negative
 ------------------------------*/
Food::Food(string name, int fat_gain, int protein_gain, int price):
	name(name), fat_gain(fat_gain), protein_gain(protein_gain), price(price) {}



/*-----------------------------
 Name getter
 @return: this's name
 ------------------------------*/
string Food::get_name() const
{
	return name;
}

/*-----------------------------
 Fat gain getter
 @return: this's fat_gain
 ------------------------------*/
int Food::get_fat_gain() const
{
	return fat_gain;
}

/*-----------------------------
 Protein gain getter
 @return: this's protein_gain
 ------------------------------*/
int Food::get_protein_gain() const
{
	return protein_gain;
}

/*-----------------------------
 Price getter
 @return: this's price
 ------------------------------*/
int Food::get_price() const
{
	return price;
}