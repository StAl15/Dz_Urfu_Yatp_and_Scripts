#include <iostream>

using namespace std;

int countEl(int arr[], int x, int length)
{
    int i = 0;
    int c = 0;
    while (i < length)
    {
        if (arr[i] == x)
        {
            c++;
        }
        i++;
    }
    return c;
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

    for (int i = 0; i < len; i++)
    {
        if (countEl(items, items[i], len) > 1)
        {
            cout << "FALSE" << endl;
            return 0;
        }
    }

    cout << "TRUE" << endl;

    return 0;
}

// tak sebe variant

// for (int i = 0; i < len; i++)
// {
//     for (int j = 0; j < len; j++)
//     {
//         if (items[i] == items[j] && i != j)
//         {
//             cout << "FALSE" << endl;
//             return 0;
//         }
//     }
// }