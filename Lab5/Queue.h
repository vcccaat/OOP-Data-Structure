

#ifndef QUEUE_H_
#define QUEUE_H_

const int SIZE = 8;

//First-in-first-out
class Queue
{

	int content[SIZE]; //stores the elements
	int n; //number of elements

public:
	Queue();
	int dequeue(); //remove an element from the queue, and return the value of it
	void enqueue(int element); //add an element to the queue
	int elementCount() { return n; }; //return the number of elements
	int getContent(int);
};



#endif /* QUEUE_H_ */
