/* Разветвляющийся вычислительный процесс. Неформализованные задачи. N3  */
#include <iostream>

using namespace std;

int main() {
    int c1, c2, c3, c4, x;
    cout << "The program checks whether a four digit number is a palindrome" << endl;
    cout << "Enter a four digit number ";
    cin >> x;
    c1 = x / 1000;
    c2 = x/ 100 % 10;
    c3 = x / 10 % 10;
    c4 = x % 10;
    if (c1 == c4 && c2 == c3) {
        cout << "The number is a palindrome";
    } else {
        cout << "The number is not a palindrome";
        }
}
