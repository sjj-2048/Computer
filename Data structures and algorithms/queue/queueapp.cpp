#include"queue.h"
using namespace std;

//银行服务模拟

//定义顾客类
struct Customer {
	
	int window;
	unsigned int time;

};

//服务过程模拟
void simulate(int nWin, int servTime) {
	Queue<Customer> *windows = new Queue<Customer>[nWin];
	
	for (int now = 0; now < servTime; now++) {
		
		if ( rand() % (1 + nWin)) {//新用户到达的概率
			
			Customer c;

			c.time = 1 + rand() % 98;//用户的服务时间随机
			c.window = bestWindow(windows, nWin);

			windows[c.window].enqueue(c);//新用户加入对应的队列
		}
	}

	for (int i = 0; i < nWin; i++) {

		if (!windows[i].empty()) {

			if (--windows[i].front().time <= 0) {

				windows[i].dequeue();

			}
		}
	}
	delete[] windows;
}

//确定最佳队列

int bestWindow(Queue<Customer> windows[], int nWin) {

	int minSize = windows[0].size();
	int optiWin = 0;

	for (int i = 1; i < nWin; i++) {

		if (minSize > windows[i].size()) {

			minSize = windows[i].size();
			optiWin = i;

		}
	}
	return optiWin;
}
