/* Дана динамическая целочисленная матрица. Построить динамический одномерный
массив, каждый элемент которого равен сумме четных элементов одной строки исходной
матрицы.
  Освободить  память  от  матрицы.  Найти  максимальный  элемент  одномерного
массива и записать его как динамическую переменную.
  Все исходные данные, результаты и соответствующие адреса распечатать. */

#include <iostream>

using namespace std;

typedef int *pInt; //Указатель на переменную типа int

int main() {
    pInt *A;
    int *B;
    int i, j, N, M, sum, *pmax;


    //Размеры матрицы
    cout << "Enter size of matrix" << endl;
    cout  << "Enter number of rows: ";
    cin >> N;
    cout << "Enter number of columns: ";
    cin >> M;

    //Объявляем и заполняем матрицу
    A = new pInt[N];
    A[0] = new int[N*M];
    for ( i = 1; i < N; i++) {
        A[i] = A[i - 1] + M;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cout << "Enter A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    //Выводим полученную матрицу
    cout << endl << "Your matrix" << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cout.width(3);
            cout << A[i][j];
        }
        cout << endl;
    }

    //Зполняем одномерный массив
    B = new int[N];
    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < M; j++) {
            if (A[i][j] % 2 == 0) {
                sum += A[i][j];
            }
        }
        B[i] = sum;
    }

    //Выводим полученный массив
    cout << endl << "Your array" << endl;
    for (i = 0; i < N; i++) {
        cout << B[i] << " ";
    }

    //Освобождаем память матрицы
    for (i = 0; i < N; i++) {
        delete [] A[i];
    }
    delete [] A;

    //Ищем максимум
    int max = B[0];
    pmax = &max;
    for (i = 1; i < N; i++) {
        if (B[i] > max) {
            max = B[i];
        }
    }
    delete [] B; //освобождаем память массива
    cout << endl << "max = " << *pmax;
}
