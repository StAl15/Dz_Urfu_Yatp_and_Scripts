#include <iostream>
#include <cmath>

using namespace std;

double faq(double n)
{
    if (n == 0)
        return 1;
    else
        return n * faq(n - 1);
}

int main()
{

    double epsilon, x;

    cin >> epsilon >> x;

    double result = 1;

    double sum = 0;

    double n = -1;
    double n1 = -1;

    bool isMinus = true;

    while (abs(result) >= epsilon)
    {
        result = pow(x, n1) / pow(3, n);
        if (isMinus==true) result *= -1;
        sum += result;
        n1 += 2;
        n++;
        isMinus = not(isMinus);
    }

    cout << sum << endl;

    return 0;
}