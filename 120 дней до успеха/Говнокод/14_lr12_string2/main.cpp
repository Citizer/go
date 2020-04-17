/*Дан текст. Найти в нем самое короткое и самое длинное слово.*/

#include <iostream>
#include <cstring>

using namespace std;

int main() {

    string text, min_word, max_word;
    char* token;//для опередления самого длинного слова для функции strtok_s
    char* next_token = NULL;
    char split[] = " " "," "-" "!" "?" "." """" "("")";
    int lengthOfWord, minLengthOfWord, maxLengthOfWord;

    cout << "Program for finding the longest and shortest word." << endl;
    cout << "Enter text: ";
    getline(cin, text);
    minLengthOfWord = text.size();
    maxLengthOfWord = 0;

    token = strtok_s(&text[0], split, &next_token);
    lengthOfWord = strlen(token);
    while (token != NULL) {
        lengthOfWord = strlen(token); //находим длину первого слова
        if (lengthOfWord < minLengthOfWord) {
            minLengthOfWord = lengthOfWord;
            min_word = token;
        }
        if (lengthOfWord > maxLengthOfWord) {
            maxLengthOfWord = lengthOfWord;
            max_word = token;
        }
        token = strtok_s(NULL, split, &next_token); //переход к следующему слову
    }

    cout << "Shortest word: " << min_word << endl;
    cout << "Longest word: " << max_word << endl;
}
