#include "header.h"

int main() {

    int n, d;
    cout << "Kalichestvo nechesti: ";
    cin >> n;
    int nums[32];
    cout << "Elementi nechesti: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Kolichestvo cifr nechesti: ";
    cin >> d;
    ofstream out("subsets.txt");
    generateSubsets(nums, n, d, out);
    out.close();
    return 0;
}