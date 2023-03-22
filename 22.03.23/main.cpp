#include "header.h"

int main() {

    ifstream file;
    LinkedList lst;
    num *r;
    int countN=0;
    int countN_ = 0;
    openFile(file, "nums.txt");
    readFile(file, lst, countN);
    setDiffNums(r, lst, countN, countN_);
    sortNums(r, countN_);
    writeAnswer(r, countN_);

    return 0;
}