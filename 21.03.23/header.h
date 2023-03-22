#include "iostream"
#include "fstream"
#include "string"
#include "cmath"

using namespace std;

struct Point {
    int x;
    int y;
};

struct ModelMnogoug {
    int countN;
    Point *points;
};

class Mnogoug {
public:

    Mnogoug(int countN, Point *points);

    bool isVipucl();

    double getDiagonal();

    double getS();

    double getP();

    int getCountN() {
        return countN;
    }

    Point *getPoints() {
        return points;
    }

private:
    int countN;
    Point *points;
};

void openFile(ifstream &file, string name);

void readFile(ifstream &file, ModelMnogoug *&mg, int &countMg);

void writeAnswer(ModelMnogoug *mg, int countA);

void sortMg(ModelMnogoug *&mg, int countMg);

double getSide(Point a, Point b);

void getVipuclMg(ModelMnogoug *&mg, ModelMnogoug *&rmg, int countMg, int &countVpMg);