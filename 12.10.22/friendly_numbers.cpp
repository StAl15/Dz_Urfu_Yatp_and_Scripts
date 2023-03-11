#include <iostream>

using namespace std;

int s_divs(int n)
{
    int s = 1;
    int i = 2;
    for (; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            s += i;
            s += n / i;
        }
    }
    i--;
    if (i * i == n)
    {
        s -= i;
        return s;
    }

    return s;
}

bool verify(int n1, int n2)
{
    if (s_divs(n1) == n2 && s_divs(n2) == n1)
    {
        return true;
    }
    return false;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    if (verify(n1, n2)) cout << "nums are friends " << endl;
    else cout << "nums are not friends " << endl;

    return 0;
}