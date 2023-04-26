#include "header.h"

LinkedList LinkedList::operator+(LinkedList lst) {
    LinkedList r;
    r.setRows(rows);
    r.setColumns(cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            r.add_node(i, j, getValue(i, j) + lst.getValue(i, j));
        }
    }
    return r;
}

LinkedList LinkedList::operator-(LinkedList lst) {
    LinkedList r;
    r.setRows(rows);
    r.setColumns(cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            r.add_node(i, j, getValue(i, j) - lst.getValue(i, j));
        }
    }
    return r;
}

LinkedList LinkedList::operator*(LinkedList lst) {
    LinkedList r;
    r.setRows(rows);
    r.setColumns(cols);
    int tmp;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < lst.cols; j++) {
            tmp = 0;
            for (int k = 0; k < cols; k++) {
                tmp += getValue(i, k) * lst.getValue(k, j);
            }
            r.add_node(i, j, tmp);
        }
    }

    return r;
}

LinkedList LinkedList::operator*(int n) {
    LinkedList r;
    r.setRows(rows);
    r.setColumns(cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            r.add_node(i, j, getValue(i, j) * n);
        }
    }
    return r;
}

