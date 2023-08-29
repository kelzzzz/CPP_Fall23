#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;	// programmer: Kels (Kelsey) Cavin

bool isFeasible(int x, int y) {
    //fail fast
    if (x <= 0 || y <= 0) {
        cout << "\nproduction schedule is not feasible\n" << endl;
        cout << "\nmaterial qty must be greater than 0.\n" << endl;
        return false;
    }
    if ((12 * x + 4 * y >= 156) && (7 * x + 3 * y >= 116)) {
        cout << "\nproduction schedule is not feasible\n" << endl;
        cout << "\nmaterial qty exceeds available materials.\n" << endl;
        return false;
    }
    return true;
}

bool ProfitIsValid(int profit) {
    if (profit < 20) {
        return false;
    }
    return true;
}

int CalculateProfit(int x, int y) {
    return (3 * x + 1.5 * y);
}

void FindProfit(int x, int y) {
    int const profit = CalculateProfit(x, y);

    if (isFeasible(x,y))
    {
        cout << "the production schedule is feasible" << endl;
        cout << "and the profit yielded by this schedule is $"
            << setiosflags(ios::fixed | ios::showpoint)
            << setprecision(2) << profit << endl;
        if (!ProfitIsValid(profit)) {
            cout << "profit is below $20.00 which is not reccomended" << endl;
            cout << "consider optimizing this production schedule." << endl;
        }
    }
}

int main()
{
    int x, y;
    char answer = 'y';

    cout << "Avenue Bakery" << endl;
    cout << "_ _ _ _ _ _ _\n\n" << endl;
    cout << "Apple Pies and Apple Tarts:\n" << endl;
    cout << "Production Scheduling Program:\n\n" << endl;
    cout << "  the production constraints are:\n" << endl;
    cout << "  12x + 4y <= 156 Ounces of Fruit" << endl;
    cout << "   7x + 3y <= 116 Ounces of Dough" << endl;
    cout << "\n\n";
    cout << "  where x equals the number of pies" << endl;
    cout << "  and y equals the number of tarts\n" << endl;

    do
    {
        cout << "Please enter the number of pies" << endl;
        cin >> x;
        cout << "Please enter the number of tarts" << endl;
        cin >> y;
        
       /****************/
        FindProfit(x, y);
       /****************/

        cout << "\nEnter another production schedule?" << endl;
        cout << "type Y for Yes or N for No" << endl;
        cin >> answer;
        system("CLS");
    } while (answer == 'Y' || answer == 'y');

    return 0;
}

