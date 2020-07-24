#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int N, M, K, D, L;
unordered_map<string, int>gas;
bool vist[1020] = { false };
int G[1020][1020], d[1020], maxn = 100000000, minn =0, sumd = maxn, res = 0;
float r1, r2;

void Dji(int s) {
	int index, mins, i, sum = 0;
	for (i = 1; i <= L; i++) {
		d[i] = G[s][i];
		vist[i] = false;
	}
	d[s] = 0;
	while (true)
	{
		mins = maxn;
		for (i = 1; i <= L; i++) {
			if (!vist[i] && mins > d[i]) {
				index = i;
				mins = d[i];
			}
		}
		if (mins == maxn) {
			break;
		}
		vist[index] = true;
		for (i = 1; i <= L; i++) {
			if (vist[i] || G[index][i] == maxn) {
				continue;
			}
			if (mins + G[index][i] < d[i]) {
				d[i] = mins + G[index][i];
			}
		}
	}
	for (i = 1; i <= N; i++) {
		if (!vist[i] || d[i] >= D) {
			return;
		}
		sum += d[i];
		mins = min(mins, d[i]);
	}
	if (mins > minn) {
		sumd = sum;
		minn = mins;
		res = s;
	}
	else if (mins==minn&&sum < sumd) {
		sumd = sum;
		minn = mins;
		res = s;
	}

}

int GetIndex(string& s) {
	if (s[0] == 'G') {
		return gas[s];
	}
	else {
		return atoi(s.c_str());
	}
}

int main() {
	cin >> N >> M >> K >> D;
	int i, n1, n2, dis;
	string s1 = "G1", s2;
	L = M + N;
	fill(G[0], G[0] + 1020*1020, maxn);
	for (i = 1; i < M; i++) {
		gas[s1] = i + N;
		s1[1]++;
	}
	if (M == 10) {
		gas["G10"] = N + M;
	}
	else {
		gas[s1] = N + M;
	}


	for (i = 0; i < K; i++) {
		cin >> s1 >> s2 >> dis;
		n1 = GetIndex(s1);
		n2 = GetIndex(s2);
		G[n1][n2] = G[n2][n1] = dis;
	}

	for (i = N + 1; i <= L; i++) {
		Dji(i);
	}

	if (sumd == maxn) {
		printf("No Solution\n");
	}
	else {
		printf("G%d\n",res-N);
		r1 = minn;
		r2 = sumd * 1.0 / N;
		printf("%.1f %.1f", r1, r2);
	}
	return 0;
}