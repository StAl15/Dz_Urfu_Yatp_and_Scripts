#include "iostream"
#include "cmath"
#include "string"

using namespace std;

typedef double (&func)(double);

double getProiz(func f, double x, double e) {
    return (f(x + e) - f(x)) / e;
}

