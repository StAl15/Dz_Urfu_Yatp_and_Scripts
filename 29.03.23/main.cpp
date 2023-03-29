#include "headers.h"


int main() {

    int n, k, m;
    cout << "Нелюди: ";
    cin >> n;
    cout << "Людь k: ";
    cin >> k;
    cout << "Словцы m: ";
    cin >> m;

    LinkedList list;
    for (int i = 1; i <= n; i++) {
        list.add(i);
    }

    int result = list.josephus(k, m);
    cout << "Ведущий нелюдь # " << result << endl;
    return 0;

}

/*
 ТЕСТОВЫЕ ДАННЫЕ
 n k m
 10 4 2 -> 6
 5 2 3 -> 5
 */
