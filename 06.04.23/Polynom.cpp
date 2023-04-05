#include "header.h"

LinkedList LinkedList::operator*(const LinkedList &lst) {
    LinkedList res;

    for (Node *ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
        int currDegree = ptr1->degree;
        int currKoef = ptr1->koef;
        for (Node *ptr2 = lst.head; ptr2 != NULL; ptr2 = ptr2->next) {
            res.appendBack(currDegree + ptr2->degree, currKoef * ptr2->koef);
        }
    }
    return res;
}

LinkedList LinkedList::operator+(const LinkedList &lst) {
    LinkedList res;
    for (Node *ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
        int currDegree = ptr1->degree;
        int currKoef = ptr1->koef;
        bool found = false;
        for (Node *ptr2 = lst.head; ptr2 != NULL; ptr2 = ptr2->next) {
            if (currDegree == ptr2->degree) {
                if (currKoef + ptr2->koef != 0) res.appendBack(currDegree, currKoef + ptr2->koef);
                found = true;
            }
        }
        if (!found) {
            res.appendBack(currDegree, currKoef);
        }
    }
    return res;
}

void fill(LinkedList &lst) {
    int n;
    cout << "input your count n: " << endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int deg, koef;
        cout << "input deg, koef: " << endl;
        cin >> deg >> koef;
        lst.appendBack(deg, koef);
    }
}


LinkedList LinkedList::filter() {
    LinkedList res;
//    LinkedList old;

    for (Node *ptr1 = head; ptr1 != NULL && !res.isInList(ptr1->degree); ptr1 = ptr1->next) {
        int currDegree = ptr1->degree;
        int currKoef = ptr1->koef;
        int tmp = currKoef;
        for (Node *ptr2 = head; ptr2 != NULL && ptr1 != ptr2; ptr2 = ptr2->next) {
            if (currDegree == ptr2->degree) {
                tmp += ptr2->koef;
            }
        }

        res.appendBack(currDegree, tmp);

//        old.appendBack(currDegree, tmp);
    }
    return res;
}