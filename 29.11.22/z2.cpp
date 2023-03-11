// Проверить, что в квадратной матрице любой элемент выше главной диагонали не меньше, чем любой элемент ниже главной диагонали.

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

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] > matrix[i][size - 1 - i])
            {
                cout << "FALSE" << endl;
                cout << matrix[i][j] << " " << matrix[i][size - 1 - i] << endl;
                return 0;
            }
        }
    }

    cout << "True" << endl;

    return 0;
}