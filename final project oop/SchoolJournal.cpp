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
        if (isValidPth(pthfileUser))
        {
            pthfileUser = pthfileUser + ".txt";
        }
        fstream fileUser(pthfileUser, ios_base::in | ios_base::out);
        if (!fileUser.is_open())
        {
            cout << "ERROR: This file doen't created!" << endl;
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
            if (isValidPth(pthfileUser))
            {
                pthfileUser = pthfileUser + ".txt";
            }
            fstream fileUser(pthfileUser, ios_base::app | ios_base::out | ios_base::in);
            if (!fileUser.is_open())
            {
                cout << "ERROR: This file doen't created!";
            }
            usefileUsers = true;
            fileUser.close();
            break;
        }
        case 'n':
            break;
        default:
            cout << "ERROR: Invalid choice" << endl;
            break;
        }
        break;
    }
    default:
        cout << "ERROR: Invalid choice" << endl;
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
        if (isValidPth(pthfileLesson))
        {
            pthfileLesson = pthfileLesson + ".txt";
        }
        fstream fileLesson(pthfileLesson, ios_base::in | ios_base::out);
        if (!fileLesson.is_open())
        {
            cout << "ERROR: This file doen't created!" << endl;
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
            if (isValidPth(pthfileLesson))
            {
                pthfileLesson = pthfileLesson + ".txt";
            }
            fstream fileLesson(pthfileLesson, ios_base::app | ios_base::out | ios_base::in);
            if (!fileLesson.is_open())
            {
                cout << "ERROR: This file doen't created!" << endl;
            }
            usefileLessons = true;
            fileLesson.close();
            break;
        }
        case 'n':
            break;
        default:
            cout << "ERROR: Invalid choice" << endl;
            break;
        }
        break;
    }
    default:
        cout << "ERROR: Invalid choice" << endl;
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
        if (isValidPth(pthfileMark))
        {
            pthfileMark = pthfileMark + ".txt";
        }
        fstream fileMark(pthfileMark, ios_base::in | ios_base::out);
        if (!fileMark.is_open())
        {
            cout << "ERROR: This file doen't created!" << endl;
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
            if (isValidPth(pthfileMark))
            {
                pthfileMark = pthfileMark + ".txt";
            }
            fstream fileMark(pthfileMark, ios_base::app | ios_base::out | ios_base::in);
            if (!fileMark.is_open())
            {
                cout << "ERROR: This file doen't created!" << endl;
            }
            usefileMarks = true;
            fileMark.close();
            break;
        }
        case 'n':
            break;
        default:
            cout << "ERROR: Invalid choice" << endl;
            break;
        }
        break;
    }
    default:
        cout << "ERROR: Invalid choice" << endl;
        break;
    }

    // загрузка з файла
    // User
    
    if (usefileUsers)
    {
        try
        {
            importUsers(pthfileUser);
        }
        catch (const std::exception& ex)
        {
            cout << "ERROR: " << ex.what() << endl;
        }
    }

    // Lesson
    
    if (usefileLessons)
    {
        try
        {
            importLessons(pthfileLesson);
        }
        catch (const std::exception& ex)
        {
            cout << "ERROR: " << ex.what() << endl;
        }
    }

    // Mark
    
    if (usefileMarks)
    {
        try
        {
            importMarks(pthfileMark);
        }
        catch (const std::exception& ex)
        {
            cout << "ERROR: " << ex.what() << endl;
        }
    }


    system("cls");
    short choice_menu;
    do
    {
        cout << "Menu:\n[1] Print users\n[2] Add User\n[3] Edit User\n[4] Delete User\n\n[5] Print Lessons\n[6] Add Lesson\n[7] Edit Lesson\n[8] Delete Lesson\n\n[9] Print Marks\n[10] New mark\n[11] Edit mark\n[12] Delete mark\n\n[13] Count user avg mark\n[14] Program info\n[15] View marks from lesson\n[16] Save\n[0] Exit\n";
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
            try
            {
                addUser();
            }
            catch (const std::exception& ex)
            {
                cout << "ERROR: " << ex.what() << endl;
            }
            break;
        }
        case 3:
        {
            printUsers();
            cout << endl;
            int choice;
            cout << "Enter a ID user what do you need a change info: "; cin >> choice;
            system("cls");
            try
            {
                editUser(choice);
            }
            catch (const std::exception& ex)
            {
                cout << "ERROR: " << ex.what() << endl;
            }
            break;
        }
        case 4:
        {
            system("cls");
            printUsers();
            cout << endl;
            int choice;
            cout << "Enter a ID user what do you need a delete: "; cin >> choice;
            system("cls");
            try
            {
                deleteUser(choice);
            }
            catch (const std::exception& ex)
            {
                cout << "ERROR: " << ex.what() << endl;
            }
            break;
        }
        case 5:
        {
            system("cls");
            printLessons();
            break;
        }
        case 6:
        {
            // Add lesson
            system("cls");
            try
            {
                addLesson();
            }
            catch (const std::exception& ex)
            {
                cout << "ERROR: " << ex.what() << endl;
            }
            break;
        }
        case 7:
        {
            // Edit lesson
            system("cls");
            printLessons();
            cout << endl;
            int choice;
            cout << "Enter a ID lesson what do you need a change info: "; cin >> choice;
            system("cls");
            try
            {
                editLesson(choice);
            }
            catch (const std::exception& ex)
            {
                cout << "ERROR: " << ex.what() << endl;
            }
            break;
        }
        case 8:
        {
            // Delete lesson
            system("cls");
            printLessons();
            cout << endl;
            int choice;
            cout << "Enter a ID lesson what do you need a delete: "; cin >> choice;
            system("cls");
            try
            {
                deleteLesson(choice);
            }
            catch (const std::exception& ex)
            {
                cout << "ERROR: " << ex.what() << endl;
            }
            break;
        }
        case 9:
        {
            // Print marks
            system("cls");
            printMarks();
            break;
        }
        case 10:
        {
            // New mark
            system("cls");
            newMark();
            break;
        }
        case 11:
        {
            // Edit mark
            bool markFound = false;
            printMarks();
            cout << endl;
            int choice;
            cout << "Enter a ID mark what do you need a change info: "; cin >> choice;
            system("cls");
            try
            {
                editMark(choice);
            }
            catch (const std::exception& ex)
            {
                cout << "ERROR: " << ex.what() << endl;
            }
            break;
        }
        case 12:
        {
            // Delete mark
            bool markFound = false;
            system("cls");
            printMarks();
            cout << endl;
            int choice;
            cout << "Enter a ID mark what do you need a delete: "; cin >> choice;
            system("cls");
            try
            {
                deleteMark(choice);
            }
            catch (const std::exception& ex)
            {
                cout << "ERROR: " << ex.what() << endl;
            }
            break;
        }
        case 13:
        {
            // Count user avg mark
            system("cls");
            printUsers();
            cout << endl;
            int user;
            cout << "Enter a ID user what do you need a count avg mark: "; cin >> user;
            int lesson;
            system("cls");
            printLessons();
            cout << "Enter a ID lesson : "; cin >> lesson;
            int sum = 0;
            int counter = 0;
            try
            {
                countAvg(user, lesson);
            }
            catch (const std::exception& ex)
            {
                cout << "ERROR: " << ex.what() << endl;
            }
            break;
        }
        case 14:
        {
            system("cls");
            printInfo();
            break;
        }
        case 15:
        {
            system("cls");
            printUsers();
            cout << endl;
            int user;
            cout << "Enter a ID user what do you need a count avg mark: "; cin >> user;
            int lesson;
            system("cls");
            printLessons();
            cout << "Enter a ID lesson : "; cin >> lesson;
            system("cls");
            try
            {
                printMarks(user, lesson);
            }
            catch (const std::exception& ex)
            {
                cout << "ERROR: " << ex.what() << endl;
            }
            break;
            
        }
        case 16:
        {
            // Save users
            if (usefileUsers)
            {
                saveUsers(pthfileUser);
            }
            else
            {
                cout << "Please, enter your name file of users(without .txt): " << endl;
                cin >> pthfileUser;
                if (isValidPth(pthfileUser))
                {
                    pthfileUser = pthfileUser + ".txt";
                }
                saveUsers(pthfileUser);
            }
            
            // Save lessons
            if (usefileLessons)
            {
                saveLessons(pthfileLesson);
            }
            else
            {
                cout << "Please, enter your name file of lessons(without .txt): " << endl;
                cin >> pthfileLesson;
                if (isValidPth(pthfileLesson))
                {
                    pthfileLesson = pthfileLesson + ".txt";
                }
                saveLessons(pthfileLesson);
            }

            // Save marks
            if (usefileMarks)
            {
                saveMarks(pthfileMark);
            }
            else
            {
                cout << "Please, enter your name file of marks(without .txt): " << endl;
                cin >> pthfileMark;
                if (isValidPth(pthfileMark))
                {
                    pthfileMark = pthfileMark + ".txt";
                }
                saveMarks(pthfileMark);
            }
            break;
        }
        case 0:
        {
            // Exit
            cout << "Exiting...";
            break;
        }
        default:
            cout << "Invalid choice, please try again or enter 0 to exit!" << endl;
            break;
        }
    } while (choice_menu != 0);
}

