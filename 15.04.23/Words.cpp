#include "headers1.h"

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
            sentences.append(sentence + ".", 0);
            sentence.clear();
        }
    }
    return sentences;
}

LinkedList splitWords(LinkedList &sentences) {
    LinkedList words;
    string word = "";
    for (Node *ptr = sentences.getHead(); ptr != NULL && ptr->key != " ."; ptr = ptr->next) {
        string currentSentence = ptr->key;
        for (const auto i: currentSentence) {
            if (isLetterOrApp(i)) {
                word += i;
            } else {
                words.append(StringToLowerCase(word), 0);
                word = "";
            }
        }
//        words.append(".", 0);
    }
    return words;
}

LinkedList buildNgram(LinkedList words_list, int n) {
    LinkedList n_gram_model;
    Node *curr = words_list.getHead();
    while (curr != nullptr) {
        string key = "";
        Node *next = curr;
        for (int i = 0; i < n; i++) {
            if (next == nullptr) {
                break;
            }
            key += next->key + " ";
            next = next->next;
        }
        if (key != "" && !n_gram_model.isInList(key)) {
            n_gram_model.increment(key);
        }
        curr = curr->next;
    }
    return n_gram_model;

}

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