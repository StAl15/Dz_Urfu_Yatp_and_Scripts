#include <iostream>
#include <cmath>

using namespace std;

// https://www.math10.com/ru/geometria/geogebra/geogebra.html - построение фигур для проверки

double calculate_square(double x1, double y1, double x3, double y3, double x_1, double y_1, double x_3, double y_3)
{
    /*
    x1, y1 - левая нижняя точка первого прямоугольника
    x3, y3 - правая верхняя точка первого прямоугольника
    x_1, y_1 - левая нижняя точка второго прямоугольника
    x_3, y_3 - правая верхняя точка второго прямоугольника
    */

    double left = max(x1, x_1);
    double top = min(y3, y_3);
    double right = min(x3, x_3);
    double bottom = max(y1, y_1);

    double width = right - left;
    double height = top - bottom;

    return width * height;
}

int main()
{

    // left top right bottom
    double x1, y1, x2, y2, x3, y3, x4, y4;
    double x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3 >> x_4 >> y_4;

    double result = calculate_square(x1, y1, x3, y3, x_1, y_1, x_3, y_3);

    if (result >= 0)
    {
        cout << "Да, пересекаются, площадь пересечения равна: " << result << endl;
    }
    else
    {
        cout << "Нет, не пересекаются" << endl;
    }

    return 0;
}