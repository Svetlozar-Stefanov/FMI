#pragma once

template<typename T>
class myVector
{
public:
	myVector();
	myVector(const myVector<T>& other);
	myVector<T>& operator=(const myVector<T>& other);
	~myVector();

	int length() const;
	void Add(const T& el);

	bool Delete(const int i);

	const T& operator[](const int i) const;

private:
	T* items;
	int index, size;

	void free();
	void copy(const myVector<T>& other);
	void resize();
};

template<typename T>
myVector<T>::myVector()
{
	index = 0;
	size = 5;
	items = new T[size];
}

template<typename T>
myVector<T>::myVector(const myVector<T>& other)
{
	copy(other);
}

template<typename T>
myVector<T>& myVector<T>::operator=(const myVector<T>& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

template<typename T>
myVector<T>::~myVector()
{
	free();
}

template<typename T>
inline int myVector<T>::length() const
{
	return index;
}

template<typename T>
void myVector<T>::Add(const T& el)
{
	if (index >= size)
	{
		resize();
	}

	items[index++] = el;
}

template<typename T>
bool myVector<T>::Delete(const int i)
{
	if (i >= index)
	{
		return false;
	}

	items[i] = T();

	return true;
}

template<typename T>
const T& myVector<T>::operator[](const int i) const
{
	if (i >= index)
	{
		throw "Out of range";
	}

	return items[i];
}

template<typename T>
void myVector<T>::free()
{
	delete[] items;
}

template<typename T>
void myVector<T>::copy(const myVector<T>& other)
{
	index = other.index;
	size = other.size;
	items = new	T[size];
	for (int i = 0; i < index; i++)
	{
		items[i] = other.items[i];
	}
}

template<typename T>
void myVector<T>::resize()
{
	T* temp = new T[size *= 2];
	for (int i = 0; i < index; i++)
	{
		temp[i] = items[i];
	}

	delete[] items;
	items = temp;
}
