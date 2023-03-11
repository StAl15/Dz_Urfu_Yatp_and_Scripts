#include <iostream>
#include <cmath>

using namespace std;


int len(int n)
{
    int k = 0;
    while (n > 0)
    {
        k++;
        n /= 10;
    }
    return k;
}

int main()
{
    int n;
    cin >> n;
    int k1, k2;
    bool r = false;
    while (len(n)>=2)
    {
        k1 = n / pow(10, len(n) - 1);
        k2 = n % 10;
        cout << k1 << " " << k2 << endl;
        if (k1 == k2){
            r = true;
        }
        else {
            r = false;
            break;
        }
        n/= 10;
        cout << n << endl;
        n/=pow(10, len(n) - 1);
        cout << n << endl;
        
    }
    

    if (r)
        cout << "palindrom\n";
    else
        cout << "not palindrom\n";

    return 0;
}