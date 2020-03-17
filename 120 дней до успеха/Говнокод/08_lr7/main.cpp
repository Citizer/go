/* Дана  целая  квадратная  матрица  порядка n. Найти  наименьшее  из  значений
элементов, расположенных в заштрихованной части матрицы, N10 */
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
    const int N = 5;
    const int Rand_Max = 1000; //максимальное значение случайного числа - 1
    int A[N][N];
    int number, i, j, minimum, key, flag;
    char str_zw[] = "**********************************";
    char str_space[] = "                                    ";
    srand(time(NULL));
    minimum = Rand_Max;
    key = 1; //для случая default
    flag = 0; // для проверки четности размера матрицы
    cout << "Program for finding the smallest value elements located in the shaded part of the matrix" << endl;
    for (i = 1; i <= N / 2; i++) {//Идем по строкам
        printf("\n%*.*s", i, i, str_zw);
        printf("%*.*s", N - (i * 2), N - (i*2), str_space);
        printf("%*.*s", i, i, str_zw);
        printf("%4.4s", str_space);
        //Первая верхняя половина первой матрицы


        printf("%*.*s", i, i, str_zw);
        printf("%*.*s", N - i, N - i, str_space);
        printf("%4.4s", str_space);
        //Верхняя половина второй матрицы

        printf("%*.*s", N - i, N - i, str_space);
        printf("%*.*s", i, i, str_zw);
        printf("%4.4s", str_space);
        //Верхняя половина третьей матрицы

        printf("%*.*s", N - i + 1, N - i + 1, str_zw);
        printf("%*.*s", i - 1, i - 1, str_space);
        printf("%4.4s", str_space);
        //Верхняя половина четвертой матрицы

        printf("%*.*s", N - i + 1, N - i + 1, str_space);
        printf("%*.*s", i, i, str_zw);
        //Верхняя половина последней матрицы
    }
    if (N % 2 == 1) { // Строчка посередине

        flag = 1;

        printf("\n%*.*s", N, N, str_zw);
        printf("%4.4s", str_space);
        //Первая матрица

        printf("%*.*s", N / 2 + 1, N / 2 + 1, str_zw);
        printf("%*.*s", N / 2, N / 2, str_space);
        printf("%4.4s", str_space);
        //Вторая матрица

        printf("%*.*s", N / 2, N / 2, str_space);
        printf("%*.*s", N / 2 + 1, N / 2 + 1, str_zw);
        printf("%4.4s", str_space);
        //Третья матрица

        printf("%*.*s", N / 2 + 1, N / 2 + 1, str_zw);
        printf("%*.*s", N / 2, N / 2, str_space);
        printf("%4.4s", str_space);
        //Четвертая матрица

        printf("%*.*s", N / 2 + 1, N / 2 + 1, str_space);
        printf("%*.*s", N / 2 + 1, N / 2 + 1, str_zw);
        //Пятая матрица
    }
    for (i = N / 2 + flag; i < N; i++) {
        printf("\n%*.*s", N - i, N - i, str_zw);
        printf("%*.*s", i * 2 - N, i * 2 - N, str_space);
        printf("%*.*s", N - i, N - i, str_zw);
        printf("%4.4s", str_space);
        //Нижняя половина первой матрицы

        printf("%*.*s", N - i, N - i, str_zw);
        printf("%*.*s", i, i, str_space);
        printf("%4.4s", str_space);
        //Нижняя половина второй матрицы

        printf("%*.*s", i, i, str_space);
        printf("%*.*s", N - i, N - i, str_zw);
        printf("%4.4s", str_space);
        //Нижняя половина третьей матрицы

        printf("%*.*s", N - i, N - i, str_zw);
        printf("%*.*s", i, i, str_space);
        printf("%4.4s", str_space);
        //Нижняя половина четвертой матрицы

        printf("%*.*s", N - i, N - i, str_space);
        printf("%*.*s", i + 1, i + 1, str_zw);
        //Нижняя половина пятой матрицы
    }
    cout << endl << endl;

    printf("%*.*s", N / 2 + 1, N / 2 + 1, "1");
    printf("%*.*s", N + 2, N + 2, "2");
    printf("%*.*s", 3 * N / 2 + 4, 3 * N / 2 + 4, "3");
    printf("%*.*s", 2 * N, 2 * N, "4");
    printf("%*.*s", N * 2, N * 2, "5");
    //Вывод цифр под матрицами

    cout << endl << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = rand() % Rand_Max;
            cout << setw(5) << A[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << "Enter the number of the matrix type ";
    cin >> number;
    switch (number) {
        case 1:                
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
                break;
        case 2:                
                for (j = 0; j <=N / 2; j++) {
                    for (i = j; i <= N - j - 1; i++) {
                        if (A[i][j] < minimum) {
                            minimum = A[i][j];
                        }
                    }
                }                
                break;
        case 3:                
                for (j = N - 1; j >= N / 2; j--) {
                    for (i = j; i >= N - j -1; i--) {
                        if (A[i][j] < minimum) {
                            minimum = A[i][j];
                        }
                    }
                }                
                break;
        case 4:                
                for (i = 0; i < N; i++) {
                    for (j = 0; j < N - i; j++) {
                        if (A[i][j] < minimum) {
                            minimum = A[i][j];
                        }
                    }
                }                
                break;
        case 5:                
                for (i = N - 1; i >= 0; i--) {
                    for (j = N - 1; j >= N - i - 1; j--) {
                        if (A[i][j] < minimum) {
                            minimum = A[i][j];
                        }
                    }
                }                
                break;
        default:
                cout << "There is no such type of matrix";
                key = -1;
                break;
    }
    if (key == 1) { // Проверка, если выбран default, то не надо выводить minimum
        cout << "minimum=" << minimum;
    }
}
