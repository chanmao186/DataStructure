#include <iostream>
using namespace std;
#define N 10
#define MAX 10000
//int city[N];
int G[N][N] = {
		{0,30,6,4},
		{30,0,5,10},
		{6,5,0,20},
		{4,10,20,0}
};
int n;
//0代表未去此城市 ，1代表已去此城市
int CityFlag[N] = { 0 };
int BestCost = MAX;
int BestX[N];
int CX[N] = { 0 };

bool Bound(int cc) {
	return cc < BestCost;
}

bool Constraint(int c) {
	return c < MAX&& c;
}

/**
t代表要去第几个城市城市
*/
void Backtrack(int t, int cc) {
	if (Bound(cc)) {
		if (t == n-1) {
			if (Constraint(G[CX[t]][0])) {
				cc += G[CX[t]][0];
				if (Bound(cc)) {
					BestCost = cc;
					for (int i = 1; i < n; i++) {
						BestX[i] = CX[i];
					}
				}
				//cc -= G[t][0];
			}
		}
		else {
			for (int i = 1; i < n; i++) {
				if (CityFlag[i] == 0) {
					if (Constraint(G[CX[t]][i])) {
						CityFlag[i] = 1;
						cc += G[CX[t]][i];
						CX[t + 1] = i;
						Backtrack(t + 1, cc);
						CityFlag[i] = 0;
						cc -= G[CX[t]][i];
					}
				}
			}
		}
	}
}
int main(void) {
	n = 4;
	Backtrack(0, 0);
	if (BestCost == MAX) {
		cout << "无回路";
	}
	else {
		cout << "最小花费为:" << BestCost << endl;
		cout << "方案路径为:" << endl;
		cout << BestX[0];
		for (int i = 1; i < n+1; i++) {
			cout << " -> " << BestX[i];
		}
		cout<<endl;
	}
	return 0;
}
