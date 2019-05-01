#pragma once
#include "Node_1-link.h"

template <class T>
class CircleList {
private:
	Link<T> * end;
	Link<T> * currPos;
	int totNodes;
public:
	CircleList();
	~CircleList();
	void reset();
	Link<T> * getNextNode();
	void putNode(T);
	void deleteNode(T);
	void printNodes();
};
