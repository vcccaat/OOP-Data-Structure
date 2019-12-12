/*
 * LinearProbing.cpp
 *
 *  Created on: Nov 25, 2019
 *      Author: sze
 */


#include "LinearProbing.h"

// To be implemented in sub-classes: if there is no empty entries
// or any other errors exist, please return -1
int LinearProbing::getIndexByhashing(int keyValue)
{
	if(bucketSize == occupiedSize)
		return -1;
	int index = keyValue%bucketSize;
	while(data[index] != -1)
	{
		index = (index+1)%bucketSize;
	}
	return index;
}
