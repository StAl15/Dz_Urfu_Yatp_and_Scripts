#include <iostream>

using namespace std;

int main()
{
    int num, temp_num, result;
    result = 0;
    cin >> num;
    temp_num = num;
    for (int i = 9; i >= 0; i--) // перебираем цифры по убыванию
    {
        num = temp_num; // возвращаем переменную как было при смене перебираемой цифры
        while (num / 10 > 0 || (num > 0 && num <= 9)) // пока есть цифра или оставшаяся цифра в (0;9]
        {
            if (num % 10 == i) // собираем ответ по убыванию
            {
                result *= 10; // добавляем разряд
                result += i; // добавляем цифру
            }
            num /= 10; // уменьшаем разряд
        }
    }
    cout << result << endl;

    return 0;
}