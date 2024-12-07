#include <iostream>
#include "Date.h"
#include "Mark.h"
#include "Lesson.h"
#include "User.h" // сховати підключення
using namespace std;

int main()
{
    cout << "==================== DATE ========================\n";
    Date date(22, 11, 2005);
    date.print();
    //date.edit();
    //date.print();



    cout << "==================== MARK ========================\n";
    Mark mark(222, 333, Date(22, 04, 2005), false, 12);
    mark.print();
    cout << endl;
    Mark mark2(222, 333, Date(22, 01, 2005), true, 10);
    //mark2.edit();

    cout << "==================== LESSON ========================\n";
    Lesson lesson("IT", "PV421", Date(06, 12, 2024));
    lesson.print();
    //lesson.edit();



    cout << "==================== USER ========================\n";
    User user("Panchuk", "Oleksandr", Date(11, 4, 2008), "PV421");
    user.print();
    //user.edit();

}