#include <iostream>
#include<vector>
using namespace std;
bool good[100005] = { false };
vector<int> igoods[100005];

int main() {
	int N, M, g1, g2;
	scanf("%d %d", &N,&M);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &g1, &g2);
		igoods[g1].push_back(g2);
		igoods[g2].push_back(g1);
	}
	int n, code;
	bool flag = true;
	for (int i = 0, j; i < M; i++) {
		fill(good, good + 100005 * sizeof(bool), false);
		flag = true;
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%d", &code);
			good[code] = true;
			if (flag) {
				for (auto g : igoods[code]) {
					if (good[g]) {
						flag = false; break;
					}
				}
			}
		}
		if (flag) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}