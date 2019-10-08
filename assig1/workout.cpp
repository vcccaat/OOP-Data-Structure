//
//  workout.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "workout.h"

/*-----------------------------
 Constructor

 fat_change, muscle_change & energy_change accept all integers
 ------------------------------*/
Workout::Workout(string name, int fat_change, int muscle_change, int energy_change):
	name(name), fat_change(fat_change), muscle_change(muscle_change), energy_change(energy_change) {}


/*-----------------------------
 Name getter
 @return: this's name
 ------------------------------*/
string Workout::get_name() const
{
	return name;
}

/*-----------------------------
 Fat change getter
 @return: this's fat_change
 ------------------------------*/
int Workout::get_fat_change() const
{
	return fat_change;
}

/*-----------------------------
 Muscle change getter
 @return: this's muscle_change
 ------------------------------*/
int Workout::get_muscle_change() const
{
	return muscle_change;
}

/*-----------------------------
 Energy change getter
 @return: this's energy_change
 ------------------------------*/
int Workout::get_energy_change() const
{
	return energy_change;
}