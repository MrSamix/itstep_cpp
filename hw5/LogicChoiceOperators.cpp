#include <iostream>
using namespace std;

int main()
{
	// Task 1.1
	int number;
	cout << "Enter number: ";
	cin >> number;
	number % 2 == 0 ? cout << "True" << endl : cout << "False" << endl;

	// Task 1.2
	int num1, num2;
	cout << "Enter two numbers: ";
	cin >> num1 >> num2;
	num1 > num2 ? cout << num2 << endl: cout << num1 << endl;

	// Task 1.3
	int number_for_check;
	cout << "Enter number to check: " << endl;
	cin >> number_for_check;
	if (number_for_check > 0)
	{
		cout << "Your number > 0" << endl;
	}
	else if (number_for_check < 0) {
		cout << "Your number < 0" << endl;
	}
	else
	{
		cout << "Your number = 0" << endl;
	}
	
	// Task 1.4
	int number_to_check_1, number_to_check_2;
	cout << "Enter two numbers to check: ";
	cin >> number_to_check_1 >> number_to_check_2;
	if (number_to_check_1 == number_to_check_2)
	{
		cout << "Your first number = two number" << endl;
	}
	else
	{
		number_to_check_1 > number_to_check_2 ? cout << number_to_check_2 << endl << number_to_check_1 << endl : cout << number_to_check_1 << endl << number_to_check_2 << endl;
	}

	// Task 2.1
	int mark_1, mark_2, mark_3, mark_4, mark_5;
	cout << "Enter 5 marks: ";
	cin >> mark_1 >> mark_2 >> mark_3 >> mark_4 >> mark_5;
	float avg = (float)(mark_1 + mark_2 + mark_3 + mark_4 + mark_5) / 5;
	if (avg >= 4)
	{
		cout << "Avg = " << avg << endl << "You are admitted to the exam" << endl;
	}
	else
	{
		cout << "Avg = " << avg << endl << "You aren't admitted to the exam" << endl;
	}

	// Task 2.2
	int numbeR_1;
	cout << "Enter number: ";
	cin >> numbeR_1;
	numbeR_1 % 2 == 0 ? cout << numbeR_1 * 3 << endl : cout << (float)numbeR_1 / 2 << endl;

	// Task 2.3
	int Number1, Number2;
	char choice;
	cout << "Enter a first number: ";
	cin >> Number1;
	cout << "Enter second number : ";
	cin >> Number2;
	cout << "Enter the sign(+,-,*,/): ";
	cin >> choice;
	switch (choice)
	{
	case '+':
		cout << "Result: " << Number1 + Number2 << endl;
		break;
	case '-':
		cout << "Result: " << Number1 - Number2 << endl;
		break;
	case '*':
		cout << "Result: " << Number1 * Number2 << endl;
		break;
	case '/':
		cout << "Result: " << Number1 / Number2 << endl;
		break;
	default:
		cout << "Invalid input!" << endl;
		break;
	}
}