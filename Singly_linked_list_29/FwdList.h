#pragma once
#include <iostream>

using std::cout;
using std::endl;

template<typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node(const T& data = T(), Node<T>* next = nullptr)
		:data(data), next(next) {}
};

template <typename T>
class FwdList
{
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
public:
	FwdList() = default;
	FwdList<T>& operator = (const FwdList<T>& other);
	FwdList<T> clone() const;
	FwdList operator+(const FwdList& fwd_other) const;
	FwdList operator*(const FwdList& fwd_other) const;
	bool empty() const;
	void print() const;
	void clear();

	// head
	void addHead(const T& data);
	void removeHead();

	// tail
	void addTail(const T& data);

	// dtor
	~FwdList()
	{
		clear();
	}
	
};

template<typename T>
inline FwdList<T> FwdList<T>::clone() const
{
	FwdList<T> newList;
	if (empty()) 
		return newList;

	Node<T>* tmp = head;
	while (tmp) {
		newList.addTail(tmp->data);
		tmp = tmp->next;
	}
	return newList;
}

template<typename T>
inline FwdList<T> FwdList<T>::operator+(const FwdList<T>& fwd_other) const
{
	FwdList<T> result = this->clone();
	Node<T>* tmp = fwd_other.head;
	while (tmp) {
		result.addTail(tmp->data);
		tmp = tmp->next;
	}
	return result;

}

template<typename T>
inline FwdList<T> FwdList<T>::operator*(const FwdList& other) const
{
	FwdList<T> result;
	Node<T>* tmp = head;
	while (tmp) {
		Node<T>* otherTmp = other.head;
		while (otherTmp) {
			if (tmp->data == otherTmp->data) {
				result.addTail(tmp->data);
				break;
			}
			otherTmp = otherTmp->next;
		}
		tmp = tmp->next;
	}
	return result;
}

template<typename T>
inline bool FwdList<T>::empty() const
{
	return head == nullptr;
}

template<typename T>
inline void FwdList<T>::print() const
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
inline void FwdList<T>::clear()
{
	if (empty())
		return;
	for (int i = 0; i < size; i++)
	{
		removeHead();
	}
}

template<typename T>
inline void FwdList<T>::addHead(const T& data)
{
	Node<T>* tmp = new Node<T>(data, head);
	if (empty())
	{
		tail = tmp;
	}

	head = tmp;
	++size;
}

template<typename T>
inline void FwdList<T>::removeHead()
{
	if (empty())
		return;
	auto tmp = head;
	head = head->next;
	if (empty())
		tail = nullptr;
	delete tmp;
	--size;
}

template<typename T>
inline void FwdList<T>::addTail(const T& data)
{
	Node<T>* tmp = new Node<T>(data);
	if (empty())
	{
		head = tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tmp;
	}
	++size;
}

template<typename T>
inline FwdList<T>& FwdList<T>::operator=(const FwdList<T>& other)
{
	if (this == &other)
		return *this;

	clear();

	Node<T>* tmp = other.head;
	while (tmp) {
		addTail(tmp->data);
		tmp = tmp->next;
	}

	return *this;
}
