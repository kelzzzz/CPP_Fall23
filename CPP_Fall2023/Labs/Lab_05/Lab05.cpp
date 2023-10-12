#include <iostream>
#include "Employee.h"
#include "SalariedEmployee.h"
int main()
{
    Employee robin = Employee("Dick Grayson");
    robin.setHourlyRate(20.00);
    robin.setHoursWorked(50);
    robin.Display();

    SalariedEmployee batman = SalariedEmployee("Bruce Wayne");
    batman.setAnnualSalary(250000);
    batman.Display();
}
