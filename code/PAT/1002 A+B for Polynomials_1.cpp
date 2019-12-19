#include <iostream>
using namespace std;

#define N 1005
int main() {
	double result[N] = { 0.0 };
	int k, e, count=0,f=2;
	double c;
	while (f--) {
		cin >> k;
		while (k--)
		{
			cin >> e >> c;
			result[e] += c;
		}
	}
	
	int i = 0;
	for (; i < N; i++) {
		if (result[i] != 0.0) {
			count++;
		}
	}

	cout << count;

	for (i = N-1; i >= 0; i--) {
		if (result[i]!=0.0) {
			printf(" %d %.1f", i, result[i]);
		}
	}

	cout << endl;
	return 0;
}