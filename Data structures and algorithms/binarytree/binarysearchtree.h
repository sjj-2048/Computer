#pragma once
#include"binarytree.cpp"

template<class K,class V>
struct Entry {
	
	K key;
	V val;

	Entry(K k = K(), V v = V())
		:key(k), val(v) {};
	Entry(const Entry<K, V>& e)
		:key(e.key), val(e.val) {};

	bool operator<(const Entry<K, V>& e) {
		return key < e.key;
	}
	bool operator>(const Entry<K, V>& e) {
		return key > e.key;
	}
	bool operator==(const Entry<K, V>& e) {
		return key == e.key;
	}
	bool operator!=(const Entry<K, V>& e) {
		return key != e.key;
	}

};

template<class T>
class BST :public BinaryTree<T> {

protected:
	
	TreeNode(T) _hot;
	TreeNode(T) connect34(TreeNode(T) a, TreeNode(T) b, TreeNode(T) c,
		TreeNode(T) T0, TreeNode(T) T1, TreeNode(T) T2, TreeNode(T) T3);
	TreeNode(T) rotateAt(TreeNode(T) v);

public:
	
	virtual TreeNode(T)& search(const T& e);
	virtual TreeNode(T) insert(const T& e);
	virtual bool remove(const T& e);

};