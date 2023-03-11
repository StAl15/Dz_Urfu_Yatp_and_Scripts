#include "header.h"

int main() {
    int c = 0;
    Line_s line;
    line.coefs = new double[3];
    cout << "Input 3 coefs" << endl;
    while (c != 3) {
        cin >> line.coefs[c];
        c++;
    }
    Line_s line_;
    line_.coefs = new double[3];
    cout << "Input again 3 coefs" << endl;
    int c_ = 0;
    while (c_ != 3) {
        cin >> line_.coefs[c_];
        c_++;
    }

    Point common;

    Line L(line);
    L.setLine(line);
    bool result = L.hasCommonPoint(line_, common);
    if (result) {
        cout << "Yes oni peresekautsya v tochke: " << "x=" << common.x << " y=" << common.y << endl;
    } else cout << "No, Ne peresekautsya " << endl;

}