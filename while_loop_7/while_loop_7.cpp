#include <iostream>
using namespace std;

int main()
{
	// hw 1
	//// Task 1
	//int a;
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
		num2++;

		if (digit1 != digit2 && digit1 != digit3 && digit2 != digit3)
		{
			count2++;
		}
	}
	cout << "The number of integers with two unidentical digits is: " << count2 << endl;

	// Task 3
	int number;
	cout << "Enter an integer task3 : ";
	cin >> number;
	
	int result = 0;
	int multiplier = 1;
	
	while (number != 0)
	{
	    int digit = number % 10;
	    if (digit != 3 && digit != 6)
	    {
	        result += digit * multiplier;
	        multiplier *= 10;
	    }
	    number /= 10;
	}
	
	cout << "The modified number is: " << result << endl;

	// Task 4
	int A;
	cout << "Enter an integer task4 : ";
	cin >> A;
	
	int B = 1;
	while (B <= A)
	{
	    if (A % (B * B) == 0 && A % (B * B * B) != 0)
	    {
	        cout << B << endl;
	    }
	    B++;
	}

	// Task 5
	int a;
	cout << "Enter an integer task5 : ";
	cin >> a;
	
	int sum = 0;
	int number5 = a;
	while (number5 != 0)
	{
	    int digit = number5 % 10;
	    sum += digit;
	    number5 /= 10;
	}
	
	int cube = sum * sum * sum;
	
	if (cube == a * a)
	{
	    cout << "The cube of the sum of the digits is equal to A * A." << endl;
	}
	else
	{
	    cout << "The cube of the sum of the digits is not equal to A * A." << endl;
	}

	// Task 6
	int number6;
	cout << "Enter an integer task6 : ";
	cin >> number6;
	
	int divisor = 1; // дільник
	while (divisor <= number6)
	{
	    if (number6 % divisor == 0)
	    {
	        cout << divisor << endl;
	    }
	    divisor++;
	}

	// Task 7
	int number7_1, number7_2;
	cout << "Enter an integers: ";
	cin >> number7_1 >> number7_2;

	divisor = 1; // дільник
	int min = number7_1 < number7_2 ? number7_1 : number7_2;
	while (divisor <= min)
	{
		if (number7_1 % divisor == 0 && number7_2 % divisor == 0)
		{
			cout << divisor << endl;
		}
		divisor++;
	}
}