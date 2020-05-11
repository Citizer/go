/* Все ненулевые элементы матрицы D(k,l) расположить в начале массива E( k,l ) и
подсчитать их количество. */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef int *pInt;

int main() {
    int countOfRows, countOfColumns, countNoZero = 0;
    vector<int> E;
    ofstream ofs;

    //Читаем файл
    ifstream ifs("input.txt");
    if (!ifs.is_open()) {
        cout << "Error. File not open";
        exit(1);
    } else {
        ifs >> countOfRows; //считываем количество строк
        ifs >> countOfColumns; // считываем количество столбцов

        //Cоздаем матрицу
        int **D = new int *[countOfRows];
        for (int i = 0; i < countOfRows; i++ ) {
            D[i] = new int[countOfColumns];
        }

        //Считываем данные в матрицу и располагаем ненулевые элементы в массив
        for (int i = 0; i < countOfRows; i++) {
            for (int j = 0; j < countOfColumns; j++) {
                ifs >> D[i][j];
                if (D[i][j] != 0) {
                    E.push_back(D[i][j]);
                    countNoZero++;
                }
            }
        }

        //Записываем массив в файл output
        ofs.open("output.txt");
        ofs << "Count of non-zero elements: " << countNoZero << endl;
        for (int i = 0; i < countNoZero; i++) {
            ofs << E[i] << " ";
        }
        ofs.close();
        cout << "Data was saved successfully";
    }
}
