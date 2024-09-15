#include <iostream>
using namespace std;

int main()
{
    // Task 1.1
    int N = 5; // N — розмірність таблиці
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i<j)
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

    // Task 1.2
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
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
        if (i<=4) // просто, щоб не було багаторядкових відступів
        {
            cout << endl;
        }
    }
    cout << endl;

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

    // Task 1.6
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0 || j == i || j == 9 || j == 10 - i - 1) // заповнити всередині трикутників не вийшло(
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

    // Task 1.7
    //for (int i = 0; i < 10; i++)
    //{
    //    for (int j = 0; j < 10; j++)
    //    {
    //        if (j == 0 || j == i || j == 9 || j == 10 - i - 1) // заповнити всередині трикутників не вийшло(
    //        {
    //            cout << "+";
    //        }
    //        else
    //        {
    //            cout << " ";
    //        }
    //    }
    //    cout << endl;
    //}
    //cout << endl;
}