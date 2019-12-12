// SUBMIT THIS FILE

#include "consecutiveRNG.h"


ConsecutiveRNG::~ConsecutiveRNG()
{}

ConsecutiveRNG::ConsecutiveRNG():current(0)
{
}

int ConsecutiveRNG::getRandomNumber()
{
	int randomNumber = current%32768;
	current++;
	return randomNumber;
}
