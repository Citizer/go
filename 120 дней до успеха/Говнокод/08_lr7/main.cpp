/* Дана  целая  квадратная  матрица  порядка n. Найти  наименьшее  из  значений
элементов, расположенных в заштрихованной части матрицы, N10 */
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
    const int N = 5;
    int A[N][N];
    int number, i, j, minimum;
    srand(time(NULL));
    cout << "Program for finding the smallest value elements located in the shaded part of the matrix" << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = rand() % 1000;
            cout << setw(5) << A[i][j];
        }
        cout << endl;
    }    
    cout << " _________" << endl << "|*       *|" << endl << "|***   ***|" << endl << "|*********|  1" << endl << "|***   ***|" << endl << "|*       *|" << endl << " ---------" << endl;
    cout << " _________" << endl << "|*        |" << endl << "|***      |" << endl << "|****     |  2" << endl << "|***      |" << endl << "|*        |" << endl << " ---------" << endl;
    cout << " _________" << endl << "|        *|" << endl << "|      ***|" << endl << "|     ****|  3" << endl << "|      ***|" << endl << "|        *|" << endl << " ---------" << endl;
    cout << " _________" << endl << "|*********|" << endl << "|******** |" << endl << "|*******  |  4" << endl << "|***      |" << endl << "|*        |" << endl << " ---------" << endl;
    cout << " _________" << endl << "|        *|" << endl << "|      ***|" << endl << "|     ****|  5" << endl << "|    *****|" << endl << "|*********|" << endl << " ---------" << endl;
    cout << "Enter the number of the matrix type ";
    cin >> number;
    switch (number) {
        case 1:
                minimum = A[0][0];
                for (j = 0; j <=N / 2; j++) {
                    for (i = j; i <= N - j - 1; i++) {
                        if (A[i][j] < minimum) {
                            minimum = A[i][j];
                        }
                    }
                }
                for (j = N - 1; j >= N / 2; j--) {
                    for (i = j; i >= N - j -1; i--) {
                        if (A[i][j] < minimum) {
                            minimum = A[i][j];
                        }
                    }
                }
                cout << "minimum=" << minimum;
                break;
        case 2:
                minimum = A[0][0];
                for (j = 0; j <=N / 2; j++) {
                    for (i = j; i <= N - j - 1; i++) {
                        if (A[i][j] < minimum) {
                            minimum = A[i][j];
                        }
                    }
                }
                cout << "minimum=" << minimum;
                break;
        case 3:
                minimum = A[4][4];
                for (j = N - 1; j >= N / 2; j--) {
                    for (i = j; i >= N - j -1; i--) {
                        if (A[i][j] < minimum) {
                            minimum = A[i][j];
                        }
                    }
                }
                cout << "minimum=" << minimum;
                break;
        case 4:
                minimum = A[0][0];
                for (i = 0; i < N; i++) {
                    for (j = 0; j < N - i; j++) {
                        if (A[i][j] < minimum) {
                            minimum = A[i][j];
                        }
                    }
                }
                cout << "minimum=" << minimum;
                break;
        case 5:
                minimum = A[4][4];
                for (i = N - 1; i >= 0; i--) {
                    for (j = N - 1; j >= N - i - 1; j--) {
                        if (A[i][j] < minimum) {
                            minimum = A[i][j];
                        }
                    }
                }
                cout << "minimum=" << minimum;
                break;
        default:
                cout << "There is no such type of matrix";
                break;
    }
}
