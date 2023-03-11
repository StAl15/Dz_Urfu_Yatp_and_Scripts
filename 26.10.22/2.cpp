#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{

    double a, b;
    cin >> a;
    cin >> b;

    int arr_divs[100] = {};
    int first_n = int(a / b);

    for (int i = 0; i < 10; i++)
    {
        int digit = int(a * (pow(10, i)) / b) % 10;
        arr_divs[i] = digit;
    }

    for (int i = 0; i < 10; i++){
        cout << arr_divs[i] << endl;
    }

    string result = to_string(first_n)+".";
    if (arr_divs[2] >= 5) result += to_string(arr_divs[1]+1);
    else result += to_string(arr_divs[1]);

    cout << result << endl;

    return 0;
}