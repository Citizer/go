/*№ 17   Игра “двадцать одно” (человек - человек).
Два  игрока  по  очереди  называют  цифры  от 1 до 9. Программа  суммирует  эти
цифры.
Проигрывает тот, кто первым дойдет до числа 21 или более.
Например:
Номер хода  Игрок 1  Игрок 2  Сумма
1               9                9
2                       9       18
3               2               20
4                   Проиграл

№*/

#include <iostream>
#include <iomanip>

using namespace std;

double getNumber() //Функция проверки является ли ввод числом
{
    double number;
    char c;
    while (1) {
        if (!scanf("%lf", &number) || getchar() != '\n') {
            while ((c = getchar()) != '\n' && c != EOF);
        } else if ((number >0) && (number < 10)) {
            return number;
        }
        printf("You must enter a number.\nRepeat the entry: ");
    }
}


int main() {

    int totalpoints = 0, temppoints; //начальная сумма очков
    int step = 1;
    string playername[2]; // хранение имен игроков
    int lengthOfName[2]; //для хранения длины имен игроков
    bool laststep[2];


    cout << "Two players take turns calling numbers from 1 to 9." << endl << "Program summarizes these numbers numbers." << endl << "The first player to reach the number 21 or more loses" << endl << endl;
    cout << "What is name first player? ";
    getline(cin, playername[0]);
    cout << "What is name second player? ";
    getline(cin, playername[1]);
    lengthOfName[0] = playername[0].size();
    lengthOfName[1] = playername[1].size();

    while (totalpoints < 21) {
        cout << playername[(step - 1) % 2] << " Enter a number ";
        temppoints = getNumber();
        totalpoints += temppoints;

        if ((step - 1) % 2 == 0) {
            cout << "N step | " << playername[0] << " | " << playername[1] << " | Total" << endl;
            cout << setw(5) << step << "  |";
            cout << setw(lengthOfName[0] / 2 + 2) << temppoints << setw(lengthOfName[0] / 2 + lengthOfName[0] % 2 + 1) << "  |";
            cout << setw(lengthOfName[1] + 3) << "|";
            cout << "   " << totalpoints << endl;
            laststep[0] = true; // походил 1-й игрок
            laststep[1] = false;
        } else {
            cout << "N step | " << playername[0] << " | " << playername[1] << " | Total" << endl;
            cout << setw(5) << step << "  |";
            cout << setw(lengthOfName[0] + 3) << "|";
            cout << setw(lengthOfName[1] / 2 + 2) << temppoints << setw(lengthOfName[1] / 2 + lengthOfName[1] % 2 + 1) << "  |";
            cout << "   " << totalpoints << endl;
            laststep[1] = true; // походил 2-й игрок
            laststep[0] = false;
        }
        step++;
    }
    if (laststep[0]) {
        cout << "Win " << playername[1] << "!";
    } else {
        cout << "Win " << playername[0] << "!";
    }



}
