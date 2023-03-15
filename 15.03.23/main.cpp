#include "header.h"

int main() {

    ifstream file;
    int countA, countDeb = 0;
    modelAbonent *abonents;
    modelAbonent *debts;
    openFile(file, "abonents.txt");
    readFile(file, abonents, countA);
    debts = getDebts(abonents, countA, countDeb);
    sortDebts(debts, countDeb);
    writeAnswer(debts, countDeb);

    return 0;
}