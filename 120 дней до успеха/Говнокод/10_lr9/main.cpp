/* Имеется  список  произведений,  опубликованных  в  виде  отдельной  книги  или  в
журналах. Каждая строка списка содержит следующие сведения:
1) автор;
2) название произведения;
3) признак вида публикации (книга или журнал);
4) для книги - город, издательство, год издания;
    для журнала - название журнала, год издания и номер.
Составить отдельный список всех журнальных произведений. Список должен быть
упорядочен по фамилиям авторов. */

#include <iostream>
#include <fstream>

using namespace std;

int main() {

    //Описываем структуру
    typedef struct {
        string author;
        string title;        
        string type; // book или journal
        union {
            char city[50];            
            char jtitle[50];            
        } property1;
        union {
            char publish[50];
            int year;
        } property2;
        union {
            int year;
            int number;
        } property3;
    } TBook;
    const int N = 100;
    int countrecord = 0, t;
    TBook Book[N];
    int mas[N];

    //Читаем файл
    ifstream ifs("input.txt");
        if (!ifs.is_open()) {
            cout << "Error. File not open";
            exit(1);
        } else {
            while (!ifs.eof()) {
                ifs >> Book[countrecord].author;
                ifs >> Book[countrecord].title;                
                ifs >> Book[countrecord].type;
                if (Book[countrecord].type == "book") {
                    ifs >> Book[countrecord].property1.city;
                    ifs >> Book[countrecord].property2.publish;
                    ifs >> Book[countrecord].property3.year;
                } else {
                    ifs >> Book[countrecord].property1.jtitle;
                    ifs >> Book[countrecord].property2.year;
                    ifs >> Book[countrecord].property3.number;
                }
                countrecord++;
            }
        }

    //Вывод структтуры
    cout << "The available data about books:" << endl;
    for (int i = 0; i < countrecord; i++) {
        cout << Book[i].author << "  ";
        cout << Book[i].title << "  ";
        cout << Book[i].type << "  ";
        if (Book[i].type == "book") {
            cout << Book[i].property1.city << " ";
            cout << Book[i].property2.publish << " ";
            cout << Book[i].property3.year << "  ";
            } else {
                cout << Book[i].property1.jtitle << " ";
                cout << Book[i].property2.year << "  ";
                cout << Book[i].property3.number << " ";
            }
        cout << endl;
    }
    cout << endl;

    //заполняем массив по порядку
    for (int i = 0; i < N; i++) {
        mas[i] = i;
    }

    //Сортировка и вывод структуры
    for (int i = 0; i < countrecord - 1; i++) {
        for (int j = countrecord - 2; j >= i; j--) {
            if (Book[mas[j]].author > Book[mas[j + 1]].author) {
                t = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = t;
            }
        }
    }
    //Вывод структтуры
    cout << "The available data about journal:" << endl;
    for (int i = 0; i < countrecord; i++) {
        if (Book[mas[i]].type == "journal") {
            cout << Book[mas[i]].author << "  ";
            cout << Book[mas[i]].title << "  ";
            cout << Book[mas[i]].type << "  ";
            cout << Book[mas[i]].property1.jtitle << " ";
            cout << Book[mas[i]].property2.year << "  ";
            cout << Book[mas[i]].property3.number << " ";
            cout << endl;
        }
    }
}
