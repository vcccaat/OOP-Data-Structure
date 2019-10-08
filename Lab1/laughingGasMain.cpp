#include <iostream>
#include "nitrogen.h"
#include "oxygen.h"

using namespace std;

int main()
{
	const Nitrogen* nitrogen1 = new Nitrogen;
	const Nitrogen nitrogen2;
	const Oxygen* oxygen = new Oxygen;

	nitrogen1->sayTheName(); //why use "->" here?
	nitrogen2.sayTheName(); //and why use "." here?
	oxygen->sayTheName();

	cout << "And we have laughing gas (dinitrogen oxide)! hahaha" << endl;

	delete nitrogen1;
	delete oxygen;

	//we needed to delete nitrogen1 but not nitrogen2, why?

	return 0;
}
