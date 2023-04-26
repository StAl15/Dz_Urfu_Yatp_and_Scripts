#include "header.h"

int main() {

    LinkedList testArr;
    testArr.setRows(3);
    testArr.setColumns(3);
    testArr.add_node(0, 0, 1);
    testArr.add_node(0, 1, 2);
    testArr.add_node(0, 2, 6);

    testArr.add_node(1, 0, 0);
    testArr.add_node(1, 1, 0);
    testArr.add_node(1, 2, 2);

    testArr.add_node(2, 0, 0);
    testArr.add_node(2, 1, 0);
    testArr.add_node(2, 2, 7);

    LinkedList testArr1;
    testArr1.setRows(3);
    testArr1.setColumns(3);
    testArr1.add_node(0, 0, 1);
    testArr1.add_node(0, 1, 2);
    testArr1.add_node(0, 2, 6);

    testArr1.add_node(1, 0, 0);
    testArr1.add_node(1, 1, 7);
    testArr1.add_node(1, 2, 3);

    testArr1.add_node(2, 0, 0);
    testArr1.add_node(2, 1, 0);
    testArr1.add_node(2, 2, 4);

    cout << "first: " << endl;
    testArr.print();
    cout << "second: " << endl;;
    testArr1.print();

    cout << "res: " << endl;
    LinkedList r;
//    r = testArr + testArr1;
//    r = testArr - testArr1;
    r = testArr * 2;
//    r = testArr * testArr1;
    r.print();

    return 0;
}