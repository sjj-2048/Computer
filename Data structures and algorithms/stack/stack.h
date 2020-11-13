#include"vector.h"
using namespace std;

template<class T>
class Stack : public Vector<T>{
public:
	void push(const T& e) {
		this->insert(this->size(), e);
	}

	T pop() {
		return this->remove(this->size() - 1);
	}

	T& top() {
		return (*this)[size() - 1];
	}
};