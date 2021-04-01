#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
	int t, w;
};

bool cmp(Node& n1, Node& n2) {
	if (n1.t == n2.t) {
		return n1.w > n2.w;
	}
	return n1.t < n2.t;
}
int main() {
	int t, n, res, cur;
	cin >> t;
	while (t--) {
		cin >> n;
		res = 0;
		vector<Node> nodes(n);
		for (int i = 0; i < n; ++i) {
			cin >> nodes[i].t;
		}
		for (int i = 0; i < n; ++i) {
			cin >> nodes[i].w;
		}
		sort(nodes.begin(), nodes.end(),cmp);
		cur = 0;
		for (auto& node : nodes) {
			if (cur != node.t) {
				cur = node.t;
				res += node.w;
			}
			else {
				res -= node.w;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}