#include <iostream>

using namespace std;


double* get_pascal(int n)
{
    double* arr = new double[n+1]; //набор значений
    for (int i = 0; i < n; i++){
        arr[i] = 0; //заполняем настолько насколько нужно
    }
    arr[0] = 1; //первый элемент треугольника паскаля
    for (int j = 1; j <= n ; j++){ // ряд
        for (int i = j; i >=1; i--){ // позиция справа налево
            arr[i] = arr[i-1] + arr[i]; // суммируем предыдущие 
        }
    }
    return arr;
}

int main()
{

    int n;
    cin >> n;
    double* res = get_pascal(n);
    for (int i = 0; i <= n; i++){
        cout << " " << res[i] << " ";
    }

    return 0;
}