#include<iostream>
using namespace std;
#define N 1005
int M ,n;
int coins[N] = { 0 };
int main() {
	cin >> n >> M;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		coins[temp]++;
	}
	for (int i = 1; i < M; i++) {
		if (coins[i] == 0)continue;
		if (coins[M - i] == 0)continue;
		if (i * 2 == M&& coins[i] == 1) continue;
	
		printf("%d %d\n", i, M-i);
		return 0;
	}
	printf("No Solution\n");

	
	return 0;
}

/*
哈希表不够熟练，要学会区分key与values
*/