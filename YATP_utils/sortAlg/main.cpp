#include <iostream>

using namespace std;


void Swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

void printArr(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "\t";
    }
}


void bubbleSort(int *arr, int length) {

    for (int i = 0; i < length; i++) { //i с какого индекса начинать сортировать
        for (int j = (length - 1); j >= (i + 1); j--) { //j проходится с конца до i
            if (arr[j - 1] >
                arr[j]) { // если предыдущий больше текущего (но тут как бы следующий больше текущего мы типа наоборот идем)
                Swap(arr[j - 1], arr[j]); //меняем их местами
            }
        }
    }
}

void sheakerSort(int *arr, int length) {
    bool sort_or_not = true; //flag отсортировано ли
    int right = length - 1; // правая граница (ну длина массива логично)
    int left = 1; // левая тоже логично начало (1 потому что с предыдущим сравниваем)
    do {
        sort_or_not = true; // ставим что сортировано но дальше проверяем
        for (int i = left; i <= right; i++) { // проходимся от левой границы до правой (из начала в конец)
            if (arr[i - 1] > arr[i]) { // если предыдущее больше текущего
                Swap(arr[i - 1], arr[i]); //меняем местами
                sort_or_not = false; // ставим флаг что еще не отсортировано
            }
        }
        right--; //уменьшаем правую границу
        for (int i = right; i >= left; i--) { // затем идем от правой до левой (из конца в начло)
            if (arr[i] < arr[i - 1]) { //если предыдущее больше текущего
                Swap(arr[i], arr[i - 1]); //меняем местами
                sort_or_not = false; // ставим флаг что еще не отсортировано
            }
        }
        left++; //увеличиваем левую границу
    } while (!sort_or_not); //делаем так пока флаг не отсортировано
}

void selectionSort(int *arr, int length) {
    for (int i = 0; i < length - 1; ++i) { //проходимся до конца массива
        int min_index = i; //ставим минимальный индекс
        for (int j = i + 1; j < length; ++j) { // проходимся от i до конца массива
            if (arr[min_index] > arr[j])
                min_index = j; // если текущий элекмент как бы меньше начального то начальный будет текущим
        }
        Swap(arr[min_index], arr[i]);
    }
}

void insertionSort(int *arr, int length) {
    for (int i = 1; i < length; ++i) { //проходимся до конца массива
        int sorted = i - 1; //запоминаем предыдущее
        while (sorted > -1 && arr[sorted] > arr[sorted + 1]) { //пока предыдущее ≥ 0 и предыдущее больше следующего
            Swap(arr[sorted], arr[sorted + 1]); //меняем местами предыдущее и следующее до того момента
            sorted--; //уменьшаем предыдущее постепенно до момента пока не достигнем меньшего элемента
        }
    }
}

int partOfSortHoara(int *arr, int left, int right) {
    int pivot = arr[(left + right) / 2]; //middle
    while (left <= right) { // пока не приблизились к правой части
        while (arr[left] < pivot) ++left; //пока левый элемент меньше середины идем дальше слева
        while (arr[right] > pivot) --right; // пока правый элемент больше середины идем дальше справа
        if (left <= right) {
            Swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    }
    return left;
}


void quickSortHoar(int *arr, int start, int end) {
    if (start >= end) return; //если дошли до границы заканчиваем
    int rightStart = partOfSortHoara(arr, start, end); //правая часть
    quickSortHoar(arr, start, rightStart - 1); //сначала от старта до типа половины/правой части
    quickSortHoar(arr, rightStart, end); //от левой части типа до конца
}

void quickSortHoar(int *arr, int length) {
    quickSortHoar(arr, 0, length - 1);
}




int main() {
    int m = 14;
    int *pArray = new int[m]{-2, 1, 23, 0, 44, 66, 22, 4, 7, -5, 22, 34, 34, 23};

//    bubbleSort(pArray, m);
//    sheakerSort(pArray, m);
//    selectionSort(pArray, m);
//    insertionSort(pArray, m);
//    quickSortHoar(pArray, m);

    printArr(pArray, m);


    // HoareSort(pArray, pArray.size(), 0 , -1);

    return 0;
}