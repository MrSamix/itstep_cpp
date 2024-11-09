#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
    Vector a(10, 3);
    a.print();

    a[0] = 10;
    a.print();
    for (size_t i = 0; i < a.getSize(); i++)
    {
        a[i] = (i + 1) * 10;
    }
    a.print();
    cout << a[222] << endl;

    Vector b = a(2, 4);
    b.print();
    b.pushBack(33);
    b.print();
    b.pushBack(43);
    b.print();
    b.pushBack(53);
    b.print();
    b.pushBack(63);
    b.print();



    // Self-work
    // Task 1
    Vector c = a + b;
    c.print();

    // Task 2
    Vector d = a - b;
    d.print();

    // Task 3
    Vector e = a * 5;
    e.print();

    // Task 4
    cout << "Sum of vector a = " << (int)a << endl;

    // Task 5
    cout << "char a = " << (char*)a << endl;

    // Task 7
    e.pushFront(35);
    e.print();

    // Task 8
    e.insert(0, 5);
    e.print();

    // Task 9
    e.popBack();
    e.print();

    // Task 10
    e.popFront();
    e.print();

    // Task 11
    e.remove(4);
    e.print();

    // Task 12
    cout << "Index: " << e.find(350) << endl;

}