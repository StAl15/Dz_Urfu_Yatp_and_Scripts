#include "headers.h"
#include <string>
#include <iostream>

using namespace std;

void output(mnogocghlen m) {

    for (int i = 0; i < m.countKoef && m.arr_koef[i]!=0; i++) {
        if (m.arr_koef[i] >= 0) cout << " " << m.arr_koef[i];
        else cout << "- " << abs(m.arr_koef[i]);
        if ( m.countKoef - 1 - i != 0) cout << "x^" << m.countKoef - 1 - i << " ";
        if (i != m.countKoef - 1 && m.arr_koef[i + 1] >= 0) cout << "+";
    }
    cout << "\n";
}