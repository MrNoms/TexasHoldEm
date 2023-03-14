#include <string>

#include "SingleLink.h"

using namespace std;

template <class T>
SingleLink<T>::SingleLink(T content) {
	this->data = content;
	this->next = nullptr;
}

template <class T>
string SingleLink<T>::ToString() {
	ostringstream strm;
	strm << "{ " << this->data << " }->";
	return strm.str();
}
