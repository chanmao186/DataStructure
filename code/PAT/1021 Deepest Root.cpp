#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
#define Max 10010
int n;
vector<int> CurentResult;
set<int> Result;
vector<vector<int>> G(Max);//ͼ
bool vist[Max] = { false };

int Maxdeep;
void DFS(int index, int deep) {
	vist[index] = true;
	if (deep > Maxdeep) {
		Maxdeep = deep;
		CurentResult.clear();
		CurentResult.push_back(index);
	}
	else if (deep == Maxdeep) {
		CurentResult.push_back(index);
	}
	int next = deep + 1;
	for (auto e:G[index]) {
		if (!vist[e]) {
			DFS(e, next);
		}
	}
}

int main() {
	cin >> n;
	int i;
	int n1, n2;
	for (i = 1; i < n; i++) {
		cin >> n1 >> n2;
		G[n1].push_back(n2);
		G[n2].push_back(n1);
	}
	int cnt = 0;
	Maxdeep = 0;
	for (i = 1; i <= n; i++) {
		if (!vist[i]) {
			cnt++;
			DFS(i, 0);
		}
	}

	if (cnt > 1) {
		printf("Error: %d components", cnt);
	}
	else {
		Maxdeep = 0;
		for (auto e : CurentResult) {
			Result.insert(e);
		}
		int s = *Result.begin();
		CurentResult.clear();
		fill(vist,vist+Max,false);

		DFS(s, 0);
		for (auto e : CurentResult) {
			Result.insert(e);
		}
		for (auto e : Result) {
			cout << e << endl;
		}
	}
	return 0;
}