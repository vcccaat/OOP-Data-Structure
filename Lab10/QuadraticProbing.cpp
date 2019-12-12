/*
 * QuadraticProbing.cpp
 *
 *  Created on: Nov 25, 2019
 *      Author: sze
 */

#include "QuadraticProbing.h"
#include <math.h>
#include <iostream>
using namespace std;

// To be implemented in sub-classes: if there is no empty entries
// or any other errors exist, please return -1
int QuadraticProbing::getIndexByhashing(int keyValue)
{
	if(bucketSize == occupiedSize)
		return -1;
	int index = keyValue%bucketSize;
	int orginalIndex = index;
	for(int i = 0; data[index] != -1; i++)
	{
		index = fmod((orginalIndex + pow(i,2)),bucketSize);
	}

	return index;
}

