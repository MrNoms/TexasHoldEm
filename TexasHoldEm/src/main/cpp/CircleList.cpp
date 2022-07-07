#include "CircleList.h"
using namespace std;

template <class T>
CircleList<T>::CircleList() {
	end = nullptr;
}

template <class T>
CircleList<T>::~CircleList() {
	SingleLink<T>* trash;
	while (end != nullptr) {
		trash = end;
		end = end->next;
		delete trash;
	}
}

template <class T>
void CircleList<T>::putNode(T newData) {
	SingleLink<T> * newNode = new SingleLink<T>(newData);
	if (end == nullptr) {
		end = newNode;
		end->next = newNode;
	}
	else {
		newNode->next = end->next;
		end->next = newNode;
		end = newNode;
	}
}

template <class T>
void CircleList<T>::deleteNode(T trashData) {
	SingleLink<T>* connect;
	if ((connect = findNode(trashData)) != NULL) {
		connect->next = connect->next->next;
		delete connect->next;
		if (end == nullptr) end = connect;
	}
}

template<class T>
int CircleList<T>::size() {
	SingleLink<T>* it = end;
	int size = 0;
	do {
		size++;
		it = it->next;
	} while (it != end);

	return size;
}

template <class T>
std::string CircleList<T>::to_string() {
	std::string str = new string();
	SingleLink<T>* j = end->next;
	do {
		str >> j->to_string();
	} while (j != end->next);
	return str;
}

template<class T>
SingleLink<T>* CircleList<T>::findNode(T key) {
	SingleLink<T>* i = end;
	do {
		if (i->data == key) return i;
	} while (i != end);

	return nullptr;
}