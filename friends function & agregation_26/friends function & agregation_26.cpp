#include <iostream>
#include "TV.h"
#include "Remote.h"
using namespace std;


int main()
{
    TV tv1(20, 30);
    cout << ">>>>>>>>> Info TV1 <<<<<<<<<" << endl;
    tv1.printInfo();

    Remote remote(&tv1);
    cout << "\t\tAfter turn on the TV" << endl;
    remote.power();
    +remote;
    ++remote;
    tv1.printInfo();

    TV tv2(5, 10);
    cout << ">>>>>>>>> Info TV2 <<<<<<<<<" << endl;
    tv2.printInfo();
    remote.chooseTV(&tv2);
    cout << "\t\tAfter turn on the TV" << endl;
    remote.power();
    +remote;
    tv2.printInfo();
}