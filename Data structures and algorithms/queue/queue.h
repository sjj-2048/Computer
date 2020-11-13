#pragma once
#include"list.h"

template<class T>
class Queue :public List<T> {
public:

	void enqueue(const T& e) {
		insertAsLast(e);
	}

	T dequeue() {
		return remove(first());
	}

	T& front() {
		return first()->data;
	}

};