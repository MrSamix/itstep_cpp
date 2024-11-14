#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue queue(10, 1);
	for (int i = 0; i < queue.getCapacity(); i++)
	{
		queue.InsertWithPriority(rand() % 5000 + 1, rand() % 30 + 1);
	}
	queue.Show();
	cout << "Return data from max priority: " << queue.Peek() << endl;
	cout << "Size: " << queue.getSize() << endl;
	queue.PullHighestPriorityElement();
	cout << "Removed max index: " << endl;
	queue.Show();
	cout << "Size: " << queue.getSize() << endl;
}