#include "headers.h"

int main() {

    ifstream file;
    string text;
    LinkedList sentences;
    LinkedList words;
    openFile(file, "text.txt");
    readFile(file, text);
    sentences = splitSentences(text);
    sentences.print();
    words = splitWords(sentences);
    writeAnswer(words);
    cout << "all fine" << endl;

    return 0;
}