#include <iostream>
#include <queue>
using namespace std;

#define N 10
#define W 20

typedef MNode* M;
struct MNode{
	int weight;
	int value;
	M Next;
};

/*
����һ��Ԫ��m
Weight ����
Value ��ֵ
*/
M CreateM(int Weight,  int Value) {
	M m = (M)malloc(sizeof(MNode));
	m->Weight = Weight;
	m->Value = Value;
	m->Next = NULL;
	return m;
}
/**
v��¼��ֵ������
w��¼����������
c��¼�˱����ĳ���
n��¼��Ʒ����������
m��¼���Ž�Ķ�ά����
*/
void Knapsack(int* v, int* w, int c, int n,M m[]) {

	//����Ԫ�ظ�����ȡ���һ�������±�
	int index = n - 1, i = index-1, j = 0, temp = 0;
	M cm,nm,tm;
	//��ȡ��ǰ�ܳ��ص������������ֹ������Ʒ���������������������
	if (w[index] <= c) {
		m[index]->Next = CreateM(w[index], v[index]);
	}
	for (; i >= 0; i--) {
		nm = m[i + 1]->Next;
		if (w[i] > c) {
			while (nm)
			{
				cm->Next = CreateM(nm->Weight, nm->Value);
				cm = cm->Next;
				nm = nm->Next;
			}
		}
		else {
			if (nm != NULL) {

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
void Traceback(int m[N][W], int* w, int c, int n, int* x) {
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
	int n, c;

	M m[N];
	for (int i=0; i < N; i++) {
		m[i]= CreateM(0,0);
	}

	cout << "�����뱳����������" << endl;
	cin >> c;
	cout << "��������Ʒ�ĸ�����" << endl;
	cin >> n;

	cout << "�밴˳������ÿ����Ʒ��������" << endl;
	Input(n, w);
	cout << "�밴˳������ÿ����Ʒ�ļ�ֵ��" << endl;
	Input(n, v);
	
	cout << "�ܷ���Ʒ������ֵΪ:" << m[0][c] << endl;
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