/* N1.
Дан  текст.  Определить  в  нем  наиболее  часто  встречающийся  символ;  затем
определить все слова, в которых доля этого символа максимальна.
Пример.  Текст: "Veni, scripsi, vixi" ("Пришел,  написал,  прожил").  Наиболее
часто  встречающийся  символ - "i". Слова,  в  которых  доля  этого  символа  максимальна:
"vixi" (0.5). */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {

    vector<string> max_word;
    string text;
    int max_id = 0, temp_count, symbols[256]; //массив symbols для хранения количества вхождений символа в текст. Всего 256 символов
    float max_part =0, temp_part;
    char* token;//для опередления самого длинного слова для функции strtok_s
    char* next_token = NULL;
    char split[] = " " "," "-" "!" "?" "." """" "("")";

    cout << "Enter text: ";
    getline (cin, text);

    //Ищем наиболее часто встречающийся символ
    //Сначала заполняем массив с количеством символов нулями
    for (int i = 0; i < 256; i++) {
        symbols[i] = 0;
    }
    // Подсчет символов в тексте
    for (unsigned char c : text){
        symbols[c]++;
    }
    // Определение индекса наиболее часто встречающегося символа.
    for (int i = 1; i < 256; i++) {
        if (symbols[i] > symbols[max_id]) {
            max_id = i;
        }
    }

    //Вывод max
    cout << "Letter that occurs the maximum number of times: " << static_cast<char>(max_id) << " - " << symbols[max_id] << " times" << endl;

    //Ищем слова с максимальным вхождением.
    token = strtok_s(&text[0], split, &next_token); //берем очередное слово
    while (token != NULL) {
        temp_count = 0;
        int len = strlen(token);
        for (int j = 0; j < len; j++) {
            if (token[j] == static_cast<char>(max_id)) {
                temp_count++;
            }
        temp_part = float(temp_count) / len * 100; //вычисляем долю в слове
        }
        if (temp_part == max_part) { //Если уже есть такая доля то добавляем в массив
            max_word.push_back(token);
        }
        if (temp_part > max_part) { //Если новая максимальная доля, то сначала очищаем массив, потом добавляем новое слово
            max_part = temp_part;
            max_word.clear();
            max_word.push_back(token);
        }
        token = strtok_s(NULL, split, &next_token); //переход к следующему слову
    }

    //Вывод максимальной доли и всех слов с максимальной долей
    cout << "Maximum percentage of words: " << max_part << "%" << endl;
    cout << "Words of maximum percentage: ";
    for (int i = 0; i < max_word.size(); i++) {
        cout << max_word[i] << ", ";
    }
}
