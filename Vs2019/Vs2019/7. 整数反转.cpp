#include<iostream>
using namespace std;
int reverse(int x) {
	int max = 0x7fffffff;
	double num =(double) abs(x);
	double res = 0,  temp;
	while (num) {
		res *= 10;
		temp = num % 10;
		res += temp;
		num /= 10;
		if (res > max) {
			return 0;
		}
	}

	return x > 0 ? res : -res;
}
