#include"queue.h"
using namespace std;

//���з���ģ��

//����˿���
struct Customer {
	
	int window;
	unsigned int time;

};

//�������ģ��
void simulate(int nWin, int servTime) {
	Queue<Customer> *windows = new Queue<Customer>[nWin];
	
	for (int now = 0; now < servTime; now++) {
		
		if ( rand() % (1 + nWin)) {//���û�����ĸ���
			
			Customer c;

			c.time = 1 + rand() % 98;//�û��ķ���ʱ�����
			c.window = bestWindow(windows, nWin);

			windows[c.window].enqueue(c);//���û������Ӧ�Ķ���
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

//ȷ����Ѷ���

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
