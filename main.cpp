// COMSC-210 | Lab 20 | Mika Aquino
// IDE used: Visual Studio 2022

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 3;

class Chair {
private:
	int legs;
	double* prices;
public:
	// Default constructor
	Chair() {
		prices = new double[SIZE];
		// Randomly select 3 or 4 legs
		legs = (rand() % 2) + 3;
		// Randomly select prices from $100.00 to $999.99.
		const int MIN = 10000, MAX = 99999;
		for (int i = 0; i < SIZE; ++i) {
			prices[i] = (rand() % (MAX - MIN + 1) + MIN) / (double) 100;
		}
	}
	// Parameter constructor
	Chair(int l, double p[]) {	// Takes number of legs and an array of 3 doubles (the prices)
		prices = new double[SIZE];
		legs = l;
		for (int i = 0; i < SIZE; ++i) {
			prices[i] = p[i];
		}
	}
	// setters and getters
	void setLegs(int l)		{ legs = l; }
	int getLegs()			{ return legs; }

	void setPrices(double p1, double p2, double p3) {
		prices[0] = p1; prices[1] = p2; prices[2] = p3;
	}

	double getAveragePrices() {
		double sum = 0;
		for (int i = 0; i < SIZE; i++)
			sum += prices[i];
		return sum / SIZE;
	}

	void print() {
		cout << "CHAIR DATA - legs: " << legs << endl;
		cout << "Price history: ";
		for (int i = 0; i < SIZE; i++)
			cout << prices[i] << " ";
		cout << endl << "Historical avg price: " << getAveragePrices();
		cout << endl << endl;
	}
};

int main() {
	srand(static_cast<unsigned int>(time(0)));	// Seed for random numbers

	cout << fixed << setprecision(2);

	// Create a chair object and call its setters to populate the object's data
	Chair* chairPtr = new Chair;
	chairPtr->setLegs(4);
	chairPtr->setPrices(121.21, 232.32, 414.14);
	chairPtr->print();
	delete chairPtr;
	chairPtr = nullptr;

	// Creating dynamic chair object with the parameter constructor
	double livingChairPrices[SIZE] = {525.25, 434.34, 252.52};
	Chair* livingChair = new Chair(3, livingChairPrices);
	livingChair->print();
	delete livingChair;
	livingChair = nullptr;

	// Create a dynamic array of chair objects using the default constructor to populate the objects with random values
	Chair* collection = new Chair[SIZE];
	const int COLLECTION_SIZE = 3;
	for (int i = 0; i < COLLECTION_SIZE; ++i) {
		collection[i].print();
	}
	delete[] collection;
	collection = nullptr;
	
	return 0;
}