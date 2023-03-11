#include <iostream>
#include <cmath>
using namespace std;

int get_len(int n)
{
    int k = 0;
    while (n > 0)
    {
        k++;
        n /= 10;
    }
    return k;
}

bool verify(int n)
{
    int k = 0;
    int len = get_len(n);
    int s = 0;
    int n1 = n;
    while (k != len)
    {
        s += pow(n % 10, len);
        k++;
        n /= 10;
    }
    if (s == n1) return true;
    else return false;
}

int main()
{
    int input;
    cin >> input;
    if (verify(input)) cout << "GOOD_GUY" << endl;
    else cout << "BAD_GUY" << endl;
    return 0;
}