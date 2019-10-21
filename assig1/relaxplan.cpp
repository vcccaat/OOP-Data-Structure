//
//  relaxplan.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 3/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "relaxplan.h"

/*-----------------------------
 Copy Constructor

 Copy name, and DEEP COPY the linked list: for every node (Relaxation*) in rp,
 copy a new node of it, and link all copied nodes in the same sequence
 ------------------------------*/
// Example solution for copy constructor, you don't have to implement it
RelaxPlan::RelaxPlan(RelaxPlan const & rp): name(rp.name) {
    // empty list
    if (!rp.head) {
        head = NULL;
        return;
    }
    // copy first node, prepare to copy second
    head = new Relaxation(*rp.head);
    Relaxation* curr_copied = head;
    Relaxation* next_to_copy = rp.head->get_next();
    // while next exists, continue copy
    while (next_to_copy) {
        Relaxation* copied = new Relaxation(*next_to_copy);
        curr_copied->set_next(copied);
        // next_to_copy is always a node in rp
        // curr_copied is always a node in self
        next_to_copy = next_to_copy->get_next();
        curr_copied = copied;
    }
}


/*-----------------------------
 Constructor
 @param name: string
 @appendix: initialize head to NULL
 ------------------------------*/
RelaxPlan::RelaxPlan(string name): name(name)
{
    head = NULL;
}


/*-----------------------------
 Destructor

 Deallocate all (Relaxation*) linked in this's linked list
 ------------------------------*/
RelaxPlan::~RelaxPlan()
{
    while (head != NULL)
    {
        // need to record next first, if after delete head, can't find head->next
        Relaxation* next = head->get_next();
        delete head;
        head = next ;
    }
}


/*-----------------------------
 Head getter
 @return: this's head
 ------------------------------*/
Relaxation* RelaxPlan::get_head() const
{
    return head;
}


/*-----------------------------
 Append an relaxation to the START of the linked list,
 @param r: a relaxation in STACK. You need to create a copy of it in HEAP, then do the append.
    DON'T DIRECTLY USE &r to append.

 Example:

 initial: "Sleep for 1h" (head) -> "Play for 15 min" -> NULL
 addToStart: "Complete 2012 PA1"
 result: "Complete 2012 PA1" (head) -> "Sleep for 1h" -> "Play for 15 min" -> NULL

 initial: NULL
 addToEnd: "Complete 2012 PA1"
 result: "Complete 2012 PA1" -> NULL
 ------------------------------*/
void RelaxPlan::addToStart(Relaxation r)
{
    Relaxation* p = new Relaxation(r);
    p->set_next(head);
    head = p;
}

/*-----------------------------
 Append an relaxation to the END of the linked list, for
 @param r: a relaxation in STACK. You need to create a copy of it in HEAP, then do the append.
 DON'T DIRECTLY USE &r to append.

 Example:

 initial: "Sleep for 1h" (head) -> "Play for 15 min" -> NULL
 addToEnd: "Complete 2012 PA1"
 result: "Sleep for 1h" (head) -> "Play for 15 min" -> "Complete 2012 PA1" -> NULL

 initial: NULL
 addToEnd: "Complete 2012 PA1"
 result: "Complete 2012 PA1" -> NULL
 ------------------------------*/
void RelaxPlan::addToEnd(Relaxation r)
{
    Relaxation* p = new Relaxation(r);
    Relaxation* temp = head;
    if (head == NULL) head = p;
    else
    {
        for (; temp->get_next() != NULL; temp = temp->get_next());
        temp->set_next(p);
    }
}

/*-----------------------------
 Remove and deallocate a node at a given index
 @ return: whether the removal is success or not

 Example:

 initial: "Sleep for 1h" (head) -> "Play for 15 min" -> "Complete 2012 PA1" -> NULL

 remove: 3
 result: false, nothing happened to the list

 remove: 1
 result: true, "Sleep for 1h" (head) -> "Complete 2012 PA1" -> NULL

 remove: 1
 result: true, "Sleep for 1h" (head) -> NULL

 remove: 0
 result: true, NULL (head)

 remove: 0
 result: false, nothing happened to the list
 ------------------------------*/
bool RelaxPlan::remove(int remove_index)
{
    bool not_exist = true;
    Relaxation* prev = NULL;
    Relaxation* cur = head;
    for (int index=0 ;cur != NULL; prev = cur, cur = cur->get_next(), ++index)
        if (index == remove_index) 
        {
            not_exist = false;
            break;
        }

    if (cur != NULL && not_exist == false)        
    {
        if (cur == head) head = head->get_next();
        else prev->set_next(cur->get_next());
        delete cur;
        return true;
    }
    return false;
}
