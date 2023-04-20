#include "headers.h"

void openFile(ifstream &file, string name) {
    file.open(name);
}

void readFile(ifstream &file, string &text) {
    while (!file.eof()) {
        string c = "";
        file >> c;
        text += c + " ";
    }
    file.close();
}

bool isZnak(char c) {
    return c == '!' || c == '.' || c == '?' || c == ';' || c == ':' || c == '(' || c == ')';
}

bool isLetterOrApp(char c) {
    return c != ' ' && (isalpha(c) || c == '\'');
}

string StringToLowerCase(string &data) {
    string r = "";
    for (const auto i: data) {
        r += tolower(i);
    }
    return r;
}

LinkedList splitSentences(string &text) {
    LinkedList sentences;
    string sentence = "";
    for (const auto i: text) {
        if (!isZnak(i)) {
            sentence += i;
        } else {
            sentences.append(sentence + ".");
            sentence.clear();
        }
    }
    return sentences;
}

LinkedList splitWords(LinkedList &sentences) {
    LinkedList words;
    string word = "";
    for (Node *ptr = sentences.getHead(); ptr != NULL && ptr->data != " ."; ptr = ptr->next) {
        string currentSentence = ptr->data;
        for (const auto i: currentSentence) {
            if (isLetterOrApp(i)) {
                word += i;
            } else {
                words.append(StringToLowerCase(word));
                word = "";
            }
        }
        words.append(".");
    }
    return words;
}

void writeAnswer(LinkedList &words) {
    ofstream file;
    file.open("answer.txt");
    for (Node *ptr = words.getHead(); ptr != NULL; ptr = ptr->next) {
        file << ptr->data << " ";
    }
    file.close();

}
