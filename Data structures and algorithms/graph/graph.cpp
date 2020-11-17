#include"graph.h"
#include"queue.h"

//广度优先搜索

template<typename Tv,typename Te>
void Graph<Tv, Te>::BFS(int v,int& clock) {

	Queue<int> Q;
	status(v) = DISCOVERED;
	Q.enqueue(v);
	while (!Q.empty()) {
		int v = Q.dequeue(); 
		dTime(v) = ++clock;
		for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
			if (status(u) == UNDISCOVERED) {
				
				status(u) = DISCOVERED;
				Q.enqueue(u);
				type(v, u) = TREE;
				parent(u) = v;

			}
			else {
				type(v, u) = CROSS;
			}
		}
		status(v) = VISITED;
	}
}

template<typename Te,typename Tv>
void Graph<Te, Tv>::bfs(int s) {
	reset();
	int v = s;
	int clock = 0;

	do {
		if (status(v) = UNDISCOVERED) {
			BFS(v, clock);
		}
	} while (s != (v = (++v%n)));
}

//深度优先搜索

template<typename Tv,typename Te>
void Graph<Tv,Te>::DFS(int v, int &clock){
	dTime(v) = ++clock;
	status(v) = DISCOVERED;
	for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
		switch (status(u)) {
			case UNDISCOVERED:
				type(v, u) = TREE;
				parent(u) = v;
				DFS(u, clock);
				break;
			case DISCOVERED:
				type(v, u) = BACKWARD;
				break;
			case VISIED:
				type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : type(v, u) = CROSS;
				break;
		}
	}
	status(v) = VISITED;
	fTime(v) = ++clock;
}

template<typename Tv,typename Te>
void Graph<Tv, Te>::dfs(int s) {
	reset();
	int v = s;
	int clock = 0;
	do {
		if (UNDISCOVERED == status(v)) {
			DFS(v, clock);
		}
	} while (s != (v = (++v%n)));
}