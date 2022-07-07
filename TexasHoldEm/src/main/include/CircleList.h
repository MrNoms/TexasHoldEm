#pragma once
#include <string>
#include "SingleLink.h"

template <class T>
class CircleList {
private:
	SingleLink<T> * end;

	SingleLink<T>* findNode(T);
	
public:
	CircleList();
	~CircleList();

	SingleLink<T> * begin();
	void putNode(T);
	void deleteNode(T);
	int size();
	std::string to_string();
};