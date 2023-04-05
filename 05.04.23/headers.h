#include <iostream>
#include <fstream>
#include <string>


using namespace std;


struct Node {
    string data;
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

    void append(string n) {
        Node *tmp = new Node;
        tmp->data = n;
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

private:
    Node *tail;
    Node *head;
};

void openFile(ifstream &file, string name);

void readFile(ifstream &file, string &text);

LinkedList splitSentences(string &text);

LinkedList splitWords(LinkedList &sentences);

void writeAnswer(LinkedList &words);

