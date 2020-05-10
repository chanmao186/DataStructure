#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define N 105
int n;
int op[N] = { 0 };
int result[N] = { 0 };

int GetHappy(int num) {
	int  h = 0;
	int temp;
	while ((num /10)> 0) {
		temp = num % 10;
		num /= 10;
		h += temp * temp * temp;
	}
	if (num > 0) {
		h += num * num * num;
	}
	return h;
}

int CheckIsHappy(int num) {
	vector<int> m;
	int layer = 0;
	while (num!=1)
	{
		num = GetHappy(num);
		layer++;
		for (auto e : m) {
			if (e == num) {
				return e;
			}
		}
		m.push_back(num);
	}
	return layer;
}

int main() {
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> op[i];
	}

	for (i = 0; i < n; i++) {
		result[i] = CheckIsHappy(op[i]);
	}
	/*
	if (n > 0) {
		cout << result[i];
	}
	*/

	for (i = 0; i < n; i++) {
		cout << result[i] << endl;
	}
	return 0;
}