
#include <iostream>
#include "SeparateChaining.h"
using namespace std;

SeparateChaining::SeparateChaining(int size): Hashing(size),data(NULL){
	reset(size);
}

SeparateChaining::~SeparateChaining(){
	clearData();
}


void SeparateChaining::reset(int newSize){
	if(data != NULL)
		clearData();

	//create the hash table
	data = new ChainingElem[newSize];
	for(int i = 0; i < newSize; i++){
		data[i].value = EMPTY;			//NOTE: please do not store any other data here
		data[i].next = NULL;	 		//the pointer pointing to the linked list
	}
	bucketSize=newSize;
}

void SeparateChaining::print(){
	cout<<"[";
	for(int i = 0; i < bucketSize; i++){
		if(data[i].next == NULL){
			cout<<"_";
			if(i != bucketSize -1){
				cout<<",";
			}
		}
		else{
			ChainingElem *tmp = data[i].next;
			while(tmp != NULL){
				if(tmp != data[i].next){ //the value is not the first element of the linked list
					cout<<"->";
				}
				cout<<tmp->value;
				tmp = tmp->next;
			}
			cout<<",";
		}
	}
	cout<<"]"<<endl;
}


//TODO: Implement the hash function and return the location in which new value will be inserted
int SeparateChaining::getIndexByhashing(int keyValue)
{
	return keyValue%bucketSize;
}



//TODO: Implement the function that will insert the new value into the hash table
bool SeparateChaining::insert(int newValue)
{
	int index = getIndexByhashing(newValue);
	ChainingElem* head = new ChainingElem;
	head->value = newValue;
	head->next = NULL;

	if (data[index].next == NULL)  // linked list is NULL
	{
		data[index].next = head;
	}
	else
	{
		ChainingElem* p = data[index].next;
		while(p->next != NULL)   // add to the end
			p = p->next;

		p->next = head;

	}
	return true;

}


//TODO: Implement the function that clear the hash table
//just return true after deletion; you may return false if the data is already deleted when this function is called
bool SeparateChaining::clearData()
{
	delete data;
	bucketSize = 0;

}

