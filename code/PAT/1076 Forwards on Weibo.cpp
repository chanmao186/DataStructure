#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node {
	int id;
	int lar;
	Node(int i,int l) {
		id = i; lar = l;
	}
};

int N, L, res, self;
vector<int> user[1005], r;
bool vist[1005] = { false };
int main() {
	int s, temp, i, j;
	scanf("%d %d", &N, &L);
	for (i = 1; i <= N; i++) {
		scanf("%d", &s);
		for (j = 0; j < s; j++) {
			scanf("%d", &temp);
			user[temp].push_back(i);
		}
	}
	scanf("%d", &s);
	Node node(0, 0);
	for (j = 0; j < s; j++) {
		scanf("%d", &self);
		fill(vist, vist + N + 1, false);
		res = -1;
		queue<Node> q;
		q.push(Node(self,0));
		while (!q.empty())
		{
			node = q.front();
			q.pop();
			if (vist[node.id]) {				
				continue;
			}			
			res++;
			vist[node.id] = true;
			if(node.lar < L)
			for (auto& x : user[node.id]) {
				if (!vist[x]) {
					q.push(Node(x, node.lar + 1));
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;
}