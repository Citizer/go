/*Дан файл  F (создать его), компоненты которого являются целыми числами.
Записать в файл G все четные числа  файла  F , а в файл H  -  все  нечетные числа
файла F. Порядок следования чисел сохраняется.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int number;
    ifstream F("F.txt");
    ofstream G, H;
    G.open("G.txt");
    H.open("H.txt");
    if (F.is_open()) {
        while (!F.eof()) {
            F >> number;
            if (number % 2 == 0) {
                G << number << " ";
            } else {
                H << number << " ";
            }
        }
        F.close();
        G.close();
        H.close();
        cout << "Data was saved successfully";
    } else {
        cout << "Error. File not open";
    }
}
