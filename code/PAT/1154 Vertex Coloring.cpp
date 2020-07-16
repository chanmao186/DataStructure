#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> edgs[10005];

int color[10005];
int main() {
	int M, N,K,f,t;
	//fill(E, E + 10005 * 10005*sizeof(bool), false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &f, &t);
		edgs[f].push_back(t);
	}
	scanf("%d", &K);
	for (int i = 0,j; i < K; i++) {
		set<int>temp;
		for (j = 0; j < N; j++) {
			scanf("%d", &color[j]);
			temp.insert(color[j]);
		}
		for (j = 0; j < N; j++) {
			for (auto index : edgs[j]) {
				if (color[j] == color[index]) {
					printf("No\n");
					goto la;
				}
			}
		}
		printf("%d-coloring\n", temp.size());

	la:;
	}
	return 0;
}