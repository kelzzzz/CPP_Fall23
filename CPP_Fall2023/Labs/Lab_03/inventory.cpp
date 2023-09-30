/*******************\
* Kels Cavin
* 9/12/2023
* CIS 242 FH
* Lab 03
* ******************/

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>

using namespace std;

class Inventory
{
public:
	int local;
	int itemsNum[100];
	char itemsChar[100];
	double itemsCosts[100];
	int iterableInventory;

	void setIterableInventory(int max) {
		this->iterableInventory = max;
	}

	void setItemsNum(int iterator, int value) {
		this->itemsNum[iterator] = value;
	}

	void setItemsChar(int iterator, char value) {
		this->itemsChar[iterator] = value;
	}

	void setItemsCost(int iterator, double value) {
		this->itemsCosts[iterator] = value;
	}

	double getTotalCost() {
		double ans=0;
		for (int i = 0; i < iterableInventory; i++) {
			ans += this->itemsCosts[i];
		}
		return ans;
	}
};

class Valuation {
public:
	Inventory inv;

	Valuation(Inventory &inv) {
		this->inv = inv;
	}

	void EvaluateWeightedAverage() {
		double weighted = 0;
		double totalCost = inv.getTotalCost();
		weighted = totalCost/(double)inv.iterableInventory;
		cout << "Total weighted average unit cost = $" << setprecision(2) << fixed << weighted << endl;
	}
};

//Removed global variables; no longer needed, encapsulated in Inventory object

void GenerateRandomLetters(Inventory &inv);
void GenerateRandomNumbers(Inventory &inv);
void GenerateRandomCosts(Inventory &inv);
void InputItemsInInventory(Inventory& inv);

int getRandomInt();
char getRandomChar();

int main()
{
	// seed for the random number generator
	srand(time(NULL));
	Inventory inv{};

	InputItemsInInventory(inv);
	GenerateRandomLetters(inv);
	GenerateRandomNumbers(inv);
	GenerateRandomCosts(inv);

	Valuation val(inv);
	val.EvaluateWeightedAverage();

	system("PAUSE");
	return 0;
}

void InputItemsInInventory(Inventory& inv) {
	int units = 0;
	cout << "How many items in the inventory?" << endl;
	cin >> units;
	inv.setIterableInventory(units);
}

int getRandomInt() {
	int random;
	random = 100 * (rand() / (RAND_MAX + 1.0));
	return random;
}

char getRandomChar() {
	int random;
	random = 26 * (rand() / (RAND_MAX + 1.0));
	random = random + 97;
	return (char)random;
}

void GenerateRandomLetters(Inventory &inv)
{
	char randChar = '\0';

	for (int i = 0; i < inv.iterableInventory; i++)
	{
		randChar = getRandomChar();
		inv.setItemsChar(i, randChar);
		printf("Inventory Item: %c\n", randChar);
	}
}

void GenerateRandomNumbers(Inventory &inv)
{
	int randNum = 0;
	for (int i = 0; i < inv.iterableInventory; i++)
	{
		randNum = getRandomInt();
		inv.setItemsNum(i, randNum);
		printf("Item Quantity: %d\n", randNum);
	}
}

void GenerateRandomCosts(Inventory &inv) {
	double fMin = 20000.00, fMax = 0.00;
	double f = 0.00;
	double cost = 0.00;

	for (int i = 0; i < inv.iterableInventory; i++)
	{
		f = (double)rand() / RAND_MAX;
		cost = ceil(fMin + f * (fMax - fMin)) / 100;
		inv.setItemsCost(i, cost);
		cout << "Item Cost = $" << setprecision(2) << fixed << cost << endl;
	}
}
