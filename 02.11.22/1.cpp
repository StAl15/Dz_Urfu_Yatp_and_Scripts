#include <iostream>

using namespace std;

int count_el(int arr[], int x, int len)
{
    int c = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == x)
        {
            c++;
        }
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

    // buble sort
    for (int i = 0; i < len; i++) // current
    {
        for (int j = i + 1; j < len; j++) // next
        {
            if (items[j] < items[i])
            {
                int tmp = items[j];
                //меняем числа местами: большее на меньшее
                items[j] = items[i];
                items[i] = tmp;
            }
        }
    }

    int max_nums[] = {items[len - 1], items[len - 2], items[len - 3]};

    cout << "max elems: " << items[len - 1] << " " << items[len - 2] << " " << items[len - 3] << endl;

    return 0;
}