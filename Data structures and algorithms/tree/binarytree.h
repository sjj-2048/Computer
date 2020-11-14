#pragma once
#include<iostream>
using namespace std;
#define Node(T) BinNode<T>*//节点位置
#define stature(p)((p)?(p)->height : -1)//节点高度，空树高度为-1
typedef enum{RB_RED,RB_BLACK} RBColor;//节点颜色
/*************************************************************

			BinNode状态与性质的判断

**************************************************************/
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x)&&(&(x)==(x).parent->lc))
#define IsRChild(x) (!IsRoot(x)&&(&(x)==(x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x)||HasRChild(x))
#define HasBothChild(x) (HasLChild(x)&&HasRChild(x))
#define IsLeaf(x) (!HasChild(x))
/*************************************************************

           与BinNode具有特定关系的节点及指针

**************************************************************/
#define sibling(p) \ (IsLChild(*(p))? (p)->parent->rc:(p)->parent->rc
#define uncle(x) \ (IsLChild(*((x)->parent))? (x)->parent->parent->rc:(x)->parent->parent->lc
#define FromParentTo(x) \ (IsRoot(x)? _root:(IsLChild(x)? (x)->parent->lc:(x).parent->rc))

//二叉树节点模板类
template<class T>
struct BinNode {

	T data;
	Node(T) parent;
	Node(T) lc;
	Node(T) rc;
	int height;
	int npl;//左式堆
	RBColor color;//颜色，红黑树

	//构造函数
	BinNode() :
		parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
	BinNode(T e, Node(T) p = NULL, Node(T) lc = NULL, Node(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED) :
		data(e),parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}

	//操作接口
	int size();
	Node(T) insertAsLC(const T& e);
	Node(T) insertAsRC(const T& e);
	Node(T) succ();

	//遍历
	template<typename VST>
	void travLevel(VST&);//子树层次遍历
	
	template<typename VST>
	void travPre(VST&);//子树先序遍历
	
	template<typename VST>
	void travIn(VST&);//子树中序遍历
	
	template<typename VST>
	void travPost(VST&);//子树后序遍历

	//比较器、判等器
	bool operator<(const BinNode& bn) {
		return data < bn.data;
	}

	bool operator==(const BinNode& bn) {
		return data == bn.data;
	}

};

//二叉树模板类

template<class T>
class BinTree {
protected:
	
	int _size;
	Node(T) _root;
	
	virtual int updateHeight(Node(T) x);//定义为虚函数 ，方便不同种类的二叉树重写
	void updateHeightAbove(Node(T) x);

public:
	BinTree()
		:_sie(0),_root(NULL){}
	~BinTree() {
		if (0 < _size) {
			remove(_root);
		}
	}

	int size()const { return _size; }
	bool empty()const { return !_root; }
	Node(T) root()const { return _root; }

	Node(T) insertAsRoot(const T& e);
	Node(T) insertAsLC(Node(T) x, T& e);
	Node(T) insertAsRC(Node(T) x, T& e);
	Node(T) attachAsLC(Node(T) x, BinTree<T>* &T);//将T作为左子树接入
	Node(T) attachAsRC(Node(T) x, BinTree<T>* &T);

	int remove(Node(T) x);
	BinTree<T>* secede(Node(T) x);//将子树从当前位置摘除，并转换成新的子树

	//遍历
	template<typename VST>
	void travLevel(VST& visit) {
		if (_root) {
			_root->travLevel(visit);
		}
	}
	template<typename VST>
	void travPre(VST& visit) {
		if (_root) {
			_root->travPre(visit);
		}
	}
	template<typename VST>
	void travIn(VST& visit) {
		if (_root) {
			_root->travIn(visit);
		}
	}
	template<typename VST>
	void travPost(VST& visit) {
		if (_root) {
			_root->travPost(visit);
		}
	}

	//重载操作符
	bool operator<(const BinTree<T>& t) {
		return _root && t._root && (_root < t._root);
	}
	bool operator==(const BinTree<T>& t) {
		return _root && t._root && (_root == t._root);
	}
};