#include <iostream>
#include "CircleList.h"
using namespace std;

template <class T>
CircleList<T>::CircleList() {
	head = nullptr;
}

template <class T>
CircleList<T>::~CircleList() {
	while (head) deleteNode(head->data);
}

template <class T>
Link<T> * CircleList<T>::getNextNode() {
	if (!currPos)
		currPos = head;
	else
		currPos = currPos->next;
	return currPos;
}

template <class T>
void CircleList<T>::putNode(T newData) {
	Link<T> * newNode = new Link<T>;
	newNode->data = newData;
	newNode->next = head;
	head = newNode;
	totNodes++;
}

template <class T>
void CircleList<T>::printNodes() {
	for (Link<T> * j = head; j; j = j->next)
		cout << j->data << ' ';
	cout << endl;
}

template <class T>
void CircleList<T>::deleteNode(T trashData) {
	Link<T> * i = head;
	while (i && i->data == trashData) {
		head = head->next;
		delete i;
		totNodes--;
		i = head;
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