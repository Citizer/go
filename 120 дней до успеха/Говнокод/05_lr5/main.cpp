/* Разветвляющийся вычислительный процесс. Неформализованные задачи. N3  */
#include <iostream>

using namespace std;

int main() {
    int firstdigit, seconddigit, thirddigit, fourthdigit, number;
    cout << "The program checks whether a four digit number is a palindrome" << endl;
    cout << "Enter a four digit number ";
    cin >> number;
    firstdigit = number / 1000;
    seconddigit = number / 100 % 10;
    thirddigit = number / 10 % 10;
    fourthdigit = number % 10;
    if (firstdigit == fourthdigit && seconddigit == thirddigit) {
        cout << "The number is a palindrome";
    } else {
        cout << "The number is not a palindrome";
    }
}
