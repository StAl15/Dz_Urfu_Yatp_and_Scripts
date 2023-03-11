#include <iostream>

using namespace std;

string ToRoman(int number)
{
    if (number < 1) return "";
    if (number >= 1000) return "M" + ToRoman(number - 1000);
    if (number >= 900) return "CM" + ToRoman(number - 900);
    if (number >= 500) return "D" + ToRoman(number - 500);
    if (number >= 400) return "CD" + ToRoman(number - 400);
    if (number >= 100) return "C" + ToRoman(number - 100);
    if (number >= 90) return "XC" + ToRoman(number - 90);
    if (number >= 50) return "L" + ToRoman(number - 50);
    if (number >= 40) return "XL" + ToRoman(number - 40);
    if (number >= 10) return "X" + ToRoman(number - 10);
    if (number >= 9) return "IX" + ToRoman(number - 9);
    if (number >= 5) return "V" + ToRoman(number - 5);
    if (number >= 4) return "IV" + ToRoman(number - 4);
    if (number >= 1) return "I" + ToRoman(number - 1);
    else return "какую-то фигню на вход получаю";
    /*
    99
    90 - XC + func(99-90)
    XC + IX
    XCIX

    83
    50 - L + 33
    33 - L + X + 23
    23 - L + X + X + 13
    13 - L + X + X + X + 3
    3 - L + X + X + X + I + I + I
    LXLIII
    */
}

int main()
{

    int number;
    cin >> number;
    if ((number < 0) || (number > 3999)) cout << "Пожалуйста введите число от 0 до 3999, иначе офигеете от ответа" << endl;
    cout << ToRoman(number) << endl;

    return 0;
}