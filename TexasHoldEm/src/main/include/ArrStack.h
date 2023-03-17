#pragma once
#include <string>
#include <stdexcept>
#include <sstream>

template <class T>
class ArrStack {
private:
	T* items;
	int capacity;
	int top;

public:
	ArrStack<T>(int cap) {
		if (cap < 1)
			throw std::out_of_range("Stack must fit at least 1 element.");

		items = new T[cap];
		capacity = cap;
		top = -1;
	}
	~ArrStack<T>() {
		delete[] items;
	};

	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == capacity - 1;
	};
	T pop() {
		if (isEmpty()) throw std::out_of_range("The stack is empty.");
		return items[top--];
	};
	T peek() {
		if (isEmpty()) throw std::out_of_range("The stack is empty.");
		return items[top];
	};
	void add(T newItem) {
		if (isFull()) throw std::length_error("Stack is full.");

		items[++top] = newItem;
	};
	int size() {
		return top + 1;
	};
	std::string toString() {
		std::ostringstream out;
		for (int i = top; i > -1; i--) {
			out << this->items[i] << '\n';
		}
		out << "---";
		return out.str();
	};
};