#include<iostream>
using namespace std;
int main() {
	int n, time, f_current, f_willto, num;
	f_current = time = 0;
	
	cin >> n;
	while (n--) {
		cin >> f_willto;
		num = f_willto - f_current;
		f_current = f_willto;
		if (num >= 0) {
			time += num * 6;
		}
		else {
			time += abs(num) * 4;
		}
		time += 5;
	}
	cout << time << endl;
	return 0;
}