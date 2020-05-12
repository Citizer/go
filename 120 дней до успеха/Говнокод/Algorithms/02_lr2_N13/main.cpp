/*Слить две очереди в одну.*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue <int> queue1; //первая очередь
    queue <int> queue2; //вторая очередь
    queue <int> queueResult; // результирующая очередь
    int countQueue1, countQueue2;

    //Заполняем первую очередь
    cout << "Enter the number of items in the first queue: ";
    cin >> countQueue1;
    cout << "Enter the items in the first queue" << endl;
    for (int i = 0; i < countQueue1; i++) {
        int a;
        cin >> a;
        queue1.push(a);
    }

    //Заполняем вторую очередь
    cout << "Enter the number of items in the second queue: ";
    cin >> countQueue2;
    cout << "Enter the items in the second queue" << endl;
    for (int i = 0; i < countQueue2; i++) {
        int a;
        cin >> a;
        queue2.push(a);
    }

    while (!queue1.empty() && !queue2.empty()) {
        if (queue1.front() > queue2.front()) {
            queueResult.push(queue2.front());
            queue2.pop();
        } else {
            queueResult.push(queue1.front());
            queue1.pop();
        }

    }

    //проверяем на пустоту 1 очередь, если не пустая, то добавляем в результирующую очередь
    if (!queue1.empty()) {
        while (!queue1.empty()) {
            queueResult.push(queue1.front());
            queue1.pop();
        }
    }

    //проверяем на пустоту 2 очередь, если не пустая, то добавляем в результирующую очередь
    if (!queue2.empty()) {
        while (!queue2.empty()) {
            queueResult.push(queue2.front());
            queue2.pop();
        }
    }

    //вывод результируюзей очереди. Знаю что она в итоге пустая будет
    while (!queueResult.empty()) {
        cout << queueResult.front() << " ";
        queueResult.pop();
    }


}
