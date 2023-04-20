#include "headers1.h"

using namespace std;


int main() {
    ifstream file;
    string text;
    openFile(file, "text.txt");
    readFile(file, text);
    LinkedList sentences = splitSentences(text);
    LinkedList words = splitWords(sentences);
    LinkedList n2_gram_model = buildNgram(words, 2);
//    LinkedList n3_gram_model = buildNgram(words, 3);
    n2_gram_model.print();
//    n3_gram_model.print();

    return 0;
}