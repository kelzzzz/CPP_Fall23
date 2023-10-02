#include "SalariedEmployee.h"
#include <iostream>

SalariedEmployee::SalariedEmployee(std::string name)
{
	this->empName = name;
	this->empID = generateEmpId();
	std::cout << "SalariedEmployee object constructed.\n";
}

void SalariedEmployee::Display()
{
	std::cout << "Name: " << this->empName << "\n";
	std::cout << "ID: " << this->empID << "\n";
	std::cout << "Annual Salary: $" << this->annualSalary << "\n";
	std::cout << "Gross pay: $" << this->getGrossPay() << "\n";

}

float SalariedEmployee::getGrossPay()
{
	return this->annualSalary/26;
}

float SalariedEmployee::getAnnualSalary()
{
	return this->annualSalary;
}

void SalariedEmployee::setAnnualSalary(float annual)
{
	this->annualSalary = annual;
}
