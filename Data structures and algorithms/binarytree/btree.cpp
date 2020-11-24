#include"btree.h"

//≤È’“
template<typename T>
BTreeNode(T) BTree<T>:: search(const T& e) {
	BTreeNode(T) v = _root;
	_hot = NULL;
	while (v) {
		Rank r = v->key.search(e);
		if ((0 <= r) && (e == v->key[r])) {
			return v;
		}
		_hot = v;
		v = v->child[r + 1];
	}
	return NULL;
}

//≤Â»Î
template<typename T>
BTreeNode(T) BTree<T>::insert(const T& e) {
	BTreeNode(T) v = search(e);
	if (v) {
		return false;
	}
	Rank r = _hot->key.search(e);
	_hot->key.insert(r + 1, e);
	_hot->child.insert(r + 2, NULL);
	_size++;
	solveOverflow(_hot);
	return true;
}

//…æ≥˝

template<typename T>
bool BTree<T>::remove(const T& e) {
	BTreeNode(T) v = search(e);
	if (!v) {
		return false;
	}
	Rank r = v->key.search(e);
	if (v->child[0]) {
		BTreeNode(T) u = v->child[r + 1];
		while (u->child[0]) {
			u = u->child[0];
		}
		v->key[r] = u->key[0];
		v = u;
		r = 0;
	}
	v->key.remove(r);
	v->child.remove(r + 1);
	_size--;
	solveUnderflow(v);
	return true;
}