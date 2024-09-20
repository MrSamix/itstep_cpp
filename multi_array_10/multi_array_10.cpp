#include <iostream>
using namespace std;

int main()
{
	// Task 1
	const int ROW = 5, COL = 5;
	int array[ROW][COL]{};
	cout << "Enter first number: ";
	cin >> array[0][0];
	int counter = array[0][0];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (j == 0 && i == 0)
			{
				cout << array[0][0] << "\t";
			}
			else if (i == 4 && j >= 2)
			{
				counter *= 2;
				array[i][j] = counter;
				cout << array[i][j] << " ";
			}
			else
			{
				counter *= 2;
				array[i][j] = counter;
				cout << array[i][j] << "\t";
			}
		}
		cout << endl;
	}
	// Task 2
	{
		const int ROW = 5, COL = 5;
		int array[ROW][COL]{};
		cout << "Enter first number: ";
		cin >> array[0][0];
		int counter = array[0][0];
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				if (j == 0 && i == 0)
				{
					cout << array[0][0] << "\t";
				}
				else
				{
					counter += 1;
					array[i][j] = counter;
					cout << array[i][j] << "\t";
				}
			}
			cout << endl;
		}
		cout << "\n\n";
	}
	// Task 3
	srand(time(0));
	const int row = 2, col = 6;
	int arr[row][col]{};

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
	// print array
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n\n";

	// зміщення на 2 елементи
	for (size_t w = 0; w < 2; w++)
	{
		for (size_t i = 0; i < row; i++)
		{
			int temp = arr[i][col - 1];
			for (int j = col - 1; j > 0; j--)
			{
				arr[i][j] = arr[i][j - 1];
			}
			arr[i][0] = temp;
		}
	}
	// print array
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}