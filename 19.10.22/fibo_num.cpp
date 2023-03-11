#include <iostream>
#include <string>

using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        int r = fib(n - 1) + fib(n - 2);
        return r;
    }
}

double get_len(double n){
    double c = 0;
    while(n>0){
        c++;
        n/=10;
    }
    return c;
}




int main()
{
    double index;
    cin >> index;
    string r = "";
    cout << "фрагмент фибоначи"<<endl;
    cout << "0112358132134558914423337761098715972584418167651094617711286574636875025121393\n" << endl;
    for (int i = 0; i <= index; i++){
        r+=to_string(fib(i));
    }
    r=r[index];
    cout << r << endl;
    


    return 0;
}