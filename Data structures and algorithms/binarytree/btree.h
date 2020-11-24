#include"vector.h"
#define BTNode(T) BTreeNode<T>*
#define Rank int
template<class T>
struct BTreeNode {
	//成员
	BTNode(T) parent;
	Vector<T> key;
	Vector<BTNode(T)> child;

	//构造
	BTreeNode() {
		parent = NULL;
		child.insert(0, NULL);
	}

	BTreeNode(T e, BTNode(T) lc = NULL, BTNode(T) rc = NULL) {
		parent = NULL;
		key.insert(0, e);
		child.insert(0, lc);
		child.insert(1, rc);
		if (lc) {
			lc->parent = this;
		}
		if (rc) {
			rc->parent = this;
		}
	}
};

template<class T>
class BTree {

protected:
	int _size;
	int _order;//B树的阶次
	BTreeNode(T) _root;
	BTreeNode(T) _hot;
	void solveOverflow(BTreeNode(T) v);//上溢
	void solveUnderflow(BTreeNode(T) v);//下溢

public:
	BTree(int order = 3)
		:_order(order), _size(0) {
		_root = new BTreeNode<T>();
	}
	~BTree() {
		if (_root) {
			release(_root);
		}
	}
	const int order() {
		return _order;
	}
	const int size() {
		return _size;
	}
	BTNode(T)& root() {
		return _root;
	}
	bool empty()const {
		return !_root;
	}

	BTreeNode(T) search(const T& e);
	bool insert(const T& e);
	bool remove(const T& e);

};
