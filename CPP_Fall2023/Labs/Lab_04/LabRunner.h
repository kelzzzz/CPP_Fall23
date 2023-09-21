#pragma once
#include <string>
#include "Account.h"
class LabRunner
{
public:
	float input;
	char stateDescription[20];
	void run();
	void setUp();
	void obtainData(char state);
	void printReport();
	bool stateIsValid(char state);
private:
	char state = 'r';
	bool firstRun = true;
	Account* account; //order dependency
};

