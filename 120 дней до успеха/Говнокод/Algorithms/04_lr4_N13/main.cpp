/* Переставить местами элементы, обрамляющие i-тый элемент списка.*/

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main() {

    list<int> myList;
    list<int>::iterator i;

    int tempvalue, countOfList = 0, choiceOfNumber, prev, next;

    //Читаем файл
    ifstream ifs("input.txt");
    if (!ifs.is_open()) {
        cout << "Error. File not open";
        exit(1);
    } else {
        while (!ifs.eof()) {
            ifs >> tempvalue;
            myList.push_back(tempvalue);
            countOfList++;
        }

        //Вывод списка
        for(i = myList.begin(); i != myList.end(); i++) {
            cout << (*i) << " ";
        }

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
            prev = choiceOfNumber--;
            next = choiceOfNumber++;

        }





    }





}
