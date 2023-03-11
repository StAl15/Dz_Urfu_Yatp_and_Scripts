#include <iostream>
#include <cmath>
#define PI 3.14159265

using namespace std;

double get_angle(double x1, double x2, double y1, double y2)
{
    double up = (x1 * x2 + y1 * y2);
    double down = sqrt((pow(x1, 2) + pow(y1, 2)) * (pow(x2, 2) + pow(y2, 2)));
    return acos(up / down);
}

bool is_exist(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    return s > 0;
}

double get_len(double x, double y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

double *get_vector(double x, double y, double x1, double y1)
{
    double *arr = new double[10];
    arr[0] = x1 - x;
    arr[1] = y1 - y;
    return arr;
}

int main()
{

    int n;
    cin >> n;
    double arr_x[100];
    double arr_y[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr_x[i] >> arr_y[i]; // input x & y
    }
    double angl1, angl2, angl3, max_angl = 0;
    double *vec1;
    double *vec2;
    double *vec3;
    double a, b, c;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                vec1 = get_vector(arr_x[i], arr_y[i], arr_x[j], arr_y[j]);
                vec2 = get_vector(arr_x[i], arr_y[i], arr_x[k], arr_y[k]);
                vec3 = get_vector(arr_x[j], arr_y[j], arr_x[k], arr_y[k]);

                cout << vec1 << " " << vec2 << " " << vec3 << endl;

                a = get_len(vec1[0], vec1[1]);
                b = get_len(vec2[0], vec2[1]);
                c = get_len(vec3[0], vec3[1]);

                cout << a << " " << b << " " << c << endl;

                if (is_exist(a, b, c) == false)
                {
                    cout << "Not exist" << endl;
                    return 0;
                }
                angl1 = get_angle(vec1[0], vec2[0], vec1[1], vec2[1]);
                angl2 = get_angle(vec1[0], vec3[0], vec1[1], vec3[1]);
                angl3 = get_angle(vec2[0], vec3[0], vec2[1], vec3[1]);

                max_angl = max(angl1, max(angl2, angl3));
                cout << angl1 << " " << angl2 << " " << angl3 << " " << max_angl << endl;
            }
        }
    }

    cout << max_angl * 180 / PI << endl;

    return 0;
    // 53.1978
    // 22.5699
    // 40.5142
}