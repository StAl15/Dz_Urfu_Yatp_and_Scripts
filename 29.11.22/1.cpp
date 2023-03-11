// Проверить, является ли заданная матрица целых чисел A размера n*n «магическим квадратом» (т.е. суммы чисел в каждой строке, столбце и на двух диагоналях одинаковы).

#include <iostream>

using namespace std;

int main()
{

    int size;
    cin >> size;
    int matrix[size][size];

    int curr_sum_str1 = 0;
    int curr_sum_str2 = 0;

    //цикл по переменной i, в которой перебираем строки матрицы
    for (int i = 0; i < size; i++)
        //цикл по переменной j, в котором перебираем элементы внутри строки (или проще говоря по столбцу)
        for (int j = 0; j < size; j++)
            cin >> matrix[i][j]; //ввод очередного элемента матрицы

    for (int i = 0; i < size; i++)
    {
        //цикл по переменной i, в котором перебираем строки матрицы
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << "\t"; //вывод очередного элемента матрицы
        cout << endl;                     //переход на новую строку после вывода всех элементов строки
    }

    // verify strs
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size; j++)
        {
            curr_sum_str1 += matrix[i][j];
            curr_sum_str2 += matrix[i + 1][j];
        }
        if (curr_sum_str1 != curr_sum_str2)
        {
            cout << "Not equal stroke " << curr_sum_str1 << " " << curr_sum_str2 << endl;
            cout << "Not magic square" << endl;
            return 0;
        }
        curr_sum_str1 = curr_sum_str2 = 0;
    }

    // columns
    for (int j = 0; j < size - 1; j++)
    {
        // stroke
        for (int i = 0; i < size; i++)
        {
            curr_sum_str1 += matrix[i][j];
            curr_sum_str2 += matrix[i][j + 1];
        }
        // cout << "sum1(column) = " << curr_sum_str1 << " sum2(column) = " << curr_sum_str2 << endl;
        if (curr_sum_str1 != curr_sum_str2)
        {
            cout << "Not equal column " << curr_sum_str1 << " " << curr_sum_str2 << endl;
            cout << "Not magic square" << endl;

            return 0;
        }
        curr_sum_str1 = curr_sum_str2 = 0;
    }

    // diagonals
    for (int i = 0; i < size; i++)
    {
        curr_sum_str1 += matrix[i][i];
        curr_sum_str2 += matrix[i][size - 1 - i];
    }
    if (curr_sum_str1 != curr_sum_str2)
    {
        cout << "Not equal diagonal " << endl;
        cout << "Not magic square" << endl;

        return 0;
    }

    cout << "Equal columns and strokes " << endl;

    return 0;
}