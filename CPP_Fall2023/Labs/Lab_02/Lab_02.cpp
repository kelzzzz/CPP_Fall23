#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

/* 
programmer: Kels (Kelsey) Cavin
CIS 242 Section FH, Professor Papademas
09/05/2023
*/

void DisplayInfo()
{
    cout << "\n\n";
    cout << "Edgebrook Electronics" << endl;
    cout << "_____________________\n\n" << endl;
    cout << "Standard Desktop, Laptop and Portable Palm Models:\n" << endl;
    cout << "Production Scheduling program:\n\n" << endl;
    cout << "	The production constraints are:\n" << endl;
    cout << "	40d + 30l + 20p <= 2460 (Labor Constraints in hours)" << endl;
    cout << "	550d + 225l + 175p <= 50000 (Capital Constraints in USD)\n";
    cout << "\n\n";
    cout << "   where:" << endl;
    cout << "	  d equals the number of Standard Desktop Models" << endl;
    cout << "	  l equals the number of Laptop Models" << endl;
    cout << "	  and p equals the number of Portable Palm Models" << endl;
}

bool isScheduleFeasible(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "cannot produce any electronics less than 0" << endl;
        return false;
    }
    if ((40 * a + 30 * b + 20 * c <= 2460)
        && ((550 * a) + (225 * b) + (175 * c) <= 50000)) {
        return true;
    }
    else {
        return false;
    }
}

double calculateProft(int a, int b, int c) {
    return 1.30 * ((550 * a) + (225 * b) + (175 * c));
}

void FindProfit(int a, int b, int c)
{
    if (isScheduleFeasible(a,b,c))
    {
        cout << "the production schedule is feasible" << endl;
        double profit = calculateProft(a, b, c);
        cout << "and the profit yielded by this schedule is $"
            << setiosflags(ios::fixed | ios::showpoint)
            << setprecision(2)
            << profit << endl;
    }
    else
    {
        cout << "\nthe production schedule is not feasible\n" << endl;
    }
}


void UserInput(int &a, int &b, int &c) {
    cout << "Please enter the number of Standard Desktop Models:" << endl;
    cin >> a;
    cout << "Please enter the number of Laptop Models:" << endl;
    cin >> b;
    cout << "Please enter the number of Portable Palm Models:" << endl;
    cin >> c;
}

int main()
{
    int d = 0, l = 0, p = 0;

    char ans;

    //print header

    DisplayInfo();

    do
    {
        UserInput(d, l, p);
        FindProfit(d, l, p);

        cout << "\nEnter another production schedule?" << endl;
        cout << "type Y for Yes or N for No" << endl;
        cin >> ans;
        system("CLS");
    } while (ans == 'Y' || ans == 'y');

    return 0;
}
