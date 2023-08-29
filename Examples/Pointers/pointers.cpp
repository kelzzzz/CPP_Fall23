#include<iostream>
using namespace std;
int main() {
	int j = 2, * k = &j;
	*k = 3;
	cout << "J value= " << j << "\nK value= " << *k << endl;
	cout << "J address= " << &j << "\nK address= " << k << endl;
	j = 5;
	cout << "J value after= " << &j << "\nK value after= " << k << endl;

	return 0;
}