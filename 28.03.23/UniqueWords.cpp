#include "headers.h"

void openFile(ifstream &file, string name) {
    file.open(name);
}

void readFile(ifstream &file, LinkedList &words, int &countN) {
    while (!file.eof()) {
        string c = "";
        file >> c;
        words.add_node(c);
        countN++;
    }
    file.close();
}

void setCountWords(LinkedList &words1, LinkedList &words2, int &countN1, int &countN2, IWords *&res) {
    res = new IWords[countN1];
    int c = 0;
    for (Node *ptr = words1.getHead(); ptr != NULL; ptr = ptr->next) {
        string target = ptr->data;
        res[c].n = target;
        res[c].countRepeat = 0;
        for (Node *ptr1 = words2.getHead(); ptr1 != NULL; ptr1 = ptr1->next) {
            if (ptr1->data == target) res[c].countRepeat++;
        }
        cout << c << " " << res[c].n << " " << res[c].countRepeat << endl;
        c++;
    }

}

void writeAnswer(IWords *words, int countN) {
    ofstream file;
    file.open("answer.txt");
    for (int i = 0; i < countN; i++) {
        file << "n = " << words[i].n << " cr = " << words[i].countRepeat << endl;
    }
    file.close();
}

void sortWords(IWords *&words, int countN) {
    for (int i = 0; i < countN; i++) {
        for (int j = 0; j < countN - i - 1; j++) {
            if (words[j].countRepeat < words[j + 1].countRepeat) {
                swap(words[j], words[j + 1]);
            }
        }
    }
}

