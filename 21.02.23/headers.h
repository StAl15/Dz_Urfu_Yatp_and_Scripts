#include "iostream"
#include <string>
#include <cmath>

using namespace std;

struct mnogocghlen {
    int *arr_koef;
    int countKoef;
    int countOp;
    string *arr_operations;
};

void input(mnogocghlen &m);

void output(mnogocghlen m);

void getCoefProizv(mnogocghlen m);

void getValueInPoint(mnogocghlen m, int x);

void getProizvInPoint(mnogocghlen m, int x);

void sumMnogochl(mnogocghlen m1, mnogocghlen m2);

void minusMnogochl(mnogocghlen m1, mnogocghlen m2);

void multiplyMnogochl(mnogocghlen m1, mnogocghlen m2);

void divideMnogochl(mnogocghlen m1, mnogocghlen m2);

