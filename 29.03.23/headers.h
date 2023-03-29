#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void add(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        tail->next = head;
    }

    int getHead() {
        return head->data;
    }

    int getTail() {
        return tail->data;
    }

    int josephus(int k, int m) {
        Node *current = head;
        Node *prev = tail;
        while (head != tail || head->next != head) {
            for (int i = 1; i < k; i++) {
                prev = current;
                current = current->next;
            }
            for (int i = 1; i < m; i++) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            Node *temp = current;
            current = current->next;

            if (temp == head) {
                head = current;
            }
            if (temp == tail) {
                tail = prev;
            }

            delete temp;
            k = (k + (m - 1)) % (tail->data + 1);
            if (k == 0) {
                k = tail->data;
            }
        }
        return head->data;
    }
};