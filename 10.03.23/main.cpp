#include "header.h"

int main() {
    ifstream f;
    int ct;
    trainType *res;
    openFile(f, "train.txt");
    readFile(f, res, ct);
    sortR(res, ct);
    writeAnswer(res, ct);
    return 0;
}