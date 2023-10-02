#pragma once
#include "Employee.h"
class SalariedEmployee : public Employee
{
public:
	SalariedEmployee(std::string name);
	void Display();
	float getGrossPay();
	float getAnnualSalary();
	void setAnnualSalary(float annual);

private:
	float annualSalary;
};

