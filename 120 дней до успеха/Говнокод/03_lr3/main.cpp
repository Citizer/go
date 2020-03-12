/* Программа для вычисления y=f(x) используя ветвления для N30 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const float N = 1.2345;
    float x, y;
    cout << "Calculating y=f(x) for a given x using two formulas" << endl;
    cout << "Enter x" << endl;
    cin >> x;
    if (x > 0 && x <= 0.7) {
        y = N * pow(x + 1, 1 / 3) + pow(M_PI - x, 2);
        cout << "For " << x << " y=" << y;
    } else {
        if (x > 0.7 && x < 1) {
            y = (exp(M_PI + x) + N * sin(x) * sin(x)) / log(x + N);
            cout << "For " << x << " y=" << y;
        } else { cout << "For " << x << " no decision";
        }
    }
}
