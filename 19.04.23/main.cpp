#include <iostream>
#include <cmath>

using namespace std;

double f(double x) { // определение функции
    return pow(x, 2) - 5;
}

double integral(double a, double b, double e, double (&func)(double)) {
//h - интервал разбиения, которая каждый раз делится пополам
    double I = 0, I_prev, h = b - a; //значение для тек опр интеграла и предыдущего
    int n = 1; //количество разбиений
    do {
        I_prev = I;
        I = 0;
        h /= 2;
        for (double x = a + h / 2; x < b; x += h) { //сумма значений на середине каждого интервала
            I += func(x);
        }
        I *= h;
        n *= 2;
    } while (abs(I - I_prev) > e && n < 1000000); //проверяется точность e
    return I;
}

int main() {
    double a = 0, b = 1, e = 0.0001;
    cout << "Значение интеграла: " << integral(a, b, e, f) << endl;
    return 0;
}