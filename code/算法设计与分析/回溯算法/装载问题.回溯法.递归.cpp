#include <iostream>
using namespace std;
#define N 10

/*
Besw：物品的最优重量
w：物品重量数组
n：物品的数量
c：两船的载重
bestX：船1钟要存放的物品
r：剩余集装箱重量
*/
int BestW = 0,
w[N] = { 10,50,45,30,20,25,40,15,35,10 },
n = N,
c[2] = { 150,150 },
bestX[N] = { 0 },
X[N] = { 0 },
r = 0;

/**
限界条件，判定条件为当前路径的最大值能超过最优解
*/
bool Bound(int cw) {
	return cw + r > BestW;
}

/*
约束条件，船1必须放的下剩余物品
*/
bool Constraint(int cw) {
	return cw <= c[0];
}

/**
回溯算法
当前运算物品的下标
船1的载重
*/
void  Backtrack(int cn, int cw) {
	//如果到达最后一层，则更新一下结果
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
	    //每向下一层,剩余物品的重力就减去当前运算物品的重量
		r -= w[cn];
		if (Constraint(cw) && Bound(cw)) {
			Backtrack(cn + 1, cw);
		}
		X[cn] = 1;
		cw -= w[cn];
		if (Constraint(cw) && Bound(cw)) {
			Backtrack(cn + 1, cw);
		}
		//恢复剩余重量重量
		r += w[cn];
	}
}
/*
装载问题
目标最优解：使船1的承重最大
*/
int main() {

	cout << "请输入物品的总量(输入0：默认方案)：" << endl;
	cin >> n;

	//判读是否用默认方案
	if (n == 0) {
		n = N;
		r = 280;
	}
	else {
		//输入重量
		cout << "请按顺序输入各物品的重量:" << endl;
		for (int i = 0; i < n; i++) {
			cin >> w[i];
			r += w[i];
		}
		//输入载重
		for (int i = 0; i < 2; i++) {
			cout << "请输入船" << i << "的载重:" << endl;
			cin >> c[i];
		}
	}

	//判读是否超重
	if (r <= c[0] + c[1]) {
		//判断是否有解决方案
		Backtrack(0, 0);
		if (BestW) {
			cout << "最优解决方案为: ";
			for (int i = 0; i < n; i++) {
				cout << bestX[i] << " ";
			}
		}
		else {
			cout << "错误2:二船无法装下物品清单里的物品" << endl;
		}
	}
	else {
		cout << "错误1:物品超重，二船无法装下" << endl;
	}
	return 0;
}