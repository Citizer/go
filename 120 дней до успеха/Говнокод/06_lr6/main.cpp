/* Программа проверяет, является ли введенное число совершенным, N15 */
#include <iostream>

using namespace std;

int main() {
    int sum, n, k;
    cout << "The program checks whether the entered number is perfect" << endl;
    cout << "Enter number ";
    cin >> n;
    sum = 0;
    k = 1;
    while (k < n) {
        if (n % k == 0) {
            sum += k;
        }
        k ++;
    }
    if (sum == n) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
