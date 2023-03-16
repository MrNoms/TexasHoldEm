#pragma once
#include <string>

template <class T>
class ArrStack {
private:
	T* items;
	int capacity;
	int top;

public:
	ArrStack<T>(int);
	~ArrStack<T>();

	bool isEmpty();
	bool isFull();
	T pop();
	T peek();
	void add(T);
	int size();
	std::string toString();
};