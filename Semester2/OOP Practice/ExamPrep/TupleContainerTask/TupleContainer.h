#pragma once
#include "Tuple.h"

template<typename T, typename S>
class TupleContainer
{
public:
	TupleContainer();
	TupleContainer(const TupleContainer<T, S>& other);
	TupleContainer<T, S>& operator=(const TupleContainer<T, S>& other);
	TupleContainer(TupleContainer<T, S>&& other);
	TupleContainer<T, S>& operator=(TupleContainer<T, S>&& other);
	~TupleContainer();

	void add(const Tuple<T, S>& tuple);
	int getSize() const;

	const Tuple<T, S>& operator[](int index) const;

	bool operator==(const TupleContainer<T, S>& other) const;

	TupleContainer<S, T> swap() const;

private:
	Tuple<T, S>* tuples;
	int size, cap;
	
	void copy(const TupleContainer<T, S>& other);
	void free();
	void resize();
};

template<typename T, typename S>
inline TupleContainer<T, S>::TupleContainer()
{
	cap = 5;
	size = 0;
	tuples = new Tuple<T, S>[cap];
}

template<typename T, typename S>
inline TupleContainer<T, S>::TupleContainer(const TupleContainer<T, S>& other)
{
	copy(other);
}

template<typename T, typename S>
inline TupleContainer<T, S>& TupleContainer<T, S>::operator=(const TupleContainer<T, S>& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

template<typename T, typename S>
inline TupleContainer<T, S>::TupleContainer(TupleContainer<T, S>&& other)
{
	size = other.size;
	cap = other.cap;
	tuples = other.tuples;
	other.tuples = nullptr;
}

template<typename T, typename S>
inline TupleContainer<T, S>& TupleContainer<T, S>::operator=(TupleContainer<T, S>&& other)
{
	if (this != &other)
	{
		free();
		size = other.size;
		cap = other.cap;
		tuples = other.tuples;
		other.tuples = nullptr;
	}
}

template<typename T, typename S>
inline TupleContainer<T, S>::~TupleContainer()
{
	free();
}

template<typename T, typename S>
inline void TupleContainer<T, S>::add(const Tuple<T, S>& tuple)
{
	if (size >= cap)
	{
		resize();
	}
	tuples[size++] = tuple;
}

template<typename T, typename S>
inline int TupleContainer<T, S>::getSize() const
{
	return size;
}

template<typename T, typename S>
inline const Tuple<T, S>& TupleContainer<T, S>::operator[](int index) const
{
	if (index >= size)
	{
		throw "Out_Of_Range";
	}

	return tuples[index];
}

template<typename T, typename S>
inline bool TupleContainer<T, S>::operator==(const TupleContainer<T, S>& other) const
{
	if (size != other.size)
	{
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		if (tuples[i] != tuples)
		{
			return false;
		}
	}
	return true;
}

template<typename T, typename S>
inline TupleContainer<S, T> TupleContainer<T, S>::swap() const
{
	TupleContainer<S, T> temp;
	for (int i = 0; i < size; i++)
	{
		temp.add(tuples[i].swap());
	}
	return temp;
}

template<typename T, typename S>
inline void TupleContainer<T, S>::copy(const TupleContainer<T, S>& other)
{
	cap = other.cap;
	size = other.size;
	tuples = new Tuple<T, S>[cap];
	for (int i = 0; i < size; i++)
	{
		tuples[i] = other.tuples[i];
	}
}

template<typename T, typename S>
inline void TupleContainer<T, S>::free()
{
	delete[] tuples;
}

template<typename T, typename S>
inline void TupleContainer<T, S>::resize()
{
	Tuple<T, S>* temp = new Tuple<T, S>[cap *= 2];
	for (int i = 0; i < size; i++)
	{
		temp[i] = tuples[i];
	}
	delete[] tuples;
	tuples = temp;
}



