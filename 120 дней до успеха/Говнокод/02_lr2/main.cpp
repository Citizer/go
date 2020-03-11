/* Вычисление y=f(x) для заданного x по двум формулам */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const float N = 5.329142;
    const float PI = 3.14;
    float x, y;
    cout << "Calculating y=f(x) for a given x using two formulas\n" ;
    cout << "Calculating y using the first formula 0<x<=4\n";
    cout << "Enter  x (0<x<=4)\n";
    cin >> x;
    y = N * fabs(PI - x) + N / (sqrt(x) + PI * x *x);
    cout << "For x=" << x << " y=" << y << endl;
    cout << "Calculating y using the second formula 4<x<=5.8\n";
    cout << "Enter  x (4<x<=5.8)\n";
    cin >> x;
    y = (N - exp(x - PI) + pow(cos(x), 2)) / log(x);
    cout << "For x=" << x << " y=" << y;
}
