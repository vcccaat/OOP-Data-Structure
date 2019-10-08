//
//  workoutenvironment.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "workoutenvironment.h"

/*-----------------------------
 Constructor
 @appendix:
    available_workouts = dynamic array with length MAX_NUM_OF_WORKOUTS
    current_num_of_workouts = 0
    participants = NULL
    current_num_of_participants = 0

 you may assume:
    entry_fee is non-negative
    MAX_NUM_OF_WORKOUTS is positive
 ------------------------------*/


WorkoutEnvironment::WorkoutEnvironment(string name, int entry_fee, int MAX_NUM_OF_WORKOUTS)
:name(name), entry_fee(entry_fee) ,available_workouts(new Workout [MAX_NUM_OF_WORKOUTS]),MAX_NUM_OF_WORKOUTS(MAX_NUM_OF_WORKOUTS)
{
	current_num_of_workouts = 0;
	participants = NULL;
	current_num_of_participants = 0;
}

/*-----------------------------
 Destructor

 Delete the available_workouts array
 Delete the participants array
 DO NOT delete the buddy objects inside the participants array, their life cycles are managed elsewhere
 ------------------------------*/
WorkoutEnvironment::~WorkoutEnvironment()
{
    delete [] available_workouts;
    delete [] participants;
}


/*-----------------------------
 Name getter
 @return this's name
 ------------------------------*/
string WorkoutEnvironment::get_name() const
{
    return name;
}

/*-----------------------------
 Entry fee getter
 @return this's entry_fee
 ------------------------------*/
int WorkoutEnvironment::get_entry_fee() const
{
    return entry_fee;
}


/*-----------------------------
 Insert a workout at available_workouts[add_index]. (Fix length dynamic array)
 @return: whether the add is success or not

 @appendix:
    You need to check whether the index is valid or not.
    Valid indices are in [0, current_num_of_workouts], and the array shouldn't be full.

    If the insertion cannot be done, do nothing and return false;
    otherwise perform the adding and return true.

    The workout inserted is actually a copy of the passed in workout.

 Example:

 initial: MAX_NUM_OF_WORKOUTS = 4; current_num_of_workouts = 0;

 add_workout: "Wrestling", 2
 result: false (index invalid)

 add_workout: "Wrestling", 0
 result: true
    0: "Wrestling"

 add_workout: "Bicep Dumbbell Curl", 1
 add_workout: "Machine Shoulder Press", 2
 result: true
    0: "Wrestling"
    1: "Bicep Dumbbell Curl"
    2: "Machine Shoulder Press"

 add_workout: "Machine Chest Fly", 1
 result: true
    0: "Wrestling"
    1: "Machine Chest Fly"
    2: "Bicep Dumbbell Curl"
    3: "Machine Shoulder Press"

 add_workout: "Type Code", 1
 result: false (array full)
    (array not changed)
 ------------------------------*/
bool WorkoutEnvironment::add_workout(const Workout& workout, int add_index)
{
    if ( 0 <= add_index && add_index <= current_num_of_workouts && current_num_of_workouts < MAX_NUM_OF_WORKOUTS)  
    {   
        for (int i = 0; i <= current_num_of_workouts; ++i)
        {
            if (i == add_index)
            {
                for (int j = current_num_of_workouts; j > i; --j)  //MAX_NUM_OF_WORKOUTS
                {
                    available_workouts[j] = available_workouts[j-1];
                }
                available_workouts[add_index] = workout;
                ++current_num_of_workouts;
                
            }
        }
        return true;
    }

    return false;

}

/*-----------------------------
 Remove a workout at available_workouts[remove_index]. (Fix length dynamic array)
 @return: whether the remove is successful or not

 @appendix:
    You need to check whether the index is valid or not.
    Valid indices are in [0, current_num_of_workouts), and the array shouldn't be empty.

    If the removal cannot be done, do nothing and return false;
    otherwise perform the removal and return true.

 Example:

 initial: MAX_NUM_OF_WORKOUTS = 4; current_num_of_workouts = 4;
    0: "Wrestling"
    1: "Machine Chest Fly"
    2: "Bicep Dumbbell Curl"
    3: "Machine Shoulder Press"

 remove_workout: 4
 result: false

 remove_workout: 3
 result: true
    0: "Wrestling"
    1: "Machine Chest Fly"
    2: "Bicep Dumbbell Curl"

 remove_workout: 1
 result: true
    0: "Wrestling"
    1: "Bicep Dumbbell Curl"

 remove_workout: 2
 result: false

 remove_workout: 0
 remove_workout: 0
 result: true
    empty array; current_num_of_workouts = 0;

 remove_workout: 0
 result: false
 ------------------------------*/
