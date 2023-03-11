#include <iostream>

using namespace std;

bool is_on_side(double a, double x, double y)
{
    y = abs(y);
    x = abs(x);

    double side = abs(a / 2);

    if ((x <= side && y == side) || (x == side && y <= side))
    {
        return true;
    }

    return false;
}

bool is_in(double a, double x, double y)
{
    y = abs(y);
    x = abs(x);

    double side = abs(a / 2);

    if (x<=side && y<=side) return true;
    return false;
}

int main()
{
    double a, x, y;
    cin >> a >> x >> y;

    if (is_in(a, x, y))
    {
        if (is_on_side(a, x, y))
            cout << "Лежит на границе";
        else
            cout << "Лежит внутри";
    }
    else
        cout << "Лежит вне";

    return 0;
}