#include <iostream>
using namespace std;

// Task 1
template <typename T>
void inputArray(T arr[], int count_of_elements)
{
	T temp;
	for (size_t i = 0; i < count_of_elements; i++)
	{
		cout << "Enter element: ";
		cin >> temp;
		arr[i] = temp;
	}
}
// Task 2
template <typename T>
void printArray(T arr[], int count_of_elements)
{
	for (size_t i = 0; i < count_of_elements; i++)
	{
		cout << arr[i] << "\t";
	} cout << "\n\n";
}

// Task 3
template <typename T>
int searchArray(T arr[], int count_of_elements, T key)
{
	for (int i = 0; i < count_of_elements; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}


// char(Task 3)
int searchArray(char arr[], int count_of_elements, char key)
{
	for (int i = 0; i < count_of_elements; i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			arr[i] = arr[i] + 32;
		}
	}
	for (int i = 0; i < count_of_elements; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}


// Task 4
template <typename T>
int searchArray2(T arr[], int count_of_elements, T key)
{
	for (int i = count_of_elements-1; i >= 0; i--)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}


// char task 4
int searchArray2(char arr[], int count_of_elements, char key)
{
	for (int i = 0; i < count_of_elements; i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			arr[i] = arr[i] + 32;
		}
	}
	for (int i = count_of_elements - 1; i >= 0; i--)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}



// Task 5
template <typename T>
void shuffleArray(T arr[], int count_of_elements)
{
	srand(time(0));
	int i_temp;
	T temp;
	for (int i = 0; i < count_of_elements; i++)
	{
		i_temp = rand() % count_of_elements;
		if (i == i_temp)
		{
			i_temp = rand() % count_of_elements;
		}
		temp = arr[i_temp];
		arr[i_temp] = arr[i];
		arr[i] = temp;
	}
}

// Task 6
template <typename T>
void fillArray(T arr[], int length, T fill_item)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = fill_item;
	}
}

// Task 7
template <typename T>
void sortArrayByGrowth(T arr[], int SIZE)
{
	T temp;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = SIZE - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// Task 8
template <typename T>
void sortArrayByDescending(T arr[], int SIZE)
{
    T temp;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = SIZE - 1; j > i; j--)
        {
            if (arr[j - 1] < arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
	// Task 1
	int const SIZE = 10;
	char arr[SIZE]{};
	inputArray(arr, SIZE);

	// Task 2
	printArray(arr, SIZE);

	// Task 3
	cout << "Result = " << searchArray(arr, SIZE, 'h') << endl;

	// Task 4
	cout << "Result = " << searchArray2(arr, SIZE, 'h') << endl;

	// Task 5
	shuffleArray(arr, SIZE);
	printArray(arr, SIZE);

	// Task 6
	char arr_to_fill[SIZE]{};
	fillArray(arr_to_fill, SIZE, 'h');
	printArray(arr_to_fill, SIZE);

	// Task 7
	sortArrayByGrowth(arr, SIZE);
	printArray(arr, SIZE);

	// Task 8
	sortArrayByDescending(arr, SIZE);
	printArray(arr, SIZE);
}