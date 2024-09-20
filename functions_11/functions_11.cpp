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

// Task 4
void card(string suit, int power)
{
	if (suit == "Spades")
	{
		cout << "Suit = \u2660, power = " << power << endl; // Unicode for ♠
	}
	else if (suit == "Clubs")
	{
		cout << "Suit = \u2663, power = " << power << endl; // Unicode for ♣
	}
	else if (suit == "Diamonds")
	{
		cout << "Suit = \u2666, power = " << power << endl; // Unicode for ♦
	}
	else if (suit == "Hearts")
	{
		cout << "Suit = L\u2665, power = " << power << endl; // Unicode for ♥
	}
	else
	{
		cout << "Invalid input!" << endl;
	}
}

int main()
{

	// Task 1
	cout << exponentiation(2, 2) << endl;

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
}