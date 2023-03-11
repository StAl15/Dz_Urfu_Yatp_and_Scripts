//
// Created by Rgt Hardkor on 2/22/23.
//
#include "headers.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void sumMnogochl(mnogocghlen m1, mnogocghlen m2) {

    mnogocghlen res;
    int l = max(m1.countKoef, m2.countKoef);
    res.countKoef = l;
    res.arr_koef = new int[l];
    int tmpC = 0;
    int c = m1.countKoef - 1;
    int c_ = m2.countKoef - 1;
    while (c != -1 || c_ != -1) {
        int n1 = m1.arr_koef[c];
        int n2 = m2.arr_koef[c_];
        int r = n2 + n1;
        res.arr_koef[tmpC] = r;
        tmpC++;
        c--;
        c_--;
    }
    reverse(res.arr_koef, res.arr_koef + res.countKoef);
    cout << "sum: \n";
    output(res);

}