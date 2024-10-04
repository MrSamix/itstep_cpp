#include <iostream>
using namespace std;

void fillArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10 + 1;
    }
}


void printArray(int* arr, int size, string prompt = "")
{
    if (!prompt.empty())
    {
        cout << prompt << ": " << "  ";
    }
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}


int* comparisonArray(int* arr, int* size_1, int* arr_2, int* size_2, int* size_3)
{
    // counter
    int counter = 0;
    for (int i = 0; i < *size_1; i++)
    {
        bool Flag = true;
        for (int j = 0; j < *size_2; j++)
        {
            if (arr[i] == arr_2[j])
            {
                Flag = false;
                break;
            }
        }
        for (int w = 0; w < i && Flag; w++) // перевірка на унікальні значення в масиві
        {
            if (arr[i] == arr[w])
            {
                Flag = false;
                break;
            }
        }
        if (Flag)
        {
            counter++;
        }
	}
    // запис в новий масив
    int* C = new int[counter];
    int index_c = 0;
    for (int i = 0; i < *size_1; i++)
    {
        bool Flag = true;
        for (int j = 0; j < *size_2; j++)
        {
            if (arr[i] == arr_2[j])
            {
                Flag = false;
                break;
            }
        }
        for (int w = 0; w < i && Flag; w++) // перевірка на унікальні значення в масиві
        {
            if (arr[i] == arr[w])
            {
                Flag = false;
                break;
            }
        }
        if (Flag)
        {
            C[index_c++] = arr[i];
        }
    }
    *size_3 = counter;
    return C;
}


int* comparisonArray_2(int* arr, int* size_1, int* arr_2, int* size_2, int* size_3)
{
    // counter
    int counter = 0;

    // check A array
    for (int i = 0; i < *size_1; i++)
    {
        bool Flag = true;
        for (int j = 0; j < *size_2; j++)
        {
            if (arr[i] == arr_2[j])
            {
                Flag = false;
                break;
            }
        }
        for (int w = 0; w < i && Flag; w++) // перевірка на унікальні значення в масиві
        {
            if (arr[i] == arr[w])
            {
                Flag = false;
                break;
            }
        }
        if (Flag)
        {
            counter++;
        }
    }

    // check B array
    for (int i = 0; i < *size_2; i++)
    {
        bool Flag = true;
        for (int j = 0; j < *size_1; j++)
        {
            if (arr_2[i] == arr[j])
            {
                Flag = false;
                break;
            }
        }
        for (int w = 0; w < i && Flag; w++) // перевірка на унікальні значення в масиві
        {
            if (arr_2[i] == arr_2[w])
            {
                Flag = false;
                break;
            }
        }
        if (Flag)
        {
            counter++;
        }
    }
    // запис в новий масив
    int* C = new int[counter];
    int index_c = 0;
    // check A array
    for (int i = 0; i < *size_1; i++)
    {
        bool Flag = true;
        for (int j = 0; j < *size_2; j++)
        {
            if (arr[i] == arr_2[j])
            {
                Flag = false;
                break;
            }
        }
        for (int w = 0; w < i && Flag; w++) // перевірка на унікальні значення в масиві
        {
            if (arr[i] == arr[w])
            {
                Flag = false;
                break;
            }
        }
        if (Flag)
        {
            C[index_c++] = arr[i];
        }
    }

    // check B array
    for (int i = 0; i < *size_2; i++)
    {
        bool Flag = true;
        for (int j = 0; j < *size_1; j++)
        {
            if (arr_2[i] == arr[j])
            {
                Flag = false;
                break;
            }
        }
        for (int w = 0; w < i && Flag; w++) // перевірка на унікальні значення в масиві
        {
            if (arr_2[i] == arr_2[w])
            {
                Flag = false;
                break;
            }
        }
        if (Flag)
        {
            C[index_c++] = arr_2[i];
        }

    }
    *size_3 = index_c;
    return C;
}


int main()
{
    srand(time(0));
    // Task 1
    int m, n;
    cout << "Enter M number: ";
    cin >> m;
    cout << "Enter N number: ";
    cin >> n;

    int* A = new int[m];
    int* B = new int[n];

    fillArray(A, m);
    fillArray(B, n);

    printArray(A, m, "Print array A");
    printArray(B, n, "Print array B");


    int k;
    int* C = comparisonArray(A, &m, B, &n, &k);
    printArray(C, k, "Print array C");

    delete[] C;

    // Task 2
    cout << "\n\n";
    printArray(A, m, "Print array A");
    printArray(B, n, "Print array B");

    int k_new = 0;
    int* C_new = comparisonArray_2(A, &m, B, &n, &k_new);

    printArray(C_new, k_new, "Print array C");
}