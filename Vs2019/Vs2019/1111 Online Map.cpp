#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxn = 0x7fffffff;
int D[505][505] = { 0 },
T[505][505] = { 0 };
vector<int> Pred[505], Pret[505], resd, rest, temp;
int mind[505], mint[505], N, M, s, d, sum;
bool vist[505];

void Djs(int m[505], vector<int> Pre[505], int G[505][505]) {
	//fill(mind, mind + 505, maxn);
	fill(vist, vist + 505, false);
	int minn, index;
	for (int i = 0; i < N; i++) {
		if (G[s][i] != 0) {
			m[i] = G[s][i];
		}
	}
	m[s] = 0;
	while (true)
	{
		minn = maxn;
		for (int i = 0; i < N; i++) {
			if (!vist[i] && minn > m[i]) {
				minn = m[i];
				index = i;
			}
		}
		if (minn == maxn)break;
		vist[index] = true;
		for (int i = 0; i < N; i++) {
			if (!vist || G[index][i] == maxn)continue;
			if (minn + G[index][i] < m[i]) {
				Pre[i].clear();
				m[i] = minn + G[index][i];
				Pre[i].push_back(index);
			}
			else if (minn + G[index][i] == m[i]) {
				Pre[i].push_back(index);
			}
		}
	}
}

void DFS(int n, vector<int>Pre[505], vector<int>& res, int& minn, int G[505][505]) {
	if (n == s) {
		if (minn > sum) {
			minn = sum;
			res = temp;
		}
		return;
	}
	temp.push_back(n);
	for (auto& x : Pre[n]) {
		sum += G[n][x];
		DFS(x, Pre, res, minn, G);
		sum -= G[n][x];
	}
	temp.pop_back();
}

void DFS_s(int n, vector<int>Pre[505], vector<int>& res, int& minn) {
	if (n == s) {
		if (minn > temp.size()) {
			minn = temp.size();
			res = temp;
		}
		return;
	}
	temp.push_back(n);
	for (auto& x : Pre[n]) {
		DFS_s(x, Pre, res, minn);
	}
	temp.pop_back();
}

int main() {
	fill(T[0], T[0] + 505 * 505, maxn);
	fill(D[0], D[0] + 505 * 505, maxn);
	scanf("%d %d", &N, &M);
	int star, dist, one, length, time;
	
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &star, &dist, &one, &length, &time);
		D[star][dist] = length;
		T[star][dist] = time;
		if (one==0) {			
			D[dist][star] = length;
			T[dist][star] = time;
		}
	}
	scanf("%d %d", &s, &d);


	Djs(mind, Pred, D);
	Djs(mint, Pret, T);
	sum = 0;
	int minnn = maxn;
	DFS(d, Pred, resd, minnn, T);
	sum = 0;
	temp.clear();
	minnn = maxn;
	DFS_s(d, Pret, rest, minnn);


	if (resd == rest) {
		printf("Distance = %d; Time = %d: ", mind[d], mint[d]);
		printf("%d", s);
		for (int i = resd.size() - 1; i >= 0; i--) {
			printf(" -> %d", resd[i]);
		}
	}
	else {
		printf("Distance = %d: ", mind[d]);
		printf("%d", s);
		for (int i = resd.size() - 1; i >= 0; i--) {
			printf(" -> %d", resd[i]);
		}

		printf("\n");

		printf("Time = %d: ", mint[d]);
		printf("%d", s);
		for (int i = rest.size() - 1; i >= 0; i--) {
			printf(" -> %d", rest[i]);
		}
	}
	return 0;
}