#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

unordered_map<string, vector<int>>lis;

int main() {
	int N, K;
	cin >> N >> K;
	string p;
	p.resize(4);
	for (int i = 0,j,k,c; i < K; i++) {
		scanf("%d %d", &c, &k);
		for (j = 0; j < k; j++) {
			scanf("%s", &p[0]);
			lis[p].push_back(c);
		}
	}

	for (auto &x : lis) {
		sort(x.second.begin(), x.second.end());
	}

	for (int i = 0,j; i < N; i++) {
		scanf("%s", &p[0]);
		printf("%s ", p.c_str());
		printf("%d",lis[p].size());
		for (auto& num : lis[p]) {
			printf(" %d", num);
		}
		printf("\n");
	}
	return 0;
}