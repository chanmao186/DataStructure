#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int color[205] = { 0 };
vector<int>strip;
int dp[10005] = { 0 };
int main() {
	int n, m,index,L,maxn=-1;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> index;
		color[index] = i;
	}
	cin >> L;

	for (int i = 1; i <= L; i++) {
		cin >> index;
		if (color[index] > 0) {
			strip.push_back(color[index]);
		}
	}

	for (int i = 0; i < strip.size(); i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (strip[i] >= strip[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		maxn = max(dp[i], maxn);
	}
	printf("%d\n", maxn);
	return 0;
}