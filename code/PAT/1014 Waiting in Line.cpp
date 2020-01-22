#include <iostream>
#include<queue>
using namespace std;
#define Max 0x7fffffff
#define MaxTime 540//定义最大服务时间为540秒
int n, m, k, q;//为当前窗口的总人数
int Curtime = 0, CurIndex = 1,CurNum;//Curtime为当前时间,Cur当前服务完的总人数
int capacity,cur_capacity=0;

struct customer {
	int time = 0;
	bool flag = false;
	int DoneTime = 550;	//默认每个消费者都没被服务
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
这段话的意思是在5点没背服务的就不能被服务了

总结：
本题坑点较多，本人也有许多考虑不周的地方
比如多个窗口同时接收完成任务的情况就没考虑到，以后要多考虑同时完成的情况

学习了set只能在插入删除的时候排序，其他情况不行

想的太多，没想清楚时间复杂度的概念，用逐秒的算法可以解决问题的
以后有限次循环可以用的
*/