#include <iostream>
using namespace std;

int main()
{
    // Task 1
    int choice;
    do
    {
        cout << "Menu: \n[1] Print a 90 angle triangle flipped. \n[2] Print a 90 angle triangle. \n[3] Print a triangle. \n[4] Print a second triangle. \n[5] Print a two triangles. \n[6] Print a two triangles rotated 90 angle. \n[7] Print a triangle rotated 90 angle. \n[8] Print a triangle rotated -90 angle. \n[9] Print a first diagonal. \n[10] Print a second diagonal. \n[0] Exit" << endl;
        cout << "Enter the number of the task: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // Task 1.1
            for (int i = 0; i <= 5; i++)
            {
                for (int j = 0; j <= 5; j++)
                {
                    if (i < j)
                    {
                        cout << "+";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            cout << endl;
            break;
        case 2:
            // Task 1.2
            for (int i = 0; i <= 5; i++)
            {
                for (int j = 0; j <= 5; j++)
                {
                    if (i > j)
                    {
                        cout << "+";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            cout << endl;
            break;
        case 3:
            // Task 1.3
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (i + j <= 9 && i <= j)
                    {
                        cout << "+";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                if (i <= 4) // просто, щоб не було багаторядкових відступів
                {
                    cout << endl;
                }
            }
            cout << endl;
            break;
        case 4:
            // Task 1.4
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (i + j >= 9 && i >= j)
                    {
                        cout << "+";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                if (i >= 4) // просто, щоб не було багаторядкових відступів
                {
                    cout << endl;
                }
            }
            cout << endl;
            break;
        case 5:
            // Task 1.5
        // diagonal down
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (i + j <= 9 && i <= j)
                    {
                        cout << "+";
                    }
                    else if (i == 3 && j == 9)
                    {
                        cout << endl;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                if (i < 3) // просто, щоб не було багаторядкових відступів
                {
                    cout << endl;
                }
            }
            // diagonal up
            for (int i = 0; i < 10; i++)
            {
                if (i == 5) // щоб не виводило в консоль дві зірки
                {
                    cout << endl;
                    continue;
                }
                for (int j = 0; j < 10; j++)
                {
                    if (i + j >= 9 && i >= j)
                    {
                        cout << "+";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                if (i > 5) // просто, щоб не було багаторядкових відступів
                {
                    cout << endl;
                }
            }
            break;
        case 6:
            // Task 1.6
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (j == 0 || j == i || j == 9 || j == 10 - i - 1)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            cout << endl;
            break;
        case 7:
            // Task 1.7
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            for (int i = 4; i > 0; i--)
            {
                for (int j = 0; j < i; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            cout << endl;
            break;
        case 8:
            // Task 1.8
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5 - i - 1; j++)
                {
                    cout << " ";
                }
                for (int j = 0; j <= i; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            for (int i = 5 - 2; i >= 0; i--)
            {
                for (int j = 0; j < 5 - i - 1; j++)
                {
                    cout << " ";
                }
                for (int j = 0; j <= i; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            cout << endl;
            break;
        case 9:
            // Task 1.9
            for (int i = 0; i < 5; i++)
            {
                for (int j = 5 - i; j > 0; j--)
                {
                    cout << "*";
                }
                cout << endl;
            }
            cout << endl;
            break;
        case 10:
            // Task 1.10
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (j >= 4 - i)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            break;
        case 0:
            cout << "Exiting ..." << endl;
            break;
        default:
            cout << "Invalid input. Try again." << endl;
            break;
        }
    } while (choice != 0);


    // Task 2
    int number, choice2, digitCount = 0, digitSum = 0, zeroCount = 0;
    cout << "Enter a number: ";
    cin >> number;
    do {
        cout << "Menu:" << endl;
        cout << "[1] Calculate digit count, digit sum, and average \n[2] Calculate zero count \n[0] Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice2;
        int temp = number;
		double average;

        switch (choice2) 
        {
        case 1:
            if (digitCount == 0 && digitSum == 0)
            {
                while (temp != 0) {
                    int digit = temp % 10;
                    digitCount++;
                    digitSum += digit;
                    temp /= 10;
                }
            }
            average = (double)(digitSum) / digitCount;
            cout << "Digit count: " << digitCount << endl;
            cout << "Digit sum: " << digitSum << endl;
            cout << "Average: " << average << endl;
            break;
        case 2:
            if (zeroCount == 0)
            {
                while (temp != 0) {
                    int digit = temp % 10;
                    if (digit == 0) {
                        zeroCount++;
                    }
                    temp /= 10;
                }
            }
            cout << "Zero count: " << zeroCount << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice2 != 0);
}