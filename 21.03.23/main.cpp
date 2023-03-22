#include "header.h"

int main() {

    ifstream file;
    int countA = 0;
    int countVpMg = 0;
    ModelMnogoug *mg;
    ModelMnogoug *mgvp;
    openFile(file, "mgs.txt");
    cout << "file opend" << endl;
    readFile(file, mg, countA);
    cout << "file read" << endl;
    getVipuclMg(mg, mgvp, countA, countVpMg);
    cout << "geting vipuc" << endl;
    sortMg(mgvp, countVpMg);
    cout << "sorted" << endl;
    writeAnswer(mgvp, countVpMg);
    cout << "wrote answer" << endl;
    for (int i = 0; i < countVpMg; i++) {
        cout << mgvp[i].countN << endl;
        cout << Mnogoug(mgvp[i].countN, mgvp[i].points).isVipucl() << endl;
        cout << Mnogoug(mgvp[i].countN, mgvp[i].points).getDiagonal() << endl;
    }


    return 0;
}