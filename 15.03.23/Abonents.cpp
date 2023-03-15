#include "header.h"


Abonent::Abonent(modelAbonent ab) {
    this->abonent = ab;
}

void openFile(ifstream &file, string name) {
    file.open(name);
}

void readFile(ifstream &file, modelAbonent *&abonents, int &countA) {
    string ca;
    file >> ca;
    countA = stoi(ca);
    abonents = new modelAbonent[countA];
    int c = 0;
    while (!file.eof()) {
        file >>
             abonents[c].surname >>
             abonents[c].phone >>
             abonents[c].balance;
        c++;
    }
    file.close();
}

void writeAnswer(modelAbonent *abonents, int countA) {
    ofstream file;
    file.open("answer.txt");
    if (countA != 0) {
        for (int c = 0; c < countA; c++) {
            file <<
                 "---------------" <<
                 endl <<
                 c+1 <<
                 endl <<
                 abonents[c].surname <<
                 endl <<
                 abonents[c].phone <<
                 endl <<
                 abonents[c].balance <<
                 endl;
        }
    } else {
        file << "Nothing debts YOUHUUUUUU!!!!!";
    }

    file.close();
}

modelAbonent *getDebts(modelAbonent *abonents, int countA, int &countDeb) {
    int c = 0;
    //если что переделать
    for (int i = 0; i < countA; i++) {
        if (Abonent(abonents[i]).hasDebet()) countDeb++;
    }
    modelAbonent *debts = new modelAbonent[countDeb];
    for (int i = 0; i < countA; i++) {
        if (Abonent(abonents[i]).hasDebet()) {
            debts[c] = abonents[i];
            c++;
        }
    }
    return debts;
}

void sortDebts(modelAbonent *&abonents, int countDeb) {
    for (int i = 0; i < countDeb; i++) {
        for (int j = 0; j < countDeb - i + 1; j++) {
            int j_ = j + 1;
            Abonent(abonents[j]).sortArr(Abonent(abonents[j + 1]), j, j_, abonents);
        }
    }
}
