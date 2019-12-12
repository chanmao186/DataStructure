#include<iostream>
#include"../�������ݽṹ/HeapX.h"
using namespace std;
#define N 10000
#define Max 1000000
int n;//���е�����
int dn;//��n-1
int BestX[N];
int MinOut[N];
int BestC = Max;//���Ż���
//����·��
int G[N][N] = {
		{0,30,6,4},
		{30,0,5,10},
		{6,5,0,20},
		{4,10,20,0}
};

struct HeapNode {
	int cc;//��Ʒ�ĵ�ǰ��ֵ
	int lcost;//�÷�֧���ܴﵽ����Сֵ
	int lev;//��ǰ����Ĳ���
	int rcost;//lev->dn֮�����С���Ⱥ�
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
cc:��ǰ�Ļ���
*/
bool Bound(int cc) {
	return cc < BestC;
}
/*
weight:��������֮���Ȩ��
*/
bool Constraint(int weight) {
	return weight && weight < Max;
}
HeapX<HeapNode> H;
//���г�ʼ��
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

	//Ѱ��ÿ���ڵ����С����
	int CCity;//��ǰ���ڳ���
	int WillToCity;//��Ҫȥ�ĳ���
	int cc, rcost, lcost;
	for (i = 0; i < n; i++) {
		E.CX[i] = i;
		E.rcost += MinOut[i];
	}
	while (true) {
		if (Bound(E.cc)) {
			CCity = E.CX[E.lev];
			if (E.lev == dn) {//��չ��Ҷ�ӽڵ�
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
				//���µ�ǰ���ڳ��нڵ�
				rcost = E.rcost - MinOut[E.lev];
				for (i = E.lev+1; i < n; i++) {
					WillToCity = E.CX[i];//���½�Ҫȥ�ĳ��нڵ�

					if (Constraint(G[CCity][WillToCity])) {
						cc = E.cc + G[CCity][WillToCity];						
						lcost = cc + rcost;//���㵱ǰ�ڵ���ܴﵽ����Сֵ
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
							temp.lcost = lcost;//�ܴﵽ���½�
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
		cout << "�޻�·" << endl;
	}
	else {
		cout << "��С����Ϊ:" << BestC << endl;
		cout << "����·��Ϊ:" << endl;
		cout << 0;
		for (i = 1; i < n; i++) {
			cout << "->" << BestX[i];
		}
		cout << "->" << 0 << endl;
	}
	return 0;
}