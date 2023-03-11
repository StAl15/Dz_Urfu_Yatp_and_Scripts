#include <iostream>

using namespace std;

int main()
{
    int size;
    cin >> size;
    int matrix[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << "\t";
                }
        cout << endl;
    }

    return 0;
}