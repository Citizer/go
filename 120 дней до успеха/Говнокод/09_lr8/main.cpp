/* Имеется  таблица  сведений  об  автомобилях.  Каждая  строка  содержит  следующие
сведения:  номер,  фамилия  владельца,  марка,  технические  характеристики (не  более 4),
каждая характеристика - целое положительное число.
Упорядочить  таблицу  по  номерам  автомобилей  и  найти  количество  автомобилей
каждой марки. */

#include <iostream>
#include <fstream>
#include <map>
#include <conio.h>

using namespace std;

int main() {
    typedef struct {
        string number; //номер автомобиля
        string family; //фамилия
        string model; // марка
        int year; //год выпуска
        int power; //мощность
    } TAuto;
    const int N = 100; //размер массива с запасом
    int countrecord = 0, t; //число записей в файле
    map <string, int> book; //ассоциативный массив "модель: количество моделей"
    TAuto Auto[N]; // массив структур, возможно его лучше вставить после чтения из файла и не делать ему размер 100
    TAuto B; //вспомогательная переменная для сортировки
    int mas[N]; //вспомогательный массив для сортировки

    //Читаем файл
    ifstream ifs("input.txt");
    if (!ifs.is_open()) {
        cout << "Error. File not open";
        exit(1);
    } else {
        while (!ifs.eof()) {            
            ifs >> Auto[countrecord].number;
            ifs >> Auto[countrecord].family;
            ifs >> Auto[countrecord].model;
            ifs >> Auto[countrecord].year;
            ifs >> Auto[countrecord].power;
            countrecord++;
        }
    }    

    //Вывод структуры
    cout << "The available data about automobiles" << endl;
    for (int i = 0; i < countrecord; i++) {
        cout << Auto[i].number << "  ";
        cout << Auto[i].family << "  ";
        cout << Auto[i].model << "  ";
        cout << Auto[i].year << "  ";
        cout << Auto[i].power << endl;
    }
    cout << endl;

   //заполняем массив по порядку
    for (int i = 0; i < N; i++) {
        mas[i] = i;
    }

   //Сортировка и вывод структуры
    for (int i = 0; i < countrecord - 1; i++) {
        for (int j = countrecord - 2; j >= i; j--) {
            if (Auto[mas[j]].number > Auto[mas[j + 1]].number) {
                t = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = t;
                //B.number = Auto[j].number;
                //Auto[j].number = Auto[j + 1].number;
                //Auto[j + 1].number = B.number;
            }
        }
    }
    cout << "Entries are sorted by number. Look output.txt" << endl;
    cout << "Display entries on the screen? Press 'Enter' if 'YES' or any key if 'NO' " << endl;
    if (getch() == 13) {
        cout << "The available data about automobiles" << endl;
        for (int i = 0; i < countrecord; i++) {
            cout << Auto[mas[i]].number << "  ";
            cout << Auto[mas[i]].family << "  ";
            cout << Auto[mas[i]].model << "  ";
            cout << Auto[mas[i]].year << "  ";
            cout << Auto[mas[i]].power << endl;
        }
        cout << endl;
    }

    //Количество автомобилей каждой марки
    for (int i = 0; i < countrecord; i++) {
        int p;
        p = book.count(Auto[i].model);
        if (p == 1) {
            book[Auto[i].model]++;
        } else {
            book.insert ( pair<string,int> (Auto[i].model, 1) );
        }
    }
    map <string, int>::iterator it;
    for (it = book.begin(); it != book.end(); it++) {
        cout << it -> first << ": " << it -> second << endl;
    }

    //вывод в файл
    ofstream ofs;
    ofs.open("output.txt");
    for (int i = 0; i < countrecord; i++) {
        ofs << Auto[i].number << " " << Auto[i].family << " " << Auto[i].model << " " << Auto[i].year << " " << Auto[i].power << endl;
    }
}
