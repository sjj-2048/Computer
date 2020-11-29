//�궨��
#define InHeap(n,i) (((-1)<(i))&&((i)<(n)))
#define Parent(i) ((i-1)>>i)
#define LastInternal(n) Parent(n-1)//���һ���ڲ��ڵ㣨��ĩ�ڵ�ĸ��ף�
#define LChild(i) (1+((i)<<1))
#define RChild(i) ((1+(i))<<1)
#define ParentValid(i) (0<i)//�ж�PQ[i]�Ƿ��и���
#define LChildValid(n,i) Inheap(n,LChild(i))//�ж�PQ[i]�Ƿ���һ�����󣩺���
#define RChildValid(n,i) Inheap(n,RChild(i))
#define Bigger(PQ,i,j) (lt(PQ[i],PQ[j])?j:i)//ȡ�����
#define ProperParent(PQ,n,i) \
			(RChildValid(n,i)?Bigger(PQ,Bigger(PQ,i,LChild(i)),RChild(i)):\
			(LChildValid(n,i)?Bigger(PQ,i,LChild(i)):i\
)\
)//���ʱ���ڵ����ȣ���˿ɱ��ⲻ��Ҫ�Ľ���
#include"vector.h"
#include"binarytree.h"

template<class T>
struct PQ {

	virtual void insert(T) = 0;
	virtual T getMax() = 0;
	virtual T delMax() = 0;

};

template<class T>
class PQ_ComplHeap :public PQ<T>, public Vector<T> {//���ؼ̳л��ƣ���������ʵ����ȫ�����

protected:
	Rank percolateDown(Rank n, Rank i);//����
	Rank percolateUp(Rank i);//����
	void heapify(Rank n);//Floyd�����㷨

public:
	PQ_ComplHeap() {}//Ĭ�Ϲ���
	PQ_ComplHeap(T* A, Rank n) {
		copyFrom(A, 0, n);
		heapify(n);
	}//�������� ����
	void insert(T);
	T getMax();
	T delMax();

};

template<class T>
class PQ_LeftHeap :public  PQ<T>, public BinTree<T> {

public:
	PQ_LeftHeap() {};
	PQ_LeftHeap(T* E, int n) {
		for (int i = 0; i < n; i++) {
			insert(E[i]);
		}
	}
	void insert(T);
	T getMax() {
		return _root->data;
	}
	T delMax();

};