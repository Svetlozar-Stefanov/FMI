#pragma once
#include <iostream>

template<typename T>
struct Node
{
	T data;
	Node* next;

	Node(T data, Node* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};

template<typename T>
class List {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	List() {
		head = nullptr;
		tail = nullptr;
	}

	void push_back(T newEl) {
		if (head == nullptr)
		{
			head = new Node<T>(newEl);
			tail = head;
		}
		else
		{
			tail->next = new Node<T>(newEl);
			tail = tail->next;
		}
	}

	void push_front(T newEl)
	{
		if (head == nullptr)
		{
			head = new Node<T>(newEl);
			tail = head;
		}
		else
		{
			Node<T>* newHead = new Node<T>(newEl, head);
			head = newHead;
		}
	}

	void print() 
	{
		Node<T>* tracker = head;
		while (tracker != nullptr)
		{
			std::cout << tracker->data << " ";
			tracker = tracker->next;
		}
		std::cout << "\n";
	}

	void insert(T newEl, int pos) {
		if (pos == 0)
		{
			push_front();
			return;
		}
		else if (head == nullptr)
		{
			throw std::out_of_range("Invalid insert index, list is empty");
		}

		Node<T>* current = head;
		Node<T>* previous = nullptr;
		for (int i = 0; i < pos; i++)
		{
			if (current != nullptr)
			{
				previous = current;
				current = current->next;
			}
			else
			{
				throw std::out_of_range("Cannot insert in invalid position");
			}
		}

		previous->next = new Node<T>(newEl, current);
		if (tail == previous)
		{
			tail = previous->next;
		}
	}

	void delete_first() {
		if (head != nullptr)
		{
			Node<T>* temp = head->next;
			delete head;
			head = temp;
		}
	}

	void delete_last() {
		Node<T>* current = head;
		Node<T>* previous = nullptr;

		while (current != tail)
		{
			previous = current;
			current = current->next;
		}
		tail = previous;
		tail->next = nullptr;
		delete current;
	}

	void remove(int pos) {
		if (pos == 0)
		{
			delete_first();
			return;
		}
		else if (head == nullptr)
		{
			throw std::out_of_range("Invalid remove index, list is empty");
		}

		Node<T>* current = head;
		Node<T>* previous = nullptr;
		for (int i = 0; i < pos; i++)
		{
			if (current != tail)
			{
				previous = current;
				current = current->next;
			}
			else
			{
				throw std::out_of_range("Cannot insert in invalid position");
			}
		}

		previous->next = current->next;
		if (tail == current)
		{
			tail = previous;
		}
		delete current;
	}

	bool contains(T el) {
		Node<T>* iterator = head;
		while (iterator != tail)
		{
			if (iterator->data == el)
			{
				return true;
			}

			iterator = iterator->next;
		}

		return false;
	}

	void mergeLists(List<T>& other)
	{
		tail->next = other.head;
		tail = other.tail;
		other.head = head;
	}

	void copyMerge(List<T>& other)
	{
		Node<T>* iterator = other.head;
		while (iterator != other.tail)
		{
			push_back(iterator);
			iterator = iterator->next;
		}
	}

	void reverse_list()
	{
		Node<T>* current = head;
		Node<T>* previous = nullptr;
		do
		{
			Node<T>* next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		} while (current != nullptr);
		Node<T>* temp = tail;
		tail = head;
		head = temp;
	}
};