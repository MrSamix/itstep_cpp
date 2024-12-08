#include "SchoolJournal.h"

void SchoolJournal::menu()
{
    // Flags
    bool usefileUsers = false;
    bool usefileLessons = false;
    bool usefileMarks = false;




    // User's file
    string pthfileUser;
    cout << "Do you have a file with users?(y/n): ";
    char choice;
    cin >> choice;
    switch (choice)
    {
    case 'y':
    {
        cout << "Enter filename(without .txt): "; cin >> pthfileUser;
        //write validation(inputed txt or not)
        pthfileUser = pthfileUser + ".txt";
        fstream fileUser(pthfileUser, ios_base::in | ios_base::out);
        if (!fileUser.is_open())
        {
            throw runtime_error("Error opening file");
        }
        usefileUsers = true;
        fileUser.close();
        break;
    }
    case 'n':
    {
        char choice_n;
        cout << "Create file?(y/n): "; cin >> choice_n;
        switch (choice_n)
        {
        case 'y':
        {
            cout << "Enter filename(without .txt): "; cin >> pthfileUser;
            // enter validation(if user enter with .txt)
            pthfileUser = pthfileUser + ".txt";
            fstream fileUser(pthfileUser, ios_base::app | ios_base::out | ios_base::in);
            //fstream fileUser;
            //fileUser.open(pthfileUser, ios_base::out | ios_base::in);
            if (!fileUser.is_open())
            {
                throw runtime_error("Error opening file");
            }
            usefileUsers = true;
            fileUser.close();
            break;
        }
        case 'n':
            break;
        default:
            throw invalid_argument("Invalid choice");
            break;
        }
        break;
    }
    default:
        throw invalid_argument("Invalid choice");
        break;
    }

    // Lesson's file
    string pthfileLesson;
    cout << "Do you have a file with lessons?(y/n): ";
    char choice_2;
    cin >> choice_2;
    switch (choice_2)
    {
    case 'y':
    {
        cout << "Enter filename(without .txt): "; cin >> pthfileLesson;
        //write validation(inputed txt or not)
        pthfileLesson = pthfileLesson + ".txt";
        fstream fileLesson(pthfileLesson, ios_base::in | ios_base::out);
        if (!fileLesson.is_open())
        {
            throw runtime_error("Error opening file");
        }
        usefileLessons = true;
        fileLesson.close();
        break;
    }
    case 'n':
    {
        char choice_n;
        cout << "Create file?(y/n): "; cin >> choice_n;
        switch (choice_n)
        {
        case 'y':
        {
            cout << "Enter filename(without .txt): "; cin >> pthfileLesson;
            // enter validation(if user enter with .txt)
            pthfileLesson = pthfileLesson + ".txt";
            fstream fileLesson(pthfileLesson, ios_base::app | ios_base::out | ios_base::in);
            if (!fileLesson.is_open())
            {
                throw runtime_error("Error opening file");
            }
            usefileLessons = true;
            fileLesson.close();
            break;
        }
        case 'n':
            break;
        default:
            throw invalid_argument("Invalid choice");
            break;
        }
        break;
    }
    default:
        throw invalid_argument("Invalid choice");
        break;
    }

    // Mark's file
    string pthfileMark;
    cout << "Do you have a file with marks?(y/n): ";
    char choice_3;
    cin >> choice_3;
    switch (choice_3)
    {
    case 'y':
    {
        cout << "Enter filename(without .txt): "; cin >> pthfileMark;
        //write validation(inputed txt or not)
        pthfileMark = pthfileMark + ".txt";
        fstream fileMark(pthfileMark, ios_base::in | ios_base::out);
        if (!fileMark.is_open())
        {
            throw runtime_error("Error opening file");
        }
        usefileMarks = true;
        fileMark.close();
        break;
    }
    case 'n':
    {
        char choice_n;
        cout << "Create file?(y/n): "; cin >> choice_n;
        switch (choice_n)
        {
        case 'y':
        {
            cout << "Enter filename(without .txt): "; cin >> pthfileMark;
            // enter validation(if user enter with .txt)
            pthfileMark = pthfileMark + ".txt";
            fstream fileMark(pthfileMark, ios_base::app | ios_base::out | ios_base::in);
            if (!fileMark.is_open())
            {
                throw runtime_error("Error opening file");
            }
            usefileMarks = true;
            fileMark.close();
            break;
        }
        case 'n':
            break;
        default:
            throw invalid_argument("Invalid choice");
            break;
        }
        break;
    }
    default:
        throw invalid_argument("Invalid choice");
        break;
    }

    // загрузка з файла

    fstream fileUser(pthfileUser, ios_base::in);
    if (!fileUser.is_open())
    {
        cout << "Error opening file: " << pthfileUser << endl;
    }
    else if (usefileUsers)
    {
        fileUser.seekg(0, ios_base::end);
        size_t lengthFile = fileUser.tellg();
        size_t length = lengthFile / sizeof(User);
        users.resize(length);
        fileUser.read(reinterpret_cast<char*>(users.data()), lengthFile);
        /*User tmp();
        while (fileUser.read(reinterpret_cast<char*>(&tmp), sizeof(User)))
        {
            users.push_back(tmp);
        }*/
    }
    

    // Menu
    system("cls");
    short choice_menu;
    do
    {
        cout << "Menu:\n[1] Print user\n[2] Add User\n[3] Edit User\n[4] Delete User\n\n[5] Print Lessons\n[6] Add Lesson\n[7] Edit Lesson\n[8] Delete Lesson\n\n[9] Print Marks\n[10] New mark\n[11] Edit mark\n[12] Delete mark\n\n[13] Count user avg mark\n[14] Save\n[0] Exit\n";
        cout << "Enter a choice: "; cin >> choice_menu;
        switch (choice_menu)
        {
        case 1:
        {
            system("cls");
            printUsers();
            break;
        }
        case 2:
        {
            char surname[SIZE]{};
            char name[SIZE]{};
            /*char group[SIZE]{};*/
            int day, month, year;
            cout << "Enter surname: "; cin >> surname;
            cout << "Enter name: "; cin >> name;
            /*cout << "Enter group: "; cin >> group;*/
            cout << "Enter birthday date(Format: DD MM YYYY): "; cin >> day >> month >> year;

            User user(surname, name, Date(day, month, year), this->group);
            users.push_back(user);
            system("cls");
            cout << "Added!" << endl;
            break;
        }
        case 3:
        {
            printUsers();
            cout << endl;
            int choice;
            cout << "Enter a ID user what do you need a change info: "; cin >> choice;
            system("cls");
            for (auto& i : users)
            {
                if (i.getIDUser() == choice)
                {
                    i.edit();
                }
            }
            break;
        }
        case 4:
        {
            printUsers();
            cout << endl;
            int choice;
            cout << "Enter a ID user what do you need a delete: "; cin >> choice;
            system("cls");
            int counter = 0;
            for (auto& i : users)
            {
                if (i.getIDUser() == choice)
                {
                    users.erase(users.begin() + counter);
                    cout << "Deleted!" << endl;
                }
                counter++;
            }
            break;
        }
        case 5:
        {
            printLessons();
            break;
        }
        case 6:
        {
            char name[SIZE]{};
            /*char group[SIZE]{};*/
            int day, month, year;
            cout << "Enter name of lesson: "; cin >> name;
            //cout << "Enter group: "; cin >> group;
            cout << "Enter date(Format: DD MM YYYY): "; cin >> day >> month >> year;

            Lesson lesson(name, this->group, Date(day, month, year));
            lessons.push_back(lesson);
            break;
        }
        case 7:
        {
            // Edit lesson
            break;
        }
        case 8:
        {
            // Delete lesson
            break;
        }
        case 9:
        {
            // Print marks
            break;
        }
        case 10:
        {
            // New mark
            break;
        }
        case 11:
        {
            // Edit mark
            break;
        }
        case 12:
        {
            // Delete mark
            break;
        }
        case 13:
        {
            // Count user avg mark
            break;
        }
        case 14:
        {
            // Save
            saveUsers(pthfileUser); // fix if user don't create a file
            break;
        }
        case 0:
        {
            // Exit
            cout << "Do you want to exit without saving?(y/n): ";
            break;
        }
        default:
            cout << "Invalid choice, please try again or enter 0 to exit!" << endl;
            break;
        }
    } while (choice_menu != 0);
}

void SchoolJournal::saveUsers(string pthfileUsers)
{
    fstream fileUser(pthfileUsers, ios_base::out);
    if (!fileUser.is_open())
    {
        throw runtime_error("Error opening file");
    }
    fileUser.write(reinterpret_cast<const char*>(users.data()), sizeof(User) * users.size());
    fileUser.close();
    cout << "Saved!" << endl;
}
