#pragma once
typedef int Rank;
#define DEFAULT_CAPACITY 3

template<class T>
class Vector {
protected:
	Rank _size;
	int _capacity;
	T* _elem;

	void copyFrom(T const *A, Rank lo, Rank hi);
	void expand();
	void shrink();
	Rank bubble(Rank lo, Rank hi);
	void bubbleSort(Rank lo, Rank hi);
	Rank max(Rank lo, Rank hi);
	void selectSort(Rank lo, Rank hi);
	void merge(Rank lo, Rank mid, Rank hi);
	void mergeSort(Rank lo, Rank hi);
	Rank partition(Rank lo, Rank hi);
	void quickSort(Rank lo, Rank hi);
	void heapSort(Rank lo, Rank hi);
public:
	Vector(int c = DEFAULT_CAPACITY, int s = 0,T v=0);
	Vector(const T*A, Rank n);
	Vector(const T *A, Rank lo, Rank hi);
	Vector(const Vector<T> &V);
	Vector(const Vector<T> &V, Rank lo, Rank hi);
	~Vector();
	//只读接口
	Rank size()const;
	bool empty()const;
	int disordered()const;
	Rank find(const T &e)const;
	Rank find(const T &e, Rank lo, Rank hi)const;
	Rank search(const T &e)const;
	Rank search(const T &e, Rank lo, Rank hi)const;

	//可写接口
	T& operator[](Rank r)const;
	Vector<T> &operator=(const Vector<T> &);
	T remove(Rank r);
	int remove(Rank lo, Rank hi);
	Rank insert(Rank r, const T &e);
	Rank insert(const T &e);
	void sort(Rank lo, Rank hi);
	void sort();
	void unsort(Rank lo,Rank hi);
	void unsort();
	int deduplicate();
	int uniquify();
    //遍历
	template<typename VST>
	void traverse(VST &);
};