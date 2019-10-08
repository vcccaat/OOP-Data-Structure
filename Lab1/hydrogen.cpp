#include "hydrogen.h"
#include <iostream>

using namespace std;

Hydrogen::Hydrogen()
{
	cout << "Constructing Hydrogen..." << endl;
}

void Hydrogen::sayTheName() const
{
	cout << "There is Hydrogen!" << endl;
}
