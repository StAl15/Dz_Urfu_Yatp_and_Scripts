#include "headers.h"
#include <string>
#include <iostream>

using namespace std;

void input(mnogocghlen &m) {

    int n = 0;
    string m_;

    cout << "kol-vo koef" << endl;
    cin >> m.countKoef;

    m.arr_koef = new int[m.countKoef];

    cout << "Vvedite koef po ocheredi" << endl;
    while (n < m.countKoef) {
        cin >> m.arr_koef[n];
        n++;
    }

//    int c = 0;
//    m.countOp = 0;
//    for (int i = 0; i < m_.length(); i++) {
//        if (m_[i] == '+' || m_[i] == '-') {
//            m.arr_operations[c] = m_[i];
//            c++;
//        }
//    }
//    m.countOp = c;


}