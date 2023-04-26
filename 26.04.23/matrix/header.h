#include "iostream"
#include "string"
#include "fstream"
#include "cmath"

using namespace std;

struct Node {
    int row;
    int col;
    int num;
    Node *next;
};

class LinkedList {
public:
    LinkedList() {
        tail = NULL;
        head = NULL;
    }

    int getRows() {
        return rows;
    }

    int getColumns() {
        return cols;
    }

    void setRows(int r) {
        rows = r;
    }

    void setColumns(int c) {
        cols = c;
    }

    Node *getTail() {
        return tail;
    }

    Node *getHead() {
        return head;
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << getValue(i, j) << "\t";
            }
            cout << endl;
        }
    }

    int getValue(int r, int c) {
        for (Node *ptr = head; ptr != NULL; ptr = ptr->next) {
            if (ptr->row == r && ptr->col == c) return ptr->num;
        }
    }

    void add_node(int r, int c, int n) {

        Node *tmp = new Node;
        tmp->row = r;
        tmp->col = c;
        tmp->num = n;
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
            if (ptr->num == elem) return true;
        }
        return false;
    }

    LinkedList operator+(LinkedList lst);

    LinkedList operator-(LinkedList lst);

    LinkedList operator*(LinkedList lst);

    LinkedList operator*(int n);

private:
    int cols;
    int rows;
    Node *tail;
    Node *head;
};

void openFile(ifstream &file, string name);

void readFile(ifstream &file, LinkedList &nums, int &countN);