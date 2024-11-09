#include "Vector.h"
#include <iostream>
#include <string>
#include <cstring>

Vector::Vector()
	:Vector(1)
{
}

Vector::Vector(const size_t& size)
	:size(size), capacity(size)
{
	this->arr = new int[this->size] {};
}

Vector::Vector(const size_t& size, const int& value)
	:Vector(size)
{
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = value;
	}
}

Vector::Vector(const Vector& other)
	:Vector(other.size)
{
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = other.arr[i];
	}
}

Vector& Vector::operator=(const Vector& other)
{
	if (this->arr != nullptr)
		delete[] this->arr;
	this->size = other.size;
	this->capacity = this->size;
	this->arr = new int[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}

void Vector::print() const
{
	std::cout << "Array has size = " << size << "; capacity = " << capacity << "\n\t";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}

Vector::~Vector()
{
	if (arr != nullptr)
		delete[] arr;
}

int Vector::operator[](size_t index) const
{
	if (isValidIndex(index))
		return arr[index];
	std::cout << ">>>>>>>>> Error index (get) :" << index << std::endl;
	return INT_MIN;
}

int& Vector::operator[](size_t index)
{
	static int errVal;
	if (isValidIndex(index))
		return arr[index];
	std::cout << ">>>>>>>>> Error index (set) : " << index << std::endl;
	return errVal;
}

Vector Vector::operator()(size_t startIndex, size_t lastIndex) const
{
	if (startIndex > lastIndex)
		std::swap(startIndex, lastIndex);
	if (!isValidIndex(startIndex))
		return Vector(0);
	if (lastIndex >= size)
		lastIndex = size - 1;
	Vector tmp(lastIndex - startIndex + 1);
	for (size_t i = 0; i <= tmp.size; i++)
	{
		tmp[i] = this->arr[i + startIndex];
	}
	return tmp;
}

Vector Vector::operator+(const Vector& other) const
{
	size_t size = this->size + other.size;
	Vector tmp(size);
	size_t index = 0;
	for (size_t i = 0; i < this->size; i++) // from a arr
	{
		tmp[index++] = arr[i];
	}
	for (size_t i = 0; i < other.getSize(); i++) // from b arr
	{
		tmp[index++] = other.arr[i];
	}
	return tmp;
}

Vector Vector::operator-(const Vector& other) const
{
	// counter
	size_t size = 0;
	bool Flag = true;
	for (size_t i = 0; i < this->size; i++)
	{
		Flag = true;
		for (size_t j = 0; j < other.getSize(); j++)
		{
			if (arr[i] == other.arr[j])
			{
				Flag = false;
				break;
			}
		}
		if (Flag)
		{
			size++;
		}
	}
	Vector tmp(size);
	size_t index = 0;
	// write
	for (size_t i = 0; i < this->size; i++)
	{
		Flag = true;
		for (size_t j = 0; j < other.getSize(); j++)
		{
			if (arr[i] == other.arr[j])
			{
				Flag = false;
				break;
			}
		}
		if (Flag)
		{
			tmp[index++] = arr[i];
		}
	}
	return tmp;
}

Vector Vector::operator*(const size_t& n) const
{
	Vector tmp(this->size);
	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i] = arr[i] * n;
	}
	return tmp;
}

Vector::operator int() const
{
	int sum = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

Vector::operator char* () const
{
	if (size == 0) {
		char* emptyStr = new char[1];
		emptyStr[0] = '\0';
		return emptyStr;
	}

	std::string res;
	for (size_t i = 0; i < size; ++i) {
		res += std::to_string(arr[i]);
		if (i < size - 1) {
			res += "\t";
		}
	}

	char* tmp = new char[res.size() + 1];
	strcpy_s(tmp, res.size() + 1, res.c_str());
	return tmp;
}

void Vector::pushBack(const int& value)
{
	if (size >= capacity)
		resize();
	arr[size++] = value;
}

void Vector::pushFront(const int& value)
{
	if (size >= capacity)
		resize();
	int* tmp = new int[this->capacity];
	++size;
	for (size_t i = 1; i < this->size; i++)
	{
		tmp[i] = this->arr[i - 1];
	}
	tmp[0] = value;
	delete[] this->arr;
	this->arr = tmp;
}

void Vector::insert(const int& value, const size_t& index)
{
	if (size >= capacity)
		resize();
	int* tmp = new int[this->capacity];
	++size;
	for (size_t i = 0; i < this->size; i++)
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
	tmp[index] = value;
	delete[] arr;
	arr = tmp;
}

void Vector::popBack()
{
	size--;
}

void Vector::popFront()
{
	int* tmp = new int[this->capacity];
	--size;
	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i] = arr[i + 1];
	}
	delete[] arr;
	arr = tmp;
}

void Vector::remove(const size_t& index)
{
	int* tmp = new int[this->capacity];
	--size;
	for (size_t i = 0; i < this->size; i++)
	{
		if (i < index)
		{
			tmp[i] = arr[i];
		}
		else
		{
			tmp[i] = arr[i+1];
		}
	}
	delete[] arr;
	arr = tmp;
}

int Vector::find(const int& value)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

inline void Vector::resize()
{
	this->capacity *= 2;
	int* tmp = new int[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;
}
