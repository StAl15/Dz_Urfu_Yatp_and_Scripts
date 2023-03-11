#include "headers.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void getValueInPoint(mnogocghlen m, int x) {
    double res = 0;
    int count = 0;
    res += m.arr_koef[0] * pow(x, m.countKoef - 1);
    for (int i = 0; i < m.countKoef; i++) {
        if (count < m.countKoef) {
            res += m.arr_koef[i + 1] * pow(x, m.countKoef - i - 2);
        }
    }

    cout << "value in point:" << endl;
    cout << res << endl;
}