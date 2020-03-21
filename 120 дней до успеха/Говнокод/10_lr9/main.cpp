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
        int year;
        union {
            char city[50];            
            char jtitle[50];            
        } property1;
        union {
            char publish[50];            
        } property2;
        union {            
            int number;
        } property3;
    } TBook;

    int countrecord, t, i = 0;

    //Читаем файл
    //сначала узнаем количество записей
    ifstream ifs("input.txt");
    if (!ifs.is_open()) {
        cout << "Error. File not open";
        exit(1);
    } else {
        ifs >> countrecord;
        TBook Book[countrecord];
        while (!ifs.eof()) {
            ifs >> Book[i].author;
            ifs >> Book[i].title;
            ifs >> Book[i].type;
            ifs >> Book[i].year;
            if (Book[i].type == "book") {
                ifs >> Book[i].property1.city;
                ifs >> Book[i].property2.publish;
            } else {
                ifs >> Book[i].property1.jtitle;
                ifs >> Book[i].property3.number;
            }
            i++;
        }


        //Вывод структтуры
        cout << "The available data about books:" << endl;
        for (i = 0; i < countrecord; i++) {
            cout << Book[i].author << "  ";
            cout << Book[i].title << "  ";
            cout << Book[i].type << "  ";
            cout << Book[i].year << " ";
            if (Book[i].type == "book") {
                cout << Book[i].property1.city << " ";
                cout << Book[i].property2.publish << " ";
            } else {
                cout << Book[i].property1.jtitle << " ";                
                cout << Book[i].property3.number << " ";
            }
            cout << endl;
        }
        cout << endl;

        //заполняем массив для сортировки по порядку
        int mas[countrecord];
        for (i = 0; i < countrecord; i++) {
            mas[i] = i;
        }

        //Сортировка структуры с помощью вспомогательного массива, структуры не перемещаются
        for (i = 0; i < countrecord - 1; i++) {
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
        for (i = 0; i < countrecord; i++) {
            if (Book[mas[i]].type == "journal") {
                cout << Book[mas[i]].author << "  ";
                cout << Book[mas[i]].title << "  ";
                cout << Book[mas[i]].type << "  ";
                cout << Book[mas[i]].year << " ";
                cout << Book[mas[i]].property1.jtitle << " ";
                cout << Book[mas[i]].property3.number << " ";
                cout << endl;
            }
        }
    }
}
