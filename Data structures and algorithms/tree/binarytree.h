#pragma once
#include<iostream>
using namespace std;
#define Node(T) BinNode<T>*//�ڵ�λ��
#define stature(p)((p)?(p)->height : -1)//�ڵ�߶ȣ������߶�Ϊ-1
typedef enum{RB_RED,RB_BLACK} RBColor;//�ڵ���ɫ
/*************************************************************

			BinNode״̬�����ʵ��ж�

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

           ��BinNode�����ض���ϵ�Ľڵ㼰ָ��

**************************************************************/
#define sibling(p) \ (IsLChild(*(p))? (p)->parent->rc:(p)->parent->rc
#define uncle(x) \ (IsLChild(*((x)->parent))? (x)->parent->parent->rc:(x)->parent->parent->lc
#define FromParentTo(x) \ (IsRoot(x)? _root:(IsLChild(x)? (x)->parent->lc:(x).parent->rc))

//�������ڵ�ģ����
template<class T>
struct BinNode {

	T data;
	Node(T) parent;
	Node(T) lc;
	Node(T) rc;
	int height;
	int npl;//��ʽ��
	RBColor color;//��ɫ�������

	//���캯��
	BinNode() :
		parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
	BinNode(T e, Node(T) p = NULL, Node(T) lc = NULL, Node(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED) :
		data(e),parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}

	//�����ӿ�
	int size();
	Node(T) insertAsLC(const T& e);
	Node(T) insertAsRC(const T& e);
	Node(T) succ();

	//����
	template<typename VST>
	void travLevel(VST&);//������α���
	
	template<typename VST>
	void travPre(VST&);//�����������
	
	template<typename VST>
	void travIn(VST&);//�����������
	
	template<typename VST>
	void travPost(VST&);//�����������

	//�Ƚ������е���
	bool operator<(const BinNode& bn) {
		return data < bn.data;
	}

	bool operator==(const BinNode& bn) {
		return data == bn.data;
	}

};

//������ģ����

template<class T>
class BinTree {
protected:
	
	int _size;
	Node(T) _root;
	
	virtual int updateHeight(Node(T) x);//����Ϊ�麯�� �����㲻ͬ����Ķ�������д
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
	Node(T) attachAsLC(Node(T) x, BinTree<T>* &T);//��T��Ϊ����������
	Node(T) attachAsRC(Node(T) x, BinTree<T>* &T);

	int remove(Node(T) x);
	BinTree<T>* secede(Node(T) x);//�������ӵ�ǰλ��ժ������ת�����µ�����

	//����
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

	//���ز�����
	bool operator<(const BinTree<T>& t) {
		return _root && t._root && (_root < t._root);
	}
	bool operator==(const BinTree<T>& t) {
		return _root && t._root && (_root == t._root);
	}
};