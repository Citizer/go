/* Дано  натуральное  число  n. Получить  все  способы  выплаты  суммы  n  с  помощью
монет достоинством  1, 3 и 5  копеек */
#include <iostream>

using namespace std;

int main() {
    int sum, i, j, k;
    cout << "Program for getting all the ways to pay the amount using coins of 1, 3 and 5 kopecks" << endl;
    cout << "Enter the amount ";
    cin >> sum;
    cout << "|   1   |   3   |   5   |" << endl;
    cout << "_________________________" << endl;    
    for (i = 0; i <= sum / 5; i++) {
        for (j = 0; j <= (sum - 5 * i) / 3; j++) {
            for (k = 0; k <= (sum - 5 * i - 3 * j); k++) {
                if (i * 5 + j * 3 + k * 1 == sum) {
                    cout << "    " << k << "      " << j << "        " << i << endl;
                }            
            }
        }
    }
	
	/*
	Должно быть так:
	    for (i = 0; i <= sum; i++) {
			int proizFive = i * 5;
        for (j = 0; j <= (sum - proizFive) / 3; j++) {
			int proizThree = j * 3;
            for (k = 0; k <= (sum - 5 * i - 3 * j); k++) {
                if (proizFive + proizThree + k * 1 == sum) {
                    cout << "    " << k << "      " << j << "        " << i << endl;
                }            
            }
        }
    }
	
	В первом вашем варианте вы в каждом вложенном цикле заново умножали переменную из первого и второго цикла
	т.е. каждый раз, когда брали новый k вы умножали старый i на 5, старый j на 3. 
	Это даёт вот такую картину вычислений: k^j^i вычислений, при возможных k*j*i. Это очень нерациональный расход ресурсов.   
	Вам нужно ещё чуть-чуть оптимизировать циклы, чтоб они не проходили лишнее. 
}
