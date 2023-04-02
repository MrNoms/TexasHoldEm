#pragma once
#include <string>
#include <stdexcept>

#include "SingleLink.h"

template <class T>
class Stack {
private:
	SingleLink<T>* top;
	int size;

public:
	Stack<T>() {
		top = nullptr;
		size = 0;
	}
	~Stack<T>() {
		while (!isEmpty()) {
			this->pop();
		}
	}

	bool isEmpty() {
		return size == 0;
	}
	T pop() {
		if (isEmpty()) throw std::logic_error("The stack is empty.");
		
		T oldData = top->data;
		SingleLink<T>* trash = top;
		top = top->next;
		delete trash;
		size--;

		return oldData;
	}
	T peek() {
		if (isEmpty()) throw std::logic_error("The stack is empty.");

		return top->data;
	}
	bool add(T newItem) {
		try {
			SingleLink<T>* newLink = new SingleLink<T>(newItem);
		}
		catch (std::runtime_error) {
			return false;
		}
		newLink->next = top;
		top = newLink;
		size++;
		return true;
	}
	int getSize() {
		return size;
	}
	std::string toString() {
		std::string out = "";
		for (SingleLink<T>* i = top; i != nullptr; i = i->next) {
			out.append(i->toString()).append("\n");
		}
		out.append("---");
		return out;
	}
};