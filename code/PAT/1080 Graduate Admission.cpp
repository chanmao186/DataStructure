#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int app[40005][10];
int sc[105];
int scrank[105] = { 0 };
vector<int> adm[105];

int N, M, K;
struct Node {
	int fin, GE, id, rank;
};
vector<Node>nodes;
bool cmp(Node& n1, Node& n2) {
	if (n1.fin != n2.fin)return n1.fin > n2.fin;
	return n1.GE > n2.GE;

}
int main() {
	cin >> N >> M >> K;

	int i, j, rank, id, sid;
	for (i = 0; i < M; i++) {
		scanf("%d", &sc[i]);
	}

	for (i = 0; i < N; i++) {
		Node node;
		scanf("%d %d", &app[i][0], &app[i][1]);
		for (j = 0; j < K; j++) {
			scanf("%d", &app[i][j + 2]);
		}
		node.id = i;
		node.GE = app[i][0];
		node.fin = app[i][0] + app[i][1];
		nodes.push_back(node);
	}
	sort(nodes.begin(), nodes.end(), cmp);
	rank = 0;
	nodes[0].rank = rank;

	for (i = 1; i < nodes.size(); i++) {
		if (nodes[i].fin == nodes[i - 1].fin && nodes[i].GE == nodes[i - 1].GE) {
			nodes[i].rank = rank;
		}
		else {
			rank = i;
			nodes[i].rank = rank;
		}
	}
	Node node;
	for (i = 0; i < nodes.size(); i++) {
		node = nodes[i];
		id = node.id;
		if (id == 19) {
			int a= 1;
		}
		for (j = 0; j < K; j++) {
			sid = app[id][j + 2];
			if (adm[sid].size() < sc[sid]) {
				adm[sid].push_back(id);
				scrank[sid] = node.rank;
				break;
			}
			else if (scrank[sid] == node.rank) {
				adm[sid].push_back(id);
				break;
			}
		}
	}

	for (i = 0; i < M; i++) {
		if (adm[i].empty()) {
			printf("\n");
			continue;
		}
		sort(adm[i].begin(), adm[i].end());
		printf("%d", adm[i][0]);

		for (j = 1; j < adm[i].size(); j++) {
			printf(" %d", adm[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*
果然是我自己的错
这个代码不复杂，思考的问题
id和index不一致了
*/