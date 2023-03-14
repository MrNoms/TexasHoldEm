#pragma once

template <class T>
struct SingleLink {
	T data;
	SingleLink * next;

	SingleLink<T>(T);

	std::string ToString();
};
