/* Дано  натуральное  число  n. Получить  все  способы  выплаты  суммы  n  с  помощью
монет достоинством  1, 3 и 5  копеек */
#include <iostream>

using namespace std;

int main() {
    int sum, i, k, j, count_1, count_3, count_5;
    cout << "Program for getting all the ways to pay the amount using coins of 1, 3 and 5 kopecks" << endl;
    cout << "Enter the amount ";
    cin >> sum;
    cout << "|   1   |   3   |   5   |" << endl;
    cout << "_________________________" << endl;
    count_1 = sum;
    count_3 = sum / 3;
    count_5 = sum / 5;
    for (i = 0; i <= count_1; i ++)
        for (j = 0; j <= count_3; j ++)
            for (k = 0; k <= count_5; k ++)
                if (i * 1 + j * 3 + k * 5 == sum) {
                    cout << "    " << i << "      " << j << "        " << k << endl;
                }
}
