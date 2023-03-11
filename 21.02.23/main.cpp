#include "headers.h"

using namespace std;

int main() {
    mnogocghlen mn;
    input(mn);
    output(mn);
    getCoefProizv(mn);
    getValueInPoint(mn, 5);
    getProizvInPoint(mn, 5);
    mnogocghlen mn_;
    input(mn_);
    output(mn_);
    minusMnogochl(mn, mn_);
    sumMnogochl(mn, mn_);
    multiplyMnogochl(mn, mn_);
    divideMnogochl(mn, mn_);


    return 0;
}