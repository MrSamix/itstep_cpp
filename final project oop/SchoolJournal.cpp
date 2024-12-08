#include "SchoolJournal.h"

void SchoolJournal::menu()
{
    // User's file
    string pthfileUser;
    cout << "Do you have a file with users?(y/n)";
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
        break;
    }
    case 'n':
    {
        char choice_n;
        cout << "Create file?(y/n)"; cin >> choice_n;
        switch (choice_n)
        {
        case 'y':
        {
            cout << "Enter filename(without .txt): "; cin >> pthfileUser;
            // enter validation(if user enter with .txt)
            pthfileUser = pthfileUser + ".txt";
            fstream fileUser(pthfileUser, ios_base::out | ios_base::in);
            if (!fileUser.is_open())
            {
                throw runtime_error("Error opening file");
            }
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
    cout << "Do you have a file with lessons?(y/n)";
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
        break;
    }
    case 'n':
    {
        char choice_n;
        cout << "Create file?(y/n)"; cin >> choice_n;
        switch (choice_n)
        {
        case 'y':
        {
            cout << "Enter filename(without .txt): "; cin >> pthfileLesson;
            // enter validation(if user enter with .txt)
            pthfileLesson = pthfileLesson + ".txt";
            fstream fileLesson(pthfileLesson, ios_base::out | ios_base::in);
            if (!fileLesson.is_open())
            {
                throw runtime_error("Error opening file");
            }
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
    cout << "Do you have a file with marks?(y/n)";
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
        break;
    }
    case 'n':
    {
        char choice_n;
        cout << "Create file?(y/n)"; cin >> choice_n;
        switch (choice_n)
        {
        case 'y':
        {
            cout << "Enter filename(without .txt): "; cin >> pthfileMark;
            // enter validation(if user enter with .txt)
            pthfileMark = pthfileMark + ".txt";
            fstream fileMark(pthfileMark, ios_base::out | ios_base::in);
            if (!fileMark.is_open())
            {
                throw runtime_error("Error opening file");
            }
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

    // Menu
    short choice_menu;
    do
    {
        cout << "Menu:\n1.Print user\n2.Add User\n3.Edit User\n4.Delete User\n5.Print Lessons\n6.Add Lesson\n7.Edit Lesson\n8.Delete Lesson\n9.Print Marks\n10.New mark\n11.Edit mark\n12.Delete mark\n13.Count user avg mark\n14.Save\n0.Exit\n";
        cout << "Enter a choice"; cin >> choice_menu;
        switch (choice_menu)
        {
        case 1:
        {
            printUsers();
            break;
        }
        case 2:
        {
            char surname[SIZE]{};
            char name[SIZE]{};
            char group[SIZE]{};
            int day, month, year;
            cout << "Enter surname: "; cin >> surname;
            cout << "Enter name: "; cin >> name;
            cout << "Enter group: "; cin >> group;
            cout << "Enter birthday date(Format: DD MM YYYY): "; cin >> day >> month >> year;

            User user(surname, name, Date(day, month, year), group);
            users.push_back(user);
            cout << "Added!" << endl;
            break;
        }
        case 3:
        {
            printUsers();
            cout << endl;
            int choice;
            cout << "Enter a ID user what do you need a change info: "; cin >> choice;
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
            int counter = 0;
            for (auto& i : users)
            {
                if (i.getIDUser() == choice)
                {
                    cout << "Not deleted!" << endl;
                    //users.erase(users.begin() + counter);
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
            char group[SIZE]{};
            int day, month, year;
            cout << "Enter name of lesson: "; cin >> name;
            cout << "Enter group: "; cin >> group;
            cout << "Enter birthday date(Format: DD MM YYYY): "; cin >> day >> month >> year;

            Lesson lesson(name, group, Date(day, month, year));
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
//#include "SchoolJournal.h"
//
//void SchoolJournal::menu()
//{
//	// User's file
//	string pthfileUser;
//	cout << "Do you have a file with users?(y/n)";
//	char choice;
//	cin >> choice;
//	switch (choice)
//	{
//	case 'y':
//	{
//		cout << "Enter filename(without .txt): "; cin >> pthfileUser;
//		//write validation(inputed txt or not)
//		pthfileUser = pthfileUser + ".txt";
//		fstream fileUser(pthfileUser, ios_base::in | ios_base::out);
//		if (!fileUser.is_open())
//		{
//			throw exception("Error opening file");
//		}
//		break;
//	}
//	case 'n':
//	{
//		char choice_n;
//		cout << "Create file?(y/n)"; cin >> choice_n;
//		switch (choice_n)
//		{
//		case 'y':
//		{
//			cout << "Enter filename(without .txt): "; cin >> pthfileUser;
//			// enter validation(if user enter with .txt)
//			pthfileUser = pthfileUser + ".txt";
//			fstream fileUser(pthfileUser, ios_base::out | ios_base::in);
//			if (!fileUser.is_open())
//			{
//				throw exception("Error opening file");
//			}
//			break;
//		}
//		case 'n':
//			break;
//		default:
//			throw invalid_argument("Invalid choice");
//			break;
//		}
//	}
//	default:
//		throw invalid_argument("Invalid choice");
//		break;
//	}
//
//	// Lesson's file
//	string pthfileLesson;
//	cout << "Do you have a file with lessons?(y/n)";
//	char choice_2;
//	cin >> choice_2;
//	switch (choice_2)
//	{
//	case 'y':
//	{
//		cout << "Enter filename(without .txt): "; cin >> pthfileLesson;
//		//write validation(inputed txt or not)
//		pthfileLesson = pthfileLesson + ".txt";
//		fstream fileLesson(pthfileLesson, ios_base::in | ios_base::out);
//		if (!fileLesson.is_open())
//		{
//			throw exception("Error opening file");
//		}
//		break;
//	}
//	case 'n':
//	{
//		char choice_n;
//		cout << "Create file?(y/n)"; cin >> choice_n;
//		switch (choice_n)
//		{
//		case 'y':
//		{
//			cout << "Enter filename(without .txt): "; cin >> pthfileLesson;
//			// enter validation(if user enter with .txt)
//			pthfileLesson = pthfileLesson + ".txt";
//			fstream fileLesson(pthfileLesson, ios_base::out | ios_base::in);
//			if (!fileLesson.is_open())
//			{
//				throw exception("Error opening file");
//			}
//			break;
//		}
//		case 'n':
//			break;
//		default:
//			throw invalid_argument("Invalid choice");
//			break;
//		}
//	}
//	default:
//		throw invalid_argument("Invalid choice");
//		break;
//	}
//
//	// Mark's file
//	string pthfileMark;
//	cout << "Do you have a file with marks?(y/n)";
//	char choice_3;
//	cin >> choice_3;
//	switch (choice_3)
//	{
//	case 'y':
//	{
//		cout << "Enter filename(without .txt): "; cin >> pthfileMark;
//		//write validation(inputed txt or not)
//		pthfileMark = pthfileMark + ".txt";
//		fstream fileMark(pthfileMark, ios_base::in | ios_base::out);
//		if (!fileMark.is_open())
//		{
//			throw exception("Error opening file");
//		}
//		break;
//	}
//	case 'n':
//	{
//		char choice_n;
//		cout << "Create file?(y/n)"; cin >> choice_n;
//		switch (choice_n)
//		{
//		case 'y':
//		{
//			cout << "Enter filename(without .txt): "; cin >> pthfileMark;
//			// enter validation(if user enter with .txt)
//			pthfileMark = pthfileMark + ".txt";
//			fstream fileMark(pthfileMark, ios_base::out | ios_base::in);
//			if (!fileMark.is_open())
//			{
//				throw exception("Error opening file");
//			}
//			break;
//		}
//		case 'n':
//			break;
//		default:
//			throw invalid_argument("Invalid choice");
//			break;
//		}
//	}
//	default:
//		throw invalid_argument("Invalid choice");
//		break;
//	}
//
//	// загрузка з файла
//
//
//	// Menu
//	short choice_menu;
//	do
//	{
//		cout << "Menu:\n1.Print user\n2.Add User\n3.Edit User\n4.Delete User\n5.Print Lessons\n6.Add Lesson\n7.Edit Lesson\n8.Delete Lesson\n9.Print Marks\n10.New mark\n11.Edit mark\n12.Delete mark\n13.Count user avg mark\n14.Save\n0.Exit\n";
//		cout << "Enter a choice"; cin >> choice_menu;
//		switch (choice_menu)
//		{
//		case 1:
//		{
//			printUsers();
//			break;
//		}
//		case 2:
//		{
//			char surname[SIZE]{};
//			char name[SIZE]{};
//			char group[SIZE]{};
//			int day, month, year;
//			cout << "Enter surname: "; cin >> surname;
//			cout << "Enter name: "; cin >> name;
//			cout << "Enter group: "; cin >> group;
//			cout << "Enter birthday date(Format: DD MM YYYY): "; cin >> day >> month >> year;
//
//			User user(surname, name, Date(day, month, year), group);
//			users.push_back(user);
//			cout << "Added!" << endl;
//			break;
//		}
//		case 3:
//		{
//			printUsers();
//			cout << endl;
//			int choice;
//			cout << "Enter a ID user what do you need a change info: "; cin >> choice;
//			for (auto& i : users)
//			{
//				if (i.getIDUser() == choice)
//				{
//					i.edit();
//				}
//			}
//			break;
//		}
//		case 4:
//		{
//			printUsers();
//			cout << endl;
//			int choice;
//			cout << "Enter a ID user what do you need a delete: "; cin >> choice;
//			int counter = 0;
//			for (auto& i : users)
//			{
//				if (i.getIDUser() == choice)
//				{
//					cout << "Not deleted!" << endl;
//					//users.erase(users.begin() + counter);
//				}
//				counter++;
//			}
//			break;
//		}
//		case 5:
//		{
//			printLessons();
//			break;
//		}
//		case 6:
//		{
//			char name[SIZE]{};
//			char group[SIZE]{};
//			int day, month, year;
//			cout << "Enter name of lesson: "; cin >> name;
//			cout << "Enter group: "; cin >> group;
//			cout << "Enter birthday date(Format: DD MM YYYY): "; cin >> day >> month >> year;
//
//			Lesson lesson(name, group, Date(day, month, year));
//			lessons.push_back(lesson);
//			break;
//		}
//		case 7:
//		{
//			// Edit lesson
//			break;
//		}
//		case 8:
//		{
//			// Delete lesson
//			break;
//		}
//		case 9:
//		{
//			// Print marks
//			break;
//		}
//		case 10:
//		{
//			// New mark
//			break;
//		}
//		case 11:
//		{
//			// Edit mark
//			break;
//		}
//		case 12:
//		{
//			// Delete mark
//			break;
//		}
//		case 13:
//		{
//			// Count user avg mark
//			break;
//		}
//		case 14:
//		{
//			// Save
//			break;
//		}
//		case 0:
//		{
//			// Exit
//			cout << "Do you want to exit without saving?(y/n): ";
//			break;
//		}
//		default:
//			cout << "Invalid choice, please try again or enter 0 to exit!" << endl;
//			break;
//		}
//	} while (choice_menu);
//
//}
