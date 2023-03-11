#include <iostream>

using namespace std;

int f(int n)
{
    if (n > 10)
    {
        if (n % 10 < (n / 10) % 10)
        {
            return f(n / 10);
        }
        else
        {
            return -1;
        }
    }
    return n % 10 < (n / 10) % 10;
}

int main()
{

    int n;
    cin >> n;
    if (n < 10)
    {
        cout << "not ub " << endl;
        return 0;
    }

    if (f(n) == -1)
    {
        cout << "not ub" << endl;
        return 0;
    }
    cout << " yes ub " << endl;

    return 0;
}