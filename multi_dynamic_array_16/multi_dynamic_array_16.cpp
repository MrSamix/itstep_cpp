#include <iostream>
using namespace std;


template <typename T>
void fill(T** arr, const size_t& row, const size_t& col, int min = 0, int max = 10)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr[i][j] = min + rand() % (max - min + 1);
        }
    }
}

template <typename T>
void print(T** arr, const size_t& row, const size_t& col, string prompt = "")
{
    if (!prompt.empty())
    {
        cout << prompt << ": " << endl;
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << arr[i][j] << "\t";
        }cout << endl;
    }
}

// ROW
// Task 1
template <typename T>
void insert_first_Row(T**& arr, int& row, const size_t& col)
{
    T** tmp = new T * [row + 1];
    for (size_t i = 0; i < row; i++)
    {
        if (i >= 0)
        {
            tmp[i + 1] = arr[i];
        }
    }
    tmp[0] = new T[col]{};
    row++;
    delete[] arr;
    arr = tmp;
}

// Task 2
template <typename T>
void insert_last_Row(T**& arr, int& row, const size_t& col)
{
    T** tmp = new T * [row + 1];
    for (size_t i = 0; i < row; i++)
    {
        if (i < row)
        {
            tmp[i] = arr[i];
        }
    }
    tmp[row] = new T[col]{};
    row++;
    delete[] arr;
    arr = tmp;
}

// Task 3
template <typename T>
void insertRow(T**& arr, int& row, const size_t& col, const size_t& index)
{
    if (index > row)
    {
        cout << "Error, out of range!" << endl;
        return;
    }
    T** tmp = new T * [row + 1];
    for (size_t i = 0; i < row; i++)
    {
        if (i < index)
        {
            tmp[i] = arr[i];
        }
        else
        {
            tmp[i + 1] = arr[i];
        }
    }
    tmp[index] = new T[col]{};
    row++;
    delete[] arr;
    arr = tmp;
}

// Task 4
template <typename T>
void removeRow(T**& arr, int& row, const size_t& index)
{
    if (index >= row)
    {
        cout << "Error, out of range!" << endl;
        return;
    }
    T** tmp = new T * [--row];
    for (size_t i = 0; i < row; i++)
    {
        if (i < index)
        {
            tmp[i] = arr[i];
        }
        else
        {
            tmp[i] = arr[i + 1];
        }
    }
    delete[] arr[index];
    delete[] arr;
    arr = tmp;
}

// Task 5
template <typename T>
void remove_first_Row(T**& arr, int& row, const size_t& col)
{
    T** tmp = new T * [row - 1];
    for (size_t i = 0; i < row; i++)
    {
        if (i >= 0)
        {
            tmp[i] = arr[i + 1];
        }
    }
    row--;
    delete[] arr;
    arr = tmp;
}

// Task 6
template <typename T>
void remove_last_Row(T**& arr, int& row, const size_t& col)
{
    T** tmp = new T * [row - 1];
    for (size_t i = 0; i < row - 1; i++)
    {
        tmp[i] = arr[i];
    }
    row--;
    delete[] arr;
    arr = tmp;
}

// COL

// Task 1
template <typename T>
void insert_first_Col(T** arr, const size_t& row, int& col, T value = T())
{
    for (size_t i = 0; i < row; i++)
    {
        T* tmp = new T[col + 1];
        for (size_t j = 0; j < col; j++)
        {
            tmp[j + 1] = arr[i][j];
        }
        tmp[0] = value;
        delete[] arr[i];
        arr[i] = tmp;
    }
    col++;
}

// Task 2
template <typename T>
void insert_last_Col(T** arr, const size_t& row, int& col, T value = T())
{
    for (size_t i = 0; i < row; i++)
    {
        T* tmp = new T[col + 1];
        for (size_t j = 0; j < col; j++)
        {
            tmp[j] = arr[i][j];
        }
        tmp[col] = value;
        delete[] arr[i];
        arr[i] = tmp;
    }
    col++;
}

// Task 3
template <typename T>
void insertCol(T** arr, const size_t& row, int& col, const size_t& index, T value = T())
{
    if (index > col)
    {
        cout << "Error, out of range";
        return;
    }
    for (size_t i = 0; i < row; i++)
    {
        T* tmp = new T[col + 1];
        for (size_t j = 0; j < col; j++)
        {
            if (j < index)
            {
                tmp[j] = arr[i][j];
            }
            else
            {
                tmp[j + 1] = arr[i][j];
            }
        }
        tmp[index] = value;
        delete[] arr[i];
        arr[i] = tmp;
    }
    col++;
}

// Task 4
template <typename T>
void removeCol(T** arr, const size_t& row, int& col, const size_t& index)
{
    if (index >= col)
    {
        cout << "Error, out of range";
        return;
    }
    col--;
    for (size_t i = 0; i < row; i++)
    {
        T* tmp = new T[col];
        for (size_t j = 0; j < col; j++)
        {
            if (j < index)
            {
                tmp[j] = arr[i][j];
            }
            else
            {
                tmp[j] = arr[i][j + 1];
            }
        }
        delete[] arr[i];
        arr[i] = tmp;
    }
}

// Task 5
template <typename T>
void remove_first_Col(T** arr, const size_t& row, int& col)
{
    col--;
    for (size_t i = 0; i < row; i++)
    {
        T* tmp = new T[col];
        for (size_t j = 0; j < col; j++)
        {
            tmp[j] = arr[i][j + 1];
        }
        delete[] arr[i];
        arr[i] = tmp;
    }
}

// Task 6
template <typename T>
void remove_last_Col(T** arr, const size_t& row, int& col)
{
    col--;
    for (size_t i = 0; i < row; i++)
    {
        T* tmp = new T[col];
        for (size_t j = 0; j < col; j++)
        {
            tmp[j] = arr[i][j];
        }
        delete[] arr[i];
        arr[i] = tmp;
    }
}

int main()
{
    // create array
    int row = 4, col = 5;
    int** arr = new int* [row];

    for (size_t i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    // fill array
    fill(arr, row, col, 1);

    // print multi array
    print(arr, row, col, "Print array");

    // ROW
    // Task 1
    insert_first_Row(arr, row, col);
    print(arr, row, col, "Print array after insert first ROW");

    // Task 2
    insert_last_Row(arr, row, col);
    print(arr, row, col, "Print array after insert last ROW");

    // Task 3
    insertRow(arr, row, col, 2);
    print(arr, row, col, "Print array after insert ROW");

    // Task 4
    removeRow(arr, row, 1);
    print(arr, row, col, "Print array after remove ROW");

    // Task 5
    remove_first_Row(arr, row, col);
    print(arr, row, col, "Print array after remove first ROW");

    // Task 6
    remove_last_Row(arr, row, col);
    print(arr, row, col, "Print array after remove last ROW");

    // COL
    // Task 1
    insert_first_Col(arr, row, col, 55);
    print(arr, row, col, "Print array after insert first COL");

    // Task 2
    insert_last_Col(arr, row, col, 555);
    print(arr, row, col, "Print array after insert last COL");

    // Task 3
    insertCol(arr, row, col, 2, -1);
    print(arr, row, col, "Print array after insert COL");

    // Task 4
    removeCol(arr, row, col, 3);
    print(arr, row, col, "Print array after remove COL");

    // Task 5
    remove_first_Col(arr, row, col);
    print(arr, row, col, "Print array after remove first COL");

    // Task 6
    remove_last_Col(arr, row, col);
    print(arr, row, col, "Print array after remove last COL");
}