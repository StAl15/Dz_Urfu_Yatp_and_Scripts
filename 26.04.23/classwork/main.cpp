#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x / 2; // replace on another function
}

typedef double (&func)(double);

// a, b - пределы хорды, epsilon — необходимая погрешность
double findRoot(double a, double b, double epsilon, func f) {
    while (fabs(b - a) > epsilon) {
        a = a - (b - a) * f(a) / (f(b) - f(a));
        b = b - (a - b) * f(b) / (f(a) - f(b));
    }
    // a, b — (i - 1)-й и i-й члены

    return b;
}

int main() {

    cout << findRoot(1, 2, pow(1, -10), f) << endl;

    return 0;
}