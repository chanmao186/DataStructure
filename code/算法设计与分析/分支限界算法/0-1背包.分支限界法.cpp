#include<iostream>
//工程文件里引用的头文件，可以按需求自行更改
#include"../公用数据结构/Heap.h"
#include <algorithm>
#include <vector>
using namespace std;
#define N 100
void AddLiveNode(int up, int cp, int cw, int ch, int lev);

//物品的结构体
struct Item {
	int ID;//ID编号，即物品的下标，因为之后要进行排序，所以要靠下标记录
	int Weight;//重量
	int Value;//价值
	float d;//单位价值
	Item() {};
	Item(int id, int weight, int value) :ID(id), Weight(weight), Value(value) {
		d = Value / (Weight * 1.0);
	}
	//重载预算符，之后排序使用，因为是升序，所以返回的是大于号
	bool operator <(const Item& other)const {
		return d > other.d;
	}
};

//储存选择的信息
struct bbNode {
	bbNode* parent;
	int flag;
	bbNode(bbNode* p, int f) :parent(p), flag(f) {}
};

/*
堆中的节点，按可能获得最大值进行排序
*/
struct HeapNode {

	bool operator <(const HeapNode& h) const {
		return uprofit < h.uprofit;
	}
	HeapNode() {};
	void operator = (int Num) {
		uprofit = Num;
	}
	int uprofit;//可能达到的最大价值
	int profit;//当前价值
	int Weight;//当前重量
	int Level;//当前计算的层次
	bbNode* ptr;//物品选择信息的指针
	HeapNode(int up, int cp, int w, int lev, bbNode* b) :
		uprofit(up), profit(cp), Weight(w), Level(lev), ptr(b) {}
};


int BestX[N] = { 0 };//最优解数组
/*
cw:当前重量
cp:当前价值
n:物品总数
c:背包容量
up：该路径可能达到的最大值
besp：最优花费
*/
int cw, cp, n, c, up, bestp;
/*
物品数组
*/
Item items[N];
//用来记录弹出的节点
HeapNode HN;
//选择信息的根节点
bbNode* E = NULL;
//选择信息的最优节点
bbNode* BestE = NULL;
//声明大顶堆
MaxHeap<HeapNode> H(1000);

/**
限界函数，即用贪心算法求背包的最有解
*/
int Bound(int i) {
	int cleft = c - cw,
		b = cp;
	for (; i < n && cleft>items[i].Weight; i++) {
		cleft -= items[i].Weight;
		b += items[i].Value;
	}
	//若还有剩余物品，则将剩余物品的部分装进背包
	if (i <= n) {
		b += items[i].d * cleft;
	}
	return b;
}
int main() {
	
	//初始化
	cw = cp = up = bestp = 0;
	//输入数据
	cout << "请输入背包的承重：" << endl;
	cin >> c;
	cout << "请输入物品的数量：" << endl;
	cin >> n;
	cout << "请按顺序输入物品的重量和价值：" << endl;
	int w, v, i,lev;

	for (i = 0; i < n; i++) {
		cin >> w >> v;
		items[i] = Item(i, w, v);
	}
	//按照物品的价值进行排序
	sort(items, items + n);

	//求0层可以达到的最大值
	up = Bound(0);
	i = 0;
	while (i < n)
	{
		//先算选择该物品的价值
		w = cw + items[i].Weight;
		if (w < c) {
			v = cp + items[i].Value;
			if (v > bestp) {
				bestp = v;
			}
			//将该节点加入活节点
			AddLiveNode(up, v, w, 1, i + 1);
		}
		up = Bound(i + 1);
		//不满足的条件进行剪枝
		if (up > bestp) {
			AddLiveNode(up, cp, cw, 0, i + 1);
		}
		if (H.IsEmputy()) {
			break;
		}
		HN = H.Delete();
		E = HN.ptr;
		cw = HN.Weight;
		up = HN.uprofit;
		cp = HN.profit;
		i = HN.Level;
		//记录计算的层数及最有解
		if (cp == bestp) {
			BestE = E;
			lev = i;
		}
		
	}
	i = lev;
    while (i--&& BestE)
	{
		BestX[items[i].ID] = BestE->flag;
		BestE = BestE->parent;
	}
	cout << "最大价值为" << bestp << endl;
	for (i = 0; i < n; i++) {
		cout << BestX[i] << " ";
	}
	return 0;
}
void AddLiveNode(int up, int cp, int cw, int flag, int lev) {
	bbNode* b = new bbNode(E, flag);
	HeapNode n(up, cp, cw, lev, b);
	H.Insert(n);
}

/*
测试数据
10
5
2 6
2 3
6 5
5 4
4 6
*/