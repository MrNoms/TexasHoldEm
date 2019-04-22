#pragma once

template <class T>
class ArrStack {
private:
	T * items;
	int capacity;
	int top;
	class EmptyStack {};
	class FullStack {};
public:
	ArrStack(int);
	~ArrStack();
	bool empty();
	bool full();
	T pop();
	void add(T);
};