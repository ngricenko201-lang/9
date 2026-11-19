//////////////////////////////////////////////////////////////////////////////
// Lab_9_1.cpp
//                  головний файл проекту - функція main
//
// Варіант 4: ln(x+1) = x - x^2/2 + x^3/3 - x^4/4 + ...,  -1 < x <= 1

#include <iostream>
#include <math.h>
#include <iomanip>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    // шапка таблиці
    cout << "-----------------------------------------------------" << endl;
    cout << "|" << setw(8) << "x"
        << "|" << setw(14) << "ln(x+1)"
        << "|" << setw(14) << "S"
        << "|" << setw(12) << "n"
        << "|" << endl;
    cout << "-----------------------------------------------------" << endl;

    x = x_p;
    while (x <= x_k) {
        sum();                          // виклик процедури обчислення суми

        cout << "|" << setw(8) << fixed << setprecision(3) << x
            << "|" << setw(14) << setprecision(6) << log(x + 1)
            << "|" << setw(14) << s
            << "|" << setw(12) << n
            << "|" << endl;            // тут використовується форматний вивід

        x += dx;
    }
    cout << "-----------------------------------------------------" << endl;

    cin.get();
    cin.get();
    return 0;
}



