#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 505
const int Max = 100000000,
Min = -10000000;

int M[N][N] = { Max };
vector<int> Pre[N];
vector<int> BestPath, tPath;
int Cmax, Best;//最大容量和最优容量
int ShotPath[N];
int Bike[N];
int flag[N] = { false };
int sp, n;
int sent = Max, in = Max, _sent, _in;
void Djik() {
	int _m, j, pos = 0, temp;
	for (int i = 0, j; i <= n; i++) {
		_m = Max;
		for (j = 0; j <= n; j++) {
			if (!flag[j] && _m > ShotPath[j]) {
				pos = j;
				_m = ShotPath[j];
			}
		}
		flag[pos] = true;
		for (j = 0; j <= n; j++) {
			if (!flag[j]) {
				temp = ShotPath[pos] + M[pos][j];
				if (temp < ShotPath[j]) {
					ShotPath[j] = temp;
					Pre[j].clear();
					Pre[j].push_back(pos);
				}
				else if (temp == ShotPath[j]) {
					Pre[j].push_back(pos);
				}
			}
		}
	}
}
void Dfs(int city) {
	if (city == 0) {
		_sent = _in = 0;
		int temp;
		for (int i = tPath.size() - 1; i >= 0; i--) {
			temp = Bike[tPath[i]] - Best;
			if (temp < 0) {
				if (_in + temp >= 0) {
					_in += temp;
				}
				else {
					_sent += abs(_in + temp);
					_in = 0;
				}
			}
			else {
				_in += temp;
			}
		}
		if (_sent < sent || (_sent == sent && _in < in)) {
			sent = _sent;
			in = _in;
			BestPath = tPath;
		}
	}
	tPath.push_back(city);
	for (auto x : Pre[city]) {
		Dfs(x);
	}
	tPath.pop_back();
}
int main() {
	int  m;

	fill(M[0], M[0] + N * N, Max);
	cin >> Cmax >> n >> sp >> m;
	for (int i = 1; i <= n; i++) {
		cin >> Bike[i];
	}
	Best = Cmax / 2;
	int a, b, c;

	while (m--)
	{
		cin >> a >> b >> c;
		M[a][b] = M[b][a] = c;
	}
	M[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		ShotPath[i] = M[0][i];
	}
	Djik();
	Dfs(sp);
	reverse(BestPath.begin(), BestPath.end());
	cout << sent << " 0";
	for (auto x : BestPath) {
		cout << "->" << x;
	}
	cout << " " << in << endl;
	return 0;
}

/*
Dijkstra+Dfs,
用Dijks找到最短路径
用DFS找到满足条件的最优解
*/