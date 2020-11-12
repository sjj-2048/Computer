#include"list.h"

//节点操作实现

//插入前驱
template<typename T>
Node(T) ListNode<T>::insertAsPred(const T &e) {
	Node(T) x = new ListNode(e, pred, this);
	pred->succ = x; pred = x;
	return x;
}

//插入后继
template<typename T>
Node(T) ListNode<T>::insertAsSucc(const T& e) {
	Node(T) x = new ListNode(e, this, succ);
	succ->pred = x;
	succ = x;
	return x;
}

//列表操作实现

//列表初始化
template<typename T>
void List<T>::init() {

	header = new ListNode<T>;
	trailer = new ListNode<T>;

	header->succ = trailer;
	header->pred = NULL;

	trailer->pred = header;
	trailer->succ=NULL;

	_size = 0;
}

//复制操作
template<typename T>
void List<T>::copyNodes(Node(T) p, int n){
	init();
	while (0 < n--) {
		insertAsLast(p->data);
		p = p->succ;
	}
}

//void merge(Node(T)&, int, List<T>&, Node(T), int);
//void mergeSort(Node(T), int);

//选择排序
template<typename T>
void List<T>::selectionSort(Node(T) p, int n) {
	Node(T) head = p->pred;
	Node(T) tail = p;
	for (int i = 0; i < n; i++) {
		tail = tail->succ;
	}
	while (1 < n) {
		Node(T) max = selectMax(head->succ, n);
		insertBefore(tail, remove(max));
		tail = tail->pred;
		n--;
	}
}
//找最大值
template<typename T>
Node(T) List<T>::selectMax(Node(T) p, int n) {
	Node(T) max = p;
	for (Node(T) cur = p; 1 < n; n--) {
		if ((cur = cur->succ)->data > max->data){
			max = cur;
		}
	}
	return max;
}

//插入排序
template<typename T>
void List<T>::insertionSort(Node(T) p, int n) {
	for (int r = 0; r < n ; r++) {
		insertAfter(search(p->data, r, p), p->data);
		p = p->succ;
		remove(p->pred);
	}
}

//清空外部可见列表元素
template<typename T>
int List<T>::clear() {
	int oldSize = _size;
	while (0 < _size) {
		remove(header->succ);
	}
	return oldSize;
}

//构造和析构
template<typename T>
List<T>::List(const List<T>& L) {
	copyNodes(L.first(), L._size);
}

template<typename T>
List<T>::List(const List<T>& L, Rank r, int n) {
	copyNodes(L.find(L[r]), n);
}

template<typename T>
List<T>::List(Node(T) p, int n) {
	copyNodes(p, n);
}

template<typename T>
List<T>::~List() {
	clear();
	delete header;
	delete trailer;
}

//只读访问接口

//重载[]操作符，从指针到位置
template<typename T>
T& List<T>::operator[](Rank r)const {
	Node(T) p = first();
	while (0 < r--) {
		p = p->succ;
	}
	return p->data;
}

//无序查找
template<typename T>
Node(T) List<T>::find(const T& e, int n, Node(T) p)const {
	while (0 < n--) {
		if (e == (p = p->pred)->data) {
			return p;
		}
	}
	return NULL;
}

//有序查找，在整个列表查找某个元素
template<typename T>
Node(T) List<T>::search(const T& e)const {
	search(e, _size, trailer);
}

//有序查找，在节点p的n个前驱中，查找不大于e的最后者
template<typename T>
Node(T) List<T>::search(const T& e, int n, Node(T) p)const {
	while (n--) {
		if ((p = p->pred)->data <= e) {
			break;
		}
	}
	return p;
}

//可写访问接口

//插入首节点
template<typename T>
Node(T) List<T>::insertAsFirst(const T& e) {
	_size++;
	return header->insertAsSucc(e);
}

//插入末节点
template<typename T>
Node(T) List<T>::insertAsLast(const T& e) {
	_size++;
	return trailer->insertAsPred(e);
}

//插入后继
template<typename T>
Node(T) List<T>::insertAfter(Node(T) p, const T& e) {
	_size++;
	return p->insertAsSucc(e);
}

//插入前驱
template<typename T>
Node(T)List<T>::insertBefore(Node(T) p, const T& e) {
	_size++;
	return p->insertAsPred(e);
}

//删除节点
template<typename T>
T List<T>::remove(Node(T) p) {
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}

//排序
template<typename T>
void List<T>::sort(Node(T) p, int n) {
	insertionSort(p, n);
	//switch (rand() % 3) {
	//	case 1:
	//		insertionSort(p, n);
	//		break;
	//	case 2:
	//		selectionSort(p, n);
	//		break;
	//	default:
	//		mergeSort(p, n);
	//		break;
	//}
}

//无序去重
template<typename T>
int List<T>::deduplicate() {
	if (_size < 2) {
		return 0;
	}
	int oldSize = _size;
	Node(T) p = header;
	Rank r = 0;
	while (trailer != (p = p->succ)) {
		Node(T) q = find(p->data, r, p);
		q ? remove(q) : r++;
	}
	return oldSize - _size;
}

//有序去重
template<typename T>
int List<T>::uniquify() {
	if (_size < 2) {
		return 0;
	}
	int oldSize = _size;
	Node(T) p = first();
	Node(T) q;
	while (trailer != (q = p->succ)) {
		if (p->data != q->data) {
			p = q;
		}
		else {
			remove(q);
		}
	}
	return oldSize - _size;
}

//遍历