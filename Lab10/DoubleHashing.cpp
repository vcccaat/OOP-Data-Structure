/*
 * DoubleHashing.cpp
 *
 *  Created on: Nov 25, 2019
 *      Author: sze
 */

#include "DoubleHashing.h"
#include <math.h>


// To be implemented in sub-classes: if there is no empty entries
// or any other errors exist, please return -1
int DoubleHashing::getIndexByhashing(int keyValue)
{
	if(bucketSize == occupiedSize)
		return -1;

	int index = keyValue%bucketSize;
	int hash2index = 5 - (keyValue%5);

	int orginalIndex = index;
	for(int i = 0; data[index] != -1; i++)
	{
		index = fmod((orginalIndex + i * hash2index),bucketSize);
	}

	return index;
}
