#include "iostream"
#include "fstream"
#include "string"
#include "cmath"

using namespace std;

struct modelAbonent {
    string surname;
    string phone;
    double balance;
};

void openFile(ifstream &file, string name);

void readFile(ifstream &file, modelAbonent *&abonents, int &countA);

void writeAnswer(modelAbonent *abonents, int countA);

void sortDebts(modelAbonent *&abonents, int countDeb);

modelAbonent *getDebts(modelAbonent *abonents, int countA, int &countDeb);

class Abonent {
public:

    Abonent(modelAbonent ab);

    bool hasDebet() {
        return abonent.balance < 0;
    }

    void swapIdx(int &idx1, int &idx2, modelAbonent *&res) {
        modelAbonent tmp = res[idx1];
        res[idx1] = res[idx2];
        res[idx2] = tmp;
    }

    double getBalance() {
        return abonent.balance;
    }

    void sortArr(Abonent ab, int &idx1, int &idx2, modelAbonent *&res) {
        if (hasDebet() && ab.hasDebet()) {
            if (abs(abonent.balance) < abs(ab.getBalance())) {
                swapIdx(idx1, idx2, res);
            }
        }

    }

private:
    modelAbonent abonent;
};