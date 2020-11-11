#include"vector.h"
#include<iostream>
using namespace std;


//复制数组区间lo~hi
template<typename T>
void Vector<T>::copyFrom(const T *A, Rank lo, Rank hi) {
	_elem = new T[_capacity = 2 * (hi - lo)];
	_size = 0;
	while (lo < hi) {
		_elem[_size++] = A[lo++];
	}
}

//动态空间，空间不足时扩容
template<typename T>
void Vector<T>::expand() {
	if (_size < _capacity) {
		return;
	}
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; i++) {
		_elem[i] = oldElem[i];
	}
	delete[]oldElem;
}

//缩容函数，当装填因子过小时，缩小向量所占空间
template<typename T>
void Vector<T>::shrink() {
	if (_capacity >> 1<DEFAULT_CAPACITY) {//避免缩小到默认容量以下
		return ;
	}
	if (_size > _capacity >> 2) {//装填因子大于25%时，不用缩容
		return ;
	}
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];
	for (int i = 0; i < _size; i++) {
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;
}

//构造函数
template<typename T>
Vector<T>::Vector(int c,int s ,T v) {
	_elem = new T[_capacity = c];
	for (_size = 0; _size < s; _size++) {
		_elem[_size] = v;
	}
}

//拷贝构造函数1,数组整体复制
template<typename T>
Vector<T>::Vector(const T* A, Rank n) {
	copyFrom(A, 0, n);
}

//拷贝构造函数2，数组区间复制
template<typename T>
Vector<T>::Vector(const T* A, Rank lo,Rank hi) {
	copyFrom(A, lo, hi);
}

//拷贝构造函数3，向量整体复制
template<typename T>
Vector<T>::Vector(const Vector<T>&v ) {
	copyFrom(v._elem, 0, v.size());
}

//拷贝构造函数4，向量区间复制
template<typename T>
Vector<T>::Vector(const Vector<T>&v, Rank lo,Rank hi) {
	copyFrom(v._elem, lo, hi);
}

//析构函数
template<typename T>
Vector<T>::~Vector() {
	if (_elem != NULL) {
		delete[] _elem;
		_elem = NULL;
	}
}

//只读访问接口

//向量规模
template<typename T>
Rank Vector<T>::size() const{
	return _size;
}

//判空
template<typename T>
bool Vector<T>::empty()const {
	return !_size;
}

//有序性甄别，返回向量中逆序相邻元素对的总数，返回0就是有序
template<typename T>
int Vector<T>::disordered()const {
	int n = 0;
	for (int i = 0; i < _size; i++) {
		if (_elem[i - 1] > _elem[i]) {
			n++;
		}
	}
	return n;
}

//无序向量整体查找
template<typename T>
Rank Vector<T>::find(const T& e)const {
	return find(e, 0, _size);
}

//无序向量区间查找
template<typename T>
Rank Vector<T>::find(const T& e, Rank lo, Rank hi)const {
	while ((lo < hi--) && (_elem[hi] != e)) {
	}
	return hi;
}

//有序向量整体查找
template<typename T>
Rank Vector<T>::search(const T&e)const {
	return (_size <= 0) ? -1 : search(_elem, e, 0, _size);
}

//有序向量区间查找
template<typename T>
Rank Vector<T>::search(const T&e, Rank lo, Rank hi)const {
	binSearchC(_elem, e, lo, hi);
}

//二分查找，版本A
//template<typename T>
//static Rank binSearchA(T *A, const T& e, Rank lo, Rank hi) {
//	while (lo < hi) {
//		Rank mi = (lo + hi) >> 1;
//		if (A[mi] < e) {
//			lo = mi;
//		}
//		else if (e < A[mi]) {
//			hi = mi+1 ;
//		}
//		else {
//			return mi;
//		}
//	}
//	return -1;
//}

//二分查找，版本B
//template<typename T>
//static Rank binSearchB(T *A, const T&e, Rank lo, Rank hi) {
//	while (hi - lo > 1) {
//		Rank mi = (lo + hi) >> 1;
//		if (e < A[mi]) {
//			hi = mi;
//		}
//		else {
//			lo = mi ;
//		}
//	}
//	return (A[lo] == e) ? lo : -1;
//}

