#include <iostream>

using namespace std;

int main()
{

   int radius, square_storona;
   cin >> radius >> square_storona;
   double s_round = 3.14 * radius * radius;
   double s_square = square_storona * square_storona;
   double res = s_square;

   if (s_round < s_square)
   {
      res = abs(s_round - s_square);
   }

   cout << res << endl;

   return 0;
}
