/*Дан текст. Найти в нем самое короткое и самое длинное слово.*/

#include <iostream>

using namespace std;

int main() {

    string text, min_word, max_word, temp_word;
    int lengthOfWord, minLengthOfWord, maxLengthOfWord, space;

    cout << "Program for finding the longest and shortest word." << endl;
    cout << "Enter text: ";
    getline(cin, text);
    minLengthOfWord = text.size();
    maxLengthOfWord = 0;

    text = text + ' '; // добавляем в конец пробел для удобства
    for (int i = 0; i < text.size(); i++) {
        space = text.find(' '); //находим пробел
        temp_word = text.substr(0, space); // копируем до пробела
        lengthOfWord = temp_word.size();
        if (lengthOfWord < minLengthOfWord) {
            minLengthOfWord = lengthOfWord;
            min_word = temp_word;
        }
        if (lengthOfWord > maxLengthOfWord) {
            maxLengthOfWord = lengthOfWord;
            max_word = temp_word;
        }
        text.erase(0, space + 1); // удаляем все до пробела и пробел
    }

    cout << "Shortest word: " << min_word << endl;
    cout << "Longest word: " << max_word << endl;
}
