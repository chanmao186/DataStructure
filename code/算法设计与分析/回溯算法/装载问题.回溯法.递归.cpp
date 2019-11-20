#include <iostream>
using namespace std;
#define N 10

/*
Besw����Ʒ����������
w����Ʒ��������
n����Ʒ������
c������������
bestX����1��Ҫ��ŵ���Ʒ
r��ʣ�༯װ������
*/
int BestW = 0,
w[N] = { 10,50,45,30,20,25,40,15,35,10 },
n = N,
c[2] = { 150,150 },
bestX[N] = { 0 },
X[N] = { 0 },
r = 0;

/**
�޽��������ж�����Ϊ��ǰ·�������ֵ�ܳ������Ž�
*/
bool Bound(int cw) {
	return cw + r > BestW;
}

/*
Լ����������1����ŵ���ʣ����Ʒ
*/
bool Constraint(int cw) {
	return cw <= c[0];
}

/**
�����㷨
��ǰ������Ʒ���±�
��1������
*/
void  Backtrack(int cn, int cw) {
	//����������һ�㣬�����һ�½��
	if (cn == n) {
		if (cw <= c[0] && r - cw <= c[1] && BestW < cw) {
			BestW = cw;
			for (int i = 0; i < n; i++) {
				bestX[i] = X[i];
			}
		}
	}
	else {
		X[cn] = 0;
		cw += w[cn];
	    //ÿ����һ��,ʣ����Ʒ�������ͼ�ȥ��ǰ������Ʒ������
		r -= w[cn];
		if (Constraint(cw) && Bound(cw)) {
			Backtrack(cn + 1, cw);
		}
		X[cn] = 1;
		cw -= w[cn];
		if (Constraint(cw) && Bound(cw)) {
			Backtrack(cn + 1, cw);
		}
		//�ָ�ʣ����������
		r += w[cn];
	}
}
/*
װ������
Ŀ�����Ž⣺ʹ��1�ĳ������
*/
int main() {

	cout << "��������Ʒ������(����0��Ĭ�Ϸ���)��" << endl;
	cin >> n;

	//�ж��Ƿ���Ĭ�Ϸ���
	if (n == 0) {
		n = N;
		r = 280;
	}
	else {
		//��������
		cout << "�밴˳���������Ʒ������:" << endl;
		for (int i = 0; i < n; i++) {
			cin >> w[i];
			r += w[i];
		}
		//��������
		for (int i = 0; i < 2; i++) {
			cout << "�����봬" << i << "������:" << endl;
			cin >> c[i];
		}
	}

	//�ж��Ƿ���
	if (r <= c[0] + c[1]) {
		//�ж��Ƿ��н������
		Backtrack(0, 0);
		if (BestW) {
			cout << "���Ž������Ϊ: ";
			for (int i = 0; i < n; i++) {
				cout << bestX[i] << " ";
			}
		}
		else {
			cout << "����2:�����޷�װ����Ʒ�嵥�����Ʒ" << endl;
		}
	}
	else {
		cout << "����1:��Ʒ���أ������޷�װ��" << endl;
	}
	return 0;
}