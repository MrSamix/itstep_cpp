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
}