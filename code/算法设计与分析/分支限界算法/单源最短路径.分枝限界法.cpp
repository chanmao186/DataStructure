#include<iostream>
#include "../公用数据结构/Heap.h"
using namespace std;
#define N 20
int dist[N];
char Node[N] = "SABCDEFGHIJKLT";
//创建邻接矩阵
int c[N][N] = {
	//s    a   b   c   d   e   f   g   h   i   t
	{  0,  2,  3,  4,MAX,MAX,MAX,MAX,MAX,MAX,MAX},
	{MAX,  0,  3,MAX,  7,  2,MAX,MAX,MAX,MAX,MAX},
	{MAX,MAX,  0,MAX,MAX,  9,  2,MAX,MAX,MAX,MAX},
	{MAX,MAX,MAX,  0,MAX,MAX,  2,MAX,MAX,MAX,MAX},
	{MAX,MAX,MAX,MAX,  0,MAX,MAX,  2,  1,MAX,MAX},
	{MAX,MAX,MAX,MAX,MAX,  0,  1,MAX,  3,MAX,MAX},
	{MAX,MAX,MAX,MAX,MAX,MAX,  0,MAX,  5,  1,MAX},
	{MAX,MAX,MAX,MAX,MAX,MAX,MAX,  0,MAX,MAX,  2},
	{MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,  0,MAX,  3},
	{MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,  2,  0,  2},
};
class node {
public:
	node(int Weight,int Index) {
		this->Weight = Weight;
		this->Index = Index;
	}
	node() {
		Weight = Index = 0;
	}
	/*重载运算符，主要是为了与小顶堆的模版类兼容*/
	bool operator <(const node& n) {
		return this->Weight < n.Weight;
	}

	bool operator >(const node& n) {
		return this->Weight > n.Weight;
	}

	void operator =(int Weight) {
		this->Weight=Weight;
	}
	int Weight;
	int Index;
};
void Initalize() {
	for (int i = 0; i < N; i++) {
		dist[i] = MAX;
	}
}
int main() {
	Initalize();
	MinHeap<node> H(1000);
	node temp(0,0);
	//先将起始点S压如小顶堆
	H.Insert(temp);
	int i,n=10;
	while (true) {
		if (H.IsEmputy())break;
		temp = H.Delete();
		for (int i = 1; i < n; i++) {
			if (c[temp.Index][i] > 0 && c[temp.Index][i] < MAX && temp.Weight + c[temp.Index][i] < dist[i]) {

			 }
		}
	}
	
	return 0;
}