void SchoolJournal::printUsers() const
{
    if (users.size() == 0)
    {
        cout << "List of users is empty!" << endl;
        return;
    }
    for (auto& i : users)
    {
        i.print();
    }
}

void SchoolJournal::printLessons() const
{
    if (lessons.size() == 0)
    {
        cout << "List of lessons is empty!" << endl;
        return;
    }
    for (auto& i : lessons)
    {
        i.print();
    }
}

void SchoolJournal::printMarks() const
{
    if (marks.size() == 0)
    {
        cout << "List of marks is empty!" << endl;
        return;
    }
    for (auto& i : marks)
    {
        bool Flag = false;
        i.print();
        for (auto& j : lessons)
        {
            if (j.getIDLesson() == i.getIDLesson())
            {
                cout << "Lesson: " << j.getLesson() << endl;
                Flag = true;
                break;
            }
        }
        if (!Flag)
        {
            cout << "Lesson: " << i.getIDLesson() << endl;
        }
    }
}

void SchoolJournal::saveUsers(string pthfileUsers)
{
    ofstream fileUser(pthfileUsers);
    if (!fileUser.is_open())
    {
        throw runtime_error("Error opening file");
    }
    for (const auto& user : users)
    {
        fileUser << user << endl;
    }
    fileUser.close();
    cout << "Users saved!" << endl;
}

