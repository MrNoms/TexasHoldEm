#include <iostream>
#include "CircleList.h"
using namespace std;

template <class T>
CircleList<T>::CircleList() {
	end = nullptr;
	totNodes = 0;
	currPos = nullptr;
}

template <class T>
CircleList<T>::~CircleList() {
	while (end) deleteNode(end->data);
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
	newNode->next = end;
	end = newNode;
	totNodes++;
}

template <class T>
void CircleList<T>::printNodes() {
	for (Link<T> * j = end; j; j = j->next)
		cout << j->data << ' ';
	cout << endl;
}

template<class T>
int CircleList<T>::getListSize()
{
	return totNodes;
}

template <class T>
void CircleList<T>::deleteNode(T trashData) {
	Link<T> * i = end;
	while (i && i->data == trashData) {
		end = end->next;
		delete i;
		totNodes--;
		i = end;
	}

	while (i && i->next) {
		if (i->next->data == trashData) {
			Link<T> * trash = i->next;
			i->next = i->next->next;
			delete trash;
			totNodes--;
		}
		else i = i->next;
	}
}