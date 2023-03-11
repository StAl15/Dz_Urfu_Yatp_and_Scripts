#include <iostream>

using namespace std;

int get_fish(int n)
{

    if (n % 3 == 0)
        return 0;
    else
    {
        int k = 0;
        while (k != 3)
        {
            n--;
            if (n % 3 == 0)
                n -= n / 3;
            else
                return 0;
            k++;
        }
    }
    return n;
}

int main()
{
    int c = 0;
    while (true)
    {
        if (get_fish(c) > 0)
        {
            cout << c << endl;
            break;
        }
        else
            c++;
    }
    return 0;
}