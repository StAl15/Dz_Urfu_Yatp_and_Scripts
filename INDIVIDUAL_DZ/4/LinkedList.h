#include "iostream"

using namespace std;

struct Node {
    int current;
    int neighboor;
    Node *next;
};

class LinkedList {
public:
    LinkedList() {
        tail = NULL;
        head = NULL;
    }

    Node *getTail() {
        return tail;
    }

    Node *getHead() {
        return head;
    }

    void append(int current, int neighboor) {
        Node *tmp = new Node;
        tmp->current = current;
        tmp->neighboor = neighboor;
        tmp->next = NULL;

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    Node *get(int idx) {
        int c = 0;
        for (Node *ptr = head; ptr->next != NULL; ptr = ptr->next) {
            if (c == idx) {
                return ptr;
            } else {
                c++;
            }
        }
        return nullptr;
    }

    void print() {
        for (Node *ptr = head; ptr->next != NULL; ptr = ptr->next) {
            cout << ptr->current << " " << ptr->neighboor << endl;
        }
    }

private:
    Node *tail;
    Node *head;
};