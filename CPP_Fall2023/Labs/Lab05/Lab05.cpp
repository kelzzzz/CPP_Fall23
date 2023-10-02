#include <iostream>
#include "Employee.h"
int main()
{
    Employee batman = Employee("Bruce Wayne");
    batman.setHourlyRate(5000.00);
    batman.setHoursWorked(50);
    batman.Display();
}
