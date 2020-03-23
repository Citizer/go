/* N1.
Дан  текст.  Определить  в  нем  наиболее  часто  встречающийся  символ;  затем
определить все слова, в которых доля этого символа максимальна.
Пример.  Текст: "Veni, scripsi, vixi" ("Пришел,  написал,  прожил").  Наиболее
часто  встречающийся  символ - "i". Слова,  в  которых  доля  этого  символа  максимальна:
"vixi" (0.5). */

#include <iostream>

using namespace std;

int main() {

    string text, s, s2;
    char s1;
    int max_id = 0, max_count = 0, temp_count, space;
    float max_part =0, temp_part;

    cout << "Enter text: ";
    getline (cin, text);
    s = text;

    //Ищем наиболее часто встречающийся символ
    for (int i = 0; i < text.size(); i++) {
        s1 = text[i];
        temp_count = 0;
        if ((s1 != ' ') && (s1 !=',') && (s1 != '.')) { // проверяем что очередной символ не пробел, запятая или точка
            for (int j = i; j < text.size(); j++) {
                if (s1 == s[j]) {
                    temp_count++;
                }
            }
            if (temp_count > max_count) {
                max_count = temp_count;
                max_id = i;
            }
        }
    }

    //Вывод max
    cout << "Letter that occurs the maximum number of times: " << text[max_id] << " - " << max_count << " times" << endl;

    //Ищем слова с максимальным вхождением. Сначала найдем максимальную долю
    s = s + ' '; // добавляем в конец пробел для удобства
    for (int i = 0; i < s.size(); i++) {
        space = s.find(' '); //находим пробел
        s2 = s.substr(0, space); // копируем до пробела
        temp_count = 0;
        int len = s2.size();
        for (int j = 0; j < len; j++) {
            if (s2[j] == text[max_id]) {
                temp_count++;
            }
            temp_part = float(temp_count) / len * 100; //вычисляем долю в слове
        }
        if (temp_part > max_part) {
            max_part = temp_part;
        }
        s.erase(0,space + 1); // удаляем все до пробела и пробел
    }
    cout << "Maximum percentage of words: " << max_part << "%" << endl;

    //Теперь ищем слова с максимальной долей
    s = text + ' '; // добавляем в конец пробел для удобства
    cout << "Words of maximum percentage: ";
    for (int i = 0; i < s.size(); i++) {
        space = s.find(' '); //находим пробел
        s2 = s.substr(0, space); // копируем до пробела
        temp_count = 0;
        int len = s2.size();
        for (int j = 0; j < len; j++) {
            if (s2[j] == text[max_id]) {
                temp_count++;
            }
        }
        temp_part = float(temp_count) / len * 100; //вычисляем долю в слове
        if (temp_part == max_part) {
            cout << s2 << " ";
        }
        s.erase(0,space + 1); // удаляем все до пробела и пробел
    }
}