//二分查找，版本C，返回（重复元素）多个可行位置中的秩最大者
template<typename T>
static Rank binSearchC(T *A, const T&e, Rank lo, Rank hi) {
	while (lo<hi) {
		Rank mi = (lo + hi) >> 1;
		if (e < A[mi]) {
			hi = mi;
		}
		else {
			lo = mi +1;
		}
	}
	return --lo;
}

//可写访问接口

//重载[]操作符，使向量可以利用下标访问元素,循秩访问
template<typename T>
T& Vector<T>::operator[](Rank r) const {
	return _elem[r];//assert:0<=r<_size
}

//重载=操作符
template<typename T>
Vector<T> & Vector<T>::operator=(const Vector<T> &v) {
	if (_elem) {
		delete[] _elem;
		copyFrom(V._elem, 0, V.size());
		return *this;
	}
}

//单元素删除
template<typename T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}

//区间删除
template<typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) {
		return 0;
	}
	while (hi < _size) {
		_elem[lo++] = _elem[hi++];
	}
	_size = lo;
	shrink();
	return hi - lo;
}

//在向量中插入元素
template<typename T>
Rank Vector<T>::insert(Rank r, const T&e) {
	expand();
	for (int i = _size; i > r; i--) {
		_elem[i] = _elem[i-1];
	}
	_elem[r] = e;
	_size++;
	return r;
}

//默认在向量末端插入元素
template<typename T>
Rank Vector<T>::insert(const T &e) {
	return insert(_size, e);
}

//区间排序算法
template<typename T>
void Vector<T>::sort(Rank lo,Rank hi) {
	switch (rand() % 5) {
	case 1:
		bubbleSort(lo, hi);
		break;
	case 2:
		selectSort(lo, hi);
		break;
	case 3:
		mergeSort(lo, hi);
		break;
	case 4:
		heapSort(lo, hi);
		break;
	default:
		quickSort(lo, hi);
		break;
	}
}

//整体排序
template<typename T>
void Vector<T>::sort() {
	sort(0, _size);
}

//冒泡排序，原版
//void bubbleSort(Rank lo, Rank hi) {
//	while (!bubble1(lo, hi--));
//}
//template<typename T>
//bool Vector<T>::bubble(Rank lo, Rank hi) {
//	bool sorted = true;
//	while (++lo < hi) {
//		if (_elem[lo - 1] > _elem[lo]) {
//			sorted = false;
//			swap(_elem[lo - 1], _elem[lo]);
//		}
//	}
//	return sorted;
//}

//冒泡排序改进版
template<typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	while (lo < (hi = bubble(lo, hi)))00;
}
template<typename T>
Rank Vector<T>::bubble(Rank lo, Rank hi) {
	Rank last = lo;
	while (++lo < hi) {
		if (_elem[lo - 1] > _elem[lo]) {
			last = lo;
			swap(_elem[lo - 1], _elem[lo]);
		}
	}
	return last;
}

//归并排序
template<typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {
	if (hi - lo < 2) {
		return;
	}
	Rank mi = (lo + hi) / 2;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}
template<typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
	T* A = _elem + lo;
	Rank lb = mi - lo;
	T* B = new T[lb];
	Rank lc = hi - mi;
	for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc)) {
		if ((j < lb) && ((B[j] < C[k]) || !(k < lc))) {
			A[i++] = B[j++];
		}
		if ((k < lc) && ((B[j] > C[k]) || !(j < lb))) {
			A[i++] = C[k++];
		}
	}
	delete[] B;
}

//无序去重
template<typename T>
int Vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while (i < _size) {
		(find(_elem[i], 0, i) < 0) ? i++ : remove(i);
	}
	return oldSize - _size;
}

//有序去重，高效版
template<typename T>
int Vector<T>::uniquify() {
	int i = 0;
	int j = 0;
	while (++j < _size) {
		if (_elem[i] != _elem[j]) {
			_elem[++i] = _elem[j];
		}
	}
	_size = ++i;
	shrink();
	return j - i;
}

//遍历,借助函数对象机制
template<typename T>
template<typename VST>
void Vector<T>::traverse(VST & visit) {
	for (int i = 0; i < _size; i++) {
		visit(_elem[i]);
	}
}