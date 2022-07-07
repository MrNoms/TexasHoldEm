#include "ArrStack.h"

template <class T>
ArrStack<T>::ArrStack(int cap) {
	items = new T [cap];
	capacity = cap;
	top = -1;
}

template <class T>
ArrStack<T>::~ArrStack() {
	delete[] items;
}

template <class T>
T* ArrStack<T>::getStack() {
	return items;
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
	return items[top--];
}

template <class T>
T ArrStack<T>::peek() {
	return items[top];
}

template <class T>
void ArrStack<T>::add(T newItem) {
	if (!isFull()) items[++top] = newItem;
}

template <class T>
int ArrStack<T>::size() {
	return top + 1;
}

template <class T>
std::string ArrStack<T>::to_string() {
	std::string out;
	for (T i : this.items) {
		out << i.to_string() << "->";
	}
	return out;
}