#pragma once
template<typename T>
struct StackElement
{
	T data;
	StackElement<T>* next;
};

template<typename T>
class Stack
{
private:
	StackElement<T>* top;

	void helper(const StackElement<T>* top);
	void copy(const Stack<T>& other);
	void free();

public:
	Stack();
	Stack(const Stack<T>& other);
	Stack<T>& operator=(const Stack<T>& other);
	~Stack();

	void push(const T& el);
	void pop();
	const T& peek() const;

	bool isEmpty() const;

};

template<typename T>
void Stack<T>::helper(const StackElement<T>* top)
{
	if (top->next != nullptr)
	{
		helper(top->next);
	}
	push(top->data);
}

template<typename T>
void Stack<T>::copy(const Stack<T>& other)
{
	if (other.isEmpty())
	{
		top = nullptr;
		return;
	}
	helper(other.top);
}

template<typename T>
void Stack<T>::free()
{
	StackElement<T>* temp;
	while (!isEmpty())
	{
		temp = top->next;
		delete top;
		top = temp;
	}
}

template<typename T>
Stack<T>::Stack() : top(nullptr)
{
	
}

template<typename T>
Stack<T>::Stack(const Stack<T>& other)
{
	copy(other);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

template<typename T>
Stack<T>::~Stack()
{
	free();
}

template<typename T>
inline void Stack<T>::push(const T& el)
{
	StackElement<T>* newTop = new StackElement<T>();
	newTop->data = el;
	newTop->next = top;
	top = newTop;
}

template<typename T>
void Stack<T>::pop()
{
	if (isEmpty())
	{
		throw "Stack is empty!";
	}
	StackElement<T>* temp = top->next;
	delete top;
	top = temp;
}

template<typename T>
const T& Stack<T>::peek() const
{
	if (isEmpty())
	{
		throw "Stack is empty!";
	}
	return top->data;
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	return top == nullptr;
}
