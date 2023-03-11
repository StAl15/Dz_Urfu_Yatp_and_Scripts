#include <iostream>

using namespace std;

int main()
{

    int age;
    cin >> age;

    if (age % 10 == 0 || (age % 100 >= 11 && age % 100 <= 19) || (age % 10 <= 9 && age % 10 >= 5))
    {
        cout << age << " лет";
    }
    else if (age % 10 == 1)
    {
        cout << age << " год";
    }
    else
    {
        cout << age << " года";
    }

    return 0;
}