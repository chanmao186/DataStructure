#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 505
const int Max = 0x7fffffff;
int G[N][N] = { 0 };
int mens[N] = { 0 };//各个城市救援人员的数量


struct Node {
	int mens = 0;
	int weight = 0;
	bool flag = false;
};
Node dist[N] = { 0 };//开始节点到各个点的权重
int main() {
	int n, m, c1, c2;

	cin >> n >> m >> c1 >> c2;
	int i = 0, x, y, w;
	for (i = 0; i < n; i++) {
		for (x = 0; x < n; x++) {
			G[i][x] = Max;
		}
	}
	for (i = 0; i < n; i++) {
		cin >> mens[i];
		dist[i].mens = mens[i];
	}
	for (i = 0; i < m; i++) {
		cin >> x >> y >> w;
		G[x][y] = G[y][x] = w;
	}
	for (i = 0; i < n; i++) {
		dist[i].weight = G[c1][i];
	}
	dist[c1].flag = true;
	int cc = c1, nc = 0; //cc当前节点，nc下一个要去的节点
	int weight, men;
	for (w = 1; w < n; w++) {
		x = Max;
		y = 0;
		//寻找一个最小的节点
		for (i = 0; i < n; i++) {
			if (!dist[i].flag && x >= G[cc][i]) {
				if (x > G[cc][1]) {
					x = G[cc][i];
					nc = i;
					y = dist[i].mens;
				}
				else {
					if (dist[i].mens > y) {
						x = G[cc][i];
						nc = i;
						y = dist[i].mens;
					}
				}

			}
		}
		dist[nc].flag = true;
		if (nc == c2)break;
		for (i = 0; i < n; i++) {
			if ((G[nc][i] != Max) && (!dist[i].flag)) {
				weight = G[nc][i] + dist[nc].weight;
				men = mens[i] + dist[nc].mens;
				if (dist[i].weight < weight || (dist[i].weight == weight || men > dist[i].mens)) {
					dist[i].weight = weight;
					dist[i].mens = men;
				}				
			}
		}
		cc = nc;
	}
	cout << dist[c2].weight << " " << dist[c2].mens + mens[c2];
	return 0;
}

/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/