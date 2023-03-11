#include <iostream>
#include <string>
#include "cmath"
#include "fstream"

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct trainType {
    int trainNumber;
    string to;
    Date date;
};

string toLowerCase(string s);

void openFile(ifstream &file, string name);

void readFile(ifstream &file, trainType *&res, int &ct);

void writeAnswer(trainType *res, int ct);

void sortR(trainType *&res, int ct);

class Train {
public:
    Train(trainType train);

    void setTrain(trainType train_) {
        train.trainNumber = train_.trainNumber;
        train.to = train_.to;
        train.date = train_.date;
    }

    void compareTrain(trainType train_, int &idx1, int &idx2, trainType *&res) {
        if (toLowerCase(train.to) != toLowerCase(train_.to)) {
            for (int i = 0; i < min(train.to.length(), train_.to.length()); i++) {
                char x1 = toLowerCase(train.to).at(i);
                char x2 = toLowerCase(train_.to).at(i);
                if (int(x1) > int(x2)) {
                    trainType tmpIdx = res[idx1];
                    res[idx1] = res[idx2];
                    res[idx2] = tmpIdx;
                    break;
                } else if (int(x1) < int(x2)) break;
            }
        } else {
            if (train.date.year >= train_.date.year) {
                if (train.date.month >= train_.date.month) {
                    if (train.date.day >= train_.date.day) {
                        trainType tmpIdx = res[idx2];
                        res[idx2] = res[idx1];
                        res[idx1] = tmpIdx;
                    }
                }
            }
        }
    }

private:
    trainType train;

};