void SchoolJournal::saveMarks(string pthfileMarks)
{
    ofstream fileMark(pthfileMarks);
    if (!fileMark.is_open())
    {
        throw runtime_error("Error opening file");
    }
    for (const auto& mark : marks)
    {
        fileMark << mark << endl;
    }
    fileMark.close();
    cout << "Marks saved!" << endl;
}

void SchoolJournal::saveLessons(string pthfileLessons)
{
    ofstream fileLesson(pthfileLessons);
    if (!fileLesson.is_open())
    {
        throw runtime_error("Error opening file");
    }
    for (const auto& lesson : lessons)
    {
        fileLesson << lesson << endl;
    }
    fileLesson.close();
    cout << "Lessons saved!" << endl;
}

void SchoolJournal::importUsers(string pthfileUser)
{
    ifstream fileUser(pthfileUser);
    if (!fileUser.is_open())
    {
        throw exception("Error opening file with users!");
    }
    else
    {
        string line;
        while (getline(fileUser, line))
        {
            istringstream iss(line); // для фіксу багу під час зчитування з файлу
            User user;
            if (iss >> user)
            {
                lastIdUser = user.getIDUser();
                users.push_back(user);
            }
        }
        fileUser.close();
    }
}

void SchoolJournal::importMarks(string pthfileMark)
{
    ifstream fileMark(pthfileMark);
    if (!fileMark.is_open())
    {
        cout << "Error opening file: " << pthfileMark << endl;
    }
    else
    {
        string line;
        while (getline(fileMark, line))
        {
            istringstream iss(line); // для фіксу багу під час зчитування з файлу
            Mark mark;
            if (iss >> mark)
            {
                lastIdMark = mark.getIDMark();
                marks.push_back(mark);
            }
        }
        fileMark.close();
    }
}

