#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int, int> color;
int main() {
	int M, N, count = 0,res,temp;
	scanf("%d%d", &M, &N);
	for (int i = 0,j; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &temp);
			color[temp]++;
			if (color[temp] > count) {
				res = temp;
				count = color[temp];
			}
		}
	}
	printf("%d\n", res);
	return 0;
}