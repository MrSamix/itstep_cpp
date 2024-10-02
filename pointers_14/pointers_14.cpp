#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 5;

    // Task 1
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[SIZE];

    int* ptr1 = arr1;
    int* ptr2 = arr2;

    for (int i = 0; i < SIZE; i++)
    {
        *ptr2 = *ptr1;
        ptr1++;
        ptr2++;
    }

    cout << "Copied array: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Task 2
    int* start = arr1;
    int* end = arr1 + (SIZE-1);

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;


    // Task 3
    int arr_1[] = {1, 2, 3, 4, 5};
    int arr_2[SIZE];

    int* ptr_1 = arr_1;
    int* ptr_2 = arr_2;


    for (int i = SIZE-1; i >= 0; i--)
    {
        *ptr_2 = *(ptr_1 + i);
        ptr_2++;
    }

    cout << "Copied array in reverse order: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr_2[i] << " ";
    }
    cout << endl;
}