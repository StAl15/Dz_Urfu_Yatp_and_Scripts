#include <iostream>

using namespace std;

bool is_simple_num(int n)
{
    if (n == 0) return false;
    
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    int n1, n2;
    cin >> n1 >> n2;

    if (is_simple_num(n1) && is_simple_num(n2) && abs(n1 - n2) == 2)
    {
        cout << "Yeah, real brothers" << endl;
    }

    else
    {
        cout << "Sorry, not a real brothers" << endl;
    }

    return 0;
}