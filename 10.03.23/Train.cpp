#include "header.h"

string toLowerCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {        // If the character is Uppercase
            str[i] = ((char) (str[i] - 'A' + 'a'));   // Conversion from uppercase to lowercase, update character value
        }
    }
    return str;
}

Train::Train(trainType train) {
    this->train = train;
}

void openFile(ifstream &file, string name) {
    file.open(name);
}

void readFile(ifstream &file, trainType *&res, int &ct) {
    string countTrain;
    file >> countTrain;
    ct = stoi(countTrain);
    res = new trainType[ct];
    int c = 0;
    string s;
    while (!file.eof()) {
        file >> res[c].to >> res[c].trainNumber >> res[c].date.year >> res[c].date.month >> res[c].date.day;
        c++;
    }
    file.close();
}

void sortR(trainType *&res, int ct) {
    for (int i = 0; i < ct; i++) {
        for (int j = 0; j < ct - i + 1; j++) {
            trainType t;
            Train T(t);
            T.setTrain(res[j]);
            int j_ = j + 1;
            T.compareTrain(res[j + 1], j, j_, res);
        }
    }
}

void writeAnswer(trainType *res, int ct) {
    ofstream file;
    file.open("answer.txt");
    for (int c = 0; c < ct; c++) {
        file <<
             res[c].to <<
             endl <<
             res[c].trainNumber <<
             endl <<
             res[c].date.year << "." << res[c].date.month << "." << res[c].date.day << endl;
    }
    file.close();
}

