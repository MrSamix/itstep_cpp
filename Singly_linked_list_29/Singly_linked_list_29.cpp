#include <iostream>
#include "FwdList.h"

using namespace std;

int main()
{
	FwdList<int> list;
	list.addTail(22);
	list.addTail(33);
	for (int i = 0; i < 2; i++)
	{
		list.addHead(rand() % 2 + 1);
		//list.print();
	}
	cout << "List 1 :\n";
	list.print();
	cout << "\n\n";
	
	
	FwdList<int> listclone;
	listclone = list.clone();
	cout << "Cloned list: \n";
	listclone.print();
	cout << "\n\n";
	
	
	FwdList<int> list2;
	list2.addTail(22);
	list2.addTail(44);
	cout << "List 2: \n";
	list2.print();
	cout << "\n\n";
	
	
	FwdList<int> list22 = list + list2;
	cout << "list + list2: " << endl;
	list22.print();
	cout << "\n\n";
	
	FwdList<int> list33 = list * list2;;
	cout << "list * list2: " << endl;
	list33.print();
}