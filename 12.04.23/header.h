#include "iostream"
#include "fstream"
#include "string"
#include "cmath"

using namespace std;

void printSubset(int *subset, int size, int d, ofstream &out) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += subset[i];
    }
    int num_digits = floor(log10(abs(sum))) + 1; //округление в меньшую сторону
    if (num_digits == d) {
        for (int i = 0; i < size; i++) {
            out << subset[i] << " ";
        }
        out << endl;
    }
}

void generateSubsets(int *nums, int n, int d, ofstream &out) {
    for (int i = 0; i < (1 << n); i++) { //сдвиг влево на n позиций (просто перебор всех элементов)
        int subset[32];
        int size = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset[size++] = nums[j];
            }
        }
        printSubset(subset, size, d, out);
    }
}
