#include "header.h"

double getSide(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

Mnogoug::Mnogoug(int countN, Point *points) {
    this->countN = countN;
    this->points = new Point[countN];
    for (int i = 0; i < countN; i++) {
        this->points[i] = points[i];
    }
}

double Mnogoug::getP() {
    double p = 0;
    for (int i = -1; i < countN-1; i++) {
        p += abs(getSide(points[i], points[i + 1]));
        cout << "s: " << getSide(points[i], points[i + 1]) << endl;
    }
    return p;
}

double Mnogoug::getS() {
    //метод гаусса
    double n1, n2;
    for (int i = 0; i < countN; i++) {
        n1 += points[i].x * points[i + 1].y;
        n2 += points[i].y * points[i + 1].x;
    }
    return abs(0.5 * (n1 - n2));
}

double Mnogoug::getDiagonal() {
    double maxN = 0;
    for (int i = 0; i < countN; i++) {
        for (int j = 0; j < countN; j++) {
            maxN = max(maxN, getSide(points[i], points[j]));
        }
    }
    return maxN;
}

bool Mnogoug::isVipucl() {
    int cp = 0;
    int cm = 0;
//    cout << "--------is Vypicl--------" << endl;
    for (int i = 0; i < countN; i++) {

        Point ab = {
                points[i].x - points[i - 1].x,
                points[i].y - points[i - 1].y
        };

        Point bc = {
                points[i + 1].x - points[i].x,
                points[i + 1].y - points[i].y
        };

        double product = ab.x * bc.y - ab.y * bc.x;
//        cout << product << endl;
        if (product < 0) cm++;
        else cp++;
    }
//    cout << cp << " " << cm << " " << (cp == 0 || cm == 0) << endl;
//    cout << "--------is Vypicl-------" << endl;
    if (cp == 0 || cm == 0) return true;
    return false;

}

void openFile(ifstream &file, string name) {
    file.open(name);
}

void readFile(ifstream &file, ModelMnogoug *&mg, int &countMg) {
    string cm;
    file >> cm;
    countMg = stoi(cm);
    mg = new ModelMnogoug[countMg];
    int c = 0;
    while (!file.eof()) {
        file >>
             mg[c].countN;
        mg[c].points = new Point[mg[c].countN];
        for (int i = 0; i < mg[c].countN; i++) {
            file >>
                 mg[c].points[i].x >>
                 mg[c].points[i].y;
        }

        c++;
    }
    file.close();
}

void writeAnswer(ModelMnogoug *mg, int countA) {
    ofstream file;
    file.open("answer.txt");
    if (countA != 0) {
        for (int c = 0; c < countA; c++) {
            Mnogoug(mg[c].countN, mg[c].points);
            file <<
                 "---------------" <<
                 endl <<
                 c + 1 <<
                 endl;
            for (int i = 0; i < mg[c].countN; i++) {
                file <<
                     mg[c].points[i].x << " " <<
                     mg[c].points[i].y <<
                     endl;
            }
            file <<
                 Mnogoug(mg[c].countN, mg[c].points).getDiagonal() << " " <<
                 Mnogoug(mg[c].countN, mg[c].points).getS() << " " <<
                 Mnogoug(mg[c].countN, mg[c].points).getP() <<
                 endl;
        }
    } else {
        file << "Nothing mnogoug YOUHUUUUUU!!!!!";
    }

    file.close();
}


void sortMg(ModelMnogoug *&mg, int countMg) {
    for (int i = 0; i < countMg; i++) {
        for (int j = 0; j < countMg - i - 1; j++) {
            if (Mnogoug(mg[j].countN, mg[j].points).getDiagonal() >
                Mnogoug(mg[j + 1].countN, mg[j + 1].points).getDiagonal()) {
                swap(mg[j], mg[j + 1]);
            }
        }
    }
}

void getVipuclMg(ModelMnogoug *&mg, ModelMnogoug *&rmg, int countMg, int &countVpMg) {
    for (int i = 0; i < countMg; i++) {
        if (Mnogoug(mg[i].countN, mg[i].points).isVipucl()) {
            cout << "isVipucl" << endl;
            countVpMg++;
        }
    }
    rmg = new ModelMnogoug[countVpMg];
    int c = 0;
    for (int i = 0; i < countMg; i++) {
        if (Mnogoug(mg[i].countN, mg[i].points).isVipucl()) {
            cout << "sec is vipucl" << endl;
            rmg[c].countN = mg[i].countN;
            rmg[c].points = mg[i].points;
            c++;
        }
    }
    cout << "a: " << rmg[0].countN << endl;
//    return r;

}