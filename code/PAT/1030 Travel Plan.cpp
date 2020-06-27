#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define MAX 505
int inf = 100000000;
int N, M, S, D;
int G[MAX][MAX], C[MAX][MAX], d[MAX];
bool flag[MAX] = { false };
vector<int> pre[MAX];
vector<int> path;
vector<int> result;
int MinCost = inf;
void Djs(int s) {

	int i;
	for (i = 0; i < N; i++) {
		d[i] = G[s][i];
	}
	d[s] = 0;
	int index, min;
	while (true)
	{
		index = -1; min = inf;
		for (i = 0; i < N; i++) {
			if (!flag[i] && d[i] < min) {
				index = i;
				min = d[i];
			}
		}
		if (index == -1)return;
		flag[index] = true;
		for (i = 0; i < N; i++) {
			if (!flag[i]) {
				if (min + G[index][i] < d[i]) {
					d[i] = min + G[index][i];
					pre[i].clear();
					pre[i].push_back(index);
				}
				else if (min + G[index][i] == d[i]) {
					pre[i].push_back(index);
				}
			}

		}
	}
}

void DFS(int v) {
	path.push_back(v);
	if (v == S) {
		int tCost = 0, td;
	    
		td = path[0];
		for (int i = 1; i < path.size(); i++) {
			tCost += C[td][path[i]];
			td = path[i];
		}

		if ( tCost < MinCost) {
			MinCost = tCost;
			result = path;
		}
		path.pop_back();
		return;
	}
	for (auto s : pre[v]) {		//path.push_back(s);
		DFS(s);	
	}
	path.pop_back();
}
int main() {

	cin >> N >> M >> S >> D;
	int c1, c2, dis, c;
	fill(G[0], G[0]+MAX*MAX, inf);
	fill(C[0], C[0]+MAX*MAX, inf);
	fill(flag, flag + MAX, false);
	for (int i = 0; i < M; i++) {
		cin >> c1 >> c2 >> dis >> c;
		G[c1][c2] = G[c2][c1] = dis;
		C[c1][c2] = C[c2][c1] = c;
	}
	Djs(S);
	//path.push_back(D);
	DFS(D);
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
	cout << d[D] << " " << MinCost;
	return 0;
}