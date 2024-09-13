#include <iostream>
using namespace std;

int main()
{
	// hw 1
	//// Task 1
 //   int a;
	//cout << "Enter a number: ";
	//cin >> a;
	//int counter = a;
	//while (a <= 500)
	//{
	//	counter += a;
	//	a++;
	//}
	//cout << "The sum of the numbers is: " << counter << endl;

	//// Task 2
	//int x, y, counter2 = 1, i = 0;
	//cout << "x and y: ";
	//cin >> x >> y;
	//while (i < y)
	//{
	//	counter2 *= x;
	//	i++;
	//}
	//cout << "The result is: " << counter2 << endl;

	//cout << endl;
	//// Task 3
	//int start = 1, counter3 = 0;
	//while (start <= 1000)
	//{
	//	counter3 += start;
	//	start++;
	//}
	//double avg = (double)counter3 / 1000;
	//cout << "The average is: " << avg << endl;

	//// Task 4
	//int num, counter4 = 0;
	//cout << "Enter a number in range(0 to 20): ";
	//cin >> num;
	//if (num >= 0 && num <= 20)
	//{
	//	while (num <= 20)
	//	{
	//		counter4 += num;
	//		num++;
	//	}
	//	cout << "The sum of the numbers is: " << counter4 << endl;
	//}
	//else
	//{
	//	cout << "The number is not in the range." << endl;
	//}

	//// Task 5
	//int k, counter5 = 1;
	//cout << "Enter a number: ";
	//cin >> k;
	//if (k < 0)
	//{
	//	cout << "The number is negative." << endl;
	//}
	//else
	//{
	//	while (counter5 <= 10)
	//	{
	//		cout << k << " * " << counter5 << " = " << k * counter5 << endl;
	//		counter5++;
	//	}
	//}

	// hw 2
	// Task 1
	int count = 0, num1 = 100;
	while (num1 <= 999)
	{
		int digit1 = num1 / 100;
		int digit2 = (num1 / 10) % 10;
		int digit3 = num1 % 10;
		num1++;

		if (digit1 == digit2 || digit1 == digit3 || digit2 == digit3)
		{
			count++;
		}
	}
	cout << "The number of integers with two identical digits is: " << count << endl;
	// Task 2
	int count2 = 0, num2 = 100;
	while (num2 <= 999)
	{
		int digit1 = num2 / 100;
		int digit2 = (num2 / 10) % 10;
		int digit3 = num2 % 10;
		num1++;

		if (digit1 != digit2 || digit1 != digit3 || digit2 != digit3)
		{
			count2++;
		}
	}
	cout << "The number of integers with two identical digits is: " << count2 << endl;
}