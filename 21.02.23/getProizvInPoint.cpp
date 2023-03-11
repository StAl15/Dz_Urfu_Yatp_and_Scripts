#include "headers.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void getProizvInPoint(mnogocghlen m, int x) {
    double res = 0;
    int *proizKoef = new int[m.countKoef];
    for (int i = 0; i < m.countKoef; i++) {
        proizKoef[i] = m.arr_koef[i] * (m.countKoef - i - 1);
    }
    res = proizKoef[0] * pow(x, m.countKoef - 2);
    for (int i = 1; i < m.countKoef; i++) {
        res += proizKoef[i] * pow(x, m.countKoef - i - 2);

    }

    cout << "proizv in point: \n" << res << endl;
}