#include <iostream>
#include<queue>
using namespace std;
#define Max 0x7fffffff
#define MaxTime 540//����������ʱ��Ϊ540��
int n, m, k, q;//Ϊ��ǰ���ڵ�������
int Curtime = 0, CurIndex = 1,CurNum;//CurtimeΪ��ǰʱ��,Cur��ǰ�������������
int capacity,cur_capacity=0;

struct customer {
	int time = 0;
	bool flag = false;
	int DoneTime = 550;	//Ĭ��ÿ�������߶�û������
	void Display() {
		if (!flag) {
			printf("Sorry\n");
		}
		else {
			int hour = DoneTime / 60 + 8;
			int minute = DoneTime % 60;
			printf("%02d:%02d\n", hour, minute);
		}
	}
};
customer customers[1005];
struct Window {
	int time = 0;
	queue <int>q;
	void Add(int i) {
		q.push(i);
	}
	void DoneOneCustomer() {
		//time += customers[q.front()].time;
		customers[q.front()].DoneTime = time+ customers[q.front()].time;		
		if (time < MaxTime) {
			customers[q.front()].flag = true;
		}	 
		time = customers[q.front()].DoneTime;
		q.pop();
		if (CurIndex <= k) {
			q.push(CurIndex++);
		}
		if (q.empty()) {
			time = Max;
		}
	}
};
Window windows[20];
Window* Running() {
	Window* p = NULL;
	int temp1 = Max,temp2;
	for (int i = 0; i < n; i++) {
		if (windows[i].q.empty()) {
			continue;
		}
		temp2 =customers[ windows[i].q.front()].time + windows[i].time;

		if (temp1 > temp2) {
			temp1 = temp2;
			p = &windows[i];
		}
	}
	return p;
}

int main() {
	scanf_s("%d%d%d%d", &n, &m, &k, &q);
	if (m == 0)m = 1;
	int i;
	capacity = n * m;
	
	for (i = 1; i <= k; i++) {		
		scanf_s("%d", &customers[i].time);
	}

	for (; CurIndex <= capacity&&CurIndex<=k; CurIndex++) {
		windows[(CurIndex-1) % n].Add(CurIndex);
	}
	Window* p = Running();
	while (p)
	{
		p->DoneOneCustomer();
		p = Running();
	}
	int op;
	for (i = 0; i < q; i++) {
		scanf_s("%d", &op);
		customers[op].Display();
	}
	return 0;
}

/*
Note that since the bank is closed everyday after 17:00,
for those customers who cannot be served before 17:00,
you must output Sorry instead.
��λ�����˼����5��û������ľͲ��ܱ�������

�ܽ᣺
����ӵ�϶࣬����Ҳ����࿼�ǲ��ܵĵط�
����������ͬʱ�����������������û���ǵ����Ժ�Ҫ�࿼��ͬʱ��ɵ����

ѧϰ��setֻ���ڲ���ɾ����ʱ�����������������

���̫�࣬û�����ʱ�临�Ӷȵĸ����������㷨���Խ�������
�Ժ����޴�ѭ�������õ�
*/