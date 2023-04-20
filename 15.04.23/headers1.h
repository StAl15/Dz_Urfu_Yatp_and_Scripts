#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Node {
    string key;
    int value;
    Node *next;

    Node(string key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node *head;
public:
    LinkedList() {
        head = nullptr;
    }

    void append(string key, int value) {
        Node *tmp = new Node(key, value);
        if (head == nullptr) {
            head = tmp;
        } else {
            Node *curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = tmp;
        }
    }

    bool isInList(string key) {
        for (Node *ptr = head; ptr != NULL; ptr = ptr->next) {
            string cur = ptr->key;
            string word = "";
            for (const auto i: cur) {
                if (i != ' ') {
                    word += i;
                } else {
                    if (word == key) return true;
                    else word = "";
                }
            }
        }
        return false;
    }

    void increment(string key) {
        Node *curr = head;
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value++;
                return;
            }
            curr = curr->next;
        }
        append(key, 1);
    }

    Node *getHead() {
        return head;
    }

    void print() {
        Node *curr = head;
        while (curr != nullptr) {
            cout << curr->key << ": " << curr->value << endl;
            curr = curr->next;
        }
    }
};

void openFile(ifstream &file, string name);

void readFile(ifstream &file, string &text);

LinkedList splitSentences(string &text);

LinkedList splitWords(LinkedList &sentences);

LinkedList buildNgram(LinkedList words_list, int n);