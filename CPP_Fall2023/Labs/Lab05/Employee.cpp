#include "Employee.h"
#include <time.h>
#include <iostream>
Employee::Employee(std::string name)
{
	this->empName = name;
	this->empID = generateEmpId();
}

void Employee::Display()
{
	std::cout << "Name: " << this->empName << "\n";
	std::cout << "ID: " << this->empID << "\n";
	std::cout << "Rate: $" << this->hourlyRate << "\n";
	std::cout << "Hours worked: " << this->hoursWorked << " hrs\n";
}

void Employee::setEmpID(std::string set)
{
	this->empID = set;
}

void Employee::setHourlyRate(float rate)
{
	this->hourlyRate = rate;
}

float Employee::getHourlyRate()
{
	return this->hourlyRate;
}

void Employee::setName(std::string name)
{
	this->empName = name;
}

std::string Employee::getEmpName()
{
	return this->empName;
}

float Employee::getGrossPay()
{
	this->grossPay = hoursWorked * hourlyRate;
	return this->grossPay;
}

int Employee::getHoursWorked()
{
	return this->hoursWorked;
}

void Employee::setHoursWorked(int hours)
{
	this->hoursWorked = hours;
}

std::string Employee::generateEmpId() //in real world you wouldn't want two of the same id to be possibly generated
{
	int code[6];
	code[5] = 1;

	srand(time(NULL));

	for (int i = 0; i < 5; ++i)
		code[i] = rand() % 10;

	std::string result;

	for (int i = 0; i < 5; i++) {
		result += std::to_string(code[i]);
	}

	return result;
}
