#pragma once
#include <string>
class Employee
{
public:
	Employee(std::string name);
	void Display();
	void setEmpID(std::string set);
	void setHourlyRate(float rate);
	float getHourlyRate();
	void setName(std::string name);
	std::string getEmpName();
	float getGrossPay();
	int getHoursWorked();
	void setHoursWorked(int hours);
	std::string generateEmpId();
protected:
	std::string empID;
	std::string empName;
	float hourlyRate;
	float grossPay;
	int hoursWorked;
};

