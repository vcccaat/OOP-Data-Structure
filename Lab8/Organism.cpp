#include "Organism.h"

Organism::Organism(double v)
	:price(v) {}

Organism::~Organism(){

}

void Organism::setPrice(double v)
{
	price = v;
}

double Organism::getPrice() const
{
	return price;
}
