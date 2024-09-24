#include <iostream>
using namespace std;

// Task 1
int exponentiation(int num, int power)
{
	if (power == 0)
	{
		return 1;
	}
	else
	{
		for (int i = 0; i < power-1; i++)
		{
			num *= num;
		}
		return num;
	}
}
// Task 2
int sum_range(int num_start, int num_end)
{
	int sum = 0;
	if (num_start < num_end) // перевірка на правильність введеного діапазону
	{
		for (int i = num_start; i <= num_end; i++)
		{
			sum += i;
		}
	}
	else if (num_start > num_end)
	{
		for (int i = num_end; i <= num_start; i++)
		{
			sum += i;
		}
	}
	else
	{
		sum += num_start;
	}
	return sum;
}
// Task 3
void perfect_numbers_in_range(int start, int stop)
{
	if (start < stop) // перевірка на правильність введеного діапазону
	{
		for (int i = start; i < stop; i++)
		{
			int sum = 0;
			for (int j = 1; j < i; j++)
			{
				if (i % j == 0)
				{
					sum += j;
				}
			}
			if (sum == i)
			{
				cout << i << " is a perfect number" << endl;
			}
		}
	}
	else
	{
		for (int i = stop; i < start; i++)
		{
			int sum = 0;
			for (int j = 1; j < i; j++)
			{
				if (i % j == 0)
				{
					sum += j;
				}
			}
			if (sum == i)
			{
				cout << i << " is a perfect number" << endl;
			}
		}
	}
}

// Task 4
void card(string suit, int power)
{
    if (suit == "Spades")
    {
        cout << "Suit = ♠, power = " << power << endl;
    }
    else if (suit == "Clubs")
    {
        cout << "Suit = ♣, power = " << power << endl;
    }
    else if (suit == "Diamonds")
    {
        cout << "Suit = ♦, power = " << power << endl;
    }
    else if (suit == "Hearts")
    {
        cout << "Suit = ♥, power = " << power << endl;
    }
    else
    {
        cout << "Invalid input!" << endl;
    }
}

// Task 5
bool isluckynumber(int num)
{
	int digit_1 = (num / 100000) % 10;
	int digit_2 = (num / 10000) % 10;
	int digit_3 = (num / 1000) % 10;
	int digit_4 = (num / 100) % 10;
	int digit_5 = (num / 10) % 10;
	int digit_6 = num % 10;
	int sum_start_3 = digit_1 + digit_2 + digit_3;
	int sum_end_3 = digit_4 + digit_5 + digit_6;
	if (sum_start_3 == sum_end_3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{

	// Task 1
	cout << "Result = " << exponentiation(2, 2) << endl;

	// Task 2
	int sum = sum_range(2, 5);
	cout << "Sum = " << sum << endl;

	// Task 3
	int num_start, num_end;
	cout << "Enter start range: ";
	cin >> num_start;
	cout << "Enter end range: ";
	cin >> num_end;
	perfect_numbers_in_range(num_start, num_end);

	// Task 4
	card("Spades", 6);
	card("Clubs", 8);
	card("Diamonds", 10);
	card("Hearts", 9);

	// Task 5
	bool res = isluckynumber(123321);
	if (res)
	{
		cout << "This number is lucky!" << endl;
	}
	else
	{
		cout << "This number is not lucky!" << endl;
	}
}