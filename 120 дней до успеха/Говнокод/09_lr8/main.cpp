/* Имеется  таблица  сведений  об  автомобилях.  Каждая  строка  содержит  следующие
сведения:  номер,  фамилия  владельца,  марка,  технические  характеристики (не  более 4),
каждая характеристика - целое положительное число.
Упорядочить  таблицу  по  номерам  автомобилей  и  найти  количество  автомобилей
каждой марки. */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    typedef struct {
        string number; //номер автомобиля
        string family; //фамилия
        string model; // марка
        int year; //год выпуска
        int power; //мощность
    } TAuto;
    const int N = 2;
    int countrecord;
    TAuto Auto[N];
    TAuto B; //вспомогательная переменная для сортировки
    ifstream Fin;
    ofstream Fout;
    FILE *F;
    string s;

    //читаем файл

    Fin.open("input_car.dat", ios::binary);
    Fin.read((char*) Auto, sizeof(TAuto) * N);
    countrecord = Fin.gcount() / sizeof(TAuto);
    Fin.close();
    //F = fopen("input_car.dat", "rb");
    //countrecord = fread(&Auto[0], sizeof(TAuto), N, F);
    //fclose(F);

    //Вывод структуры
    cout << "The available data about automobiles" << endl;
    for (int i = 0; i < N; i++) {
        cout << Auto[i].number << "  ";
        cout << Auto[i].family << "  ";
        cout << Auto[i].model << "  ";
        cout << Auto[i].year << "  ";
        cout << Auto[i].power << endl;
    }
/*
    //Ввод структуры с клавиатуры
    cout << "Enter your automobile information" << endl << "Enter the car number, last name, model, year of manufacture and power" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Enter information about " << i + 1 << " automobile" << endl;
        cin >> Auto[i].number;
        cin >> Auto[i].family;
        cin >> Auto[i].model;
        cin >> Auto[i].year;
        cin >> Auto[i].power;
    }*/

   /* //Сортировка структуры
    for (int i = 0; i < N - 1; i++) {
        for (int j = N - 2; j >= i; j--) {
            if (Auto[j].number > Auto[j + 1].number) {
                B.number = Auto[j].number;
                Auto[j].number = Auto[j + 1].number;
                Auto[j + 1].number = B.number;
            }
        }
    }*/

    //вывод в файл

    //F = fopen("output_car.dat", "wb");
    //fwrite(&Auto[0], sizeof (TAuto), N, F);
    //fclose(F);
    Fout.open("output_car.dat", ios::binary);
    Fout.write((char*) Auto, sizeof(TAuto)*N);
    Fout.close();


}
