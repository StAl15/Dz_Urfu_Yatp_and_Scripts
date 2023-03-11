#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

void addTextInFile(string text) {
    ofstream out("output.txt", ios::app); // поток для записи

    if (out.is_open()) {
        out << text;
    }
    out.close();
}

void format(double **&matrix, int &n, int &m) {

    //Создаем файловый поток и связываем его с файлом
    ifstream in("input.txt");


    if (in.is_open()) {
        //Если открытие файла прошло успешно

        //Вначале посчитаем сколько чисел в файле
        int count = 0;// число чисел в файле
        int temp;//Временная переменная

        while (!in.eof())// пробегаем пока не встретим конец файла eof
        {
            in >> temp;//в пустоту считываем из файла числа
            count++;// увеличиваем счетчик числа чисел
        }

        //Число чисел посчитано, теперь нам нужно понять сколько
        //чисел в одной строке
        //Для этого посчитаем число пробелов до знака перевода на новую строку

        //Вначале смотрим начало файла
        in.seekg(0, ios::beg);
        in.clear();

        //Число пробелов в первой строчке вначале равно 0
        int count_space = 0;
        char symbol;
        while (!in.eof())//на всякий случай цикл ограничиваем концом файла
        {
            //теперь нам нужно считывать не числа, а посимвольно считывать данные
            in.get(symbol);//считали текущий символ
            if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
            if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
        }
        //Опять переходим в потоке в начало файла
        in.seekg(0, ios::beg);
        in.clear();

        n = count / (count_space + 1);//число строк
        m = count_space + 1;//число столбцов на единицу больше числа пробелов
        matrix = new double *[n];
        for (int i = 0; i < n; i++) matrix[i] = new double[m];

        //Считаем матрицу из файла
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                in >> matrix[i][j];

        in.close();//под конец закроем файла
    } else {
        cout << "Файл не найден.";
    }
}


int main() {

//    read(matrix, size);
    double **matrix;
    int n, m;
    format(matrix, n, m);

    //Выведем матрицу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << "\t";
        cout << "\n";
    }

    double sAbs = 0;

    double **res;
    res = new double *[n];
    for (int i = 0; i < n; i++) res[i] = new double[m];

    for (int i = 1; i < n-1; i++) { //row
        for (int j = 1; j < m-1; j++) { //column
            double s = 0;
            int c = 0;

            if (matrix[i - 1][j] && i != 0) {
                s += matrix[i - 1][j];
                c++;
            }
            if (matrix[i + 1][j] && i != n - 1) {
                s += matrix[i + 1][j];
                c++;
            }
            if (matrix[i][j - 1] && j != 0) {
                s += matrix[i][j - 1];
                c++;
            }
            if (matrix[i][j + 1] && j != m - 1) {
                s += matrix[i][j + 1];
                c++;
            }

            res[i][j] = s / c;
        }
    }


    for (int i = 1; i < n; i++) { //row
        for (int j = 0; j < i - 1; j++) { //column
            sAbs += abs(res[i][j]);
        }
    }

//    addTextInFile("MATRIX\n");
    for (int i = 0; i < n; i++) { //row
        for (int j = 0; j < m; j++) { //column
//            addTextInFile(to_string(res[i][j]) + "\t");
            cout << res[i][j] << "\t";
        }
        cout << "\n";
//        addTextInFile("\n");
    }
    cout <<"s: " << sAbs << endl;

//    addTextInFile("ABSOLUTE_SUM\n");
//    addTextInFile(to_string(sAbs) + "\n");


    return 0;
}