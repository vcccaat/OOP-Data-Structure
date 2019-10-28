
#ifndef STACK_H_
#define STACK_H_

#include <iostream>
using namespace std;
const int size = 1024;

class Stack
{
	friend class Queue;
	int data[size]; // Use an array to store data
	int top_index; // Starts from 0; -1 when empty
public:
	Stack();
	bool empty() const;
	int top() const;
	void push(int);
	int pop();
};



#endif /* STACK_H_ */
