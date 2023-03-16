#include <stdexcept>
#include "ArrStack.h"

template <class T>
ArrStack<T>::ArrStack(int cap) {
	if (cap < 1)
		throw std::out_of_range("Stack must fit at least 1 element.");

	items = new T [cap];
	capacity = cap;
	top = -1;
}

template <class T>
ArrStack<T>::~ArrStack() {
	delete[] items;
}

template <class T>
bool ArrStack<T>::isEmpty() {
	return top == -1;
}

template <class T>
bool ArrStack<T>::isFull() {
	return top == capacity - 1;
}

template <class T>
T ArrStack<T>::pop() {
	if (isEmpty()) throw std::out_of_range("The stack is empty.");
	return items[top--];
}

template <class T>
T ArrStack<T>::peek() {
	if (isEmpty()) throw std::out_of_range("The stack is empty.");
	return items[top];
}

template <class T>
void ArrStack<T>::add(T newItem) {
	if (isFull()) throw std::length_error("Stack is full.");
	
	items[++top] = newItem;
}

template <class T>
int ArrStack<T>::size() {
	return top + 1;
}

template <class T>
std::string ArrStack<T>::toString() {
	std::ostringstream out;
	for (int i = top; i > -1; i--) {
		out << this->items[i] << '\n';
	}
	out << "---";
	return out.str();
}