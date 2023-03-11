#include <iostream>
#include <cmath>

using namespace std;

int f(int arr[], int index)
{
    if (index > 0)
    {
        return max(arr[index - 1], f(arr, index - 1));
    }
    return arr[0];
}

int main()
{
    int len;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    cout << "max_v: " << f(arr, len) << endl;

    return 0;
}