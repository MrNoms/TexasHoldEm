#pragma once
#include <string>
#include "SingleLink.h"

template <class T>
class CircleList {
private:
	SingleLink<T> * end;
	int size;

	SingleLink<T>* findNodeBefore(T key) {
		SingleLink<T>* i = end;
		do {
			if (i && i->next->data == key) return i;
			else if(i) i = i->next;
		} while (i != end);

		return nullptr;
	}
	
public:
	CircleList() {
		end = nullptr;
		size = 0;
	}
	~CircleList() {
		SingleLink<T>* trash;
		while (size > 0) {
			trash = end;
			end = end->next;
			delete trash;
			size--;
		}
	}

	SingleLink<T>* begin() {
		return end == nullptr ? nullptr : end->next;
	}
	bool putNode(T newData) {
		SingleLink<T>* newNode;
		try {
			newNode = new SingleLink<T>(newData);
		}
		catch (std::runtime_error) {
			return false;
		}
		if (end == nullptr) {
			end = newNode;
			end->next = newNode;
		}
		else {
			newNode->next = end->next;
			end->next = newNode;
			end = newNode;
		}
		size++;
		return true;
	}
	bool deleteNode(T trashData) {
		SingleLink<T>* connect;
		if ((connect = findNodeBefore(trashData)) != nullptr) {
			SingleLink<T>* trash = connect->next;
			connect->next = trash->next;
			if (trash == end) end = connect;
			delete trash;
			size--;
			if (size == 0) end = nullptr;
			return true;
		}

		return false;
	}
	int getSize() {
		return size;
	}
	std::string toString() {
		std::string str = "";
		SingleLink<T>* j = end->next;
		do {
			str.append(j->toString());
		} while (j != end->next);
		return str.append("end");
	}
};