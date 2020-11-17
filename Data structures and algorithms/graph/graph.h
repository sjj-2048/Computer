#pragma once
#include"vector.h"
typedef enum{UNDISCOVERED,DISCOVERED,VISITED} VStatus;
typedef enum{UNDETERMINED,TREE,CROSS,FORWARD,BACKWARD} EType;

//图模板类
template<class Tv,class Te>
class Graph {

private:
	void reset() {
		
		for (int i = 0; i < n; i++) {
			
			status(i) = UNDISCOVERED;
			dTime(i) = fTime(i) = -1;
			parent(i) = -1;
			priority(i) = INT_MAX;
			
			for (int j = 0; j < n; j++) {
				if (exists(i, j)) {
					type(i, j) = UNDETERMINED;
				}
			}
		}
	}
	void BFS(int, int&);
	void DFS(int, int&);
	void BCC(int, int&, Stack<int>&);
	bool TSort(int, int&, Stack<Tv>*);
	template<typename PU>
	void PFS(int, PU);

public:
	//顶点
	int n;
	virtual int insert(const Tv&) = 0;
	virtual Tv remove(int) = 0;
	virtual Tv& vertex(int) = 0;
	virtual int inDegree(int) = 0;
	virtual int outDegree(int) = 0;
	virtual int firstNbr(int) = 0;
	virtual int nextNbr(int,int) = 0;
	virtual VStatus& status(int) = 0;
	virtual int& dTime(int) = 0;
	virtual int& fTime(int) = 0;
	virtual int& parent(int) = 0;
	virtual int& priority(int) = 0;
	//边
	int e;
	virtual bool exists(int, int) = 0;
	virtual void insert(const Te&, int, int, int) = 0;
	virtual Te remove(int, int) = 0;
	virtual EType& type(int, int) = 0;
	virtual Te& edge(int, int) = 0;
	virtual int& weight(int, int) = 0;
	//算法
	void bfs(int);
	void dfs(int);
	void bcc(int);
	Stack<Tv>* tSort(int);
	void prim(int);
	void dijkstra(int);
	template<typename PU>
	void pfs(int, PU);
};

//顶点对象
template<class Tv>
struct Vertex {
	Tv data;
	int inDegree, outDegree;
	VStatus status;
	int dTime, fTime;
	int parent;
	int priorty;

	Vertex(const Tv& d = (Tv)0)
		:data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
		dTime(-1), fTime(-1), parent(-1), priority(INT_MAX) {}
};

//边对象
template<class Te>
struct Edge {
	Te data;
	int weight;
	EType type;
	Edge(const Te& d, int w)
		:data(d), weight(w), type(UNDETERMINED) {}
};

//基于向量，以邻接矩阵形式实现的图
template<class Tv,class Te>
class GraphMatrix :public Graph<Tv, Te> {
private:
	Vector<Vertex<Tv>> V;
	Vector<Vector<Edge<Te>*>> E;

public:
	GraphMatrix() { n = e = 0;}
	~GraphMatrix() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				delete E[i][j];
			}
		}
	}

	//顶点基本操作

	virtual Tv& vertex(int i) {
		return V[i].data;
	}
	virtual int inDegree(int i) {
		return V[i].inDegree;
	}
	virtual int outDegree(int i) {
		return V[i].outDegree;
	}
	virtual int firstNbr(int i) {
		return nextNbr(i, n);
	}
	virtual int nextNbr(int i, int j) {
		while ((-1 < j) && (!exists(i, --j))) {
			return j;
		}
	}
	virtual VStatus& status(int) {
		return V[i].status;
	}
	virtual int& dTime(int i) {
		return V[i].dTime;
	}
	virtual int& fTime(int i) {
		return V[i].fTime;
	}
	virtual int& parent(int i) {
		return V[i].parent;
	}
	virtual int& priority(int i) {
		return V[i].priority;
	}
	
	//顶点动态操作
	virtual int insert(const Tv& vertex) {
		for (int j = 0; j < n; j++) {
			E[j].insert(NULL);
		}
		n++;
		E.insert(Vector<Edge<Te>*>(n, n, (Edge<Te>*)NULL));
		return V.insert(Vertex<Tv>(Vertex));
	}
	virtual Tv remove(int i) {
		for (int j = 0; j < n; j++) {
			if (exists(i, j)) {
				delete E[i][j];
				V[j].inDegree--;
				e--;
			}
		}
		E.remove(i);
		n--;
		Tv tem = vertex(i);
		V.remove(i);
		for (int j = 0; j < n; j++) {
			if (Edge<Te>* e = E[j].remove(i)) {
				delete e;
				V[j].outDegree--;
				e--;
			}
		}
		return tem;
	}

	//边的确认操作

	virtual bool exists(int i, int j) {
		return (0 <= i) && (i < n) && (0 <= j) && (j < n) && (E[i][j] != NULL);
	}

	//边的基本操作

	virtual EType& type(int i, int j) {
		return E[i][j]->type;
	
	}
	virtual Te& edge(int i, int j) {
		return E[i][j]->edge;

	}
	virtual int& weight(int i, int j) {
		return E[i][j]->weight;

	}

	//边的动态操作

	virtual void insert(const Te& data, int w, int i, int j) {
		if (exists(i, j)) {
			return;
		}
		E[i][j] - new Edge<Te>(data, w);
		V[i].outDegree++;
		V[j].inDegree++;
		e++;
	}
	virtual Te remove(int i, int j) {
		Te tem = E[i][j]->data;
		delete E[i][j];
		E[i][j] = NULL;
		e--;
		V[i].outDegree--;
		V[j].inDegree--;
		return tem;
	}
};