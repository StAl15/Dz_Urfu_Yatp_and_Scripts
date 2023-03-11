#include <iostream>

using namespace std;

int main()
{

    /*
    Два варианта решения задачи: перевести в unix и считать традиционно
    */

    int day, month, year;
    cin >> day >> month >> year;

    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int d = 0;

    for (int i = 0; i < month - 1; i++) // не считаем конечный месяц, просто прибавим заданный день
    {
        d += months[i];
    }
    if (month == 1) cout << day << endl;
    else if ((year % 10) % 4 == 0 && month != 1) cout << day+d+1 << endl;
    else cout << day + d << endl;

    return 0;
}