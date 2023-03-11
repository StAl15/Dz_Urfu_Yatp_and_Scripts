#include <iostream>

using namespace std;

int main()
{

    int N, M, x, y;
    cin >> N >> M >> x >> y;

    string s;
    getline(cin, s);


    int min_board;
    int big_board;

    if (N >= M)
    {
        min_board = M;
        big_board = N;
    }
    else
    {
        min_board = N;
        big_board = M;
    }

    int delta_second_big = min_board - x;
    int delta_second_min = big_board - y;

    int res1, res2, res;

    if (x >= y)
    {
        res1 = y;
    }
    else
    {
        res1 = x;
    }

    if (delta_second_big > delta_second_min)
    {
        res2 = delta_second_min;
    }
    else
    {
        res2 = delta_second_big;
    }

    if (res1 > res2)
    {
        res = res2;
    }
    else
        res = res1;

    cout << res << endl;

    return 0;
}