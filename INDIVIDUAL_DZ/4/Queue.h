#include <iostream>

using namespace std;

// Класс для представления элемента очереди
class QueueNode {
public:
    int data; // Данные элемента
    QueueNode *next; // Указатель на следующий элемент

    // Конструктор
    QueueNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Класс для представления очереди
class Queue {
private:
    QueueNode *front; // Указатель на первый элемент
    QueueNode *rear; // Указатель на последний элемент
public:
    // Конструктор
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    QueueNode *getFront() {
        return front;
    }

    QueueNode *getRear() {
        return rear;
    }

    // Добавление элемента в очередь
    void push(int data) {
        QueueNode *node = new QueueNode(data);
        if (rear == nullptr) {
            front = node;
            rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
    }

    // Извлечение элемента из очереди
    int pop() {
        if (front == nullptr) {
            cout << "EMPTY" << endl;
            return 0;
        }
        int data = front->data;
        QueueNode *temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        return data;
    }

    // Проверка пустоты очереди
    bool empty() {
        return front == nullptr;
    }

};