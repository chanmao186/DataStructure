#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
	double w;
	double v;
	double d;
	void op() {
		if (w == 0) {
			d = 0.00001;
		}
		else {
			d = v / w;
		}		
	}
};

vector<Node> nodes;

bool cmp(Node& n1, Node& n2) {
	return n1.d > n2.d;
}

int main() {
	int N, D, w,temp=0;
	double v=1.00,p=0;
	cin >> N >> D;
	nodes.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> nodes[i].w;
	}

	for (int i = 0; i < N; i++) {
		cin >> nodes[i].v;
		nodes[i].op();
	}

	sort(nodes.begin(), nodes.end(), cmp);

	for (auto& node : nodes) {
		if (temp + node.w <= D) {
			temp += node.w;
			p += node.v;
		}
		else {
			p += (D - temp) * node.d;
			break;
		}
	}
	printf("%.2f", p);
	return 0;
}
