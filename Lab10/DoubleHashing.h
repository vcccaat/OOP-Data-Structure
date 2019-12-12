/*
 * DoubleHashing.h
 *
 *  Created on: Nov 25, 2019
 *      Author: sze
 */

#ifndef DOUBLEHASHING_H_
#define DOUBLEHASHING_H_


#include "OpenAddressing.h"

class DoubleHashing : public OpenAddressing{
public:
	virtual int getIndexByhashing(int keyValue);
	DoubleHashing(int s):OpenAddressing(s){}

};




#endif /* DOUBLEHASHING_H_ */
