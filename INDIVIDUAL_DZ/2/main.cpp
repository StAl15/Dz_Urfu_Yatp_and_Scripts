#include <iostream>

using namespace std;

class MyString {
private:
    char *str;
    int length;
public:
    MyString() : str(new char[1]), length(0) {
        str[0] = '\0';
    }

    MyString(const char *s) : length(0) {
        while (s[length] != '\0') {
            ++length;
        }
        str = new char[length + 1];
        for (int i = 0; i <= length; ++i) {
            str[i] = s[i];
        }
    }

    MyString(const MyString &other) : length(other.length), str(new char[length + 1]) {
        for (int i = 0; i <= length; ++i) {
            str[i] = other.str[i];
        }
    }

    ~MyString() {
        delete[] str;
    }

    int getLength() const {
        return length;
    }

    const char *getStr() const {
        return str;
    }

    MyString &operator=(const MyString &other) {
        if (this != &other) {
            MyString temp(other);
            char *tempStr = str;
            str = temp.str;
            temp.str = tempStr;
            length = other.length;
        }
        return *this;
    }

    MyString operator+(const MyString &other) const {
        MyString result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];
        for (int i = 0; i < length; ++i) {
            result.str[i] = str[i];
        }
        for (int i = 0; i <= other.length; ++i) {
            result.str[length + i] = other.str[i];
        }
        return result;
    }

    MyString substr(int k, int p) const {
        if (p < 0 || p >= length || k <= 0) {
            return MyString();
        }
        int len = (k < length - p) ? k : length - p;
        MyString result;
        result.length = len;
        result.str = new char[len + 1];
        for (int i = 0; i < len; ++i) {
            result.str[i] = str[p + i];
        }
        result.str[len] = '\0';
        return result;
    }
};

int main() {
    // тестирование конструкторов и методов класса
    MyString s1("Hello");
    MyString s2(" world");
    MyString s3 = s1 + s2;
    cout << "s1: " << s1.getStr() << endl;
    cout << "s2: " << s2.getStr() << endl;
    cout << "s3: " << s3.getStr() << endl;
    MyString s4 = s3.substr(5, 4);
    cout << "s4: " << s4.getStr() << endl;

    // тестирование операторов
    MyString s5("foo");
    MyString s6("bar");
    MyString s7 = s5 + s6;
    cout << "s5 + s6 = " << s7.getStr() << endl;

    s5 = s6;
    cout << "s5 = s6, s5: " << s5.getStr() << endl;

    // тестирование выделения подстроки
    MyString s8("Hello, world!");
    MyString s9 = s8.substr(7, 5);
    cout << "s9: " << s9.getStr() << endl;

    return 0;
}