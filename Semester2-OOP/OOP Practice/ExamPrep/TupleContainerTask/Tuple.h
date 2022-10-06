#pragma once

template<typename T, typename S>
class Tuple
{
public:
	Tuple();
	Tuple(const T& el1, const S& el2);
	Tuple(const Tuple<T, S>& other);
	Tuple<T, S>& operator=(const Tuple<T,S>& other);
	Tuple(Tuple<T, S>&& other);
	Tuple<T, S>& operator=(Tuple<T, S>&& other);
	~Tuple();

	const T& getFirst() const;
	const S& getSecond() const;

	Tuple<S, T> swap() const;

	bool operator==(const Tuple<T, S>& t1);
	bool operator!=(const Tuple<T, S>& t1);
private:
	T* el1;
	S* el2;

	void copy(const Tuple<T, S>& other);
	void free();
};

template<typename T, typename S>
inline Tuple<T, S>::Tuple()
{
	el1 = nullptr;
	el2 = nullptr;
}

template<typename T, typename S>
inline Tuple<T, S>::Tuple(const T& el1, const S& el2)
{
	this->el1 = new T(el1);
	this->el2 = new S(el2);
}

template<typename T, typename S>
inline Tuple<T, S>::Tuple(const Tuple<T, S>& other)
{
	copy(other);
}

template<typename T, typename S>
inline Tuple<T, S>& Tuple<T, S>::operator=(const Tuple<T, S>& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

template<typename T, typename S>
inline Tuple<T, S>::Tuple(Tuple<T, S>&& other) : el1(other.el1), el2(other.el2)
{
	other.el1 = nullptr;
	other.el2 = nullptr;
}

template<typename T, typename S>
inline Tuple<T, S>& Tuple<T, S>::operator=(Tuple<T, S>&& other)
{
	if (this != &other)
	{
		free();
		el1 = other.el1;
		el2 = other.el2;
		other.el1 = nullptr;
		other.el2 = nullptr;
	}
	return *this;
}

template<typename T, typename S>
inline Tuple<T, S>::~Tuple()
{
	free();
}

template<typename T, typename S>
inline void Tuple<T, S>::copy(const Tuple<T, S>& other)
{
	el1 = new T(*other.el1);
	el2 = new S(*other.el2);
}

template<typename T, typename S>
inline void Tuple<T, S>::free()
{
	delete el1;
	delete el2;
}

template<typename T, typename S>
inline const T& Tuple<T, S>::getFirst() const
{
	return *el1;
}

template<typename T, typename S>
inline const S& Tuple<T, S>::getSecond() const
{
	return *el2;
}

template<typename T, typename S>
inline Tuple<S, T> Tuple<T, S>::swap() const
{
	Tuple<S, T> temp(*el2, *el1);
	return temp;
}

template<typename T, typename S>
inline bool Tuple<T, S>::operator==(const Tuple<T, S>& t1)
{
	return (*el1 == *t1.el1) && (*el2 == *t1.el2);
}

template<typename T, typename S>
inline bool Tuple<T, S>::operator!=(const Tuple<T, S>& t1)
{ 
	return !(this==t1);
}

