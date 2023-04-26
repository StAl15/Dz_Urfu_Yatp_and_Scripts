#include "iostream"
#include "cmath"

using namespace std;

struct Node {
    int data;
    Node *next;
};

class Stack {
public:
    Stack() {
        top = nullptr;
    }

    Node *getTop() {
        return top;
    }

    void push(int data) {
        Node *tmp = new Node;
        tmp->data = data;
        tmp->next = top;
        top = tmp;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Empty stack" << endl;
            return -1;
        }
        int value = top->data;
        Node *tmp = top;
        top = top->next;
        delete tmp;
        return value;
    }

    int peek() { //get top value
        if (isEmpty()) {
            cout << "Empty stack" << endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty stack" << endl;
        }
        for (Node *ptr = top; ptr != NULL; ptr = ptr->next) {
            cout << ptr->data << " " << endl;
        }
    }

private:
    Node *top;
};

class Queue {
public:
    Queue() {}

    void enqueue(int new_data) {
        s1.push(new_data);
    }

    int dequeue() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }

    bool empty(void) {
        return s1.isEmpty() && s2.isEmpty();
    }

private:
    Stack s1;//input queue
    Stack s2;//output queue

};