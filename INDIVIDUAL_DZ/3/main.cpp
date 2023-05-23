#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Функция для вычисления значения функции в точке x в соответствии с номером функции
double func(int func_num, double x) {
    switch (func_num) {
        case 1:
            return 1 / x;
        case 2:
            return 4 - x * x;
        case 3:
            return x + sin(x);
        default:
            return 0;
    }
}

// Функция для вычисления интеграла на заданном отрезке с заданной точностью методом правых прямоугольников
double right_rectangles(double a, double b, double h, int func_num) {
    double I = 0;
    for (double x = a; x < b; x += h) {
        I += func(func_num, x + h / 2) * h;
    }
    return I;
}

// Функция для вычисления интеграла на заданном отрезке с заданной точностью методом трапеций
double trapezoids(double a, double b, double h, int func_num) {
    double I = 0;
    for (double x = a; x < b; x += h) {
        I += (func(func_num, x) + func(func_num, x + h)) * h / 2;
    }
    return I;
}

// Функция для вычисления интеграла на заданном отрезке с заданной точностью методом Симпсона
double simpson(double a, double b, double h, int func_num) {
    double I = 0;
    for (double x = a; x < b; x += 2 * h) {
        I += (func(func_num, x) + 4 * func(func_num, x + h) + func(func_num, x + 2 * h)) * h / 3;
    }
    return I;
}

int main() {
    //формат: отрезок начало - конец, эпсилон, номер функции, номер метода
    ifstream in("input.txt");
    double a, b, eps;
    int func_num, method_num;
    in >> a >> b >> eps >> func_num >> method_num;
    in.close();

    // Выбор метода интегрирования в соответствии с номером
    double (*method)(double, double, double, int);
    switch (method_num) {
        case 1:
            method = right_rectangles;
            break;
        case 2:
            method = trapezoids;
            break;
        case 3:
            method = simpson;
            break;
        default:
            cout << "А голову ты не забыл???!!!" << endl;
            return 1;
    }

    // Вычисление интеграла с заданной точностью
    double I_prev = 0, I_cur = method(a, b, eps, func_num);
    int n = 1;
    while (abs(I_cur - I_prev) > eps) {
        I_prev = I_cur;
        n *= 2;
        I_cur = method(a, b, (b - a) / n, func_num);
    }

    // Вывод результата
    cout << "Значение интеграла: " << I_cur << endl;

    return 0;
}