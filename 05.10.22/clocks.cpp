#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double hours, minutes;
    cin >> hours >> minutes;
    double minutes_to_h = minutes / 5;
    double delta = abs(hours - minutes_to_h);
    int res = delta*30;
    res = min(res, 360-res);
    cout << res << endl;
    return 0;
}