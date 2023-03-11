#include <iostream>
#include <cmath>

using namespace std;

double receive_h(double s, double a)
{
    return (2 * s) / a; // из формулы площади треугольника
}

double receive_s(double a, double b, double c) //формула герона
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double receive_storona_vector(int x, int y) //длина вектора
{
    return sqrt(x * x + y * y);
}

bool is_stupid_triangle(double a, double b, double c)
{
    return pow(a, 2) > pow(b, 2) + pow(c, 2) || pow(b, 2) > pow(a, 2) + pow(c, 2);
}

bool is_on_vector(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3)
{
    if ((x_3 - x_1) / (x_2 - x_1) == (y_3 - y_1) / (y_2 - y_1))
        return true;
    else
        return false;
}

int main()
{

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double a = receive_storona_vector(abs(x3 - x1), abs(y3 - y1));
    double b = receive_storona_vector(abs(x3 - x2), abs(y3 - y2));
    double c = receive_storona_vector(abs(x2 - x1), abs(y2 - y1)); // основание треугольника (сам отрезок)

    double s = receive_s(a, b, c);
    double res = receive_h(s, c);

    res = min(res, min(a, b));

    if (is_on_vector(x1, y1, x2, y2, x3, y3) == true) cout << "Лежит на векторе, кратчайшее расстояние 0" << endl;
    else if (is_stupid_triangle(a, b, c)) cout << min(a, b) << endl;
    else cout << res << endl;

    return 0;
}