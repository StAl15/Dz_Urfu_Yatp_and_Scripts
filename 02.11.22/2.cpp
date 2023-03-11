#include <iostream>

using namespace std;

bool isPosl(int an, int a1, int d, int n)
{
    // a(n3) = a1 + 2d
    if (an == a1 + d * (n - 1))
        return true;
    else
        return false;
}

int count_el(int items[], int indexStart, int len)
{
    int count = 2;
    int max = 0;
    for (int i = indexStart; i < len; i++)
    {
        int delta = items[i+1] - items[i];
        int delta1 = items[i+2] - items[i+1];
        if (delta1 == delta) {
            count++;
            if (count > max) max = count;
        }
        else count = 2;
    }
    return max;
}

int main()
{

    int len;
    cin >> len;
    int items[len];
    int c = 0;
    while (c < len)
    {
        cin >> items[c];
        c++;
    }
    
    int max = 0;

    for (int i = 0; i < len; i++){
        if (count_el(items, i, len) > max) max = count_el(items, i, len);
    }

    cout << max << endl;

    return 0;
}