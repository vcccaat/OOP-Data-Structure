/*
 * LinearProbing.h
 *
 *  Created on: Nov 25, 2019
 *      Author: sze
 */

#ifndef LINEARPROBING_H_
#define LINEARPROBING_H_

#include "OpenAddressing.h"

class LinearProbing : public OpenAddressing{

public:
	virtual int getIndexByhashing(int keyValue);
	LinearProbing(int s):OpenAddressing(s){}

};


#endif /* LINEARPROBING_H_ */
