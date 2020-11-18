#include"AVL.h"

//²åÈë

template<class T>
TreeNode(T) AVL<T>::insert(const T& e) {
	TreeNode(T) &X = search(e);
	if (x) {
		return x;
	}
	TreeNode(T) xx = new BinNode(e, _hot);
	_size++;
	for (TreeNode(T) g = _hot; g; g = g->parent) {
		if (!AvlBalanced) {
			FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
		}
		else {
			updataHeightAbove(g);
		}
	}
	return xx;
}

//É¾³ý

template<typename T>
bool AVL<T>::remove(const T& e) {
	TreeNode(T)& x = search(e);
	if (!x) {
		return false;
	}
	removeAt(x, _hot);
	_size--;
	for (TreeNode(T) g = _hot; g; g = g->parent) {
		if (!AvlBalanced) {
			g = FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
		}
		updataHeight(g);
	}
	return true;
}