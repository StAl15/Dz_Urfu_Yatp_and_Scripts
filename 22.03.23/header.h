#include "iostream"
#include "string"
#include "fstream"
#include "cmath"

using namespace std;

struct num {
    int n;
    int countRepeat;
};


struct Node {
    int data;
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

    void add_node(int n) {
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

    bool isInList(int elem) {
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

void readFile(ifstream &file, LinkedList &nums, int &countN);

void setDiffNums(num *&nums, LinkedList &nums_, int countN, int &countN_);

void writeAnswer(num *nums, int countN);

void sortNums(num *&nums, int countN);