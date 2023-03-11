#include <iostream>

using namespace std;

int main()
{

    int len_arr;
    cin >> len_arr; // len array

    if (len_arr == 1)
    {
        cout << "BAD ARRAY DETECTED!!!" << endl;
        return 0;
    }

    int arr[len_arr];
    int c = 0;
    while (c < len_arr)
    {
        cin >> arr[c];
        c++;
    }
    
    for (int i = 1; i < len_arr; i++)
    {
        if (arr[i] <= arr[i - 1])
        {
            cout << "FALSE" << endl;
            return 0;
        }
    }

    cout << "TRUE" << endl;
    return 0;
}