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
	M cm, nm, tm, _tm, _tm1;
	_tm = NULL;
	tm = CreateM(0, 0);
	//求取当前能承重的最大重量，防止单个物品重量超过背包的最大容量
	if (w[index] <= c) {
		m[index]->Next = CreateM(w[index], v[index]);
	}
	for (i = index - 1; i >= 0; i--) {
		tm->Next = NULL;
		//构造出一个临时的tm链表，tm为头部
		_tm = tm;
		nm = m[i + 1];
		weight = w[i] + nm->Weight;
		while (weight <= c&&nm) {
			value = v[i] + nm->Value;
			_tm->Next = CreateM(weight, value);
			nm = nm->Next;
			//当后一位链表的底部时跳出循环
			if (!nm)break;
			weight = w[i] + nm->Weight;
			_tm = _tm->Next;
		}
		//进行链表合并
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
					//释放无效的内存
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
m存储最大价值的二维数组
w存储重量的数组
c背包容量
n物品总数
x最优解数组
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
				//若找到在下一组跟本组质量一致则说明没有选该物品
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
	cout << "请输入背包的容量:" << endl;
	//cout<<"请输入背包的容量："<<endl;
	cin >> c;
	cout << "请输入物品的个数:" << endl;
	//cout << "请输入物品的个数：" << endl;
	cin >> n;

	cout << "请按顺序输入每个物品的重量：" << endl;
	Input(n, w);
	cout << "请按顺序输入每个物品的价值：" << endl;
	Input(n, v);
	Knapsack(v, w, c, n, m);
	Traceback(m, w, v, n, x);
	temp = m[0];
	while (temp->Next) {
		temp = temp->Next;
	}
	cout << "能放物品的最大价值为:" << temp->Value << endl;
	cout << "放入的方案为:" << endl;
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	return 0;
}

/*测试数据
2 2 6 5 4
6 3 5 4 6
*/
