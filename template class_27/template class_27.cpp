#include <iostream>
#include "Array.h"
using namespace std;


int main()
{
    Array<int> arr;
	cout << "Is Empty: " << boolalpha << arr.IsEmpty() << endl;
	for (int i = 0; i < 20; i++)
	{
		arr.Add(rand() % 100 + 1);
	}
	arr.print();
	arr.SetSize(10);
	cout << "Current size: " << arr.GetSize() << endl;
	arr.print();

	cout << "added 33333 in index 3" << endl;
	arr.InsertAt(3, 33333);
	arr.print();

	cout << "remove 0 index" << endl;
	arr.RemoveAt(0);
	arr.print();

	cout << "Id arr: " << arr.GetData() << endl;
}