#include <iostream>

using namespace std;

//typedef long long ll;

double count_lucky_tickets(int n, int s) {
    if (n == 0 && s == 0) {
        return 1;
    }
    if (n == 0 || s < 0) {
        return 0;
    }
    double cnt = 0;
    for (int i = 0; i <= 9; i++) {
        cnt += count_lucky_tickets(n - 1, s - i);
    }
    return cnt;
}

int main() {
    int n, s; //n<50 s<1000
    cin >> n >> s;

    cout << count_lucky_tickets(n, s) * count_lucky_tickets(n, s);


    return 0;
}