#include <iostream>
using namespace std;
long long d, q;
long long sum;
//指示灯的时间 
//t显示时间 
long long getTime(long long ty, long long t) {
	long long temp = (sum + (ty - t)) % q - d;
	return temp > 0 ? 0 : -temp;

}
int main() {
	long long r, y, g, k, t, n, temp;
	cin >> r >> y >> g >> n;

	d = r + y;
	q = d + g;
	sum = 0;
	while (n--) {
		cin >> k >> t;
		switch (k) {
		case 0:
			temp = t;
			break;
		case 1:
			temp = getTime(d, t);
			break;
		case 2:
			temp = getTime(y, t);
			break;
		case 3:
			temp = getTime(q, t);
			break;
		}
		sum += temp;
	}
	cout << sum;
	return 0;
}