#include <iostream>
#include <cmath>

using namespace std;

int getreversed(int n)
{
    int r = n % 10;
    while (n /= 10)
    {
        r = r * 10 + n % 10;
    }
    return r;
}

bool is_palindrom(int n1, int n2)
{
    return n1 == getreversed(n2);
}

int main()
{

    int len;
    cin >> len;

    int arr1[len], arr2[len];
    for (int i = 0; i < len; i++)
        cin >> arr1[i];
    for (int i = 0; i < len; i++)
        cin >> arr2[i];
    for (int i = 0; i < len; i++)
    {
        if (is_palindrom(arr1[i], arr2[len - 1 - i]) == false)
        {
            cout << "FALSE" << endl;
            return 0;
        }
    }
    cout << "TRUE" << endl;
    return 0;
}