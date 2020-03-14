/*  Вычисление y=f(x) в зависимости от n и x, используя switch, вариант N1 */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const float C = 5.329142;
    int n;
    float x,y;
    cout << "Calculating y=f(x) as a function of n and x" << endl;
    cout  << "Enter n ";
    cin >> n;
    cout << "Enter x ";
    cin >> x;
    switch (n) {
        case 1:
                if (x <= 0) {
                    cout << "x outside the range of acceptable values";
                } else {
                    y = C * fabs(M_PI - x) + C / (sqrt(x) + M_PI * x * x);
                    cout << "y=" << y;
                    }
                break;
        case 2:
                if (x <= 0 || x == 1) {
                    cout << "x outside the range of acceptable values";
                } else {
                    y = (C - exp(x - M_PI) + pow(cos(x), 2)) / log(x);
                    cout << "y=" << y;
                    }
                break;
        default:
                cout << "There is no solution for the given number of option n";
                break;
    }

}
