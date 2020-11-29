//宏定义
#define InHeap(n,i) (((-1)<(i))&&((i)<(n)))
#define Parent(i) ((i-1)>>i)
#define LastInternal(n) Parent(n-1)//最后一个内部节点（即末节点的父亲）
#define LChild(i) (1+((i)<<1))
#define RChild(i) ((1+(i))<<1)
#define ParentValid(i) (0<i)//判断PQ[i]是否有父亲
#define LChildValid(n,i) Inheap(n,LChild(i))//判断PQ[i]是否有一个（左）孩子
#define RChildValid(n,i) Inheap(n,RChild(i))
#define Bigger(PQ,i,j) (lt(PQ[i],PQ[j])?j:i)//取最大者
#define ProperParent(PQ,n,i) \
			(RChildValid(n,i)?Bigger(PQ,Bigger(PQ,i,LChild(i)),RChild(i)):\
			(LChildValid(n,i)?Bigger(PQ,i,LChild(i)):i\
)\
)//相等时父节点优先，如此可避免不必要的交换
#include"vector.h"
#include"binarytree.h"

template<class T>
struct PQ {

	virtual void insert(T) = 0;
	virtual T getMax() = 0;
	virtual T delMax() = 0;

};

template<class T>
class PQ_ComplHeap :public PQ<T>, public Vector<T> {//多重继承机制，基于向量实现完全二叉堆

protected:
	Rank percolateDown(Rank n, Rank i);//下滤
	Rank percolateUp(Rank i);//上滤
	void heapify(Rank n);//Floyd建堆算法

public:
	PQ_ComplHeap() {}//默认构造
	PQ_ComplHeap(T* A, Rank n) {
		copyFrom(A, 0, n);
		heapify(n);
	}//拷贝构造 建堆
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