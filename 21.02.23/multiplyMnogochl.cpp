//
// Created by Rgt Hardkor on 2/22/23.
//
#include "headers.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void multiplyMnogochl(mnogocghlen m1, mnogocghlen m2) {

    int l = m1.countKoef + m2.countKoef - 1;
    mnogocghlen r;
    r.countKoef = l;
    r.arr_koef = new int[l];
    for (int i = 0; i < l; i++) r.arr_koef[i] = 0; //fill

    for (int i = 0; i < m1.countKoef; i++) {
        for (int j = 0; j < m2.countKoef; j++)
            r.arr_koef[i + j] += m1.arr_koef[i] * m2.arr_koef[j];
    }

    cout <<"multiply: \n";
    output(r);

}