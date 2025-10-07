#pragma once
template <class T>
class myVector
{
private:
	const unsigned int START_SIZE = 20;
public:
	myVector();
	myVector(T* arr, const int lastIndex);
	myVector(const myVector&);
	myVector& operator=(const myVector&);
	T& operator[](const int) const;
	~myVector();
	
	void Add(T newEl);
	void Last();
	int GetSize() const;

private:
	unsigned int currentMaxSize;

	T* arr;
	int index;

	void resize();
};

template<class T>
inline myVector<T>::myVector()
{
	arr = new T[START_SIZE];
	currentMaxSize = START_SIZE;
	index = -1;
}

template<class T>
inline myVector<T>::myVector(T* arr, const int lastIndex)
{
	for (int i = 0; i < arr.GetSize(); i++)
	{
		this->arr[i] = arr[i];
	}
	index = lastIndex;
}

template<class T>
inline myVector<T>::myVector(const myVector& newVec)
{
	for (int i = 0; i < newVec.GetSize(); i++)
	{
		if (i >= currentMaxSize)
		{
			resize();
		}
		this->arr[i] = newVec[i];
	}
	index = newVec.index;
}

template<class T>
inline myVector<T>& myVector<T>::operator=(const myVector& newVec)
{
	for (int i = 0; i < newVec.GetSize(); i++)
	{
		if (i >= currentMaxSize)
		{
			resize();
		}
		this->arr[i] = newVec[i];
	}
	index = newVec.index;
	return *this;
}

template<class T>
inline T& myVector<T>::operator[](const int i) const
{
	if (i >= 0 && i < currentMaxSize)
	{
		return arr[i];
	}
}

template<class T>
inline myVector<T>::~myVector()
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
}

template<class T>
inline void myVector<T>::Add(T newEl)
{
	if (index == -1)
	{
		index = 0;
	}
	if (index >= currentMaxSize)
	{
		resize();
	}
	if (index < currentMaxSize)
	{
		arr[index] = newEl;
		index++;
	}
}

template<class T>
inline void myVector<T>::Last()
{
	return arr[index];
}

template<class T>
inline int myVector<T>::GetSize() const
{
	if (index == -1)
	{
		return 0;
	}
	return index;
}

template<class T>
inline void myVector<T>::resize()
{
	T* temp = arr;
	unsigned int tempSize = currentMaxSize * 2;
	if (tempSize <= currentMaxSize)
	{
		return;
	}
	arr = new T[tempSize];
	for (int i = 0; i < currentMaxSize; i++)
	{
		arr[i] = temp[i];
	}

	delete[] temp;
	currentMaxSize = tempSize;
}
