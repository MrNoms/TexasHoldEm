#pragma once
#include "Node_1-link.h"

template <class T>
class CircleList {
private:
	Link<T> * end;
	int totNodes;
	Link<T> * currPos;
	
public:
	CircleList();
	~CircleList();
	Link<T> * getNextNode();
	void putNode(T);
	void deleteNode(T);
	void printNodes();
	int getListSize(); // returns totNodes
};