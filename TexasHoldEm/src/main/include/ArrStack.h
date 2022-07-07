#pragma once
#include <string>

template <class T>
class ArrStack {
private:
	T * items;
	int capacity;
	int top;

protected:
	T* getStack();

public:
	ArrStack(int);
	~ArrStack();

	bool isEmpty();
	bool isFull();
	T pop();
	T peek();
	void add(T);
	int size();
	std::string to_string();
};