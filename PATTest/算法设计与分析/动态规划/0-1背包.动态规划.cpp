#include <iostream>
#include <queue>
using namespace std;

#define N 10
#define W 20

/**
v记录价值的数组
w记录重量的数组
c记录了背包的承重
n记录物品总数的整数
m记录最优解的二维数组
*/
void Knapsack(int* v, int* w, int c, int n, int m[N][W]) {

	//根据元素个数获取最后一个数的下表
	int index = n - 1, i = 0, j = 0, temp = 0;

	//求取当前能承重的最大重量，防止单个物品重量超过背包的最大容量
	int JMax = min(w[index], c);
	//给最后一列赋初始值
	for (; i < JMax; i++) {
		m[index][i] = 0;
	}
	for (i = JMax; i < c; i++) {
		m[index][i] = v[index];
	}

	//开始进行计算
	for (i = index - 1; i >= 0; i--) {
		//求取当前能承重的最大重量，防止单个物品重量超过背包的最大容量
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
m存储最大价值的二维数组
w存储重量的数组
c背包容量
n物品总数
x最优解数组
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
	int m[N][W] = { 0 };
	int n,c;
	cout << "请输入背包的容量：" << endl;
	cin >> c;
	cout << "请输入物品的个数：" << endl;
	cin >> n;
	
	cout << "请按顺序输入每个物品的重量：" << endl;
	Input(n, w);
	cout << "请按顺序输入每个物品的价值：" << endl;
	Input(n, v);
	Knapsack(v, w, c, n, m);
	cout << "能放物品的最大价值为:" << m[n - 1][c - 1] << endl;
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