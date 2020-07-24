#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, K, M;
int user[10005][6];
int p[6];
struct Node
{
	int id, prefact, sum;
	void output() {
		printf(" %05d %d", id, sum);
		for (int i = 1; i <= K; i++) {
			if (user[id][i] == -2) {
				printf(" -");
			}
			else if (user[id][i] == -1) {
				printf(" 0");
			}
			else {
				printf(" %d", user[id][i]);
			}
		}
		printf("\n");
	}
};

bool cmp(Node& n1, Node& n2) {
	if (n1.sum == n2.sum) {
		if (n1.prefact == n2.prefact) {
			return n1.id < n2.id;
		}
		else
		{
			return n1.prefact > n2.prefact;
		}
	}
	else {
		return n1.sum > n2.sum;
	}
}

vector<Node>nodes;


int main() {
	int i, j, id, pi, sore, rank, flag;
	fill(user[0], user[0] + 10005 * 6, -2);
	cin >> N >> K >> M;
	for (i = 1; i <= K; i++) {
		cin >> p[i];
	}

	for (i = 0; i < M; i++) {
		cin >> id >> pi >> sore;
		if (sore > user[id][pi])
			user[id][pi] = sore;
	}
	Node node;
	for (i = 1; i <= N; i++) {
		node.id = i;
		node.prefact = 0;
		node.sum = 0;
		flag = 0;
		for (j = 1; j <= K; j++) {
			if (user[i][j] <= -1) {
				continue;
			}
			flag++;
			node.sum += user[i][j];
			if (user[i][j] == p[j]) {
				node.prefact++;
			}
		}
		if (flag > 0) {
			nodes.push_back(node);
		}
	}

	sort(nodes.begin(), nodes.end(), cmp);
	rank = 1;
	sore = nodes[0].sum;
	printf("1");
	nodes[0].output();
	for (i = 1; i < nodes.size(); i++) {
		if (nodes[i].sum < sore) {
			sore = nodes[i].sum;
			rank = i + 1;
		}

		printf("%d", rank);
		nodes[i].output();
	}
	return 0;
}