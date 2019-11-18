#ifndef ORGANISM_H
#define ORGANISM_H


class Organism {
public:
	Organism(double v);
	virtual ~Organism();
	virtual void calculatePrice() = 0;

	void setPrice(double v);
	double getPrice() const;

private:
	double price;
};

#endif // ORGANISM_H
