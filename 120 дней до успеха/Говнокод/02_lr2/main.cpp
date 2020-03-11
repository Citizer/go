/* Вычисление y=f(x) для заданного x по двум формулам */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const float N = 5.329142;
    float x, y;
    cout << "Calculating y=f(x) for a given x using two formulas" << endl;
    cout << "Calculating y using the first formula 0<x<=4" << endl;
    cout << "Enter  x (0<x<=4)" << endl;
    cin >> x;
    y = N * fabs(M_PI - x) + N / (sqrt(x) + M_PI * x * x);
    cout << "For x=" << x << " y=" << y << endl;
    cout << "Calculating y using the second formula 4<x<=5.8" << endl;
    cout << "Enter  x (4<x<=5.8)" << endl;
    cin >> x;
    y = (N - exp(x - M_PI) + pow(cos(x), 2)) / log(x);
    cout << "For x=" << x << " y=" << y;
}
