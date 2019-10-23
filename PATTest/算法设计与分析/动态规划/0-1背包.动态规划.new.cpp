#include <iostream>
#include <queue>
using namespace std;

#define N 10
#define W 20

typedef MNode* M;
struct MNode {
	int weight;
	int value;
	M Next;
};

/*
创建一个元素m
Weight 重量
Value 价值
*/
M CreateM(int Weight, int Value) {
	M m = (M)malloc(sizeof(MNode));
	m->Weight = Weight;
	m->Value = Value;
	m->Next = NULL;
	return m;
}
/**
v记录价值的数组
w记录重量的数组
c记录了背包的承重
n记录物品总数的整数
m记录最优解的二维数组
*/
void Knapsack(int* v, int* w, int c, int n, M m[]) {

	//根据元素个数获取最后一个数的下表
	int index = n - 1, i = index - 1, j = 0, temp = 0, value, weight;
	M cm, nm, tm, _tm,_tm1;
	tm = CreateM(0, 0);
	//求取当前能承重的最大重量，防止单个物品重量超过背包的最大容量
	if (w[index] <= c) {
		m[index]->Next = CreateM(w[index], v[index]);
	}
	for (i = index - 1; i >= 0; i--) {
		//构造出一个临时的tm链表，tm为头部
		tm->Next = _tm;
		nm = m[i + 1];
		weight = w[i] + nm->Weight;
		while (weight <= c) {
			value = v[i] + nm->Value;
			_tm->Next = CreateM(weight, value);
			nm = nm->Next;
			//当后一位链表的底部时跳出循环
			if (!nm)break;
			weight = w[i] + nm->Weight;
			_tm->_tm->Next;
		}
		//进行链表合并
		_tm = tm->Next;
		nm = nm->Next;
		cm = m[i];
		while (_tm && nm) {
			if (_tm->Weight < nm->Weight) {
				if (_tm->Value >= nm->Value) {
					cm->Next = _tm;
					cm = _tm;
					_tm = _tm->Next;
					cm->Next = NULL;
				}
				else {
					//释放无效的内存
					_tm1 = _tm;
					_tm = _tm->Next;
					free(_tm1);
				}				
			}
			else if (_tm->Weight > nm->Weight) {
				cm->Next = CreateM(nm->Weight, nm->Value);
				cm = cm->Next;
				nm = nm->Next;
			}
		}
	}
}


/*
m存储最大价值的二维数组
w存储重量的数组
c背包容量
n物品总数
x最优解数组
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
	//求最后一位的值
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
	for (int i = 0; i < N; i++) {
		m[i] = CreateM(0, 0);
	}

	cout << "请输入背包的容量：" << endl;
	cin >> c;
	cout << "请输入物品的个数：" << endl;
	cin >> n;

	cout << "请按顺序输入每个物品的重量：" << endl;
	Input(n, w);
	cout << "请按顺序输入每个物品的价值：" << endl;
	Input(n, v);

	cout << "能放物品的最大价值为:" << m[0][c] << endl;
	cout << "放入的方案为:" << endl;
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	return 0;
}

/*测试数据
6 2 4 3 5
3 4 7 5 7
*/
