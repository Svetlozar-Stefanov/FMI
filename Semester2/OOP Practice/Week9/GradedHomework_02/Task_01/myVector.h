#pragma once
template <class T>
class myVector
{
private:
	const unsigned int MAX_SIZE = 2024;
public:
	myVector();
	myVector(T* arr, const int lastIndex);
	myVector(const myVector&);
	myVector& operator=(const myVector&);
	T& operator[](const int) const;
	~myVector();
	
	void Add(T newEl);
	//void Add(T &newEl);
	void Last();
	unsigned int GetSize() const;

private:
	T* arr;
	unsigned int index;
};

template<class T>
inline myVector<T>::myVector()
{
	arr = new T[MAX_SIZE];
	index = 0;
}

template<class T>
inline myVector<T>::myVector(T* arr, const int lastIndex)
{
	this->arr = arr;
	index = lastIndex;
}

template<class T>
inline myVector<T>::myVector(const myVector& newVec)
{
	this->arr = newVec.arr;
	this->index = newVec.index;
}

template<class T>
inline myVector<T>& myVector<T>::operator=(const myVector& newVec)
{
	if (arr != nullptr)
	{
		delete[] arr;
		this->arr = newVec.arr;
	}
	
	this->index = newVec.index;

	return *this;
}

template<class T>
inline T& myVector<T>::operator[](const int i) const
{
	if (i >= 0 && i < MAX_SIZE)
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
	if (index < MAX_SIZE - 1)
	{
		arr[index] = newEl;
		index++;
	}
}

//template<class T>
//inline void myVector<T>::Add(T& newEl)
//{
//	if (index < MAX_SIZE - 1)
//	{
//		arr[index] = newEl;
//		index++;
//	}
//}

template<class T>
inline void myVector<T>::Last()
{
	return arr[index];
}

template<class T>
inline unsigned int myVector<T>::GetSize() const
{
	return index + 1;
}
