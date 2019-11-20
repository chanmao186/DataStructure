#include<iostream>
using namespace std;
#define N 10

/**
<<<<<<< HEAD
弃用
//声明整形堆栈
class stack {
public:
stack() {
n = 0;
}
int Pop() {
if (Empty)
return data[--n];
else {
//队列已空
cout << "队列已空" << endl;
return 0;
}
}
void Push(int num) {
if (n == N) {
cout << "队列已满" << endl;
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
是否满足限界条件,满足为true,不满足为fakse
cn:当前运算物品下标
n:物品总数
*/
bool Bound(int cn, int n) {
	return cn > n;
}

/**
是否满足约束条件，满足返回true,不满足返回false
限界条件:两船都可以装下明确要装的物品的重量
t:当前正在计算的节点的下标
n：物品总数
cw[0]:明确分配给船0的物品重量
cw[1]:明确分配给船1的物品重量
c[0]:船0的限重
c[1]:船1的限重
*/
bool Constraint(int cw[2], int c[2],int t,int n) {
	return t<n&&cw[0] <=c[0] && cw[1] <= c[1];
}

/**
是否满足该问题的解决条件，满足返回true,不满足返回false
条件：船1可以负担的起剩余物品的重量
r:要装在船0的物品重力
c:船0的限重
*/
bool Solution(int cw[2],int c[1]) {
	return cw[0]<=c[0]&&cw[1]<=c[1];
}

/**
非递归的回溯算法
w:物品的重量列表
bestX:最优解
c:船0和船1的承重
n:物品的数量
r:物品的总重
*/
bool Backtrack(int w[N], int bestX[N], int c[2], int n, int r) {
	/**
	result:代表最后是否有解
	若出现w[2]={150,40},c[2]={100,100}的情况，
	两船可以装下物品的总重却无法装下150那个物品，
	这种情况则是无解;
	back:是否进行回溯的标识符
	true进行回溯
	false进行深度优先遍历
	*/
	bool result = false,back = false;

	/**
	X:z最优解决方案
	0放在船0
	1防止船1
	beseW:最优解，此处代表船1的最大承重
	cw[0]:明确放在船0的物品的承重
	cw[1]:明确放在船1的物品的承重
	t:当前正在计算的物品编号
	*/
	int X[N] = { 0}, bestW = 0, cw[2] = { 0 },t=1;

	//出生化第一物品的状态，放在船0
	X[0] = 1;
	cw[1] += w[0];
	r-=w[0];
	while (t) {
		if (back) {
			cw[X[t]] -= w[t];
			r+=w[t];
			if (X[t]) {
				//换个分支继续执行深度遍历
				back = false;
				X[t] = 0;
				cw[0] += w[t];	
				r-=w[t];
				t++;
			}
			else {
				t--;
			}				
		}
		else {

			//若满足约束条件和限界条件，则进行深度遍历
			if (Constraint(cw, c,t,n) &&Bound(cw[1]+r,bestW)) {
				X[t] = 1;
				cw[1] += w[t];
				r-=w[t];
				t++;
				//若满足解决条件，则对该问题结果进行记录
				if (t==n&&Solution(cw,c)) {
					//该问题有至少一个解
					result = true;
					//若该接优于最优解,则进行更新
					//最优解的判断，使船1的承重近可能的大
					if (cw[1] > bestW) {
						//更新最大重量
						bestW = cw[1];
						for (int i = 0; i < n; i++) {
							bestX[i] = X[i];
						}
					}
				}

			}
			else {
				t--;
				back = true;
			}
		}	
	}
	return result;
}


/*
装载问题
目标最优解：使船1的承重最大
*/
int main() {
	/*
	w：物品重量数组
	n：物品的数量
	c：两船的载重
	bestX：船1钟要存放的物品
	r：剩余集装箱重量
	*/
	int w[N] = { 10,50,45,30,20,25,40,15,35,10 }, n, c[2] = { 150,150 }, bestX[N] = { 0 }, r = 0;
	cout << "请输入物品的总量(输入0：默认方案)：" << endl;
	cin >> n;

	//判读是否用默认方案
	if (n == 0) {
		n = 10;
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
	if (r < c[0] + c[1]) {
		//判断是否有解决方案
		if (Backtrack(w, bestX, c, n, r)) {
			cout << "最优解决方案为: " ;
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
