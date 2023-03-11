#include <iostream>
#include <string>

using namespace std;

bool is_palindrom(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}

int minDeletions(string X, int i, int j)
{
     // базовое условие
    if (i >= j) {
        return 0;
    }
 
    // если последний символ строки совпадает с первым символом
    if (X[i] == X[j]) {
        return minDeletions(X, i + 1, j - 1);
    }
 
    return 1 + min (minDeletions(X, i, j - 1), minDeletions(X, i + 1, j));
    
}

int main()
{

    string s;
    cin >> s;
    if (is_palindrom(s))
    {
        cout << " is palindrom " << s << endl;
    }
    else
    {
        cout << minDeletions(s, 0, s.length() - 1) << endl;
    }

    return 0;
}