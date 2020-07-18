#include<iostream>
#include<algorithm>
using namespace std;

int G[205][205] = { {0} };
bool vist[205] = { false };
int main() {
	int N, M, K, c1, c2, dis, n, v, start, si = 0, sdis = 0x7fffffff;
	int haveCyecle = 0;
	bool isNa;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &c1, &c2, &dis);
		G[c1][c2] = G[c2][c1] = dis;
	}
	scanf("%d", &K);
	for (int i = 1, j; i <= K; i++) {
		scanf("%d", &n);
		v = 1;
		haveCyecle = false;
		dis = 0;
		fill(vist, vist + 205 * sizeof(bool), false);
		scanf("%d", &c1);
		vist[c1] = true;
		start = c1;
		isNa = false;
		for (j = 1; j < n; j++) {
			scanf("%d", &c2);
			if (isNa)continue;
			if (G[c1][c2] == 0) {
				isNa = true;
				continue;
			}
			dis += G[c1][c2];
			if (vist[c2]) {
				haveCyecle++;
			}
			else {
				v++;
			}

			vist[c2] = true;
			c1 = c2;
		}
		if (isNa) {
			printf("Path %d: NA (Not a TS cycle)\n", i);
			continue;
		}
		printf("Path %d: %d ", i, dis);
		if (v == N && c2 == start) {
			if (haveCyecle > 1) {
				printf("(TS cycle)\n");
			}
			else {
				printf("(TS simple cycle)\n");
			}

			if (dis < sdis) {
				sdis = dis; si = i;
			}
		}
		else {
			printf("(Not a TS cycle)\n");
		}
	}

	printf("Shortest Dist(%d) = %d", si, sdis);
	return 0;
}