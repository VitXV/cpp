#pragma once
#include <iostream>
using namespace std;

class Exception{};

const int DEFAULT_CAPACITY = 16;
template <class T> class Array{
	T* ptr;
	int size; // количество фактически используемых элементов
	int capacity; // фактическое число элементов в памяти
	
public:
	T& operator[](int index)
	{
		if (index >= size || index < 0)
		{
			throw Exception();
		}
		else
		{
			return ptr[index];
		}
	}
	void increaseCapacity(int newCapacity)
	{
		newCapacity < capacity * 2 ? capacity *= 2 : capacity = newCapacity;
		T* newPtr = new T[capacity];
		for (int i = 0;i < size;i++)
			newPtr[i] = ptr[i];
		delete[] ptr;
		ptr = newPtr;
	}
	void insert(T elem, int index)
	{
		if (index < 0 || index > size)
			throw Exception();
		if (size == capacity)
			increaseCapacity(size + 1);
		for (int j = size - 1; j >= index; j--)
			ptr[j + 1] = ptr[j];
		size++;
		ptr[index] = elem;
	}
	void insert(T elem)
	{
		insert(elem, size);
	}
	void remove(int index)
	{
		if (index < 0 || index >= size)
			throw Exception();
		for (int j = index; j < size - 1; j++)
			ptr[j] = ptr[j + 1];
		ptr[size - 1] = 0;
		size--;
	}

	int getSize() const
	{
		return size;
	}

	friend ostream& operator << (ostream& out, const Array<T>& arr)
	{
		out << "Total size: " << arr.size << endl;
		for (int i = 0; i < arr.size; i++)
			out << arr.ptr[i] << endl;
		return out;
	}

	explicit Array(int startCapacity)
	{
		if (startCapacity <= 0)
			capacity = DEFAULT_CAPACITY;
		else
			capacity = startCapacity;
		ptr = new T[capacity];
		size = 0;
	}
	Array(const Array& arr)
	{
		ptr = new T[arr.capacity];
		size = arr.size;
		capacity = arr.capacity;
		for (int i = 0; i < size; i++)
			ptr[i] = arr.ptr[i];
	}
	Array& operator =(const Array& arr)
	{
		if (this == &arr)
			return *this;
		if (capacity != arr.capacity)
		{
			delete[] ptr;
			ptr = new T[arr.capacity];
			capacity = arr.capacity;
		}
		size = arr.size;
		for (int i = 0; i < size; i++)
			ptr[i] = arr.ptr[i];
		return *this;
	}

	~Array()
	{
		delete[] ptr;
	}

};

