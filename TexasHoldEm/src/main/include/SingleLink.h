#pragma once
#include <string>

template <class T>
struct SingleLink {
	T data;
	SingleLink * next;

	SingleLink<T>(T content) {
		data = content;
		next = nullptr;
	}

	std::string to_string() {
		return "{ " + data.to_string() + " }->";
	}
};