void SchoolJournal::importLessons(string pthfileLesson)
{
    ifstream fileLesson(pthfileLesson);
    if (!fileLesson.is_open())
    {
        throw exception("Error opening file with lessons!");
    }
    else
    {
        string line;
        while (getline(fileLesson, line))
        {
            istringstream iss(line); // для фіксу багу під час зчитування з файлу
            Lesson lesson;
            if (iss >> lesson)
            {
                lastIdLesson = lesson.getIDLesson();
                lessons.push_back(lesson);
            }
        }
        fileLesson.close();
    }
}

bool SchoolJournal::isValidPth(string pthFile)
{
    if (pthFile.find(".txt") != string::npos)
    {
        return false;
    }
    return true;
}

void SchoolJournal::printInfo() const
{
    cout << "Info about " << group << ":" << endl;
    cout << "Count of users: " << lastIdUser << endl;
    cout << "Count of lessons: " << lastIdLesson << endl;
    cout << "Count of marks: " << lastIdMark << endl;
}

void SchoolJournal::countAvg(int user_id, int lesson_id) const
{
    int sum = 0;
    int counter = 0;
    if (user_id >= lastIdUser || lesson_id >= lastIdLesson)
    {
        throw invalid_argument("User id or Lesson id can't >= last id!");
    }
    for (auto& i : marks)
    {
        if (user_id == i.getIDUser())
        {
            if (lesson_id == i.getIDLesson())
            {
                if (!i.isAbsent())
                {
                    sum += i.getMark();
                    counter++;
                }
            }
        }
    }
    if (counter == 0 || sum == 0)
    {
        system("cls");
        throw exception("User hasn't any marks!");
    }
    else
    {
        float avg = (float)sum / counter;
        system("cls");
        cout << "Avg user for lesson id " << lesson_id << " == " << avg << endl;
    }
}

void SchoolJournal::addUser()
{
    char surname[SIZE]{};
    char name[SIZE]{};
    int day, month, year;
    cout << "Enter surname: "; cin >> surname;
    cout << "Enter name: "; cin >> name;
    cout << "Enter birthday date(Format: DD MM YYYY): "; cin >> day >> month >> year;

    try
    {
        User user(lastIdUser++, surname, name, Date(day, month, year), this->group);
        users.push_back(user);
        system("cls");
        cout << "Added!" << endl;
    }
    catch (const std::exception& ex)
    {
        cout << "ERROR: " << ex.what() << endl;
    }
}

void SchoolJournal::editUser(int user_id)
{
    bool userFound = false;
    if (user_id >= lastIdUser)
    {
        throw invalid_argument("User ID can't >= last ID!");
    }
    for (auto& i : users)
    {
        if (i.getIDUser() == user_id)
        {
            i.edit();
            userFound = true;
        }
    }
    if (!userFound)
    {
        throw exception("User not found!");
    }
    else
    {
        cout << "Edited!" << endl;
    }
}

void SchoolJournal::deleteUser(int user_id)
{
    bool userFound = false;
    int counter = 0;
    for (auto& i : users)
    {
        if (i.getIDUser() == user_id)
        {
            users.erase(users.begin() + counter);
            cout << "Deleted!" << endl;
            userFound = true;
        }
        counter++;
    }
    if (!userFound)
    {
        throw exception("User not found!");
    }
}

