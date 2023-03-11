#include "headers.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void getCoefProizv(mnogocghlen m) {
    mnogocghlen res;
    res.countKoef = m.countKoef;
    res.arr_koef = new int[m.countKoef];
    for (int i = 0; i < m.countKoef; i++) {
        res.arr_koef[i] = m.arr_koef[i] * (m.countKoef - i - 1);
    }

    cout << "koefs proizvodnoi: \n";
    for (int i = 0; i < res.countKoef && res.arr_koef[i] != 0; i++) {
        if (res.arr_koef[i] >= 0) cout << " " << res.arr_koef[i];
        else cout << "- " << abs(res.arr_koef[i]);
        if (res.countKoef - 2 - i != 0) cout << "x^" << res.countKoef - 2 - i << " ";
        if (i != res.countKoef - 2 && res.arr_koef[i + 1] >= 0) cout << "+";
    }
    cout << "\n";
}