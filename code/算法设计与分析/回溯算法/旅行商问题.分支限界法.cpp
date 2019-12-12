#include<iostream>
#include"../公用数据结构/HeapX.h"
using namespace std;
#define N 10000
#define Max 1000000
int n;//城市的数量
int dn;//即n-1
int BestX[N];
int MinOut[N];
int BestC = Max;//最优花费
//给定路径
int G[N][N] = {
		{0,30,6,4},
		{30,0,5,10},
		{6,5,0,20},
		{4,10,20,0}
};

struct HeapNode {
	int cc;//物品的当前价值
	int lcost;//该分支可能达到的最小值
	int lev;//当前运算的层数
	int rcost;//lev->dn之间的最小出度和
	int* CX;
	HeapNode() {
		cc = 0;
		lev = 0;
		lcost = 0;
		rcost = 0;
		CX = new int[n];
	}
	HeapNode(int _lev, int _lcost, int _cc) :
		lev(_lev), lcost(_lcost), cc(_cc) {}
	bool operator <(HeapNode& other)const {
		return lcost > other.lcost;
	}
};
/*
cc:当前的花费
*/
bool Bound(int cc) {
	return cc < BestC;
}
/*
weight:两个城市之间的权重
*/
bool Constraint(int weight) {
	return weight && weight < Max;
}
HeapX<HeapNode> H;
//进行初始化
void Initialize() {
	n = 4;
	dn = n - 1;
	for (int i = 0, j, temp; i < n; i++) {
		temp = Max;
		for (j = 0; j < n; j++) {
			if (i == j)continue;
			if (temp > G[i][j]) {
				temp = G[i][j];
			}
		}
		MinOut[i] = temp;
	}
}
int main() {
	Initialize();
	int i;
	HeapNode E;

	//寻找每个节点的最小出度
	int CCity;//当前所在城市
	int WillToCity;//将要去的城市
	int cc, rcost, lcost;
	for (i = 0; i < n; i++) {
		E.CX[i] = i;
		E.rcost += MinOut[i];
	}
	while (true) {
		if (Bound(E.cc)) {
			CCity = E.CX[E.lev];
			if (E.lev == dn) {//拓展到叶子节点
				if (Constraint(G[CCity][0])) {
					cc = E.cc + G[CCity][0];
					if (Bound(cc)) {
						BestC = cc;
						for (i = 0; i < n; i++) {
							BestX[i] = E.CX[i];
						}
					}
				}
			}
			else {
				//更新当前所在城市节点
				rcost = E.rcost - MinOut[E.lev];
				for (i = E.lev+1; i < n; i++) {
					WillToCity = E.CX[i];//更新将要去的城市节点

					if (Constraint(G[CCity][WillToCity])) {
						cc = E.cc + G[CCity][WillToCity];						
						lcost = cc + rcost;//计算当前节点可能达到的最小值
						if (Bound(lcost)) {
							HeapNode temp;
							temp.lev = E.lev + 1;
							for (int j = 0; j < n; j++) {
								temp.CX[j] = E.CX[j];
							}
							temp.CX[temp.lev] = WillToCity;
							temp.CX[i] = E.CX[temp.lev];
							temp.cc = cc;
							temp.rcost = rcost;
							temp.lcost = lcost;//能达到的下届
							H.Insert(temp);
						}
					}
				}
			}
		}
		//delete[] E.CX;
		if (H.Empty()) {
			break;
		}
		else {
			E = H.Delete();
		}
	}


	if (BestC == Max) {
		cout << "无回路" << endl;
	}
	else {
		cout << "最小花费为:" << BestC << endl;
		cout << "最优路径为:" << endl;
		cout << 0;
		for (i = 1; i < n; i++) {
			cout << "->" << BestX[i];
		}
		cout << "->" << 0 << endl;
	}
	return 0;
}