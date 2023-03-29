#include "headers.h"

int main() {

    ifstream file, file_;
    LinkedList lst, lst_;
    IWords *r;
    int countN = 0;
    int countN_ = 0;
    openFile(file, "words_rez.txt");
    cout << "is done open file" << endl;
    readFile(file, lst, countN);
    cout << "is done read file" << endl;
    openFile(file_, "words.txt");
    cout << "is done open file" << endl;
    readFile(file_, lst_, countN_);
    cout << "is done read file" << endl;
    setCountWords(lst, lst_, countN, countN_, r);
    cout << "is done count words" << endl;
    sortWords(r, countN);
    cout << "is done sort file" << endl;
    writeAnswer(r, countN);
    cout << "is done write answer file" << endl;

    return 0;
}