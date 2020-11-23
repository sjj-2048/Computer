#pragma once
#include"binarysearchtree.h"

template<class T>
class Splay:public BST<T> {
	
protected:
	TreeNode(T) splay(TreeNode(T) v);

public:
	TreeNode(T)& search(const T& e);
	TreeNode(T) insert(const T& e);
	bool remove(const T& e);
};