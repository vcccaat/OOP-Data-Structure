#include <iostream>
#include "hydrogen.h"
#include "oxygen.h"

using namespace std;

int main()
{
	const Hydrogen* hydrogen1 = new Hydrogen;
	const Hydrogen hydrogen2;
	const Oxygen* oxygen = new Oxygen;

	hydrogen1->sayTheName();
	hydrogen2.sayTheName();
	oxygen->sayTheName();

	cout << "And we have water! Need 8 glasses of it everyday yo!" << endl;

	delete hydrogen1;
	delete oxygen;

	return 0;
}
