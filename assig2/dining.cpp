#include "dining.h"

Dining::Dining() :
	name(""), fat(0), energy(0), price(0) {}

Dining::Dining(string name_, int fat_, int energy_, int price_) :
    name(name_), fat(max(0, fat_)), energy(max(0, energy_)), price(max(0, price_)) {}

string Dining::getName() const {
    return name;
}

int Dining::getFat() const {
    return fat;
}

int Dining::getEnergy() const {
    return energy;
}

int Dining::getPrice() const {
    return price;
}

void Dining::debug_print(int indent) const {
    string indent1 = string(indent, '\t');
    string indent2 = string(indent+1, '\t');

    cout << indent1 << "Dining:" << endl
         << indent2 << "name:" << name << endl
         << indent2 << "fat:" << fat << endl
         << indent2 << "energy:" << energy << endl
         << indent2 << "price:" << price << endl;
}

Dining Dining::operator+(const Dining& dining) {
    /*
     * dining1 + dining2
	 *
	 * add all other attributes (fat, energy, price)
	 *
     * if names of dining1, dining2 are different, set the name as dining1.name + dining2.name
     * otherwise, do not modify the name
     *
     * Add your code here
     * */
	int fat_new = fat +  dining.getFat();
	int energy_new = energy + dining.getEnergy();
	int price_new = price + dining.getPrice();
	string name_new = name;
	if (name != dining.getName())
		name_new = name + dining.getName();
	return Dining(name_new, fat_new, energy_new, price_new);
}

Dining& Dining::operator+=(const Dining& dining) {
	/*
	 * dining1 += dining2
	 *
	 * add all other attributes (fat, energy, price)
	 *
	 * if names of dining1, dining2 are different, set the name as dining1.name + dining2.name
	 * otherwise, do not modify the name
	 *
	 * Add your code here
	 * */
	fat += dining.getFat();
	energy += dining.getEnergy();
	price += dining.getPrice();
	if (name != dining.getName())
		name = name + dining.getName();
	return *this;
}

Dining& Dining::operator=(const Dining& dining) {
	/*
	 * Assign the input dining to this
	 *
	 * Add your code here!
	 */
	fat = dining.getFat();
	energy = dining.getEnergy();
	price = dining.getPrice();
	name = dining.getName();
	return *this;
}
