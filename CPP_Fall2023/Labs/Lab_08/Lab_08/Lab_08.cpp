#include <iostream>
#include "FirstFitService.h"
#include "NextFitService.h"
#include "BinObj.h"
#include <vector>
#include <time.h>
using namespace std;

// function prototypes
void print(const vector<int>&);
int getRandomValue(int val);

int main() {
	vector<int> vect;
	int pos = 0;
	int number = 0;
	int count = 1;
	int upperBound = 0;
	srand(time(NULL));
	cout << "how many items are to be packed? ";
	cin >> number;
	cout << "enter the bin capacity? ";
	cin >> upperBound;
	while (count <= number)
	{
		pos = getRandomValue(upperBound);
		vect.push_back(pos);
		count++;
	}
	cout << "-----------------------------" << endl;
	cout << "\nitems to pack: \n";
	print(vect);

	FirstFitService ff = FirstFitService(vect, upperBound);
	ff.fillBins();
	NextFitService nf = NextFitService(vect, upperBound);
	nf.fillBins();
	
	return 0;
}

int getRandomValue(int ub)
{
	int element = 0;
	int upperBound = ub;
	int lowerBound = 1;
	element = rand() % upperBound + lowerBound;
	return element;
}
void print(const vector<int>& a)
{
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	cout << endl;
	cout << "-----------------------------" << endl;
}