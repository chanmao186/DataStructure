#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 2005
#define M 10005
#define K 105
long long c[N][N];

int mc[N];
int n, m, k;
int tn[N];
long long Result, w;
vector<int> select;

void Insert(int x) {
	if (select.size() > 0) {
		for (auto i : select) {
			w += c[i][x];
		}
	}
	select.push_back(x);
}

void Delete(int x) {
	select.erase(find(select.begin(), select.end(), x));
}

void Floy() {
	int i, j, k, temp;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (j == i) {
				continue;
			}
			for (k = 1; k <= n; k++) {
				temp = c[j][i] + c[i][k];
				if (temp < c[j][k]) {
					c[j][k] = c[k][j] = temp;
				}
			}
		}
	}
}

void Backs(int nm) {
	tn[nm] = w;
	k--;
	if (k == 0) {
		for (int i = nm; i < m; i++) {
			Insert(i);
			if (Result > w)Result = w;
			Delete(i);
			w = tn[nm];
		}
	}
	else {
		for (int i = nm; i < m - k; i++) {
			Insert(i);
			Backs(i + 1);
			Delete(i);
			w = tn[nm];
		}
	}

	k++;
}
int main() {
	const long long Max = (long long)(5e10 + 5);
	memset(c, Max, sizeof(c));
	int i, x, y, v, j;
	w = 0;
	Result = Max;
	cin >> n >> m >> k;

	for (i = 0; i < m; i++) {
		cin >> mc[i];
	}
	j = n - 1;
	for (i = 0; i < j; i++) {
		cin >> x >> y >> v;
		c[x][y] = c[y][x] = v;
	}

	Floy();

	Backs(0);

	cout << Result;
	return 0;
}