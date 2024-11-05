#pragma once
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

class String {
private:
    char* str;
    size_t length;
    int id = ++counter;
    static size_t counter;

public:
    String() : String(80) {}

    String(size_t len) : length(len) {
        str = new char[length + 1];
        if (str != nullptr) {
            str[0] = '\0';
        }
    }

    String(const char* struser) : length(struser ? strlen(struser) : 0) {
        str = new char[length + 1];
        if (struser) {
            strcpy_s(str, length + 1, struser);
        }
        else {
            str[0] = '\0';
        }
    }

    String(const String& other) : length(other.length) {
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }

    String& operator=(const String& other);
    ~String();

    inline const char* getStr() const;
    const size_t& getLength() const;
    void setStr(const char* str);
    void input();
    void print() const;
    static size_t getCounter();


    String operator*(const String& other) const;
};

inline const char* String::getStr() const
{
    return this->str;
}

inline const size_t& String::getLength() const {
    return this->length;
}

inline void String::print() const {
    cout << endl << endl;
    cout << "Result: " << str << endl; 
    cout << "Length: " << length << endl;
}

inline size_t String::getCounter() {
    return counter;
}