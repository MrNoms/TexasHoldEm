#include <iostream>
#include "CircleList.h"
using namespace std;

template <class T>
CircleList<T>::CircleList() {
	end = currPos = nullptr;
}

template <class T>
CircleList<T>::~CircleList() {
	while (end) deleteNode(end->data);
}

template <class T>
void CircleList<T>::reset() {
	currPos = nullptr;
}

template <class T>
Link<T> * CircleList<T>::getNextNode() {
	if (!currPos)
		currPos = end;
	else
		currPos = currPos->next;
	return currPos;
}

template <class T>
void CircleList<T>::putNode(T newData) {
	Link<T> * newNode = new Link<T>;
	newNode->data = newData;
	newNode->next = end->next;
	end->next = newNode;
	end = newNode;
	totNodes++;
}

template <class T>
void CircleList<T>::printNodes() {
	Link<T> * j = end->next;
	do {
		cout << j->data << ' ';
		j = j->next;
	} while (j != end->next);
	cout << endl;
}

template <class T>
void CircleList<T>::deleteNode(T trashData) {
	Link<T> * i = end;
	do {
		if (i->next->data != trashData) i = i->next;
		else {
			Link<T> * trash = i->next;
			i->next = i->next->next;
			delete trash;
			totNodes--;
		}
	} while (i != end);
}