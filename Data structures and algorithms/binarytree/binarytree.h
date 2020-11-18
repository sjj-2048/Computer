#pragma once
#include<iostream>
using namespace std;
#define TreeNode(T) BinNode<T>*//�ڵ�λ��
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
	TreeNode(T) parent;
	TreeNode(T) lc;
	TreeNode(T) rc;
	int height;
	int npl;//��ʽ��
	RBColor color;//��ɫ�������

	//���캯��
	BinNode() :
		parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
	BinNode(T e, TreeNode(T) p = NULL, TreeNode(T) lc = NULL, TreeNode(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED) :
		data(e),parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}

	//�����ӿ�
	int size();
	TreeNode(T) insertAsLC(const T& e);
	TreeNode(T) insertAsRC(const T& e);
	TreeNode(T) succ();

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
	TreeNode(T) _root;
	
	virtual int updateHeight(TreeNode(T) x);//����Ϊ�麯�� �����㲻ͬ����Ķ�������д
	void updateHeightAbove(TreeNode(T) x);

public:
	BinTree()
		:_size(0),_root(NULL){}
	~BinTree() {
		if (0 < _size) {
			remove(_root);
		}
	}

	int size()const { return _size; }
	bool empty()const { return !_root; }
	TreeNode(T) root()const { return _root; }

	TreeNode(T) insertAsRoot(const T& e);
	TreeNode(T) insertAsLC(TreeNode(T) x, T& e);
	TreeNode(T) insertAsRC(TreeNode(T) x, T& e);
	TreeNode(T) attachAsLC(TreeNode(T) x, BinTree<T>* &S);//��T��Ϊ����������
	TreeNode(T) attachAsRC(TreeNode(T) x, BinTree<T>* &S);

	int remove(TreeNode(T) x);
	BinTree<T>* secede(TreeNode(T) x);//�������ӵ�ǰλ��ժ������ת�����µ�����

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