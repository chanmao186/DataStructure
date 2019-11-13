#include <iostream>
#include <queue>
using namespace std;

#define N 10
#define W 20

typedef struct MNode* M;
struct MNode {
	int Weight;
	int Value;
	M Next;
};

/*
����һ��Ԫ��m
Weight ����
Value ��ֵ
*/
M CreateM(int Weight, int Value) {
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
void Knapsack(int* v, int* w, int c, int n, M m[]) {

	//����Ԫ�ظ�����ȡ���һ�������±�
	int index = n - 1, i = index - 1, j = 0, temp = 0, value, weight;
	M cm, nm, tm, _tm, _tm1;
	_tm = NULL;
	tm = CreateM(0, 0);
	//��ȡ��ǰ�ܳ��ص������������ֹ������Ʒ���������������������
	if (w[index] <= c) {
		m[index]->Next = CreateM(w[index], v[index]);
	}
	for (i = index - 1; i >= 0; i--) {
		tm->Next = NULL;
		//�����һ����ʱ��tm����tmΪͷ��
		_tm = tm;
		nm = m[i + 1];
		weight = w[i] + nm->Weight;
		while (weight <= c&&nm) {
			value = v[i] + nm->Value;
			_tm->Next = CreateM(weight, value);
			nm = nm->Next;
			//����һλ����ĵײ�ʱ����ѭ��
			if (!nm)break;
			weight = w[i] + nm->Weight;
			_tm = _tm->Next;
		}
		//��������ϲ�
		_tm = tm->Next;
		nm = m[i+1]->Next;
		cm = m[i];
		while (_tm && nm) {
			if (_tm->Weight <= nm->Weight) {
				if (_tm->Value > cm->Value) {
					cm->Next = _tm;
					cm = _tm;
					_tm = _tm->Next;
					cm->Next = NULL;
				}
				else {
					//�ͷ���Ч���ڴ�
					_tm1 = _tm;
					_tm = _tm->Next;
					free(_tm1);
				}
			}
			else {
				if (nm->Value > cm->Value) {
					cm->Next = CreateM(nm->Weight, nm->Value);
					cm = cm->Next;
				}
				nm = nm->Next;
			}
		}
		while (_tm) {
			if (_tm->Value > cm->Value) {
				cm->Next = _tm;
				cm = _tm;
				_tm = _tm->Next;
				cm->Next = NULL;
			}
			else {
				_tm1 = _tm;
				_tm = _tm->Next;
				free(_tm1);
			}

		}
		while (nm) {
			if (nm->Value > cm->Value) {
				cm->Next = CreateM(nm->Weight, nm->Value);
				cm = cm->Next;
			}
			nm = nm->Next;
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
void Traceback(M m[], int w[], int v[], int n, bool x[]) {
	M cm, tm;
	int value, weight, i = 0;
	cm = m[i];
	if (!cm->Next)return;
	while (cm->Next)
	{
		cm = cm->Next;
	}
	value = cm->Value;
	weight = cm->Weight;
	for (; i < n - 1; i++) {
		tm = m[i + 1];
		while (tm->Next)
		{
			if (tm->Weight >= weight) {
				//���ҵ�����һ�����������һ����˵��û��ѡ����Ʒ
				x[i] = !(tm->Weight == weight && tm->Value == value);
				break;
			}
			tm = tm->Next;
		}
		if (x[i]) {
			weight -= w[i];
			value -= v[i];
		}
	}
	x[n - 1] = weight != 0;
}
void Input(int n, int* array) {
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
}

int main() {
	bool x[N] = { 0 };
	int w[W] = { 0 };
	int v[N] = { 0 };
	int n, c;

	M m[N], temp;
	for (int i = 0; i < N; i++) {
		m[i] = CreateM(0, 0);
	}
	cout << "�����뱳��������:" << endl;
	//cout<<"�����뱳����������"<<endl;
	cin >> c;
	cout << "��������Ʒ�ĸ���:" << endl;
	//cout << "��������Ʒ�ĸ�����" << endl;
	cin >> n;

	cout << "�밴˳������ÿ����Ʒ��������" << endl;
	Input(n, w);
	cout << "�밴˳������ÿ����Ʒ�ļ�ֵ��" << endl;
	Input(n, v);
	Knapsack(v, w, c, n, m);
	Traceback(m, w, v, n, x);
	temp = m[0];
	while (temp->Next) {
		temp = temp->Next;
	}
	cout << "�ܷ���Ʒ������ֵΪ:" << temp->Value << endl;
	cout << "����ķ���Ϊ:" << endl;
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	return 0;
}

/*��������
2 2 6 5 4
6 3 5 4 6
*/
