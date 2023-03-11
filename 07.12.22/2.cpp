#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int matrix[n][m];

    cout << "Enter first matrix" << endl;
    int count = 0;
    int gcount = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                count++;
            }
        }
        if (count == m)
        {
            gcount++;
            count = 0;
        }
        count = 0;
    }

    cout << "Answer: " << gcount << endl;

    return 0;
}