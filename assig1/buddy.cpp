//
//  buddy.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "buddy.h"

/*-----------------------------
 Constructor
 @param name: string
 @param fat: accept all integers
 @param muscle: accept all integers
 @param energy:
    DOES NOT accept negative integers,
    in this case set this's energy to 0
 @param money:
    DOES NOT accept negative integers,
    in this case set this's money to 0
 ------------------------------*/
Buddy::Buddy(string name, int fat, int muscle, int energy, int money): 
	name(name), fat(fat), muscle(muscle), 
	energy((energy<0)?0:energy), 
	money((money<0)?0:money) { }

/*-----------------------------
 Name getter
 @return: this's name
 ------------------------------*/
string Buddy::get_name() const
{
	return name;
}

/*-----------------------------
 Fat getter
 @return: this's fat
 ------------------------------*/
int Buddy::get_fat() const
{
	return fat;
}

/*-----------------------------
 Muscle getter
 @return: this's muscle
 ------------------------------*/
int Buddy::get_muscle() const
{
	return muscle;
}

/*-----------------------------
 Energy getter
 @return: this's energy
 ------------------------------*/
int Buddy::get_energy() const
{
	return energy;
}

/*-----------------------------
 Money getter
 @return: this's money
 ------------------------------*/
int Buddy::get_money() const
{
	return money;
}

/*-----------------------------
 Fat setter
 @param fat: accept all integers
 ------------------------------*/
void Buddy::set_fat(int fat)
{
	this->fat = fat;
}

/*-----------------------------
 Muscle setter
 @param muscle: accept all integers
 ------------------------------*/
void Buddy::set_muscle(int muscle)
{
	this->muscle = muscle;
}

/*-----------------------------
 Energy setter
 @param energy:
    DOES NOT accept negative integers,
    in this case set this's energy to 0
 ------------------------------*/
void Buddy::set_energy(int energy)
{
	if (energy < 0) energy = 0;
	this->energy = energy;
}

/*-----------------------------
 Money setter
 @param money:
    DOES NOT accept negative integers,
    in this case set this's money to 0
 ------------------------------*/
void Buddy::set_money(int money)
{
	if (money < 0) money = 0;
	this->money = money;
}


/*-----------------------------
 Increase this's money according to inputs,
 No need to consider negative money input / negative times
 for example:
    this->money = 100
    input money = 8
    input times = 9
 result:
    this->money = 100 + 8*9 = 172
 ------------------------------*/
void Buddy::earn_money(int money, int times)
{
	this->money +=  money*times;
}

/*-----------------------------
 Increase this's energy according to the input linked list
 for each node in plan's linked list:
    this's energy += node->energy_gain

 for exmaple:
    this->energy = 100
    plan: ("Sleep", 10) -> ("Hang out", 15)
 result:
    this->energy = 100 + 10 + 15 = 125
 ------------------------------*/
void Buddy::gain_energy(RelaxPlan plan)
{
	int sum_energy = 0;
	for (Relaxation* p = plan.get_head(); p != NULL; p = p->get_next())
	{
		sum_energy += p->get_energy_gain();
	}
	this->set_energy(this->get_energy()+sum_energy);	
}
