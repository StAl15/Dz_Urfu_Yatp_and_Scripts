#include <iostream>
#include <string>

using namespace std;

// string get_s(string s){
//     for (int i = 0; i < s.length(); i++){
        
//     }
// }

int main()
{

    string input;
    getline(cin, input);
    int len = input.length();
    string output;
    for (int i = 0; i < len ; i++){
        if (input[i] != ' ' && input[i+1] != ' '){
            output += input[i];
        }
    }
    cout << output << endl;

    return 0;
}