#include <cstddef>
#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <cstring>
#include <fstream>

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

using namespace std;

void replaceSymbols(string &s) {
    char stop[] = {'!', ' ', '.', '?', '*', '(', ')'};
    for (int i = 0; i < NELEMS(stop); i++) {
        replace(s.begin(), s.end(), stop[i], ' '); // replace all 'x' to 'y'
    }
}

bool check(string s) {
    string stop[] = {"!", " ", ".", "?", "*", "(", ")"};
    for (int i = 0; i < NELEMS(stop); i++) {
        if (s == stop[i])
            return false;
    }
    return true;
}

int main() {
    const int len = 255;
    string word;
    char line[len];
    char line_[len];
    map<string, int> rezerved_words;

    string text = "";
    string reserved_words_ = "";
    ifstream fin("text.txt");
    if (!fin) {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }
    ifstream fin_("reserved_words.txt");
    if (!fin_) {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }

    int count = 0;

    while (!fin.eof()) {
        fin.getline(line, len);
        text += line;
    }


    while (!fin_.eof()) {
        fin_.getline(line_, len);
        reserved_words_ += line_;
    }


    replaceSymbols(text);
    string word_ = "";
    for (const auto &elem: reserved_words_) {
        if (elem != ' ') {
            word_ += elem;
        } else {
            if (!rezerved_words[word_]) {
                rezerved_words[word_] = 0;
            }
            word_ = "";
        }
    }

    for (const auto &elem: text) {
        if (elem != ' ') {
            word += elem;
        } else {
            if (rezerved_words.find(word) != rezerved_words.end()) rezerved_words[word]++;
            word = "";
        }
    }

    for (const auto &elem: rezerved_words) {

        if (check(elem.first)) cout << elem.first << " : " << elem.second << endl;
    }
    return 0;
}