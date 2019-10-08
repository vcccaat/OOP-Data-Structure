//
//  relaxation.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "relaxation.h"

/*-----------------------------
 Constructor

 @param name: string
 @param energy_gain: accept all integers, but you may assume it is always non-negative
 @appendix: next should be initialized to NULL
 ------------------------------*/
Relaxation::Relaxation(string name, int energy_gain): name(name), energy_gain(energy_gain) 
{
	next = NULL;
}


/*-----------------------------
 Name getter
 @return: this's name
 ------------------------------*/
string Relaxation::get_name() const
{
	return name;
}

/*-----------------------------
 Energy gain getter
 @return: this's energy_gain
 ------------------------------*/
int Relaxation::get_energy_gain() const
{
	return energy_gain;
}

/*-----------------------------
 Next pointer getter for linked list purpose
 @return: this's 'next' pointer
 ------------------------------*/
Relaxation* Relaxation::get_next() const
{
	return this->next;
}


/*-----------------------------
 Next pointer setter for linked list purpose
 Set this's 'next'
 ------------------------------*/
void Relaxation::set_next(Relaxation* next)
{
	this->next = next;
}
