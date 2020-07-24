#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> orig;

int main() {
	int N, M, per, maxn = 1,test;
	cin >> N >> M;
	orig.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> orig[i];
	}

	sort(orig.begin(), orig.end());

	for (int i = 0, j = i + 1; i < orig.size() && j < orig.size(); i++) {
		for (; j < orig.size() && orig[j] <= orig[i] * M; j++) {
			if (maxn < j - i + 1) {
				maxn = j - i + 1;
			}
		}
	}

	cout << maxn << endl;
	return 0;
}