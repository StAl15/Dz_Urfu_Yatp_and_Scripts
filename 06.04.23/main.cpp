#include "header.h"

int main() {

    LinkedList lst1;
    LinkedList lst2;

    //Для ручного ввода значений
//    cout << "fill first" << endl;
//    fill(lst1);
//    cout << "fill sec" << endl;
//    fill(lst2);

    // Тест
    lst1.appendBack(5, 6);
    lst1.appendBack(3, 4);
    lst1.appendBack(1, 6);

    lst2.appendBack(5, 6);
    lst2.appendBack(1, 6);

    lst1.print();
    lst2.print();
    LinkedList rS = lst1 + lst2;
    LinkedList rM = lst1 * lst2;
//    rM = rM.filter();
    rS.print();
    rM.print();

    return 0;
}