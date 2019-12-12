/*
 * QuadraticProbing.h
 *
 *  Created on: Nov 25, 2019
 *      Author: sze
 */

#ifndef QUADRATICPROBING_H_
#define QUADRATICPROBING_H_


#include "OpenAddressing.h"

class QuadraticProbing : public OpenAddressing{
public:
	virtual int getIndexByhashing(int keyValue);
	QuadraticProbing(int s):OpenAddressing(s){}


};




#endif /* QUADRATICPROBING_H_ */
