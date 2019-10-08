//
//  restaurant.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "restaurant.h"

/*-----------------------------
 Constructor
 @appendix:
    list_start_index, curr_num_of_meals should be initialized to 0
    list_end_index should be initialized to 4
 ------------------------------*/
Restaurant::Restaurant(string name): name(name) 
{
	list_start_index = 0;
	curr_num_of_meals = 0;
	list_end_index = 4;
}


/*-----------------------------
 Name getter
 @return: this's name
 ------------------------------*/
string Restaurant::get_name() const
{
	return name;
}


/*-----------------------------
 'Append' a food to the 'end' of meals_list (circular array)
 @return:
    If the list is full, do nothing and return false;
    otherwise perform the append and return true

 you may need to use modulus operator '%' to create 'circular' indexes

 Example:

 initial: empty list (list_start_index = 0; list_end_index = 4; curr_num_of_meals = 0)

 add_meal: "Banana"
 result: true
    0: "Banana" (list_start_index) (list_end_index)
    curr_num_of_meals = 1

 add_meal: "Bottled Water"
 result: true
    0: "Banana" (list_start_index)
    1: "Bottled Water" (list_end_index)
    curr_num_of_meals = 2

 add_meal: "Burger"
 add_meal: "Beef Fried Rice"
 add_meal: "Chicken Nuggets"
 result: true
    0: "Banana" (list_start_index)
    1: "Bottled Water"
    2: "Burger"
    3: "Beef Fried Rice"
    4: "Chicken Nuggets" (list_end_index)
    curr_num_of_meals = 5
 Please note that list_start_index & list_end_index are now same as initial.
 Therefore, in order to differ empty & full list, we add a variable curr_num_of_meals.

 add_meal: "Pad Thai" (list is now full because curr_num_of_meals == 5)
 result: false
    (list not changed)
 ------------------------------*/
bool Restaurant::add_meal(Food food)
{
    if ((curr_num_of_meals ==5) )
	   return false;
    else if (list_end_index == 4 && list_start_index == 0)  //initialize and insert first element
    {
        list_end_index = list_start_index = 0;
        meals_list[list_end_index] = food;
        ++curr_num_of_meals;
//        cout << "list_end_index "<<list_end_index<<"  list_start_index "<<list_start_index<<endl;
    }
    else if (list_end_index == 4 && list_start_index != 0)  //insert start from 0
    {
        list_end_index = 0;
        meals_list[list_end_index] = food;
        ++curr_num_of_meals;
//        cout << "list_end_index "<<list_end_index<<"  list_start_index "<<list_start_index<<endl;
    }
    else 
    {
        ++list_end_index;
        meals_list[list_end_index] = food;
        ++curr_num_of_meals;
//        cout << "list_end_index "<<list_end_index<<"  list_start_index "<<list_start_index<<endl;
    }

    return true;
}

/*-----------------------------
 Remove the food at [list_start_index]. (Circular array)
 @return:
    If the list is empty, do nothing and return false,
    otherwise perform the remove and return true

 @appendix:
     This array is in stack, thus you don't need to delete the food. Changing list_start_index & curr_num_of_meals is enough.
     You may need to use modulus operator '%'

 Example:

 initial:
    0: "Banana" (list_start_index)
    1: "Bottled Water"
    2: "Burger" (list_end_index)
    curr_num_of_meals = 3

 remove_first_meal()
 result: true
    1: "Bottled Water" (list_start_index)
    2: "Burger" (list_end_index)
    curr_num_of_meals = 2

 remove_first_meal()
 remove_first_meal()
 result: true
    list_start_index = 3; list_end_index = 2; curr_num_of_meals = 0;

 remove_first_meal()
 result: false
    list_start_index = 3; list_end_index = 2; curr_num_of_meals = 0; (not changed)
 ------------------------------*/
bool Restaurant::remove_first_meal()
{
	if (curr_num_of_meals == 0) return false; 

//	list_start_index = (list_start_index)%4;
	if (list_start_index == 4) list_start_index =0;
	else ++list_start_index;
    --curr_num_of_meals;
//    cout << "list_end_index "<<list_end_index<<"  list_start_index "<<list_start_index<<endl;
    return true;

}

/*-----------------------------
 Remove the food at [list_end_index]. (Circular array)
 @return:
    If the list is empty, do nothing and return false,
    otherwise perform the remove and return true

 @appendix:
    This array is in stack, thus you don't need to delete the food. Changing list_end_index & curr_num_of_meals is enough.
    You may need to use modulus operator '%'

 Example:

 initial:
 0: "Banana" (list_start_index)
 1: "Bottled Water"
 2: "Burger" (list_end_index)
 curr_num_of_meals = 3

 remove_last_meal()
 result: true
 0: "Banana" (list_start_index)
 1: "Bottled Water" (list_end_index)
 curr_num_of_meals = 2

 remove_last_meal()
 remove_last_meal()
 result: true
 list_start_index = 0; list_end_index = 4; curr_num_of_meals = 0;

 remove_last_meal()
 result: false
 list_start_index = 0; list_end_index = 4; curr_num_of_meals = 0; (not changed)
 ------------------------------*/
bool Restaurant::remove_last_meal()
{
	if (curr_num_of_meals == 0) return false; 

//	list_end_index = (list_end_index)%4;
	if (list_end_index ==0) list_end_index =4;
	else --list_end_index;
    --curr_num_of_meals;
//    cout << "list_end_index "<<list_end_index<<"  list_start_index "<<list_start_index<<endl;
    return true;
}


/*-----------------------------
 Serve the buddy with the selected meal

 If the buddy has enough money to buy the meal:
    deduct food's price from buddy's money
    add food's fat_gain to buddy's fat
    add food's protein_gain to buddy's muscle
    return true
 else
    do nothing and return false

 you may assume:
 meal_index is in [0, 4]
 meals_list[meal_index] will never be 'garbage value'
 buddy will never be NULL
 ------------------------------*/
bool Restaurant::serve_meal(Buddy* buddy, int meal_index) const
{
	const Food *p = &meals_list[meal_index];
    if (buddy->get_money() >= p->get_price())
    {
        buddy->set_money(buddy->get_money() - p->get_price());
        buddy->set_fat(buddy->get_fat() + p->get_fat_gain());
        buddy->set_muscle(buddy->get_muscle() + p->get_protein_gain());
        return true;
    }
    return false;
}
