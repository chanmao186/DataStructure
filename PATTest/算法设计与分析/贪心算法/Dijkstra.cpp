#include<iostream>
using namespace std;
#define N 10
#define Max 1000

struct DNode {
	int weight;
	int pre;
	/*
	�����Ƿ�������·�����㷨
	0���������
	1����δ���
	*/
	int flag;
};

/*
nӵ�еĽڵ����
indexҪ��Ѱ�Ľڵ��±�
D�洢���������
c��ʾ·���Ķ�ά����
*/
void Dijkstra(int n, int index,DNode D[N], int c[N][N]) {
	//vΪҪ��������Ľڵ�
	int i = 0, j, temp,v;
	for (; i < n; i++) {
		D[i].weight = c[index][i];
		D[i].flag = 1;
		D[i].pre = D[i].weight == Max ? -1 : index;
	}

	D[index].flag = 0;
	for (i = 1; i < n; i++) {
		temp = Max;
		v = index;
		//��Ѱ�Խڵ�indexΪ�н�ڵ����С·��
		for (j = 0; j < n; j++) {
			if (D[j].flag && D[j].weight < temp) {
				temp = D[j].weight;
				v = j;
			}
		}	
		D[v].flag = 0;
		//���ýڵ��½��м���
		for (j = 0; j < n; j++) {
			//�����ӱ�ڵ㻹δ������С�㷨���£���v��j��ͨ
			if (D[j].flag && c[v][j] < Max) {
				temp = D[v].weight + c[v][j];
				if (temp < D[j].weight) {
					D[j].weight = temp;
					D[j].pre = v;
				}
			}
		}
	}
}

void Output(DNode D[N], int n) {
	int i;
	printf("node:  ");
	for (i = 0; i < n; i++) {
		printf("%4d", i);
	}
	cout << endl;
	
	printf("weight:");
	for (i = 0; i < n; i++) {
		printf("%4d", D[i].weight);
	}
	cout << endl;
	printf("pre:   ");
	for (i = 0; i < n; i++) {
		printf("%4d", D[i].pre);
	}
}
int main(void) {
	int c[N][N] = { 
	{0,10,Max,30,100},
	{10,0,50,Max,Max},
	{Max,50,0,20,10},
	{30,Max,20,0,60},
	{100,Max,10,60,0} };
	int n = 5;
	DNode d[N];
	Dijkstra(n, 0, d, c);
	cout << "0�ڵ�ĵ�Դ���·��Ϊ:" << endl;
	Output(d,n);
	return 0;
}