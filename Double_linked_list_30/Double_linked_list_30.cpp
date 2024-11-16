#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List<int> list;
	for (size_t i = 0; i < 5; i++)
	{
		list.addHead(rand() % 50);
	}
	list.print();


	list.insertNode(2, 3333);
	cout << "Inserted: " << endl;
	list.print();

	list.deleteNode(2);
	cout << "Deleted: " << endl;
	list.print();

	cout << "Index: " << list.findNodebyData(34) << endl;
	cout << "Replaced " << list.replace(34, 3333) << " elements." << endl;
	list.print();


	cout << "Reversed list: " << endl;
	list.reverse();
	list.print();
}