#include "String.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;


String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        if (str != nullptr) {
            strcpy_s(str, length + 1, other.str);
        }
    }
    return *this;
}

String::~String() {
    if (str != nullptr) {
        delete[] str;
        str = nullptr;
    }
    --counter;
}

void String::setStr(const char* str) {
    if (this->str != nullptr)
        delete[] this->str;
    size_t size = strlen(str) + 1;
    this->str = new char[size];
    strcpy_s(this->str, size, str);
}

void String::input() {
    cout << "Enter a string up to " << length << " characters: ";
    cin.getline(str, length + 1);
}

String String::operator*(const String& other) const
{
    char commonChars[256] = {};
    int commonLength = 0;

    for (size_t i = 0; i < this->length; ++i) {
        char currentChar = this->str[i];

        bool isAlreadyAdded = false;
        for (int k = 0; k < commonLength; ++k) {
            if (commonChars[k] == currentChar) {
                isAlreadyAdded = true;
                break;
            }
        }

        if (!isAlreadyAdded) {
            for (size_t j = 0; j < other.length; ++j) {
                if (other.str[j] == currentChar) {
                    commonChars[commonLength++] = currentChar;
                    break;
                }
            }
        }
    }
    commonChars[commonLength] = '\0';
    return String(commonChars);
}

size_t String::counter = 0;