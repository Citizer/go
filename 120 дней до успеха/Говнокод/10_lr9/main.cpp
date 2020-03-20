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
        int year;
        int type; // book или journal
        union {
            string city;
            string publish;
            string jtitle;
            int number;
        } property;
    } TBook;
    const int N = 100;
    int countrecord = 0;
    TBook Book[N];

    //Читаем файл
    ifstream ifs("input.txt");
        if (!ifs.is_open()) {
            cout << "Error. File not open";
            exit(1);
        } else {
            while (!ifs.eof()) {
                ifs >> Book[countrecord].author;
                ifs >> Book[countrecord].title;
                ifs >> Book[countrecord].year;
                ifs >> Book[countrecord].type;
                if (Book[countrecord].type == 1) {
                    ifs >> Book[countrecord].property.city;
                    ifs >> Book[countrecord].property.publish;
                } else {
                    ifs >> Book[countrecord].property.jtitle;
                    ifs >> Book[countrecord].property.number;
                }
                countrecord++;
            }
        }

}
