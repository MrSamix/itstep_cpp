#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Element
{
	int data;
	int priority;
	Element(const int& data = 0, const int& priority = 0)
		:data(data), priority(priority)
	{}
	string toString() const
	{
		return "[" + to_string(priority) + "] " + to_string(data);
	}
};

class Queue
{
	enum Default
	{
		DEFAULT_CAPACITY = 0,
		DEFAULT_GROW = 1,
		DEFAULT_PRIORITY = 0,
		DEFAULT_SIZE = 0
	};
public:
	Queue(const int& capacity = DEFAULT_CAPACITY, const int& grow = DEFAULT_GROW)
		: capacity(capacity), grow(grow)
	{
		queue = new Element[capacity];
	}
	bool IsEmpty() const;
	bool IsFull() const;
	void InsertWithPriority(const int& data, const int& priority);
	void PullHighestPriorityElement();
	int Peek() const;
	void Show() const;
	int getSize() const { return size; }
	int getCapacity() const { return capacity; }
private:
	Element* queue = nullptr;
	int capacity;
	int size = DEFAULT_SIZE;
	int grow;
	void reserve();
	int highpriority() const;
};

inline bool Queue::IsEmpty() const
{
	return size == 0;
}

inline bool Queue::IsFull() const
{
	return size == capacity;
}

inline void Queue::InsertWithPriority(const int& data, const int& priority)
{
	if (IsFull())
		reserve();
	queue[size++] = Element(data, priority);
}

inline void Queue::PullHighestPriorityElement()
{
	int index = highpriority();
	for (int i = index; i < size-1; i++)
	{
		queue[i] = queue[i + 1];
	}
	size--;
}

inline int Queue::Peek() const
{
	return queue[highpriority()].data;
}

inline void Queue::Show() const
{
	cout << "Print queue:\t";
	for (int i = 0; i < size; i++)
	{
		cout << queue[i].toString() << "\t";
	}
	cout << endl;
}

inline void Queue::reserve()
{
	Element* tmp = new Element[capacity += grow];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = queue[i];
	}
	delete[] queue;
	queue = tmp;
}

inline int Queue::highpriority() const
{
	int max_index = 0;
	for (int i = 0; i < size; i++)
	{
		if (queue[max_index].priority < queue[i].priority)
		{
			max_index = i;
		}
	}
	return max_index;
}
