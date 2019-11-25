#include<iostream>
using namespace std;
#define N 1001
int tree[N] = { 0 };
int main(void) {
	int m, n, temp, sum, singlesum, max, max_index;
	max_index = sum = 0;
	max = 0;
	cin >> n >> m;
	for (int i = 0, j; i < n; i++) {
		cin >> tree[i];
		singlesum = 0;
		for (j = 0; j < m; j++) {
			cin >> temp;
			singlesum += abs(temp);
		}
		tree[i] -= singlesum;
		sum += tree[i];
		if (max < singlesum) {
			max = singlesum;
			max_index = i;
		}
	}

	cout << sum << " " << max_index + 1 << " " << max << endl;
	return 0;
}