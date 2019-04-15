#include "Stack.h"

template <class T>
Stack<T>::Stack() {
	top = nullptr;
}

template <class T>
Stack<T>::~Stack() {
	while(top) pop();
}

template <class T>
void Stack<T>::pop() {
	if (top) {
		Link<T> * stackTop = top;
		top = top->next;
		delete stackTop;
	}
}

template <class T>
void Stack<T>::add(T info) {
	if (!Full()) {
		Link<T> * newTop = new Link<T>;
		newTop->data = info;
		newTop->next = top;
		top = newTop;
	}
}

template <class T>
Link<T> * Stack<T>::getTop() {
	if (!top) return top;
}

template <class T>
bool Stack<T>::Full() {
	try {
		Link<T> * temp = new Link<T>;
		delete temp;
		return false;
	}
	catch (...) { return true; }
}