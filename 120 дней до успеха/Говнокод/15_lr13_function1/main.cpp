/*6.9.1 Организация функций

     6.9.1.1 Задание 1

     1.  Написать  функцию 1, которая  для  любого  заданного  Х  вычисляет  с  заданной
точностью Е значение У как сумму членов бесконечного ряда. Вычисления провести по
формуле 1, которую следует выбрать из списка заданий в п.6.9.1.3.
     2.  Написать  функцию 2, которая  для  любого  заданного X вычисляет  с  заданной
точностью E значение Y как сумму членов бесконечного ряда. Вычисления провести по
формуле 2, которую следует выбрать из списка заданий в п.6.9.1.3.
     3. Написать функцию 3, которая распечатывает три  заданных величины: Х, У, Е.
     4. Написать основную программу main, которая
          а) в режиме диалога вводит исходные данные Х, Е и N - номер функции, по которой
следует вычислить Y;
          б)  в  зависимости  от  указанного  номера  формулы N вызывает  функцию 1 или
функцию 2;
          в) вызывает функцию 3 для печати результатов;
          г)  выполняет  действия,  описанные  в  пунктах  а),  б),  в),  столько  раз,  сколько
потребует пользователь.

     Замечание 1. Функции 1 и 2 должны возвращать результат через оператор return.
     Замечание 2. При  выполнении  большинства  заданий  рекомендуется  указывать
значение  Х  из  диапазона [0,1] или [-1,1], так как на этих интервалах сходятся функции
практически для всех заданий.
     Замечание 3. При  тестировании  рекомендуется  первоначально  указать  достаточно
"большое" Е (например, Е = 0,1), а затем, при получении решения за удовлетворительное
время, постепенно уменьшать точность Е .
*/

#include <iostream>
#include <conio.h>

using namespace std;

//Первая функция. Вариант №2
float f1(float x, float e) {
    float sum = 0, addend;
    float i = 1;
    addend = 1 / float(x);
    while (abs(addend) > e) {
        sum += addend;
        addend *= (i * i) / ((i + 1) * (i + 2) * x * x);
        i += 2;
    }
    return sum;
}

//Вторая функция. Вариант №3
float f2(float x, float e) {
    float sum = 0, addend;
    float i = 1;
    addend = x;
    while (abs(addend) > e) {
        sum += addend;
        addend *= (x * x * i * i) / ((i + 1) * (i + 2));
        i += 2;
    }
    return sum;
}

//Третья функция.
void printingf(float x, float e, float func(float x, float e)) {
    cout << "x=" << x << endl;
    cout << "e=" << e << endl;
    cout << func(x, e) << endl;
}


int main() {    
    float argument, precision;
    int number;
    do {
        cout << "Enter the argument (x), the specified precision (e), and the function number (n)" << endl;
        cout << "Enter the argument x=";
        cin >> argument;
        cout << "Enter the specified precision e=";
        cin >> precision;
        cout << "Enter the function number n=";
        cin >> number;
        switch (number) {
            case 1:
                    printingf(argument, precision, f1);
                    break;
            case 2:
                    printingf(argument, precision, f2);
                    break;
            default:
                    cout << "There is no such function" << endl;
                    break;
        }
        cout << "Will you still work? Press 'Enter' if 'YES' or any key and 'Enter 'if 'NO' ";
    } while (getch() == 13);
}




