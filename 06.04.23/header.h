#include "iostream"
#include "string"
#include "fstream"

using namespace std;

class Node {

public:
    int degree;
    int koef;
    Node *next;
    Node *prev;

public:
    Node(int degree, int koef) {
        this->degree = degree;
        this->koef = koef;
        this->prev = this->next = NULL;
    }
};

class LinkedList {
public:
    LinkedList() {
        tail = NULL;
        head = NULL;
    }

    int getMaxDegree() {
        return maxDegree;
    }

    Node *getTail() {
        return tail;
    }

    Node *getHead() {
        return head;
    }

    void appendFront(int degree, int koef) {
        Node *tmp = new Node(degree, koef);
        tmp->degree = degree;
        tmp->koef = koef;
        tmp->prev = NULL;

        if (tail == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            head = tmp;
            head = head->prev;
        }
    }

    void appendBack(int degree, int koef) {
        Node *tmp = new Node(degree, koef);
        tmp->degree = degree;
        tmp->koef = koef;
        tmp->next = NULL;

        if (head == NULL) {
            tmp->prev = NULL;
            head = tmp;
            tail = tmp;
        } else {
            tmp->prev = tail;
            tail->next = tmp;
            tail = tmp;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    LinkedList filter();

    bool isInList(int degree) {
        for (Node *ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
            if (ptr1->degree == degree) return true;
        }
        return false;
    }

    void print() {
        for (Node *ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
            cout << ptr1->koef << "x^" << ptr1->degree << "\t";
        }
        cout << endl;
    }

    LinkedList operator+(LinkedList const &);

    LinkedList operator*(LinkedList const &);

private:
    int maxDegree;
    Node *tail;
    Node *head;
};

void fill(LinkedList &lst);

//LinkedList filter(LinkedList res);