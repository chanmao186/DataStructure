#include <iostream>
#include <queue>
using namespace std;

#define N 10
#define W 20

/**
v��¼��ֵ������
w��¼����������
c��¼�˱����ĳ���
n��¼��Ʒ����������
m��¼���Ž�Ķ�ά����
*/
void Knapsack(int* v, int* w, int c, int n, int m[N][W]) {

	//����Ԫ�ظ�����ȡ���һ�������±�
	int index = n - 1, i = 0, j = 0, temp = 0;

	//��ȡ��ǰ�ܳ��ص������������ֹ������Ʒ���������������������
	int JMax = min(w[index], c);
	//�����һ�и���ʼֵ
	for (; i < JMax; i++) {
		m[index][i] = 0;
	}
	for (i = JMax; i < c; i++) {
		m[index][i] = v[index];
	}

	//��ʼ���м���
	for (i = index - 1; i >= 0; i--) {
		//��ȡ��ǰ�ܳ��ص������������ֹ������Ʒ���������������������
		int JMax = min(w[index], c);
		for (j = 0; j < JMax; j++) {
			m[i][j] = m[i + 1][j];
		}
		for (j = JMax; j < c; j++) {
			temp = v[i] + m[i + 1][j - w[i]];
			if (m[i][j] > temp) {
				m[i][j] = temp;
			}
		}
	}
}


/*
m�洢����ֵ�Ķ�ά����
w�洢����������
c��������
n��Ʒ����
x���Ž�����
*/
void Traceback(int m[N][W],int *w,int c,int n,int *x) {
	int index = n - 1;
	for (int i = 0; i < index; i++) {
		if (m[i][c] == m[i + 1][c]) {
			x[i] = 0;
		}
		else {
			x[i] = 1;
			c -= w[i];
		}
	}
	//�����һλ��ֵ
	x[index] = (m[index][c]) ? 1 : 0;
}
void Input(int n, int* array) {
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
}

int main() {
	int x[N] = { 0 };
	int w[W] = { 0 };
	int v[N] = { 0 };
	int m[N][W] = { 0 };
	int n,c;
	cout << "�����뱳����������" << endl;
	cin >> c;
	cout << "��������Ʒ�ĸ�����" << endl;
	cin >> n;
	
	cout << "�밴˳������ÿ����Ʒ��������" << endl;
	Input(n, w);
	cout << "�밴˳������ÿ����Ʒ�ļ�ֵ��" << endl;
	Input(n, v);
	Knapsack(v, w, c, n, m);
	cout << "�ܷ���Ʒ������ֵΪ:" << m[n - 1][c - 1] << endl;
	cout << "����ķ���Ϊ:" << endl;
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	return 0;
}

/*��������
6 2 4 3 5
3 4 7 5 7
*/