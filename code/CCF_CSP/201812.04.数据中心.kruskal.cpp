#include <iostream>
#include <vector> 
#include <algorithm>
#include <stack>
using namespace std;
#define N 50005
int par[N] = { 0 };
int dn = 1;
int n, m, root;
struct MLink {
	int ID1, ID2;
	//权重 
	int Weight;
	MLink(int id1, int id2, int weight) :ID1(id1), ID2(id2), Weight(weight) {
		root = 0;
	}
	bool operator<(const MLink other)const {
		return Weight < other.Weight;
	}
};

int find(int i) {
	while (i != par[i]) {
		i = par[i];
	}
	return i;
}
void Union(int x, int y) {
	par[x] = y;
}

int main() {
	int x, y, v, temp, ans = 0;
	cin >> n >> m >> root;

	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	vector<MLink> node;
	while (m--) {
		cin >> x >> y >> v;
		node.push_back(MLink(x, y, v));
	}
	sort(node.begin(), node.end());
	int _dn = dn;
	for (auto& e : node) {
		x = find(e.ID1);
		y = find(e.ID2);
		if (x != y) {
			Union(x, y);
			dn++;
			ans = e.Weight;
			if (dn == n) {
				break;
			}
		}
	}
	cout << ans;
	return 0;
}

/*
该代码运行超时只有70分
4
5
1
1 2 3
1 3 4
1 4 5
2 3 8
3 4 2
*/