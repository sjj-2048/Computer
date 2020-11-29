#include"priorityqueue.h"

//ȡ���ȼ����Ԫ�أ���Ϊȫ�����ȼ����Ԫ������λ�ڶѶ���ֻ�践���������׵�Ԫ

template<typename T>
T PQ_ComplHeap<T>::getMax() {
	return _elem[0];
}

//�����㷨

template<typename T>
void PQ_ComplHeap<T>::insert(T e) {
	Vector<T>::insert(e);//��Ԫ���Ȳ���β��
	percolateUp(_size - 1);//�ٶԸô���ʵʩ���˵���
}
//�����㷨
template<typename T>
Rank PQ_ComplHeap<T>::percolateUp(Rank i) {
	while (ParentValid(i)) {
		Rank j = Parent(i);
		if (_elem[i] < _elem[j]) {
			break;
		}
		swap(_elem[i], _elem[j]);
		i = j;
	}
	return i;
}

//ɾ���㷨

template<typename T>
T PQ_ComplHeap<T>::delMax() {
	T maxElem = _elem[0];
	_elem[0] = _elem[--_size];
	percolateDown(Rank _size, 0);//����
	return maxElem;
}
//�����㷨
template<typename T>
Rank PQ_ComplHeap<T>::percolateDown(Rank n, Rank i) {
	Rank j;
	while (i != (j = ProperParent(_elem, n, j))) {
		swap(_elem[i], _elem[j]);
		i = j;
	}
	return i;
}

//��������

//�����㷨(���϶��µ����ˣ�

template<typename T>
void PQ_ComplHeap<T>::heapify1(Rank n) {
	for (int i = 1; i < n; i++) {
		procolateUp(i);
	}
}

//Floyd�㷨�����¶��ϵ����ˣ�

template<typename T>
void PQ_ComplHeap<T>::heapify(Rank n) {
	for (int i = LastInternal; i>=0; i--) {
		procolateDown(n,i);
	}
}

//���������ľ͵ض�����

template<typename T>
void Vector<T>::heapSort(Rank lo,Rank hi) {
	PQ_ComplHeap<T> H(_elem + lo, hi - lo);
	while (!H.empty()) {
		_elem[--hi] = H.delMax();
	}
}

//�ϲ�������ʵ��

template<typename T>
static TreeNode(T) merge(TreeNode(T) a, TreeNode(T) b) {
	if (!a) {
		return b;
	}
	if (!b) {
		return a;
	}
	if (a->data < b->data) {
		swap(a, b);
	}
	a->rc = merge(a->rc, b);
	a->rc->parent = a;
	if (!a->lc || a->lc->npl < a->rc->npl) {
		swap(a->lc, a->rc);
	}
	a->npl = a->rc ? a->rc->npl + 1;
	return a;
}

//���ںϲ��Ĳ����㷨

template<typename T>
void PQ_LeftHeap<T>::insert(T e) {
	TreeNode(T) v= new BinNode<T>(e);
	_root = merge(_root, v);
	_root->parent = NULL;
	_size++:
}

//���ںϲ���ɾ���㷨

template<typename T>
T PQ_LeftHeap<T>::delMax() {
	TreeNode(T) lHeap = _root->lc;
	TreeNode(T) rHeap = _root->rc;
	T e = _root->data;
	delete _root;
	_size--;
	_root = merge(lHeap, rHeap);
	if (!_root) {
		_root->parent = NULL;
	}
	return e;
}