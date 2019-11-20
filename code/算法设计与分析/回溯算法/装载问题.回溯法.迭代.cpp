#include<iostream>
using namespace std;
#define N 10

/**
<<<<<<< HEAD
����
//�������ζ�ջ
class stack {
public:
stack() {
n = 0;
}
int Pop() {
if (Empty)
return data[--n];
else {
//�����ѿ�
cout << "�����ѿ�" << endl;
return 0;
}
}
void Push(int num) {
if (n == N) {
cout << "��������" << endl;
};
data[n++] = num;
}
bool Empty() {
return n;
}
private:
int n;
int data[N];
};
*/

/**
�Ƿ������޽�����,����Ϊtrue,������Ϊfakse
cn:��ǰ������Ʒ�±�
n:��Ʒ����
*/
bool Bound(int cn, int n) {
	return cn > n;
}

/**
�Ƿ�����Լ�����������㷵��true,�����㷵��false
�޽�����:����������װ����ȷҪװ����Ʒ������
t:��ǰ���ڼ���Ľڵ���±�
n����Ʒ����
cw[0]:��ȷ�������0����Ʒ����
cw[1]:��ȷ�������1����Ʒ����
c[0]:��0������
c[1]:��1������
*/
bool Constraint(int cw[2], int c[2], int t, int n) {
	return t < n&& cw[0] <= c[0] && cw[1] <= c[1];
}

/**
�Ƿ����������Ľ�����������㷵��true,�����㷵��false
��������1���Ը�������ʣ����Ʒ������
r:Ҫװ�ڴ�0����Ʒ����
c:��0������
*/
bool Solution(int cw[2], int c[1]) {
	return cw[0] <= c[0] && cw[1] <= c[1];
}

/**
������������
*/
void CopyIntArray(int* a, int* b, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = b[i];
	}
}

/**
�ǵݹ�Ļ����㷨
w:��Ʒ�������б�
bestX:���Ž�
c:��0�ʹ�1�ĳ���
n:��Ʒ������
r:��Ʒ������
*/
bool Backtrack(int w[N], int bestX[N], int c[2], int n, int r) {
	/**
	result:��������Ƿ��н�
	������w[2]={150,40},c[2]={100,100}�������
	��������װ����Ʒ������ȴ�޷�װ��150�Ǹ���Ʒ��
	������������޽�;
	back:�Ƿ���л��ݵı�ʶ��
	true���л���
	false����������ȱ���
	*/
	bool result = false, back = false;

	/**
	X:z���Ž������
	0���ڴ�0
	1��ֹ��1
	beseW:���Ž⣬�˴�����1��������
	cw[0]:��ȷ���ڴ�0����Ʒ�ĳ���
	cw[1]:��ȷ���ڴ�1����Ʒ�ĳ���
	t:��ǰ���ڼ������Ʒ���
	*/
	int X[N] = { 0 }, bestW = 0, cw[2] = { 0 }, t = 1;

	//��������һ��Ʒ��״̬�����ڴ�0
	X[0] = 1;
	cw[1] += w[0];
	r -= w[0];
	while (t>=0) {
		if (back) {
			cw[X[t]] -= w[t];
			r += w[t];
			if (X[t]) {
				//������֧����ִ����ȱ���
				back = false;
				X[t] = 0;
				cw[0] += w[t];
				r -= w[t];
				t++;			
			}
			else {
				t--;
			}
		}
		else {
			//������Լ���������޽��������������ȱ���
			if (Constraint(cw, c, t, n) && Bound(cw[1] + r, bestW)) {
				X[t] = 1;
				cw[1] += w[t];
				r -= w[t];
				t++;
			}
			else {
				t--;
				back = true;
			}
		}			
		//����������������Ը����������м�¼
		if (t == n && Solution(cw, c)) {
			//������������һ����
			result = true;
			//���ý��������Ž�,����и���
			if (cw[1] > bestW) {
				bestW = cw[1];
				CopyIntArray(bestX, X, n);
			}
		}
	}
	return result;
}


/*
װ������
Ŀ�����Ž⣺ʹ��1�ĳ������
*/
int main() {
	/*
	w����Ʒ��������
	n����Ʒ������
	c������������
	bestX����1��Ҫ��ŵ���Ʒ
	r��ʣ�༯װ������
	*/
	int w[N] = { 10,50,45,30,20,25,40,15,35,10 }, n, c[2] = { 150,150 }, bestX[N] = { 0 }, r = 0;
	cout << "��������Ʒ������(����0��Ĭ�Ϸ���)��" << endl;
	cin >> n;

	//�ж��Ƿ���Ĭ�Ϸ���
	if (n == 0) {
		n = 10;
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
		if (Backtrack(w, bestX, c, n, r)) {
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

