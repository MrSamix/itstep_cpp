#pragma once
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
struct Node
{
	T data;
	Node* next, *prev;
	Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
		:data(data), prev(prev),next(next)
	{}
};

template <typename T>
class List
{
public:
	List() = default;
	~List()
	{
		clear();
	}
	List(const List<T>& other) // copy ctor
	{
		auto tmp = other.head;
		while (tmp != nullptr)
		{
			addTail(tmp->data);
			tmp = tmp->next;
		}
	}
	List<T>& operator=(const List<T>& other);
	void clear();
	void addHead(const T& data);
	void addTail(const T& data);
	void removeHead();
	void print() const;
	void printR() const;
	bool empty() const;
	void removeByData(const T& data);
	void removeTail();

	void insertNode(const size_t& index, const T& data);
	void deleteNode(const size_t& index);
	int findNodebyData(const T& data) const;
	int replace(const T& search, const T& replace);
	void reverse();
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
	Node<T>* findNode(const T& data);
};

template<typename T>
inline List<T>& List<T>::operator=(const List<T>& other)
{
	if (this == &other) {
		return *this;
	}
	clear();
	Node<T>* current = other.head;
	while (current) {
		addHead(current->data);
		current = current->next;
	}

	return *this;
}

template<typename T>
inline void List<T>::clear()
{
	if (empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	while (!empty())
	{
		removeTail();
	}
	cout << "Cleared!" << endl;
}

template<typename T>
inline void List<T>::addHead(const T& data)
{
	auto tmp = new Node<T>(data, nullptr, head);
	if (empty())
		tail = tmp;
	if(!empty())
		head->prev = tmp;
	head = tmp;
	size++;

}

template<typename T>
inline void List<T>::addTail(const T& data)
{
	auto tmp = new Node<T>(data, tail, nullptr);

	if (!empty())
		tail->next = tmp;
	if (empty())
		head = tmp;
	tmp->prev = tail;
	tail = tmp;
	size++;
}

template<typename T>
inline void List<T>::removeHead()
{
	if (empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	auto tmp = head;
	head = head->next;
	delete tmp;
	if (empty())
		tail = nullptr;
	else
		head->prev = nullptr;
	size--;
}

template<typename T>
inline void List<T>::print() const
{
	if (empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	auto tmp = head;
	cout << "List: \t";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void List<T>::printR() const
{
	if (empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	auto tmp = tail;
	cout << "List: \t";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->prev;
	}
	cout << endl;
}

template<typename T>
inline bool List<T>::empty() const
{
	return head == nullptr;
}

template<typename T>
inline void List<T>::removeByData(const T& data)
{
	auto find = findNode(data);
	if (find == nullptr)
	{
		cout << "Data not found" << endl;
		return;
	}
	if (find == head)
	{
		removeHead();
		return;
	}
	if (find == tail)
	{
		removeTail();
		return;
	}
	find->prev->next = find->next;
	find->next->prev = find->prev;

	delete find;
	size--;
}

template<typename T>
inline void List<T>::removeTail()
{
	if (empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	auto tmp = tail;
	if (tmp == head)
	{
		removeHead();
		return;
	}
	tmp->prev->next = nullptr;
	tail = tmp->prev;
	delete tmp;
	size--;
}

template<typename T>
inline int List<T>::findNodebyData(const T& data) const
{
	auto tmp = head;
	size_t index = 0;
	while (tmp != nullptr && tmp->data != data)
	{
		tmp = tmp->next;
		index++;
	}
	if (tmp == nullptr || tmp->data != data)
	{
		return NULL;
	}
	else if (tmp->data == data)
	{
		return index;
	}
}

template<typename T>
inline int List<T>::replace(const T& search, const T& replace)
{
	size_t counter = 0;
	auto currentNode = head;
	for (int i = 0; i < size; i++)
	{
		if (currentNode->data == search)
		{
			currentNode->data = replace;
			counter++;
		}
		currentNode = currentNode->next;
	}
	if (counter == 0)
	{
		return -1;
	}
	else
	{
		return counter;
	}
}

template<typename T>
inline void List<T>::reverse()
{
	auto currentNode = tail;
	for (int i = 0; i < size; i++)
	{
		auto next_tmp = currentNode->next;
		auto prev_tmp = currentNode->prev;
		currentNode->next = prev_tmp;
		currentNode->prev = next_tmp;

		currentNode = currentNode->next;
	}
	auto head_tmp = head;
	head = tail;
	tail = head_tmp;
}

template<typename T>
inline void List<T>::insertNode(const size_t& index, const T& data)
{
	if (index > size || index < 0)
	{
		cout << "Error, index out of range!" << endl;
		return;
	}
	if (index == size)
	{
		addTail(data);
		return;
	}
	if (index == 0)
	{
		addHead(data);
		return;
	}
	auto currentNode = head;
	for (size_t i = 0; i < index; i++)
	{
		currentNode = currentNode->next;
	}
	auto newNode = new Node<T>(data, currentNode->prev, currentNode);
	currentNode->prev->next = newNode;
	currentNode->prev = newNode;
	size++;
}

template<typename T>
inline void List<T>::deleteNode(const size_t& index)
{
	if (index >= size || index < 0)
	{
		cout << "Error, index out of range!" << endl;
		return;
	}
	auto currentNode = head;
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->next;
	}
	currentNode->next->prev = currentNode->prev;
	currentNode->prev->next = currentNode->next;
	delete currentNode;
	--size;
}

template<typename T>
inline Node<T>* List<T>::findNode(const T& data)
{
	auto tmp = head;
	while (tmp != nullptr && tmp->data != data)
	{
		tmp = tmp->next;
	}

	return tmp;
}
