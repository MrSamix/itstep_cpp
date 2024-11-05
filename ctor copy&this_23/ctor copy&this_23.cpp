#include <iostream>
#include "String.h"

using namespace std;

int main() {
    String str1("sdqcg");
    String str2("rgfas34");


    String result = str1 * str2;

    cout << "After mult str1 and str2: " << endl;
    result.print();

    str2.input();
    str2.print();
}