bool WorkoutEnvironment::remove_workout(int remove_index)
{
    if (0 <= remove_index && remove_index <= current_num_of_workouts && current_num_of_workouts > 0)
    {
        
        for (int i = 0; i < current_num_of_workouts; ++i)
        {
            if (i == remove_index)
            {
                for ( ; i < current_num_of_workouts-1; ++i)
                {
                    available_workouts[i] = available_workouts[i+1];

                }
                available_workouts[current_num_of_workouts-1] = Workout();
                --current_num_of_workouts;
            }

        } 
        return true; 
    }
    return false;   
}


/*-----------------------------
 Get the buddy's index in the participants array
 @return:
    the index of the buddy if he is registered.
    If he is not registered, return -1.

 You may assume buddy is not NULL
 ------------------------------*/
int WorkoutEnvironment::participant_index(const Buddy* buddy) const
{
    // cout<<"address of buddy"<<buddy<<endl;
    for (int i = 0; i < current_num_of_participants; ++i)
    {
        // cout<<"address of candiate"<<participants[i]<<endl;
        if (participants[i] == buddy)
            return i;
    }
    return -1;
}

/*-----------------------------
 Add the buddy to the end of the participants array
 @return: whether the add is successful or not

 If the buddy is already registered or he does not have enough money:
    - do nothing and return false
 otherwise
    - deduct money!
    - Update array
        1. create a new double pointer array with length (current_num_of_participants + 1).
        2. copy all previous Buddy* to the new array. This is only copying addresses, not the Buddy objects.
        3. assign the passed in buddy* to the new array's 'current_num_of_participants' element, this is also copying addresses.
        4. delete[] participants, DO NOT delete the pointers to the Buddy objects inside the array.
        5. participants = new array, update 'current_num_of_participants'.

 If you get stuck in this function, we strongly recommend you revise 2011 (or Google) to have a clearer understanding of memory & addresses.
 You may assume buddy is not NULL.
 ------------------------------*/
bool WorkoutEnvironment::register_participant(Buddy* buddy)
{
    
    if ((participant_index(buddy)!=-1) || buddy->get_money() < entry_fee) return false;

    buddy->set_money(buddy->get_money() - entry_fee);


    Buddy** temp = new Buddy* [current_num_of_participants + 1];
    for (int i = 0; i < current_num_of_participants; ++i)
    {
        temp[i] = participants[i];
    }
    temp[current_num_of_participants] = buddy;
    delete [] participants;
    participants = temp;
    ++current_num_of_participants;
    return true;
}


/*-----------------------------
 Let a Buddy start his workout in this env
 @return: true if the participant finishes the workout; otherwise false

 1. check if participant_index & workout_index are valid
 2. check if buddy has enough energy to do this workout
 3. buddy's fat += workout's fat_change
    buddy's muscle += workout's muscle_change
    buddy's energy += workout's energy_change
 ------------------------------*/
bool WorkoutEnvironment::start_workout(int participant_index, int workout_index) const
{
    if ( participant_index <= current_num_of_participants && workout_index <= current_num_of_workouts
    		&& participant_index > 0 && workout_index > 0)
    {
        if (participants[participant_index]->get_energy() + available_workouts[workout_index].get_energy_change() > 0)
        {
            participants[participant_index]->set_fat(participants[participant_index]->get_fat() + available_workouts[workout_index].get_fat_change());
            participants[participant_index]->set_muscle(participants[participant_index]->get_muscle() + available_workouts[workout_index].get_muscle_change());
            participants[participant_index]->set_energy(participants[participant_index]->get_energy() + available_workouts[workout_index].get_energy_change());
            return true;
        }
    }
    return false;
}
