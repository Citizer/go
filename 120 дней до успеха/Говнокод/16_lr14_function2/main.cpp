/*  Оформить в виде отдельных функций:
     1) ввод двухмерной целочисленной матрицы;
     2) вывод двухмерной целочисленной матрицы;
     3) обработка матрицы по индивидуальному заданию, которое следует выбрать из
списка заданий в п. 6.9.2.2; в каждом задании есть какое-то преобразование матрицы и
получение при этом не менее двух выходных значения.
     Написать основную программу main для проверки работы этих функций.
     Замечание 1. Все данные передавать в функции и обратно как параметры, а не как
глобальные данные.
     Замечание 2. Все результаты (простые переменные, массивы), полученные в ходе
обработки матрицы, возвращать в основную программу и только там распечатывать (то
есть обязательно должна быть организована передача выходных параметров).
     Замечание 3. Минимальный шаблон основной программы для всех заданий:
       1) вызов функции 1 для ввода матрицы;
       2) вызов функции 2 для вывода введенной матрицы;
       3) вызов функции 3 для обработки матрицы;
       4) вызов функции 2 для вывода обработанной матрицы;
       5) печать результатов обработки матрицы, полученных после  выполнения п.3).
При выполнении конкретного задания может потребоваться определение еще и других
функций в дополнении к данному "минимальному" набору.
№ 3.
Дана целочисленная квадратная матрица.
Найти  количество  положительных  элементов  выше  побочной  диагонали  и
количество отрицательных элементов ниже побочной диагонали.
Все отрицательные элементы выше побочной диагонали заменить на 0.
*/

#include <iostream>

using namespace std;

//Ввод матрицы с клавиатуры
void inputMatrix (int N, int M, int **array) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "Enter A[" << i << "][" << j << "]: ";
            cin >> array[i][j];
        }
    }
}

//Вывод матрицы
void printMatrix(int N, int M, int **array) {
    cout << endl << "Your matrix" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout.width(3);
            cout << array[i][j];
        }
        cout << endl;
    }
}

int main() {
    int countOfRows, countOfColumns, countOfPositive = 0, countOfNegative = 0;

    //Размеры матрицы
        cout << "Enter size of matrix" << endl;
        cout  << "Enter number of rows: ";
        cin >> countOfRows;
        cout << "Enter number of columns: ";
        cin >> countOfColumns;

    //Cоздаем матрицу
    int **matrix = new int *[countOfRows];
    for (int i = 0; i < countOfRows; i++ ) {
        matrix[i] = new int[countOfColumns];
     }

    //Вводим матрицу
    inputMatrix(countOfRows, countOfColumns, matrix);

    //Выводим мамрицу
    printMatrix(countOfRows, countOfColumns, matrix);

    /*Ищем количество  положительных  элементов  выше  побочной  диагонали.
     Так как матрица необязательно квадратная, то в зависимости от типа матрицы
     применяем разные алгоритмы*/
    if (countOfColumns < countOfRows) { //число столбцов меньше числа строк
        for (int i = 0; i < countOfRows - 2; i++) {
            for (int j = countOfRows - i - 2; j >= 0; j--) {
                if (matrix[j][i] > 0) {
                    countOfPositive++;
                }
            }
        }
    } else { //число столбцов больше числа строк или матрица квадратная
        for (int i = 0; i < countOfRows - 1; i++) {
            for (int j = 0; j < countOfRows - i - 1; j++) {
                if (matrix[i][j] > 0) {
                    countOfPositive++;
                }
            }
        }
    }
    cout << "Count of positive elements above the side diagonal: " << countOfPositive << endl;

    /*Ищем количество отрицательных элементов ниже побочной диагонали. Так как матрица необязательно квадратная, то в зависимости от типа матрицы
     применяем разные алгоритмы*/
    if (countOfRows > countOfColumns) {


    } else { //число столбцов больше числа строк или матрица квадратная
        for (int i = 0; i < countOfRows; i++) {
            for (int j = countOfColumns - 1; j > countOfColumns - countOfRows - i; j--) {
                if (matrix[i][j] < 0) {
                    countOfNegative++;
                }
            }
        }
    }
    cout << "Count of negative elements below the side diagonal: " << countOfNegative << endl;

}
