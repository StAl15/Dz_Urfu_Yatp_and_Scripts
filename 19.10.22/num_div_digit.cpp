#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int digit;
    int n1 = n;
    while (n > 0)
    {
        digit = n % 10;
        if (n1 % digit == 0 && digit != 0)
        {
            cout << "OK" << endl;
            return 0;
        }
        n = n / 10;
    }
    cout << "NO" << endl;

    return 0;
}