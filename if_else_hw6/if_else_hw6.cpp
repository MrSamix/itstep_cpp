#include <iostream>
using namespace std;

int main()
{
    // Task 1
    char symbol;
    cout << "Enter a symbol: ";
    cin >> symbol;
    
    if (isalpha(symbol))
    {
        cout << "The symbol is a letter." << endl;
    }
    else if (isdigit(symbol))
    {
        cout << "The symbol is a digit." << endl;
    }
    else if (ispunct(symbol))
    {
        cout << "The symbol is a punctuation mark." << endl;
    }
    else
    {
        cout << "The symbol is something else." << endl;
    }

    // Task 2
    double callCost;
    int operatorCode;
    
    cout << "Enter the cost of the call: ";
    cin >> callCost;
    
    cout << "Select the operator code:\n";
    cout << "1. Kyivstar" << endl;
    cout << "2. Vodafone" << endl;
    cout << "3. Lifecell" << endl;
    cout << "4. Other" << endl;
    cout << "Enter the operator code: ";
    cin >> operatorCode;
    
    double totalCost;
    
    switch (operatorCode)
    {
        case 1:
            totalCost = callCost * 1.2;
            cout << "The total cost of the call is: " << totalCost << endl;
            break;
        case 2:
            totalCost = callCost * 1.5;
            cout << "The total cost of the call is: " << totalCost << endl;
            break;
        case 3:
            totalCost = callCost * 1.8;
            cout << "The total cost of the call is: " << totalCost << endl;
            break;
        case 4:
            totalCost = callCost * 2.0;
            cout << "The total cost of the call is: " << totalCost << endl;
            break;
        default:
            cout << "Invalid operator code." << endl;
            break;
    }
    // Task 3
    int income, delays, linesOfCode, choice;
    int salaryPerLine = 50;
    int penaltyPerDelay = 20;
    
    cout << "Menu:\n";
    cout << "1. Calculate the number of lines of code Vasya needs to write based on desired income and number of delays." << endl;
    cout << "2. Calculate the number of delays Vasya can have based on the number of lines of code written and desired salary." << endl;
    cout << "3. Calculate the amount of money Vasya will be paid and determine if he will be paid at all based on the number oflines of     code and delays." << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice)
    {
        case 1:
            cout << "Enter the desired income: ";
            cin >> income;
            cout << "Enter the number of delays: ";
            cin >> delays;
            linesOfCode = (income / salaryPerLine) * 100 - (delays / 3) * 100;
            cout << "Vasya needs to write " << linesOfCode << " lines of code." << endl;
            break;
        case 2:
            cout << "Enter the number of lines of code written by Vasya: ";
            cin >> linesOfCode;
            cout << "Enter the desired salary: ";
            cin >> income;
            delays = ((linesOfCode / 100) * salaryPerLine - income) / (salaryPerLine * 100 / 3);
            cout << "Vasya can have " << delays << " delays." << endl;
            break;
        case 3:
            cout << "Enter the number of lines of code: ";
            cin >> linesOfCode;
            cout << "Enter the number of delays: ";
            cin >> delays;
            income = (linesOfCode / 100) * salaryPerLine - (delays / 3) * penaltyPerDelay;
            if (income >= 0)
            {
                cout << "Vasya will be paid $" << income << "." << endl;
            }
            else
            {
                cout << "Vasya will not be paid." << endl;
            }
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }
}