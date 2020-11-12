#pragma once
typedef int Rank;
#define Node(T) ListNode<T>*

//节点模板类
template<typename T>
struct ListNode {
	//成员变量
	T data;
	Node(T) pred;
	Node(T) succ;
	//构造函数
	ListNode() {}
	ListNode(T e, Node(T) p = NULL, Node(T) s = NULL)
		:data(e), pred(p), succ(s) {}
	//操作接口
	Node(T) insertAsPred(const T& e);
	Node(T) insertAsSucc(const T& e);
};

//列表模板类
template<typename T>
class List {
	
private:

	int _size;
	Node(T) header;
	Node(T) trailer;

protected:

	void init();
	int clear();
	void copyNodes(Node(T) p, int n);
	void merge(Node(T)&, int, List<T>&, Node(T), int);
	void mergeSort(Node(T), int);
	void selectionSort(Node(T) p, int n);
	void insertionSort(Node(T) p, int n);

public:
	
	//构造和析构
	List() { init(); }
	List(const List<T> &L);
	List(const List<T> &L, Rank r, int n);
	List(Node(T) p, int n);
	~List();

	//只读访问接口
	Rank size() const { return _size; }
	bool empty() const { return _size <= 0; }
	T& operator[](Rank r) const;
	Node(T) first() const { return header->succ; }
	Node(T) last() const { return trailer->pred; }
	bool valid(Node(T) p) { return p && (trailer != p) && (header != p); }
	int disordered()const;
	Node(T) find(const T& e)const { return find(e, _size, trailer); }
	Node(T) find(const T& e, int n,Node(T) p)const;
	Node(T) search(const T& e)const;
	Node(T) search(const T& e, int n, Node(T) p)const;
	Node(T) selectMax(Node(T) p, int n);
	Node(T) selectMax() { return selectMax(header->succ, _size); }

	//可写访问接口
	Node(T) insertAsFirst(const T& e);
	Node(T) insertAsLast(const T& e);
	Node(T) insertAfter(Node(T) p, const T& e);
	Node(T)insertBefore(Node(T) p, const T& e);
	T remove(Node(T) p);
	void merge(List<T>& L) { merge(first(), size, L, L.first(), L._size); }
	void sort(Node(T) p, int n);
	void sort() { sort(first(), _size); }
	int deduplicate();
	int uniquify();
	void reverse();

	//遍历
	void traverse(void(*)(T&));
	template<typename VST>
	void traverse(VST&);
};