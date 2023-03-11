#include <iostream>
using namespace std;

int isMoreEqual(int **matrix, int idx_elem, int size)
{
    int s = 0;
    for (int j = 0; j < size; j++)
    {
        if (j != idx_elem)
            s += abs(matrix[idx_elem][j]);
    }

    if (abs(matrix[idx_elem][idx_elem]) > s && abs(matrix[idx_elem][idx_elem]) != s)
    {
        return 1;
    }
    else if (abs(matrix[idx_elem][idx_elem]) >= s)
    {
        return 2;
    }
    else
        return 0;
}

int main()
{
    int n;
    cin >> n;
    int **matrix = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int countMore = 0;
    for (int i = 0; i < n; i++)
    {
        if (isMoreEqual(matrix, i, n) == 0)
        {
            cout << "bad" << endl;
            return 0;
        }
        if (isMoreEqual(matrix, i, n) == 1)
        {
            countMore++;
        }
    }
    if (countMore > 0)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "It hasn't one '>' expression " << endl;
    }

    return 0;
}