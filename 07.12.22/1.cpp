#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int matrix1[n][m];

    int matrix2[n][m];

    cout << "Enter first matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter second matrix" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix2[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix1[i][j] + matrix2[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}