void SchoolJournal::addLesson()
{
    char name[SIZE]{};
    int day, month, year;
    cout << "Enter name of lesson: "; cin >> name;
    cout << "Enter date(Format: DD MM YYYY): "; cin >> day >> month >> year;

    try
    {
        Lesson lesson(this->lastIdLesson++, name, this->group, Date(day, month, year));
        lessons.push_back(lesson);
        system("cls");
        cout << "Added!" << endl;
    }
    catch (const std::exception& ex)
    {
        cout << "ERROR: " << ex.what() << endl;
    }
}

void SchoolJournal::editLesson(int lesson_id)
{
    bool lessonFounded = false;
    for (auto& i : lessons)
    {
        if (i.getIDLesson() == lesson_id)
        {
            i.edit();
            lessonFounded = true;
        }
    }
    if (!lessonFounded)
    {
        throw exception("Lesson not found!");
    }
    else
    {
        cout << "Edited!" << endl;
    }
}

void SchoolJournal::deleteLesson(int lesson_id)
{
    bool lessonFounded = false;
    int counter = 0;
    if (lesson_id >= lastIdLesson)
    {
        throw invalid_argument("Lesson ID can't >= Last ID");
    }
    for (auto& i : lessons)
    {
        if (i.getIDLesson() == lesson_id)
        {
            lessons.erase(lessons.begin() + counter);
            cout << "Deleted!" << endl;
            lessonFounded = true;
        }
        counter++;
    }
    if (!lessonFounded)
    {
       throw exception("Lesson not found!");
    }
}

void SchoolJournal::newMark()
{
    printUsers();
    int user_id;
    cout << "Select a user: "; cin >> user_id;
    system("cls");
    printLessons();
    int lesson_id;
    cout << "Select a lesson: "; cin >> lesson_id;
    int day, month, year;
    cout << "Input a date(Format: DD MM YYYY): "; cin >> day >> month >> year;
    int mark;
    cout << "Input a mark(input -1 if mark == absent): "; cin >> mark;
    bool absent = (mark == -1 ? true : false);
    try
    {
        Mark mark_obj(lastIdMark++, user_id, lesson_id, Date(day, month, year), absent, mark);
        marks.push_back(mark_obj);
        system("cls");
        cout << "Added!" << endl;
    }
    catch (const std::exception& ex)
    {
        cout << "ERROR: " << ex.what() << endl;
    }
}

void SchoolJournal::deleteMark(int mark_id)
{
    bool markFound = false;
    int counter = 0;
    if (mark_id >= lastIdMark)
    {
        throw invalid_argument("Mark id can't >= last id!");
    }
    for (auto& i : marks)
    {
        if (i.getIDMark() == mark_id)
        {
            marks.erase(marks.begin() + counter);
            cout << "Deleted!" << endl;
            markFound = true;
        }
        counter++;
    }
    if (!markFound)
    {
        throw exception("Mark not found!");
    }
}

void SchoolJournal::editMark(int mark_id)
{
    if (mark_id >= lastIdMark)
    {
        throw invalid_argument("Mark ID can't >= last ID");
    }
    bool markFound = false;
    for (auto& i : marks)
    {
        if (i.getIDMark() == mark_id)
        {
            i.edit();
            markFound = true;
        }
    }
    if (!markFound)
    {
        throw exception("Mark not found!");
    }
    else
    {
        cout << "Edited!" << endl;
    }
}

void SchoolJournal::printMarks(int user_id, int lesson_id) const
{
    if (user_id >= lastIdUser || lesson_id >= lastIdLesson)
    {
        throw invalid_argument("User id or lesson id can't >= last id");
    }
    int counter = 0;
    for (auto& i : marks)
    {
        if (i.getIDLesson() == lesson_id && i.getIDUser() == user_id)
        {
            i.print();
            counter++;
        }
    }
    if (counter == 0)
    {
        throw exception("Nothing marks!");
    }
}

int SchoolJournal::lastIdUser = 0;
int SchoolJournal::lastIdLesson = 0;
int SchoolJournal::lastIdMark = 0;