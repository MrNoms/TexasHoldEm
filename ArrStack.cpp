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
bool ArrStack<T>::empty() {
	if (top == -1) return true;
	else return false;
}

template <class T>
bool ArrStack<T>::full() {
	if (top == capacity - 1) return true;
	else return false;
}

template <class T>
T ArrStack<T>::pop() {
	if (empty()) throw EmptyStack();
	else return items[top--];
}

template <class T>
void ArrStack<T>::add(T newItem) {
	if (full()) throw FullStack();
	else items[++top] = newItem;
}#include "ArrStack.h"

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
bool ArrStack<T>::empty() {
	if (top == -1) return true;
	else return false;
}

template <class T>
bool ArrStack<T>::full() {
	if (top == capacity - 1) return true;
	else return false;
}

template <class T>
T ArrStack<T>::pop() {
	if (empty()) throw EmptyStack();
	else return items[top--];
}

template <class T>
void ArrStack<T>::add(T newItem) {
	if (full()) throw FullStack();
	else items[++top] = newItem;
}
