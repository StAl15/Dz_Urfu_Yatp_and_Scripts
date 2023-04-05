#include "headers.h"

int main() {

    ifstream file;
    string text;
    LinkedList sentences;
    LinkedList words;
    openFile(file, "text.txt");
    readFile(file, text);
    cout << text << endl;
    sentences = splitSentences(text);
    words = splitWords(sentences);
    writeAnswer(words);
    cout << "all fine" << endl;

    return 0;
}