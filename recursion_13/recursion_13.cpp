#include <iostream>
using namespace std;

// Task 1
int factorial(int number)
{
	if (number == 1)
	{
		return 1;
	}
	else
	{
		return number * factorial(number - 1);
	}
}

// Task 2
void printNumbersForward(int start, int end)
{
    if (start > end)
    {
        return;
    }
    
    cout << start << " ";
    printNumbersForward(start + 1, end);
}

void printNumbersReverse(int start, int end)
{
    if (start > end)
    {
        return;
    }
    
    printNumbersReverse(start + 1, end);
    cout << start << " ";
}

// Task 3
void reversedNumber(int number)
{
    if (number == 0)
    {
        return;
    }
    
    cout << number % 10;
    reversedNumber(number / 10);
}

// Task 4
int sum_of_digit_number(int number)
{
    if (number == 0)
    {
        return 0;
    }
    
    return number % 10 + sum_of_digit_number(number / 10);
}



#include <iostream>
using namespace std;

// Task 5
void printParentheses(int n)
{
    if (n <= 0)
    {
        return;
    }
    
    cout << "(";
    printParentheses(n - 1);
    cout << ")";
}


int main()
{
	// Task 1
	cout << "Factorial of 5 = " << factorial(5) << endl;

	// Task 2
    int start, end;
    cout << "Enter the start of the range: ";
    cin >> start;
    cout << "Enter the end of the range: ";
    cin >> end;
    
    cout << "Forward: ";
    printNumbersForward(start, end);
    cout << endl;
    
    cout << "Reversed: ";
    printNumbersReverse(start, end);
    cout << endl;

    // Task 3
    reversedNumber(1234);
    cout << "\n\n";

    // Task 4
    cout << "Sum of number = " << sum_of_digit_number(1357) << endl;
    
    // Task 5
    int n;
    cout << "Enter the number of parentheses: ";
    cin >> n;
    
    cout << "Parentheses: ";
    printParentheses(n);
    cout << endl;
}
