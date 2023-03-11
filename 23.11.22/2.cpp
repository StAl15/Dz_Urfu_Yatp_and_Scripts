#include <iostream>
#include <string>

using namespace std;

string reverseStr(string str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}

string translate(int n, int p, string result)
{
    if (p < 10)
    {
        if (n > 0)
        {
            return translate(n / p, p, result += to_string(n % p));
        }
    }
    else if (p > 10 && p <= 16)
    {
        if (n > 0)
        {
            switch (n % p)
            {
            case 10:
                result += "A";
                break;
            case 11:
                result += "B";
                break;
            case 12:
                result += "C";
                break;
            case 13:
                result += "D";
                break;
            case 14:
                result += "E";
                break;
            case 15:
                result += "F";
                break;
            default:
                result += to_string(n % p);
                break;
            }

            return translate(n / p, p, result);
        }
    }
    return reverseStr(result);
}

int main()
{
    int n, p;
    cin >> n >> p;
    cout << translate(n, p, "") << endl;

    return 0;
}