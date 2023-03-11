// Задана матрица A размера n*m. Найти индексы (r, c) элементов, которые являются одновременно максимальным в строке с номером r и минимальным в столбце с номером c

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    int matrix[n][m];

    int max_n, min_n;

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
            max_n = max(max_n, matrix[i][j]);
            min_n = min(min_n, matrix[j][i]);

            if (max_n == min_n)
            {
                cout << "r = " << i << " c = " << j << endl;
            }
        }
        cout << "max_n = " << max_n << " min_n = " << min_n << endl;
        max_n = 0;
        min_n = 999999999;
    }

    return 0;
}