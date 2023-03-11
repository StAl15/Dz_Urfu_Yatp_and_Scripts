//
// Created by Rgt Hardkor on 2/22/23.
//
#include "headers.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void divideMnogochl(mnogocghlen m1, mnogocghlen m2) {
    /*
     36 18 8 | 18 9 4
     36 18 8 | 2
     */

    /*
     42 98 5 | 5 12
     40 96   | 8
     2  2  5
     */

}

//public Polynomial2 divides(Polynomial2 b) {
//    Polynomial2 a = this;
//    if ((b.deg == 0) && (b.coef[0] == 0))
//        throw new RuntimeException("Divide by zero polynomial");
//
//    if (a.deg < b.deg) return ZERO;
//
//    int coefficient = a.coef[a.deg].divides(b.coef[b.deg]);
//    int exponent = a.deg - b.deg;
//    Polynomial2 c = new Polynomial2(coefficient, exponent);
//    return c.plus( (a.minus(b.times(c)).divides(b)) );
//}