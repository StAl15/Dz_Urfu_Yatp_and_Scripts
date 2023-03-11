#include <iostream>

using namespace std;


int *shieve(int n) {
    int arr[] = {};
    arr[1] = 0;
    for (int k = 2; k <= n; ++k)
        arr[k] = 1;

    for (int k = 2; k * k <= n; ++k) {
        if (arr[k] == 1) {
            for (int l = k * k; l <= n; l += k) {
                arr[l] = 0;
            }
        }
    }
    return arr;
}

int LinearSearch(int array[], int length, int key) {
    for (int i = 0; i < length; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int array[], int length, int key) {
    int left = 0;
    int right = length;
    int midd = 0;
    while (true) {
        midd = (left + right) / 2;

        if (key < array[midd])       // если искомое меньше значения в ячейке
            right = midd - 1;      // смещаем правую границу поиска
        else if (key > array[midd])  // если искомое больше значения в ячейке
            left = midd + 1;    // смещаем левую границу поиска
        else                       // иначе (значения равны)
            return midd;           // функция возвращает индекс ячейки

        if (left > right)          // если границы сомкнулись
            return -1;
    }
}

int BinaryRecursion(int array[], int left, int right, int key) {

    int middle = left + (right - left) / 2;

    if (key == array[middle])
        return middle;

    if (key < array[middle])
        return BinaryRecursion(array, left, middle - 1, key);

    if (key > array[middle])
        return BinaryRecursion(array, middle + 1, right, key);

    if (right < left)
        return -1;

}

int InterpolarSearch(int array[], int length, int key) {
    int left = 0;
    int right = length - 1;
    int middle = 0;
    while (true) {
        double factor = (right - left) / (array[right] - array[left]);
        int diff = key - array[left];
        //вероятность умноженная на расстояние (почему - то если переставить местами числители он не робит)
        middle = left + factor * diff;

        if (key == array[middle]) {
            return middle;
        }
        if (key < array[middle]) {
            right = middle - 1;
        }
        if (key > array[middle]) {
            left = middle + 1;
        }
        if (left == right) {
            if (array[left] == key) return left;
            return -1;
        }
    }
}

int main() {
    int arr[] = {1, 2, 4, 10, 20, 30};

//    for (int i: arr) {
//        cout << "value: " + to_string(i) << " Interpolar: " << InterpolarSearch(arr, 7, i) << endl;
//        cout << "value: " + to_string(i) << " Bin: " << BinarySearch(arr, 7, i) << endl;
//        cout << "value: " + to_string(i) << " BinRec: " << BinaryRecursion(arr, 0, 7, i) << endl;
//
//    }




    return 0;
}
