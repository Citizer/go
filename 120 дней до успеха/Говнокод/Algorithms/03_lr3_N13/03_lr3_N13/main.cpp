/*Задан список студентов. Исключить из списка отчисленных студентов, информация о
которых содержится в файле.*/

#include <iostream>
#include <iostream>
#include <fstream>

using namespace std;

//создаем структуру
typedef struct Node {
    int value;
    struct Node *next;
} Node;


//добавление нового элемента в список
void push(Node **head, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

//удаляем элемент, на который указывает head
int pop(Node **head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

//получение нужного элемента списка
Node* getNth(Node* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}

//удаление нужного элемента списка
int deleteNth(Node **head, int n) {
    if (n == 0) {
        return pop(head);
    } else {
        Node *prev = getNth(*head, n-1);
        Node *elm  = prev->next;
        int val = elm->value;

        prev->next = elm->next;
        free(elm);
        return val;
    }
}

//добавление в список из массива
void fromArray(Node **head, int *arr, size_t size) {
    size_t i = size - 1;
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        push(head, arr[i]);
    } while(i--!=0);
}

//печать списка
void printLinkedList(const Node *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    fromArray(&head, arr, 10);
    printLinkedList(head);






}
