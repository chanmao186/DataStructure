#include <iostream>
using namespace std;
#define N 100005
int main() {
	int n, Max, Min;
	int Mid;
	int c[N] = { 0 };
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	//WMax = Min = Mid = c[0];
	if (n % 2) {
		Mid = c[n / 2];
	}
	else {
		Mid = (c[n / 2] + c[n / 2 - 1]) / 2;
	}

	if (c[0] > c[n]) {
		Max = c[0];
		Min = c[n - 1];
	}
	else {
		Max = c[n - 1];
		Min = c[0];
	}
	if(n % 2||(c[n / 2] + c[n / 2 - 1])%2==0)
		cout << Max << " " << Mid << " " << Min;
	else {
		cout << Max << " " << Mid << ".5 " << Min;
	}
	return 0;
}
