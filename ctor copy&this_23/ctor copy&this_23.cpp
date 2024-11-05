#include <iostream>
#include "String.h"

using namespace std;

int main() {
    String str1("hello");
    String str2("world");
    String str3(80);

    String res = str1 * str2;

    cout << "After mult str1 and str2: ";
    res.print();

    str3.input();
    str3.print();
    string res_str3 = str3.getStr();
    size_t capacity_str3 = str3.getLength();
    cout << "Str: " << res_str3 << "\tCapacity = " << capacity_str3 << endl;
    str3.setStr("Hello world!");
    str3.print();
}