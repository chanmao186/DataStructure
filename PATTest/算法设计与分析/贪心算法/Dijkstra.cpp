#include<iostream>
using namespace std;
#define N 10
#define Max 1000

struct DNode {
	int weight;
	int pre;
	/*
	代表是否完成最短路径的算法
	0代表已完成
	1代表未完成
	*/
	int flag;
};

/*
n拥有的节点个数
index要找寻的节点下表
D存储结果的数组
c表示路径的二维数组
*/
void Dijkstra(int n, int index,DNode D[N], int c[N][N]) {
	//v为要进行运算的节点
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
		//找寻以节点index为中介节点的最小路径
		for (j = 0; j < n; j++) {
			if (D[j].flag && D[j].weight < temp) {
				temp = D[j].weight;
				v = j;
			}
		}	
		D[v].flag = 0;
		//到该节点下进行计算
		for (j = 0; j < n; j++) {
			//若连接表节点还未进行最小算法更新，且v与j联通
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
	cout << "0节点的单源最短路径为:" << endl;
	Output(d,n);
	return 0;
}