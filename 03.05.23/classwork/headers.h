#include <iostream>
#include <fstream>
#include <string>


using namespace std;


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

    void append(int n) {
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

    void print() {
        for (Node *ptr = head; ptr->next != NULL; ptr = ptr->next) {
            cout << ptr->data << endl;
        }
    }

private:
    Node *tail;
    Node *head;
};

class Graph{
public:
    int n;
    LinkedList *graph;
    
    Graph(int n_) {
        graph = new LinkedList[n_];
    }
    void complement() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    bool found = false;
                    for (Node *curr = graph[i].getHead(); curr!=NULL; curr = curr->next) {
                        if (curr->data == j) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        graph[i].append(j);
                    }
                }
            }
        }
    }
    void printGraph() {
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            Node* curr = graph[i].getHead();
            while (curr != graph[i].getTail()) {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }

};