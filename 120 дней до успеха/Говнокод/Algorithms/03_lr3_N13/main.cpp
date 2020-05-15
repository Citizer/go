/*задание*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {

    struct node {
        string name; //Значение
        string status;
        node *next; //Указатель на следующий узел
        };

    node * head = 0; //Хранит адрес головного узла
    node * curr = head; //Хранит адрес текущего узла
    node * temp; //Вспомогательные переменные
    string temp_name, temp_status;

    //Читаем файл
    ifstream ifs("input.txt");
    if (!ifs.is_open()) {
        cout << "Error. File not open";
        exit(1);
    } else {
        while (!ifs.eof()) {
            ifs >> temp_name;
            ifs >> temp_status;
            if (!head) {  //Если головного узла нет
                head = new node; //Создание головного узла
                head->name = temp_name; //Значения
                head->status = temp_status;
                head->next = NULL;
                curr = head; //Текущий узел
            } else { //Если головной элемент есть
                curr->next = new node; //Создание узла
                curr = curr->next; //Переход на этот узел
                curr->name = temp_name; //Значения
                curr->status = temp_status;
                curr->next = NULL;
            }
        }
    }

        //Печать списка
        curr = head;
        while (curr != NULL) {
            cout << curr->name << " " << curr->status << endl;
            curr = curr->next;            // переход к следующему узлу
        }

        //Удаление из списка отчисленных студентов, статус neuch
        curr = head;
        while (curr != NULL) {
            if(curr->status == "neuch") {
                if (curr == head) { // если удаляем первый элемент
                    head = head->next;
                    delete (curr);
                    curr = head;
                } else { //удаляем непервый элемент
                    temp = head;
                    while (temp->next !=curr) {
                        temp = temp->next;
                    }
                    temp->next = curr->next;
                    delete (curr);
                    curr = temp;
                }
            } else {
                curr = curr->next; // если ничего не удаляем, то переходим к следующему элементу
            }
        }
        cout << endl << endl;

        //Печать списка
        curr = head;
        while (curr != NULL) {
            cout << curr->name << " " << curr->status << endl;
            curr = curr->next;            // переход к следующему узлу
        }

        //Вывод списка в файл
        ofstream ofs;
        ofs.open("output.txt");
        curr = head;
        while (curr != NULL) {
            ofs << curr->name << " " << curr->status << endl;
            curr = curr->next;
        }
        ofs.close();
}
