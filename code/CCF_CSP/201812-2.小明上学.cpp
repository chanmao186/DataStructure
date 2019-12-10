#include <iostream>
using namespace std;
int main() {
	int r, y, g, n, k, t, sum, temp;
	sum = 0;
	cin >> r >> y >> g >> n;
	while (n--) {
		cin >> k >> t;
		switch (k) {
		case 0:
			temp = t;
			break;
		case 3:
			temp = 0;
			break;
		case 1:
			temp = t;
			break;
		case 2:
			temp = t + r;
			break;

		}
		sum += temp;
	}
	cout << sum;
	return 0;
}