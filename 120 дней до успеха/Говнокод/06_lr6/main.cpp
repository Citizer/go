/* Программа проверяет, является ли введенное число совершенным, N15 */
#include <iostream>

using namespace std;

int main() {
    int sum, number, count;
    cout << "The program checks whether the entered number is perfect" << endl;
    cout << "Enter number ";
    cin >> number;
    sum = 0;
    count = 1;
    while (count < number) {
        if (number % count == 0) {
            sum += count;
        }
        count++;
    }
    if (sum == number) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
