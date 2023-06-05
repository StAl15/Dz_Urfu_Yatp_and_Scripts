#include <iostream>

using namespace std;

// Функция для вычисления множества цифр, входящих в запись числа
int digits(int x) {
    int d = 0;
    while (x > 0) {
//        d |= 1 << (x % 10);
        d |= (1 << (x % 10));
        x /= 10;
    }
    return d;
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[32];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Вычисление множеств цифр для всех чисел
    int masks[32];
    for (int i = 0; i < n; i++) {
        masks[i] = digits(a[i]);
    }

    // Перебор всех возможных подмножеств чисел
    for (int mask = 0; mask < (1 << n); mask++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                count++;
            }
        }
        if (count == k) { // Если подмножество имеет k элементов
            bool is_same_digits = true;
            int d = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) { // Если i-й элемент входит в подмножество
                    if (d == 0) { // Если это первый элемент, записываем его множество цифр
                        d = masks[i];
                    } else {
                        if (d != masks[i]) { // Если множества цифр не совпадают, прерываем проверку
                            is_same_digits = false;
                            break;
                        }
                    }
                }
            }
            if (is_same_digits) { // Если все числа в подмножестве имеют одинаковые множества цифр, выводим его
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        cout << a[i] << " ";
                    }
                }
                cout << endl;
            }
        }
    }

    return 0;
}