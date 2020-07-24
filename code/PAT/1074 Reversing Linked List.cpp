#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
	int add, val, next;
};
Node Nodes[100005];
vector<Node>nodes;

int main() {
	int Head,N,K,temp,next;
	cin >> Head >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		cin >> Nodes[temp].val >> Nodes[temp].next;
		Nodes[temp].add = temp;
	}
	next = Head;
	while (next!=-1)
	{
		nodes.push_back(Nodes[next]);
		next = Nodes[next].next;
	}
	if (K > 1) {
		for (int i = 0; i + K <= nodes.size(); i += K) {
			reverse(nodes.begin() + i, nodes.begin() + i + K);
		}
	}
	
	N = nodes.size() - 1;
	for (int i = 0; i < N; i++) {
		printf("%05d %d %05d\n", nodes[i].add, nodes[i].val, nodes[i + 1].add);
	}

	printf("%05d %d -1", nodes[N].add, nodes[N].val);

	return 0;
}