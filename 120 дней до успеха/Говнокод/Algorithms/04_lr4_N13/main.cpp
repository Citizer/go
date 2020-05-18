/* Переставить местами элементы, обрамляющие i-тый элемент списка.*/

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main() {

    list<int> myList;
    list<int> copymyList;
    list<int>::iterator i;

    int tempvalue, countOfList = 0, choiceOfNumber, prev, next, j, valueprev, valuenext;

    //Читаем файл
    ifstream ifs("input.txt");
    if (!ifs.is_open()) {
        cout << "Error. File not open";
        exit(1);
    } else {
        while (!ifs.eof()) {
            ifs >> tempvalue;
            myList.push_back(tempvalue);
            copymyList.push_back(tempvalue);
            countOfList++;
        }

        //Вывод списка
        for(i = myList.begin(); i != myList.end(); i++) {
            cout << (*i) << " ";
        }
        cout << endl << endl;

        //Меняем местами элементы
        cout << "Select which list number to swap values for: " << endl;
        cin >> choiceOfNumber;
        if (choiceOfNumber == 1) {
            cout << "Nothing to change around the first element";
        } else if (choiceOfNumber == countOfList) {
            cout << "Nothing to change around the last element";
        } else if ((choiceOfNumber < 1) || (choiceOfNumber > countOfList)) {
            cout << "There is no such list number";
        } else {
            prev = choiceOfNumber--;//запомнили позиции
            next = choiceOfNumber++;


            cout << endl << endl;

            //Находим значение prev и next
            for (j = 1; j < prev; j++) {
                valueprev = copymyList.front();
                copymyList.pop_front();
            }
            copymyList.pop_front();
            valuenext = copymyList.front();

            cout << "Swapping " << valueprev << " and " << valuenext << endl;

            i = myList.begin();
            for (j = 1; j < prev - 1; j++) {
                i++;
            }

            //Меняем местами значения
            myList.insert(i, valuenext);
            myList.erase(i);
            i++;
            i++;
            myList.insert(i, valueprev);
            myList.erase(i);

            ofstream ofs;
            ofs.open("output.txt");
            for(i = myList.begin(); i != myList.end(); i++) {
                cout << (*i) << " ";
                ofs << (*i) << " ";
            }
            ofs.close();
            cout << endl << "Data is recorded";
        }
    }
}
