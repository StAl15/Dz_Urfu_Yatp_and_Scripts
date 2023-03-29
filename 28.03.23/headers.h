#include "iostream"
#include "string"
#include "fstream"
#include "cmath"

using namespace std;

struct IWords {
    string n;
    int countRepeat;
};


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

    void add_node(string n) {
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

    bool isInList(string elem) {
        for (Node *ptr = head; ptr != NULL; ptr = ptr->next) {
            if (ptr->data == elem) return true;
        }
        return false;
    }

private:
    Node *tail;
    Node *head;
};

void openFile(ifstream &file, string name);

void readFile(ifstream &file, LinkedList &words, int &countN);

void setCountWords(LinkedList &words1, LinkedList &words2, int &countN1, int &countN2, IWords *&res);

void sortWords(IWords *&words, int countN);

void writeAnswer(IWords *words, int countN);

