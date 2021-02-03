#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>v, tmp, res;
int n, k, p, maxa = -1;

int op(int num) {
	int temp = num;
	for (int i = 0; i < p - 1; i++) {
		temp *= num;
	}
	return temp;
}

void DFS(int num, int sum, int index, int weight) {
	if (sum > n || index > k)return;
	if (sum == n && index == k) {
		if (maxa < weight) {
			maxa = weight;
			res = tmp;
		}
	}

	if (num >= 1) {
		tmp.push_back(num);
		DFS(num, sum + v[num], index + 1, weight + num);
		tmp.pop_back();
		DFS(num - 1, sum, index, weight);//²»ÄÜÑ¡0
	}
}

int main() {
	cin >> n >> k >> p;
	for (int i = 0; op(i) <= n; i++) {
		v.push_back(op(i));
	}

	DFS(v.size() - 1, 0, 0, 0);
	if (maxa == -1) {
		printf("Impossible");
	}
	else {
		printf("%d = ",n);
		printf("%d^%d ", res[0], p);
		for (int i = 1; i < k; i++) {
			printf("+ %d^%d", res[i], p);
		}
	}
	return 0;
}