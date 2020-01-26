#include<iostream>
#include<math.h>
using namespace std;
bool isPrim(int n) {
	if (n <= 3) {
		return n > 1;
	}
	int sqr = (int)sqrt(n) + 1;
	for (int i = 2; i < sqr; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int radix, n, i, j;
	int	 num[10000];
	while (true) {
		cin >> n;
		if (n < 0) {
			break;
		}
		cin >> radix;
		if (!isPrim(n)) {
			printf("No\n");
			continue;
		}
		for (i = 0; n > 0; i++) {
			num[i] = n % radix;
			n /= radix;
		}
		n = 0;
		for (j = 0; j < i; j++) {
			n = n * radix + num[j];
		}
		if (isPrim(n)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}
/*
总结：
这次的教训就是一定要看案例之后再做题
*/