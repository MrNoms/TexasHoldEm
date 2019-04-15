#pragma once
#include "Node_1-link.h"

template <class T>
class Stack {
private:
	bool Full();

	Link<T> * top;
public:
	void pop();
	void add(T);
	Stack();
	~Stack();
	Link<T> * getTop();
};