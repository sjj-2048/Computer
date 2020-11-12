#include"list.h"

//�ڵ����ʵ��

//����ǰ��
template<typename T>
Node(T) ListNode<T>::insertAsPred(const T &e) {
	Node(T) x = new ListNode(e, pred, this);
	pred->succ = x; pred = x;
	return x;
}

//������
template<typename T>
Node(T) ListNode<T>::insertAsSucc(const T& e) {
	Node(T) x = new ListNode(e, this, succ);
	succ->pred = x;
	succ = x;
	return x;
}

//�б����ʵ��

//�б��ʼ��
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

//���Ʋ���
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

//ѡ������
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
//�����ֵ
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

//��������
template<typename T>
void List<T>::insertionSort(Node(T) p, int n) {
	for (int r = 0; r < n ; r++) {
		insertAfter(search(p->data, r, p), p->data);
		p = p->succ;
		remove(p->pred);
	}
}

//����ⲿ�ɼ��б�Ԫ��
template<typename T>
int List<T>::clear() {
	int oldSize = _size;
	while (0 < _size) {
		remove(header->succ);
	}
	return oldSize;
}

//���������
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

//ֻ�����ʽӿ�

//����[]����������ָ�뵽λ��
template<typename T>
T& List<T>::operator[](Rank r)const {
	Node(T) p = first();
	while (0 < r--) {
		p = p->succ;
	}
	return p->data;
}

//�������
template<typename T>
Node(T) List<T>::find(const T& e, int n, Node(T) p)const {
	while (0 < n--) {
		if (e == (p = p->pred)->data) {
			return p;
		}
	}
	return NULL;
}

//������ң��������б����ĳ��Ԫ��
template<typename T>
Node(T) List<T>::search(const T& e)const {
	search(e, _size, trailer);
}

//������ң��ڽڵ�p��n��ǰ���У����Ҳ�����e�������
template<typename T>
Node(T) List<T>::search(const T& e, int n, Node(T) p)const {
	while (n--) {
		if ((p = p->pred)->data <= e) {
			break;
		}
	}
	return p;
}

//��д���ʽӿ�

//�����׽ڵ�
template<typename T>
Node(T) List<T>::insertAsFirst(const T& e) {
	_size++;
	return header->insertAsSucc(e);
}

//����ĩ�ڵ�
template<typename T>
Node(T) List<T>::insertAsLast(const T& e) {
	_size++;
	return trailer->insertAsPred(e);
}

//������
template<typename T>
Node(T) List<T>::insertAfter(Node(T) p, const T& e) {
	_size++;
	return p->insertAsSucc(e);
}

//����ǰ��
template<typename T>
Node(T)List<T>::insertBefore(Node(T) p, const T& e) {
	_size++;
	return p->insertAsPred(e);
}

//ɾ���ڵ�
template<typename T>
T List<T>::remove(Node(T) p) {
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}

//����
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

//����ȥ��
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

//����ȥ��
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

//����