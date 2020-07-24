#include<iostream>
using namespace std;
bool table[10005] = { false };
bool isPrime(int n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int M, N, temp, j, k;
	cin >> M >> N;
	while (!isPrime(M))
	{
		M++;
	}
	cin >> temp;
	temp %= M;
	printf("%d", temp);
	table[temp] = true;
	for (int i = 1; i < N; i++) {
		cin >> temp;
		temp %= M;
		for (j = 0; j < M; j++) {
			k = (temp + j * j) % M;
			if (table[k] == false) {
				break;
			}
		}
		if (table[k]) {
			printf(" -");
		}
		else {
			table[k] = true;
			printf(" %d", k);
		}
	}
}