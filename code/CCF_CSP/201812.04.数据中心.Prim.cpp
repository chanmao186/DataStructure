#include <iostream>
#include <vector> 
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
#define N 50005
bool flag[N] = { false };
int dn = 0;
int n, m, root;
struct MLink {
	int ID;
	int LinkNode;
	//权重 
	int Weight;
	MLink(int linknode, int weight,int id) :LinkNode(linknode), Weight(weight),ID(id) {
	}
	bool operator<(const MLink other)const {
		if (Weight == other.Weight) {
			return ID < other.ID;
		}
		return Weight < other.Weight;
	}
};
set<MLink> s;
vector<vector<MLink>> nodes(N);
void ActiveNode(int i) {
	if (!flag[i]) {
		flag[i] = true;
		dn++;
	}
}

void Merge(int i) {
	for (auto e : nodes[i]) {
		if (!flag[e.LinkNode]) {
			s.insert(e);
		}
	}
}
int main() {
	int x, y, v, temp, ans = 0;
	cin >> n >> m >> root;
	while (m--) {
		cin >> x >> y >> v;
		nodes[x].push_back(MLink(y, v,ans++));
		nodes[y].push_back(MLink(x, v,ans++));
	}
	ActiveNode(root);
	Merge(root);
	ans = 0;
	for (set<MLink>::iterator sn = s.begin(); sn != s.end(); sn = s.begin()) {

		MLink  m = *sn;
		x = m.LinkNode;
		if (!flag[x]) {
			if (ans < m.Weight)
				ans = m.Weight;
			ActiveNode(x);
			Merge(x);
			if (dn == n) {
				break;
			}
		}
		else {
			s.erase(sn);
		}
	}
	cout << ans;
	return 0;
}

/*
prim算法，该算法在该题优于kruskal,得分满分
4
5
1
1 2 3
1 3 4
1 4 5
2 3 8
3 4 2
*/