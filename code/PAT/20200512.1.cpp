#include<iostream>
using namespace std;

#define N 1005

int n;

int op[N];

int num[N];

void MSwap(int op,int index) {
	int temp = num[index];
	num[index] = num[op];
	num[op] = temp;
}

int main() {
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> op[i];
	}

	for (i = 0; i < n; i++) {
		num[i] = i+1;
	}

	for (i = 0; i < n; i++) {
		MSwap(op[i] - 1, i);
	}

	if (n > 0) {
		cout << num[0];
	}

	for (i = 1; i < n; i++) {
		cout << " " << num[i];
	}
	return 0;
}