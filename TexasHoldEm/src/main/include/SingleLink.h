#pragma once
#include <string>
#include <sstream>

using namespace std;

template <class T>
struct SingleLink {
	T data;
	SingleLink * next;

	SingleLink<T>(T content) {
		this->data = content;
		this->next = nullptr;
	}

	std::string toString() {
		ostringstream strm;
		strm << "{ " << this->data << " }->";
		return strm.str();
	}
};
